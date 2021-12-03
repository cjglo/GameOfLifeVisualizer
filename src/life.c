#include "../inc/draw_call.h"

gint main(int argc,char *argv[])
{

    int row1[] = {1,2,3,4};
    int row2[] = {4,5,6,7};

    int* mat1[] = {row1, row2};
    // int mat1[][4] = { {1,2, 3, 4}, {5, 6, 7, 8} };
    

    GtkWidget *window, *drawing_area;
    
    gtk_init (&argc, &argv);
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);
    
    drawing_area = gtk_drawing_area_new();
    gtk_container_add (GTK_CONTAINER (window), drawing_area);
    gtk_widget_set_size_request (drawing_area, 300, 500);
    g_signal_connect (G_OBJECT (drawing_area), "draw", G_CALLBACK (draw_callback), mat1);
    gtk_widget_show_all (window);
    gtk_main ();
    return 0;
}
