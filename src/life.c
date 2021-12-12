#include "../inc/draw_callback.h"
#include "../inc/selecting_cells.h"
#include "../inc/const.h"

// quick helper functions to trigger draw and game start
gboolean timeout(GtkWidget *widget);
gboolean on_key_press (GtkWidget *widget, GdkEventKey *event, gpointer data);

gint main(int argc,char *argv[])
{
    // matrix that holds game-state data
    struct matrix* mat = init_matrix(MATRIX_HEIGHT, MATRIX_LENGTH); 

    // typical gtk window set-up
    GtkWidget *window, *drawing_area, *label;
    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window),"Game of Life Visualizer: Click the screen to customize then click space!"); 
    g_signal_connect(window, "destroy", G_CALLBACK (gtk_main_quit), NULL); // exit function
    // typical gtk drawing area set-up
    drawing_area = gtk_drawing_area_new();
    gtk_container_add(GTK_CONTAINER (window), drawing_area);
    gtk_widget_set_size_request(drawing_area, WINDOW_HEIGHT, WINDOW_LENGTH);


    g_signal_connect(G_OBJECT(drawing_area), "draw", G_CALLBACK(draw_callback), mat); // draw call, spring board for game logic I impl
    gtk_widget_show_all (window);
    
    // pre-game phase logic, where I let user choose cells
    g_signal_connect(G_OBJECT(window),  
                  "button-press-event",
                  G_CALLBACK(selecting_cells),
                  mat);
    // starts game, ends selecting
    g_signal_connect (G_OBJECT(window), 
                "key_press_event", 
                G_CALLBACK(on_key_press), 
                mat);


    g_timeout_add(250, (GSourceFunc)timeout, window); // timer to call draw every quarter second
    gtk_main (); // loop that runs gtk
    
    // free matrix
    for(int i = 0; i<MATRIX_HEIGHT; i++) {
        free(mat->data[i]);
    }
    free(mat->data); 
    free(mat); 

    return 0;
}


gboolean timeout(GtkWidget *widget)
{
    gtk_widget_queue_draw(widget);
    return TRUE;
}

gboolean on_key_press (GtkWidget *widget, GdkEventKey *event, gpointer data)
{
    struct matrix* m = data;

    if(event->keyval == GDK_KEY_space) {
        m->game_has_started = TRUE;
    }

    return TRUE;
}