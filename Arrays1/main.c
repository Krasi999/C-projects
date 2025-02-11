#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define Rows 4
#define Cols 2

bool isOutOfBounds(int num) {
    return num > 127 || num < -127;
}

void reader(char m1[Rows][Cols]) {
    int temp;
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            printf("Enter number %d row %d:\n", i + 1, j + 1);
            while (scanf("%d", &temp) != 1 || isOutOfBounds(temp)) {
                printf("Invalid input. Please enter a number between -127 and 127:\n");
                while (getchar() != '\n');
            }
            m1[i][j] = temp;
        }
    }
}

void printer(char m1[Rows][Cols]) {
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            printf("%d ", m1[i][j]);
        }
        printf("\n");
    }
}

void address(char m1[Rows][Cols], int row, int col, int **ptr) {
    *ptr = &m1[row][col];
}

int main() {

    char m1[Rows][Cols];
    reader(m1);
    printer(m1);

    int row;
    int col;
    printf("Enter a number of row:\n");
    scanf("%d", &row);
    printf("Enter a number of col:\n");
    scanf("%d", &col);

    int *ptr;
    address(m1, row, col, &ptr);

    printf("The address of m1[%d][%d] is %p\n", row, col, ptr);


    int *p = &m1[3][2];
    printf("The address of m1[3][2] is %p\n", p);

    return 0;
}
