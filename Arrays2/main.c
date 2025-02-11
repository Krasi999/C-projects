#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define Cols 2
#define Rows 4

bool isOutOfBounds(int num) {
    return num > 127 || num < -127;
}

void reader(char m[Cols][Rows]) {
    int temp;
    for (int i = 0; i < Cols; i++) {
        for (int j = 0; j < Rows; j++) {
            printf("Enter number %d row %d:\n", i + 1, j + 1);
            while (scanf("%d", &temp) != 1 || isOutOfBounds(temp)) {
                printf("Invalid input. Please enter a number between -127 and 127:\n");
                while (getchar() != '\n');
            }
            m[i][j] = temp;
        }
    }
}

void printer1(char m1[Cols][Rows]) {
    for (int i = 0; i < Cols; i++) {
        for (int j = 0; j < Rows; j++) {
            printf("%d ", m1[i][j]);
        }
        printf("\n");
    }
}

void printer2(char m2[Rows][Cols]) {
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            printf("%d ", m2[i][j]);
        }
        printf("\n");
    }
}

void transponate(char m1[Cols][Rows], char m2[Rows][Cols]) {
    char temp[Rows][Cols];
    for (int i = 0; i < Cols; i++) {
        for (int j = 0; j < Rows; j++) {
            temp[j][i] = m1[i][j];
        }
    }
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            m2[i][j] = temp[i][j];
        }
    }
}

int main() {
    char m1[Cols][Rows] = {0};
    char m2[Rows][Cols] = {0};

    printf("Matrix 1:\n");
    reader(m1);
    printf("\nMatrix 1:\n");
    printer1(m1);
    printf("\n----------------------------\n");
    printf("Matrix 2:\n");
    reader(m2);
    printf("\nMatrix 2:\n");
    printer2(m2);

    transponate(m1, m2);

    printf("\nTransposed Matrix 1:\n");
    printer2(m2);

    return 0;
}
