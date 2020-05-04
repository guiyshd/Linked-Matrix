#include<stdio.h>
#include<stdlib.h>
#include"matrix.h"

Matrix *createMatrix(){
    Matrix *mat = (Matrix*) malloc(sizeof(Matrix));

    mat->first = NULL;

    return mat;
}

Matrix *deleteMatrix(Matrix *mat){
    if(mat != NULL)
        free(mat);
}

Matrix *alocateMatrix(Matrix *mat, int m, int n){
    Node *alocate = (Node*) malloc((m*n*sizeof(Node)));

    mat->m = m;
    mat->n = n;
    mat->first = alocate;

    if(mat->first == NULL)
        return 0;

     for(int a=0, b=mat->m; b<mat->m*mat->n; a++, b++){
        Node *auxA = &mat->first[a];
        Node *auxB = &mat->first[b];
        auxA->bottom = auxB;
        auxB->top = auxA;
    }

    for(int a=0, b=(mat->m-1)*mat->n; a<mat->m, b<(mat->m)*mat->n; a++, b++){
        Node *auxA = &mat->first[a];
        Node *auxB = &mat->first[b];
        auxA->top = auxB;
        auxB->bottom = auxA;
    }

    Node *auxA = &mat->first[0];
    auxA -= 1;
    auxA = &mat->first[(mat->m)*(mat->n)];

    for(int i=0, a=0; i<m; i++)
        for(int j=0; j<n; j++, a++){
            printf("Insert value at [%d][%d] -> ", i+1, j+1);
            scanf("%d", &mat->first[a].value);
        }

    return mat;
}

void printMatrix(Matrix *mat){
    for(int i=0, a=0; i<mat->n; i++){
        for(int j=0; j<mat->m; j++, a++)
            printf("%d\t", mat->first[a].value);
        printf("\n");
    }
}

Node *insertValue(Matrix *mat, int i, int j, int value){
    if((i-1 < 0)||(j-1 > mat->m)||(i-1 > mat->n)||(j-1 < 0)){
        printf("Parameters out of Matrix range!");
        exit(1);
    }
    Node *tracer = &mat->first[(((i-1)*mat->m)+j-1)];

    tracer->value = value;

    return mat;
}

Node *searchNodebyValue(Matrix *mat, int value){
    int control=0, lines = mat->n, columns = mat->m;

    printf("Coordinate for %d: \n", value);
    for(int i=0, j=0, k=0; k<mat->m*mat->n; k++, j++){
        if(k > lines-1){
            i++;
            lines += lines;
        }
        if(k > columns-1){
            j=0;
            columns += columns;
        }
        if(mat->first[k].value == value){
            printf("(%d, %d)\t", i+1, j+1);
            control++;
        }
    }
    printf("\n");
    if(control == 0)
        return NULL;
    return mat;
}

Node *printNeighbor(Matrix *mat, int i, int j){
    if((i-1 < 0)||(j-1 > mat->m)||(i-1 > mat->n)||(j-1 < 0)){
        printf("Parameters out of Matrix range!");
        exit(1);
    }
    printf("(%d, %d) neighbors: \n", i, j);
    Node *aux = &mat->first[(((i-1)*mat->m)+j-1)];
    Node *tracer = aux;

    tracer = aux->top;
    printf("\t%d\t \n", tracer->value);

    if(i-1 == 0 && j-1 == 0){
        tracer = &mat->first[((mat->n)-1)*mat->m+((mat->n)-1)];
        printf("%d\t%d\t", tracer->value, aux->value);
    } else{
        tracer = aux-1;
        printf("%d\t%d\t", tracer->value, aux->value);
    }

    if(i-1 == (mat->m)-1 && j-1 == (mat->n)-1){
        tracer = &mat->first[0];
        printf("%d\t\n", tracer->value);
    } else{
        tracer = aux+1;
        printf("%d\t\n", tracer->value);
    }

    tracer = aux->bottom;
    printf("\t%d \n", tracer->value);
}
