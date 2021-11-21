#include "./headers/lifegui.h"


int main(int argc, char* argv[]){

	GtkWidget* window;
	GtkWidget* area;

	gtk_init(&argc, &argv);
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL); // init window

	// sets close to destroy function, which just stops gui
	g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);

	gtk_container_set_border_width(GTK_CONTAINER(window), WINDOW_SIZE);

	// initializing drawing area
	area = gtk_drawing_area_new();
	gtk_drawing_area_set_content_width (GTK_DRAWING_AREA (area), DRAWING_SIZE);
	gtk_drawing_area_set_content_height (GTK_DRAWING_AREA (area), DRAWING_SIZE);
	gtk_drawing_area_set_draw_func (GTK_DRAWING_AREA (area),
                                  draw_func,
                                  NULL, NULL);


	// g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(welcome), "button");

	gtk_window_set_title(GTK_WINDOW(window), "Game of Life Visualizer 1.0.0-alpha");

	// gtk_container_add(GTK_CONTAINER(window), button); // add button to window
	gtk_widget_show_all(window); // set visible
	gtk_main();

	return 0;
}

