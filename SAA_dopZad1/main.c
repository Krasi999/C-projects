#include <stdio.h>
#include <stdlib.h>

void enterArray(int n, int array[n][n]){
    printf("Enter elements of the array:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &array[i][j]);
            while(array[i][j] < - 1000 || array[i][j] > 1000){
                printf("You enter a wrong number!Please try again!\n");
                scanf("%d", &array[i][j]);
            }
        }
    }
}

void printArray(int n, int array[n][n]){
    printf("The array is:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

int newArrayFuction(int n, int array[n][n], int newArray[n*n]){
    int index = 0;
    for(int i = 0; i < n; i++){
        for(int j =0; j < n; j++){
            if(array[i][j] > 0){
                newArray[index++] = array[i][j];
            }
        }
    }
    return index;
}

void printNewArray(int elem, int newArray[elem]){
    printf("The new array is:\n");
    for(int i = 0; i < elem; i++){
        printf("%d ", newArray[i]);
    }
}

void bubbleSort(int elem, int newArray[elem]){
    int temp;
    for(int i =0; i < elem - 1; i++){
        for(int j = i+1; j< elem; j++){
            if(newArray[i] > newArray[j]){
                temp = newArray[i];
                newArray[i] = newArray[j];
                newArray[j] = temp;
            }
        }
    }
}

int main()
{
    printf("Maka a new array with numbers bigger then 0!\n");
    printf("Krasimir Gushmakov!\n");

    int n = 3;
    int array[n][n];
    enterArray(n, array);
    printf("\n");
    printArray(n, array);
    printf("\n");

    int newArray[n * n];
    int elem = newArrayFuction(n, array, newArray);
    printNewArray(elem, newArray);
    printf("\n");

    bubbleSort(elem, newArray);
    printf("The array after sorting is!\n");
    printNewArray(elem, newArray);

    return 0;
}
