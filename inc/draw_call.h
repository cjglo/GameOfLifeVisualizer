#include <gtk/gtk.h>
#include "init_matrix.h"

gboolean draw_callback (GtkWidget *widget, cairo_t *cr, gpointer data)
{
    int** mat= data;

    for(int i = 0; i < 2; i++) {

        // printf("%d", **mat);

        for(int j = 0; j<2; j++) {
            printf("%d ", mat[i][j]);   
            mat[i][j]++;
        }

    }


    guint width, height;
    GdkRGBA color;
    GdkRGBA white = {1.0, 1.0, 1.0, 1.0};
    GdkRGBA black = {0.0, 0.0, 0.0, 0.0};
    GtkStyleContext *context;
    int i = 0;
    context = gtk_widget_get_style_context (widget);
    width = gtk_widget_get_allocated_width (widget);
    height = gtk_widget_get_allocated_height (widget);
    gtk_render_background(context, cr, 0, 0, width, height);
    cairo_set_line_width (cr, .5);

    int x = 0;
    int y = 20;
    // interating through and drawing boxes, flipping between black and white
    while (i < 101) {

        cairo_move_to(cr, x - 20, y - 20);
        cairo_line_to(cr, x, y - 20);
        cairo_line_to(cr, x, y);
        cairo_line_to(cr, x - 20, y);
        cairo_line_to(cr, x - 20, y - 20);

        if(i % 20 == 0 && i != 0) {
            y += 20;
            x = 0;
        } else if (i % 10 == 0 && i != 0) {
            y += 20;
            x = 20;
        }

        if(i % 2 == 0) {
            gdk_cairo_set_source_rgba (cr, &black);
            cairo_fill (cr);
        } else {
            gdk_cairo_set_source_rgba (cr, &white);
            cairo_fill (cr);

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