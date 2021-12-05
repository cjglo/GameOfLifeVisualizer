#include "../inc/draw_call.h"

// quick helper function to trigger draw every half second
gboolean timeout(GtkWidget *widget)
{
    gtk_widget_queue_draw(widget);
    return TRUE;
}

gint main(int argc,char *argv[])
{
    int** mat = init_matrix(MATRIX_HEIGHT, MATRIX_LENGTH); // matrix that holds game-state data, initiated

    // basic gtk app set-up
    GtkWidget *window, *drawing_area;
    gtk_init (&argc, &argv);
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL); // exit function
    drawing_area = gtk_drawing_area_new();
    gtk_container_add (GTK_CONTAINER (window), drawing_area);
    gtk_widget_set_size_request (drawing_area, WINDOW_HEIGHT, WINDOW_LENGTH);

    g_signal_connect (G_OBJECT (drawing_area), "draw", G_CALLBACK (draw_callback), mat); // draw call, spring board for all logic I impl
    gtk_widget_show_all (window);

    g_timeout_add(500, (GSourceFunc)timeout, window); // timer to call draw every half second
    gtk_main (); // loop that runs gtk
    
    // free matrix
    for(int i = 0; i<MATRIX_HEIGHT; i++) {
        free(mat[i]);
    }
    free(mat);

    return 0;
}
