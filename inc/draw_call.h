#include <gtk/gtk.h>
#include "init_matrix.h"

gboolean draw_callback (GtkWidget *widget, cairo_t *cr, gpointer data)
{
    int** mat = data; // import matrix alloced in main


    guint width, height;
    GdkRGBA color;
    GdkRGBA white = {1.0, 1.0, 1.0, 1.0};
    GdkRGBA black = {0.0, 0.0, 0.0, 1.0};
    GtkStyleContext *context;
    int i = 0;
    context = gtk_widget_get_style_context (widget);
    width = gtk_widget_get_allocated_width (widget);
    height = gtk_widget_get_allocated_height (widget);
    gtk_render_background(context, cr, 0, 0, width, height);
    cairo_set_line_width (cr, .5);

    // x and y are coordinates on window
    int x = 0;
    int y = 10;
    // loop for drawing the board
    for(int i = 0; i < MATRIX_HEIGHT; i++) {

        for(int j = 0; j< MATRIX_LENGTH; j++) {

                // outline a box
                cairo_move_to(cr, x - 10, y - 10);
                cairo_line_to(cr, x, y - 10);
                cairo_line_to(cr, x, y);
                cairo_line_to(cr, x - 10, y);
                cairo_line_to(cr, x - 10, y - 10);

                // logic to see if cell is alive or dead, and color it so
                if(mat[i][j] == 0) {
                    gdk_cairo_set_source_rgba (cr, &black);
                } else {
                    gdk_cairo_set_source_rgba (cr, &white);
                }
                cairo_fill (cr);

                x += 10; // move to the right for next box
        }

        // reset for next row and move down
        x = 0;
        y += 10;

    }
    cairo_stroke (cr);

    gtk_style_context_get_color (context, gtk_style_context_get_state (context), &color);
    gdk_cairo_set_source_rgba (cr, &black);
    cairo_fill (cr);
    return FALSE;
}
