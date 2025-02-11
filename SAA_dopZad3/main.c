#include <stdio.h>
#include <stdlib.h>

void enterArray(int rows, int cols, int array[rows][cols]){
    printf("Enter the elements of the array:\n");
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            scanf("%d", &array[i][j]);
            while(array[i][j] < -1000 || array[i][j] > 1000){
                printf("You enter a wrong number!Please try again!\n");
                scanf("%d", &array[i][j]);
            }
        }
    }
}

void printArray(int rows, int cols, int array[rows][cols]){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

void MainExerciseFunction(int rows, int cols, int array[rows][cols]){
    int M;
    printf("Enter the lower border for the negative numbers!\n");
    scanf("%d", &M);
    while(M > 0){
        printf("The lower border must be a negative number!Please try again!\n");
        scanf("%d", &M);
    }

    int N;
    printf("Enter the upper border for the negative numbers!\n");
    scanf("%d", &N);

    int Q;
    printf("Enter the number which switch the negative numbers!\n");
    scanf("%d", &Q);

    int count = 0;

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(array[i][j] < 0 && array[i][j] > M && array[i][j] < N){
                array[i][j] = Q;
                count++;
            }
        }
    }
    printf("The number of the elements witch are switched are %d!\n", count);
}

int main()
{
    printf("Switch negative numbers with Q!\n");
    printf("Krasuska!\n");

    int rows = 2;
    int cols = 4;

    int array[rows][cols];
    enterArray(rows, cols, array);
    printArray(rows, cols, array);

    MainExerciseFunction(rows, cols, array);
    printArray(rows, cols, array);

    return 0;
}
