#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main(){
    Matrix *mat;
    mat = createMatrix();

    alocateMatrix(mat, 3, 3);

    printf("/-------------------------/\n");

    printMatrix(mat);

    printf("/-------------------------/\n");

    insertValue(mat, 1, 1, 4);
    insertValue(mat, 1, 2, 20);
    insertValue(mat, 1, 3, 0);
    insertValue(mat, 2, 1, 0);
    insertValue(mat, 2, 2, 4);
    insertValue(mat, 2, 3, 20);
    insertValue(mat, 3, 1, 20);
    insertValue(mat, 3, 2, 0);
    insertValue(mat, 3, 3, 4);

    printf("New Matrix: \n");
    printMatrix(mat);

    printf("/-------------------------/\n");

    searchNodebyValue(mat, 20);

    printf("/-------------------------/\n");

    printNeighbor(mat, 2, 2);

    return 0;
    getch();
}
