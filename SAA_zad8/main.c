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

void MainExerciseFunction(int n, int arrayA[n][n], int arrayB[n][n]){
    int K, L;
    printf("Enter the lower border for the elements:\n");
    scanf("%d", &K);
    printf("Enter the upper border for the elements:\n");
    scanf("%d", &L);

    int sum = 0;
    int count = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            sum = arrayA[i][j] + arrayB[i][j];
            if(sum % 2 == 0 && sum >= K && sum <= L){
                arrayA[i][j] = 0;
                count++;
            }
        }
    }
    printf("The number of elements which are replaced with 0 is %d\n", count);
}

int main()
{
    int n;
    printf("Enter the number of cols and rows of the array:\n");
    scanf("%d", &n);

    int arrayA[n][n];
    enterElements(n, arrayA);
    printElements(n, arrayA);

    int arrayB[n][n];
    enterElements(n, arrayB);
    printElements(n, arrayB);

    MainExerciseFunction(n, arrayA, arrayB);
    printElements(n, arrayA);

    return 0;
}
