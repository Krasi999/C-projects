#include <stdio.h>
#include <stdlib.h>

void enterElements(int n, int arrayA[n][n]){
    printf("Enter the elements of the array, numbers between -20 and 20:\n");
    for(int i =0; i <n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &arrayA[i][j]);
            while(arrayA[i][j] < -20 || arrayA[i][j] > 20){
                printf("You enter a wrong number!Please try again!\n");
                scanf("%d", &arrayA[i][j]);
            }
        }
    }
}

void printArray(int n, int arrayA[n][n]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j<n;j++){
            printf("%d ", arrayA[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int MainExerciseFunction(int n, int arrayA[n][n], int rows){
    int sum = 0;
    for(int i = 0; i < n; i++){
        if(arrayA[rows][i] > 0){
            sum += arrayA[rows][i];
        }
    }
    return sum;
}
int NewArrayFunction(int n, int arrayA[n][n], int arrayB[n]){
    int index = 0;
    for(int i = 0; i < n; i++){
        arrayB[index++] = MainExerciseFunction(n, arrayA, i);
    }
    return index;
}

void PrintNewArray(int elem, int arrayB[elem]){
    for(int i = 0; i < elem; i++){
        printf("%d ", arrayB[i]);
    }
    printf("\n");
}

void InsertionSort(int elem, int arrayB[elem]){
    for(int i = 1; i < elem; i++){
        int key = arrayB[i];
        int j = i;
        while((j>0) && arrayB[j-1] > key){
            arrayB[j] = arrayB[j-1];
            j--;
        }
        arrayB[j] = key;
    }
}

int main()
{
    int n;
    printf("Enter the number of rows and cols which are between 1 and 15!\n");
    scanf("%d", &n);
    while(n < 1 || n > 15){
        printf("You enter a wrong number!Please try again!\n");
        scanf("%d", &n);
    }

    int arrayA[n][n];
    enterElements(n, arrayA);
    printArray(n, arrayA);

    int arrayB[n];
    int elem = NewArrayFunction(n, arrayA, arrayB);
    PrintNewArray(elem, arrayB);

    InsertionSort(elem, arrayB);
    PrintNewArray(elem, arrayB);

    return 0;
}
