#include <stdio.h>
#include <stdlib.h>

void enterElements(int n, float arrayA[n][n]){
    printf("Enter the elements of the array:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0;j < n; j++){
            scanf("%f", &arrayA[i][j]);
            while(arrayA[i][j] < 0 || arrayA[i][j] > 99.9){
                printf("You enter a wrong number!Please try again!\n");
                scanf("%f", &arrayA[i][j]);
            }
        }
    }
}

void printElements(int n, float arrayA[n][n]){
    printf("The array is:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%.2f ", arrayA[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void Function1(int n, float arrayA[n][n]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){

            int flag = 0;

            if(i < j){
                arrayA[i][j] = arrayA[i][j] * arrayA[i][j];
                flag = 1;
            }

            float temp = 0;

            if(flag){
                temp = arrayA[i][j];
                arrayA[i][j] = arrayA[j][i];
                arrayA[j][i] = temp;
            }
        }
    }
}

int main()
{
    int n = 4;
    float arrayA[n][n];
    enterElements(n, arrayA);
    printElements(n, arrayA);

    Function1(n, arrayA);
    printElements(n, arrayA);

    return 0;
}
