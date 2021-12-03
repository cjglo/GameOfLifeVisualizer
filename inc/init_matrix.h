#include "const.h"


struct Matrix {
        int data[MATRIX_HEIGHT][MATRIX_LENGTH];
};

// Matrix* init() {

//     // have to dynamically alloc because returning pointer
//     // Matrix* mat = ();

//     for(int i = 0; i<MATRIX_HEIGHT; i++) {

//         for(int j = 0; j<MATRIX_LENGTH; j++) {

//             if( j % 2 == 0) {
//                 mat[i][j] = 0;
//             } else {
//                 mat[i][j] = 1;
//             }

//         }

//     }

// }