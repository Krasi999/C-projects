#include <stdio.h>
#include <stdlib.h>

void enterElements(int n, int array[n][n]){
    printf("Enter the elements of the array:\n");
    for(int i =0; i <n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &array[i][j]);
        }
    }
}

void printArray(int n, int array[n][n]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j<n;j++){
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int MainExerciseFunction(int n, int array[n][n], int rows){
    int sum = 0;
    for(int i = 0;i < n; i++){
        sum += array[rows][i];
    }
    return sum;

}

int newArrayFunction(int n, int array[n][n], int newArray[n*n]){
    int index = 0;
    for(int i = 0; i < n; i++){
        newArray[index++] = MainExerciseFunction(n, array, i);
    }
    return index;
}

void printNewArray(int elem, int newArray[elem]){
    for(int i = 0; i < elem; i++){
      printf("%d ", newArray[i]);
    }
    printf("\n");
}

void insertionSort(int elem, int newArray[elem]){
    for(int  i = 1; i < elem; i++){
        int key = newArray[i];
        int j = i;
        while((j>0)&&(newArray[j-1] > key)){
            newArray[j] = newArray[j-1];
            j--;
        }
        newArray[j] = key;
    }
}

int main()
{
    int n;
    printf("Enter the number of rows and cols of the array:\n");
    scanf("%d", &n);

    int array[n][n];
    enterElements(n, array);
    printArray(n, array);

    int newArray[n*n];
    int elem = newArrayFunction(n, array, newArray);
    printNewArray(elem, newArray);

    insertionSort(elem, newArray);
    printf("The array after sorting is:\n");
    printNewArray(elem, newArray);

    return 0;
}
