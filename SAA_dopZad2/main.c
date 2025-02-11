#include <stdio.h>
#include <stdlib.h>

void enterArray(int n, int array[n][n]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &array[i][j]);
            while(array[i][j] < -999 || array[i][j] > 999){
                printf("You enter a wrong number! Please try again!\n");
                scanf("%d", &array[i][j]);
            }
        }
    }
}

void printArray(int n, int array[n][n]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d  ", array[i][j]);
        }
        printf("\n");
    }
}

void MainExerciseFunction(int n, int array[n][n]){
    int A,B,R;
    printf("Enter the lower border of the numbers:\n");
    scanf("%d", &A);
    printf("Enter the upper border of the numbers:\n");
    scanf("%d", &B);
    printf("Enter the number do divide the other number with it:\n");
    scanf("%d", &R);

    int sum = 0;
    int count = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i < j){
                if(array[i][j] % R == 0 && array[i][j] > A && array[i][j] < B){
                    sum += array[i][j];
                    count++;
                }
            }
        }
    }

    float avg = (float)sum / count;
    printf("%.2f", avg);
}

int main()
{
    printf("Found the average of the numbers which are upper the main diagonal!\n");
    printf("Krasuska!\n");

    int n;
    printf("Enter the number of rows and cols of the array:\n");
    scanf("%d", &n);

    int array[n][n];
    enterArray(n, array);
    printArray(n, array);

    MainExerciseFunction(n, array);

    return 0;
}
