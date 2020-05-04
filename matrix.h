/**Structures*/
//Structure for Node
typedef struct node Node;
struct node{
    int value;
    Node *top, *bottom;
};
//Structure for Matrix
typedef struct matrix Matrix;
struct matrix{
    Node *first;
    int m, n;
};

/**Functions for Matrix*/
//Function for create Matrix
Matrix *createMatrix();
//Function for allocate Matrix on memory
Matrix *alocateMatrix(Matrix *mat, int m, int n);
//Function for delete Matrix
Matrix *deleteMatrix(Matrix *mat);
//Function for print all Matrix's elements
void printMatrix(Matrix *mat);

/**Functions for Node*/
//Function for insert a new value in Node's value
Node *insertValue(Matrix *mat, int i, int j, int value);
//Function for search Node by value
Node *searchNodebyValue(Matrix *mat, int value);
//Function for print all Node's neighbor
Node *printNeighbor(Matrix *mat, int i, int j);
