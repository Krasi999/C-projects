#include <stdio.h>
#include <stdlib.h>

void enterArray(int N, int array[N][N]){
    printf("Enter the elements!\n");
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N;j++){
            scanf("%d", &array[i][j]);
            while(array[i][j] < -100 || array[i][j] > 100){
                printf("You enter a wrong number! Please try again!\n");
                scanf("%d", &array[i][j]);
            }
        }
    }
}

void printArray(int N, int array[N][N]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j< N; j++){
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

int newArrayFunction(int N, int array[N][N], int newArray[N*N], int K, int L){
    int index = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(array[i][j] > K && array[i][j] < L){
                newArray[index++] = array[i][j];
            }
        }
    }
    return index;
}

void printNewArray(int elements, int newArray[elements]){
    printf("The new array is: ");
    for(int i = 0; i < elements; i++){
        printf("%d ", newArray[i]);
    }
    printf("\n");
}

void bubbleSort(int elements, int newArray[elements]){
    int temp;
    for(int i = 0; i < elements - 1; i++){
        for(int j = i + 1; j < elements; j++){
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
    printf("Found the number which are between K and L and make a new array with these numbers!\n");
    printf("Krasimir Gushmakov!\n");

    int N;
    printf("Enter the number of rows and cols of the array!\n");
    scanf("%d", &N);

    int array[N][N];
    enterArray(N, array);
    printArray(N, array);

    int K,L;
    printf("Enter the lower border for the elements: ");
    scanf("%d", &K);
    printf("Enter the uppper border for the elements: ");
    scanf("%d", &L);

    int newArray[N*N];
    int elements = newArrayFunction(N, array, newArray, K, L);
    printNewArray(elements, newArray);

    bubbleSort(elements, newArray);
    printf("The array after sorting!\n");
    printNewArray(elements, newArray);

    return 0;
}
