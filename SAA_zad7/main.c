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

int MainExerciseFunction1(int n, int arrayA[n][n], int arrayB[n*n]){
    int index = 0;
    int sum = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j <n; j++){
            sum = i + j;
            if(sum = 0 || sum % 2 == 0){
                arrayB[index++] = arrayA[i][j];
            }
        }
    }
    return index;
}

int MainExerciseFunction2(int n, int arrayA[n][n], int arrayC[n*n]){
    int index = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i > j){
                arrayC[index++] = arrayA[i][j];
            }
        }
    }
    return index;
}

void printNewArray(int elem, int array[elem]){
    printf("The new array is:\n");
    for(int i = 0; i < elem; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

void InsertionSort(int elem, int array[elem]){
    for(int i = 1; i < elem; i++){
        int key = array[i];
        int j = i;
        while((j > 0) && array[j - 1] > key){
            array[j] = array[j - 1];
            j--;
        }
        array[j] = key;
    }
}

int main()
{
    int n;
    printf("Enter the number of cols and rows of the array:\n");
    scanf("%d", &n);

    int arrayA[n][n];
    enterElements(n, arrayA);
    printElements(n, arrayA);

    int arrayB[n * n];
    int elem1 = MainExerciseFunction1(n, arrayA, arrayB);
    printNewArray(elem1, arrayB);

    InsertionSort(elem1, arrayB);
    printf("The array after sorting is:\n");
    printNewArray(elem1, arrayB);

    int arrayC[n*n];
    int elem2 = MainExerciseFunction2(n, arrayA, arrayC);
    printNewArray(elem2, arrayC);

    InsertionSort(elem2, arrayC);
    printf("The array after sorting is:\n");
    printNewArray(elem2, arrayC);

    return 0;
}
