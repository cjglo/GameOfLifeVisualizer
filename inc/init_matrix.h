#ifndef __INIT_MATRIX_H__
#define __INIT_MATRIX_H__

#include "const.h"

struct matrix* init_matrix(int height, int length) {

        // not necessary to dynamically allocate if I built it in main, but
        // I want practice
        struct matrix* m = (struct matrix*)malloc(sizeof (struct matrix));
        if(m == NULL) {
                exit(1); 
        }

        m->data = (int **)malloc(height * sizeof(int*));

        for(int i = 0; i<height; i++) {
                m->data[i] = (int *)malloc(length * sizeof(int));
        }

        for(int i = 0; i<height; i++) {

                for(int j = 0; j<length; j++) {

                       m->data[i][j] = 0;
                        
                }
        }

        m->game_has_started = FALSE; 

        return m;
}


#endif