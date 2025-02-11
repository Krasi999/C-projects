#include <stdio.h>
#include <stdlib.h>

void task1(int row, int col, int matrix[row][col]){
    int sum = 0;
    for(int i = 0;i < row; i++){
        for(int j = 0; j < col; j++){
            if(i == 0 || j == 0 || i == row - 1 || j == col - 1){
                sum += matrix[i][j];
            }
        }
    }
    printf("Sum of border elements: %d\n", sum);
}

void task2(int row, int col, int matrix[row][col]){
    int sum = 0;
    int sum1, sum2, sum3 = 0;
    for(int i = 0;i < row; i++){
        for(int j = 0; j < col; j++){
            if(i == j){
                sum += matrix[i][j];
            }
            if(i==0){
                sum1 += matrix[i][j];
            }
             if(i==1){
                sum2 += matrix[i][j];
            }
             if(i==2){
                sum3 += matrix[i][j];
            }
        }
    }
    printf("The sum of the main diagonal is %d!\n", sum);
    printf("The sum of the first line is %d!\n", sum1);
    printf("The sum of the second line is %d!\n", sum2);
    printf("The sum of the third line is %d!\n", sum3);
}

void task3(int row, int col, int matrix[row][col]){
    int sum = 0;
    int count = row - 1;
    for(int i =0; i < row;i++){
        for(int j = 0; j < col; j++){
            if(j == count){
                sum += matrix[i][j];
                count--;
            }
        }
    }
    printf("Sum of border elements: %d\n", sum);
}

void task4(int row, int col, int matrix[row][col]){
    int count;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(j > 0 && matrix[i][j] > matrix[i][j]){
                printf("%d %d , %d %d \n", i,j,j,i);
            }
        }
        count++;
    }
}

int main()
{
    int row,col;
    printf("Enter the size of the matrix!\n");
    scanf("%d", &row);
    scanf("%d", &col);

    int matrix[row][col];

    printf("Enter the elemets of the matrix!\n");

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    task1(row, col, matrix);
    task2(row, col, matrix);
    task3(row, col, matrix);
    task4(row, col, matrix);

    return 0;
}
