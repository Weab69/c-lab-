#include <stdio.h>
#include <stdlib.h>

int matrixMultiply(int A[][8], int B[][8], int row);
int allocate_matrix();
 
int main() {
	allocate_matrix;
    int **A = allocate_matrix(A, 8, 8);
    int **B = allocate_matrix(B, 8, 8);

    int i, j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            A[i][j] = i + j;
            A[i][j] = i + j;
        }
    }

    int **C = allocate_matrix(C, 8, 8);
    C = matrixMultiply(A, B, 8);

    return 0;
}

int **matrixMultiply(int A[][8], int B[][8], int row) {
    int **C = allocate_matrix(C, row, row);
    if (row == 1) {
        C[1][1] = A[1][1] * B[1][1];
    } else {
        int a11[row/2][row/2], a12[row/2][row/2], a21[row/2][row/2], a22[row/2][row/2];
        int b11[row/2][row/2], b12[row/2][row/2], b21[row/2][row/2], b22[row/2][row/2];
        int **c11 = allocate_matrix(c11, row/2, row/2);
        int **c12 = allocate_matrix(c12, row/2, row/2);
        int **c21 = allocate_matrix(c21, row/2, row/2);
        int **c22 = allocate_matrix(c22, row/2, row/2);

        int i, j;
        for (i = 0; i < row/2; i++) {
            for (j = 0; j < row/2; j++) {
                a11[i][j] = A[i][j];
                a12[i][j] = A[i][j + (row/2)];
                a21[i][j] = A[i + (row/2)][j];
                a22[i][j] = A[i + (row/2)][j + (row/2)];
                b11[i][j] = B[i][j];
                b12[i][j] = B[i][j + (row/2)];
                b21[i][j] = B[i + (row/2)][j];
                b22[i][j] = B[i + (row/2)][j + (row/2)];
                c11[i][j] = C[i][j];
                c12[i][j] = C[i][j + (row/2)];
                c21[i][j] = C[i + (row/2)][j];
                c22[i][j] = C[i + (row/2)][j + (row/2)];
            }
        }

        c11 = addmatrix(matrixMultiply(a11, b11, row/2),
                        matrixMultiply(a12, b21, row/2), c11, row/2);
        c12 = addmatrix(matrixMultiply(a11, b12, row/2),
                        matrixMultiply(a22, b22, row/2), c12, row/2);
        c21 = addmatrix(matrixMultiply(a21, b11, row/2),
                        matrixMultiply(a22, b21, row/2), c21, row/2);
        c22 = addmatrix(matrixMultiply(a21, b12, row/2),
                        matrixMultiply(a22, b22, row/2), c22, row/2);

        // missing code???
        return C;
    }
}

int **allocate_matrix(int **matrix, int row, int column) {
    matrix = (int )malloc(row * sizeof(int*));
    int i;
    for (i = 0; i < row; i++) {
        matrix[row] = (int *)malloc(row * sizeof(int));
    }
    return matrix;
}

void deallocate_matrix(int **matrix, int row) {
    int i;
    for (i = 0; i < row; i++) {
        free(matrix[row]);
    }
    free(matrix);
}

int **addMatrix(int **a, int **b, int **c, int row) {
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < row; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    return c;
}
