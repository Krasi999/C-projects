#include <stdio.h>
#include <stdlib.h>

void enterElments(int n , int arrayA[n][n]){
    printf("Enter the elements of the array:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &arrayA[i][j]);
            while(arrayA[i][j] < 0){
                printf("You enter a wrong number!Please try again!\n");
                scanf("%d", &arrayA[i][j]);
            }
        }
    }
}

void printElements(int n, int arrayA[n][n]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j <n; j++){
            printf("%d ", arrayA[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void Function1(int n, int arrayA[n][n]){
    int sum = 0;
    int diagonalElements[n];
    int diagonalElementsCount = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i + j == n - 1){
                sum+=arrayA[i][j];
                diagonalElements[diagonalElementsCount++] = arrayA[i][j];
            }
        }
    }
    printf("The sum of the elements in the second diagonal is %d\n", sum);

    if(sum > 100){

        int maxCount = 0;
        int mostFrequent = diagonalElements[0];

        for(int i = 0; i < n; i++){
            int currentCount = 0;
            for(int j = 0; j < n; j++){
                if(diagonalElements[i] == diagonalElements[j]){
                    currentCount++;
                }
            }
            if(currentCount > maxCount){
                maxCount = currentCount;
                mostFrequent = diagonalElements[i];
            }
        }
        printf("The element which is most frequent is %d and it is appeared %d times!\n", mostFrequent, maxCount);
    }
    else{
        printf("The sum is under 100!\n");
    }
}

int main()
{
    int n;
    printf("Enter the number of rows and cols of the array:\n");
    scanf("%d", &n);

    int arrayA[n][n];
    enterElments(n, arrayA);
    printElements(n, arrayA);

    Function1(n, arrayA);

    return 0;
}
