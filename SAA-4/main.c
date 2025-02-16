#include <stdio.h>
#include <stdlib.h>

void fullMatrix(int a, int b, int matrix[a][b]){
    int num;
    for(int i = 0; i < a; i++){
        for(int j = 0; j < b; j++){
            printf("Enter the element for position [%d][%d]: ", i, j);
            scanf("%d", &num);
            while(num < -1000 || num > 1000){
                printf("Your input is invalid!\n");
                printf("Enter the element for position [%d][%d] again:", i, j);
                scanf("%d", &num);
            }
            matrix[i][j] = num;
        }
    }
}

void printMatrix(int a, int b, int matrix[a][b]){
    printf("The matrix is:\n");
    for(int i = 0; i < a; i++){
        for(int j = 0; j < b; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void newMatrixFunction(int n, int matrixA[n][n], int matrixB[n][n], int newMatrix[n]){
   for (int i = 0; i < n; i++) {
        newMatrix[i] = matrixA[i][i] + matrixB[i][i];
    }
}

void printArray(int n, int newMatrix[n]) {
    printf("The array is: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", newMatrix[i]);
    }
    printf("\n");
}

void sortArray(int n, int newMatrix[n]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (newMatrix[i] > newMatrix[j]) {
                int temp = newMatrix[i];
                newMatrix[i] = newMatrix[j];
                newMatrix[j] = temp;
            }
        }
    }
}

int main()
{
    printf("Enter the number of the matrix where the numbers are between [-1000;1000]!\n");
    printf("Author: Krasimir Gushmakov\n");

    int rows, cols;
    printf("Enter the rows of the matrixes: ");
    scanf("%d", &rows);
    printf("Enter the cols of the matrixes: ");
    scanf("%d", &cols);

    int matrixA[rows][cols];
    fullMatrix(rows, cols, matrixA);
    printMatrix(rows, cols, matrixA);

    int matrixB[rows][cols];
    fullMatrix(rows, cols, matrixB);
    printMatrix(rows, cols, matrixB);

    int num = (rows + cols) / 2;
    int newMatrix[num];

    newMatrixFunction(num, matrixA, matrixB, newMatrix);
    printf("Array after the summary of the diagonals!\n");
    printArray(num, newMatrix);

    sortArray(num, newMatrix);
    printf("Array after sorting!\n");
    printArray(num, newMatrix);

    return 0;
}
