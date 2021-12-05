#include "const.h"


int** init_matrix(int height, int length) {

        // alloc the matrix (array of arrays) since returns ptr
        int** matrix = (int **)malloc(height * sizeof(int*));
        for(int i = 0; i<height; i++) {
                matrix[i] = (int *)malloc(length * sizeof(int));
        }

        for(int i = 0; i<height; i++) {

                for(int j = 0; j<length; j++) {

                        // for testing purposes, making a pre-defined structure
                        if(i == 10 && j == 10) {

                                matrix[i][j] = 1;
                                matrix[i-1][j-1] = 1;
                                matrix[i-2][j-2] = 1;
                                matrix[i][j-1] = 1;
                                matrix[i-3][j-2] = 1;
                                matrix[i-1][j] = 1;
                                matrix[i-3][j] = 1;
                                matrix[i][j-2] = 1;
                                matrix[i-4][j-3] = 1;

                        } else {
                                matrix[i][j] = 0;
                        }
                }
        }

        return matrix;
}