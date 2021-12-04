#include "const.h"


int** init_matrix(int height, int length) {

        // alloc the matrix (array of arrays) since returns ptr
        int** matrix = (int **)malloc(height * sizeof(int*));
        for(int i = 0; i<height; i++) {
                matrix[i] = (int *)malloc(length * sizeof(int));
        }

        for(int i = 0; i<height; i++) {

                for(int j = 0; j<length; j++) {

                        // creating checkered pattern by having mod j and mod i compared
                        if( j % 2 == i % 2) {
                                matrix[i][j] = 1;
                        } else {
                                matrix[i][j] = 0;
                        }
                }
        }

        return matrix;
}