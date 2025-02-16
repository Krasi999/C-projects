#include <stdio.h>
#include <stdlib.h>

void enterElements(int n, int array[n][n]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &array[i][j]);
            while(array[i][j] < -1000 || array[i][j] > 1000){
                printf("You enter a wrong number! Please try again!\n");
                scanf("%d", &array[i][j]);
            }
        }
    }
}

void printElements(int n, int array[n][n]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int MainExerciseFunction1(int n, int arrayA[n][n], int rows){
    arrayA[rows][n];
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arrayA[rows][i];
    }
    return sum;
}

void ArrayBFunction(int n, int arrayA[n][n], int arrayB[n]){
    for(int i = 0; i < n; i++){
        arrayB[i] = MainExerciseFunction1(n, arrayA, i);
        printf("The sum of row %d is %d\n", i+1, arrayB[i]);
    }
}

int MainExerciseFunction2(int n, int arrayA[n][n], int cols){
    arrayA[n][cols];
    int sum = 0;
    for(int i = 0; i <n; i++){
        sum += arrayA[i][cols];
    }
    return sum;
}

void ArrayCFunction(int n, int arrayA[n][n], int arrayC[n]){
    for(int i = 0; i < n; i++){
        arrayC[i] = MainExerciseFunction2(n, arrayA, i);
        printf("The sum of col %d is %d\n", i+1, arrayC[i]);
    }
}

void printNewArray(int n, int array[n]){
    for(int i = 0; i < n; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

void BubbleSort(int n, int array[n]){
    int temp = 0;
    for(int i = 0; i < n - 1; i++){
        for(int j = 1; j < n; j++){
            if(array[i] > array[j]){
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of rows and cols of the array!\n");
    scanf("%d", &n);

    int arrayA[n][n];
    enterElements(n, arrayA);
    printElements(n, arrayA);

    int arrayB[n];
    ArrayBFunction(n, arrayA, arrayB);
    printNewArray(n, arrayB);

    BubbleSort(n, arrayB);
    printf("The array after sorting is:\n");
    printNewArray(n, arrayB);

    int arrayC[n];
    ArrayCFunction(n, arrayA, arrayC);
    printNewArray(n, arrayC);

    BubbleSort(n, arrayC);
    printf("The array after sorting is:\n");
    printNewArray(n, arrayC);


    return 0;
}
