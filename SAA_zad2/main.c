#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void enterArray(int N, int array[N][N]){
    printf("Enter the elements of the array!\n");
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%d", &array[i][j]);
            while(array[i][j] < -10 || array[i][j] > 10){
                printf("You enter a wrong number!Please try again!\n");
                scanf("%d", &array[i][j]);
            }
        }
    }
}

void printArray(int N, int array[N][N]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

int newArrayFunction(int N, int array[N][N], int newArray[N*N]){
    int index = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j< N; j++){
            if(pow(array[i][j], 2) > 50){
                newArray[index++] = array[i][j];
            }
        }
    }
    return index;
}

void printNewArray(int element, int newArray[element]){
    printf("The elements of the newArray:\n");
    for(int i = 0; i < element; i++){
        printf("%d ", newArray[i]);
    }
    printf("\n");
}

void bubble_sort(int element, int newArray[element]){
    int temp;
    for(int i = 0; i < element - 1; i++){
        for(int j = i+1;j < element; j++){
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
    printf("Array which have squares greater then 50!\n");
    printf("Krasimir Gushmakov!\n");

    int N;
    printf("Enter the number of rows and cols of the array!\n");
    scanf("%d", &N);

    int array[N][N];
    enterArray(N, array);
    printf("\n");
    printArray(N, array);
    printf("\n");

    int newArray[N*N];
    int element = newArrayFunction(N, array, newArray);
    printNewArray(element, newArray);
    bubble_sort(element, newArray);
    printf("The array after sorting!\n");
    printNewArray(element, newArray);

    return 0;
}
