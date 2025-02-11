#include <stdio.h>
#include <stdlib.h>

void readMatrix(int rows, int cols, int arr[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter an element at position (%d, %d): ", i + 1, j + 1);
            scanf("%d", &arr[i][j]);
        }
    }
}

void multiplyMatrices(int rows1, int cols1, int arr1[rows1][cols1], int rows2, int cols2, int arr2[rows2][cols2], int result[rows1][cols2]) {
    if (cols1 != rows2) {
        printf("Cannot multiply matrices: number of columns in the first matrix is not equal to the number of rows in the second matrix.\n");
        return;
    }

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
}

void printMatrix(int rows, int cols, int arr[rows][cols]) {
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows1, cols1;
    printf("Enter the number of rows for the first matrix: ");
    scanf("%d", &rows1);
    printf("Enter the number of columns for the first matrix: ");
    scanf("%d", &cols1);
    int matrix1[rows1][cols1];
    readMatrix(rows1, cols1, matrix1);

    int rows2, cols2;
    printf("Enter the number of rows for the second matrix: ");
    scanf("%d", &rows2);
    printf("Enter the number of columns for the second matrix: ");
    scanf("%d", &cols2);
    int matrix2[rows2][cols2];
    readMatrix(rows2, cols2, matrix2);

    if (cols1 != rows2) {
        printf("Cannot multiply matrices: number of columns in the first matrix is not equal to the number of rows in the second matrix.\n");
        return 1;
    }

    int result[rows1][cols2];
    multiplyMatrices(rows1, cols1, matrix1, rows2, cols2, matrix2, result);

    printf("Resultant Matrix:\n");
    printMatrix(rows1, cols2, result);

    return 0;
}
