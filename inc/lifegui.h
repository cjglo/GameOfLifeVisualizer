#include <gtk/gtk.h>
#include <cairo.h>

static const int WINDOW_SIZE = 100;
static const int DRAWING_SIZE = 50;
static int COUNT = 0;

void welcome(GtkWidget* widget, gpointer data) {

	g_print("Hello World!\n");
	g_print("%s Clicked %d times\n", (char*)data, ++COUNT);
}

void destroy(GtkWidget* widget, gpointer data) {
	gtk_main_quit();
}

// function that is passed to Gtk to define drawing behaivor
void draw_func( 
        GtkDrawingArea *area,
        cairo_t *cr,
        int width, 
        int height,
        gpointer data ) {

        GdkRGBA color;
        GtkStyleContext *context;

        context = gtk_widget_get_style_context (GTK_WIDGET (area));

        cairo_arc (cr,
                    width / 2.0, height / 2.0,
                    MIN (width, height) / 2.0,
                    0, 2 * G_PI);

        gtk_style_context_get_color (context,
                                    &color);
        gdk_cairo_set_source_rgba (cr, &color);

        cairo_fill (cr);

    }

