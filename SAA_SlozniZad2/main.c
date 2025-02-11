#include <stdio.h>
#include <stdlib.h>

void enterElements(int n, int arrayA[n][n]) {
    printf("Enter the elements of the array, numbers between 1 and 100:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arrayA[i][j]);
            while (arrayA[i][j] < 1 || arrayA[i][j] > 100) {
                printf("You entered a wrong number! Please try again!\n");
                scanf("%d", &arrayA[i][j]);
            }
        }
    }
}

void printArray(int n, int arrayA[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", arrayA[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int FoundMainDiagonal(int n, int arrayA[n][n], int arrayB[n]) {
    int index = 0;
    for (int i = 0; i < n; i++) {
        arrayB[index++] = arrayA[i][i];
    }
    return index;
}

void CountingSortDescending(int elem, int arrayB[elem]) {
    int max = 100;
    int count[max + 1];
    int output[elem];

    for (int i = 0; i <= max; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < elem; i++) {
        count[arrayB[i]]++;
    }

     for(int i = 1; i <=max;i++){
        count[i] += count[i - 1];
    }

    for(int i = elem - 1; i >= 0; i--){
        output[count[arrayB[i]]-1] = arrayB[i];
        count[arrayB[i]]--;
    }

    for(int i = 0; i < elem; i++){
        arrayB[i] = output[i];
    }
}

int main() {
    int n = 6;
    int arrayA[n][n];

    enterElements(n, arrayA);
    printArray(n, arrayA);

    int arrayB[n];
    int elem = FoundMainDiagonal(n, arrayA, arrayB);

    CountingSortDescending(elem, arrayB);

    printf("The fourth biggest element in the main diagonal is: %d\n", arrayB[3]);

    return 0;
}
