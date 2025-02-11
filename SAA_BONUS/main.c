#include <stdio.h>
#include <stdlib.h>

void enterArray(int n, int array[n][n]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &array[i][j]);
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

int MinElementFromEachRow(int n, int array[n][n], int row) {
    int min = array[row][0];
    for (int j = 1; j < n; j++) {
        if (array[row][j] < min) {
            min = array[row][j];
        }
    }
    return min;
}

int SumOfTheElmentsFromTheMainDiagonal(int n, int array[n][n]){
    int sum = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j){
                sum += array[i][j];
            }
        }
    }
    return sum ;
}

int NumberOfTheElmentsFromTheSecondDiagonal(int n, int array[n][n]){
    int count = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i + j == n - 1){
                if(array[i][j] < 0){
                    count++;
                }
            }
        }
    }
    return count;
}

int NewArrayFunction(int n,int array[n][n], int arrayB[n*n]){
    int index = 0;
    for(int i = 0; i < n; i++){
        arrayB[index++] = MinElementFromEachRow(n, array, i);
    }
    arrayB[index++] = SumOfTheElmentsFromTheMainDiagonal(n, array);
    arrayB[index++] = NumberOfTheElmentsFromTheSecondDiagonal(n, array);

    return index;
}

void BubbleSort(int elem, int array[elem]){
    int temp = 0;
    for(int i = 0; i < elem-1; i++){
        for(int j = i+1; j < elem;j++){
            if(array[i] > array[j]){
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

void PrintSortedArray(int elem, int array[elem]){
    printf("The sorted new array is:\n");
    for(int i = 0; i < elem; i++){
        printf("%d ", array[i]);
    }
}

int main()
{
    int n;
    printf("Enter the number of rows and cols:\n");
    scanf("%d", &n);

    int arrayA[n][n];
    enterArray(n, arrayA);
    printArray(n, arrayA);

    int arrayB[n*n];
    int elem = NewArrayFunction(n,arrayA, arrayB);

    BubbleSort(elem, arrayB);
    PrintSortedArray(elem, arrayB);

    return 0;
}
