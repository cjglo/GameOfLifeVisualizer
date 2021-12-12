#ifndef __SELECT_CELLS_H__
#define __SELECT_CELLS_H__

#include <gtk/gtk.h>
#include <math.h> 
#include "const.h"

gboolean selecting_cells(GtkWidget *event_box, GdkEventButton *event, gpointer data) {

        struct matrix* mat = data;

        int x = ((int) event->x) / 10;
        int y = ((int) event->y) / 10;

        if( x >= 0 && y >= 0 && x <= MATRIX_LENGTH && y <= MATRIX_HEIGHT) {
            // y and x are flipped becuase the event has x as length, which is second index of matrix (and vice versa)
            mat->data[y][x] = !mat->data[y][x];
        }
    

        return TRUE;
}

#endif