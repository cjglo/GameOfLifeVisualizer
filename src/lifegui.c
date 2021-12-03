#include <gtk/gtk.h>

struct Matrix {
        int data[2][2];
};

gboolean draw_callback (GtkWidget *widget, cairo_t *cr, gpointer data)
{
    struct Matrix* mat = data;

    for(int i = 0; i < 2; i++) {

        for(int j = 0; j<2; j++) {
            printf("%d ", mat->data[i][j]);   
            mat->data[i][j]++;
        }



    }


    guint width, height;
    GdkRGBA color;
    GtkStyleContext *context;
    int i = 0;
    context = gtk_widget_get_style_context (widget);
    width = gtk_widget_get_allocated_width (widget);
    height = gtk_widget_get_allocated_height (widget);
    gtk_render_background(context, cr, 0, 0, width, height);
    cairo_set_line_width (cr, .5);

    int x = mat->data[0][0];
    int y = 20;
    // int scale = 0;
    while (i < 101) {

        if(i % 2 == 0) {
            cairo_move_to(cr, x - 20, y - 20);
            cairo_line_to(cr, x, y - 20);
            cairo_line_to(cr, x, y);
            cairo_line_to(cr, x - 20, y);
            cairo_line_to(cr, x - 20, y - 20);
            cairo_fill (cr);

            if(i % 20 == 0 && i != 0) {
                y += 20;
                x = 0;
            } else if (i % 10 == 0 && i != 0) {
                y += 20;
                x = 20;
            }
        }
        x += 20;
        // y += 20;
        i++;
    }
    cairo_stroke (cr);

    
    // cairo_arc (cr, width/2.0, height/2.0, MIN (width, height) / 2.0, 0, 2 * G_PI);
    gtk_style_context_get_color (context, gtk_style_context_get_state (context), &color);
    gdk_cairo_set_source_rgba (cr, &color);
    gdk_cairo_set_source_rgba (cr, &color);
    cairo_fill (cr);
    return FALSE;
}

gint main(int argc,char *argv[])
{

    struct Matrix mat1 = {
        { {1,2}, {3,4} }
    };

    GtkWidget *window, *drawing_area;
    
    gtk_init (&argc, &argv);
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);
    
    drawing_area = gtk_drawing_area_new();
    gtk_container_add (GTK_CONTAINER (window), drawing_area);
    gtk_widget_set_size_request (drawing_area, 300, 500);
    g_signal_connect (G_OBJECT (drawing_area), "draw", G_CALLBACK (draw_callback), &mat1);
    gtk_widget_show_all (window);
    gtk_main ();
    return 0;
}

// https://www.cairographics.org/samples/
// gtk gcc testcase.c `pkg-config --cflags gtk+-3.0 --libs gtk+-3.0` -o draw