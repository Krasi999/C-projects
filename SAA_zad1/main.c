#include <stdio.h>
#include <stdlib.h>

void enter_array(int N, int array[N][N]){
    printf("Enter the elements of the matrix between -1000 and 1000!\n");
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%d", &array[i][j]);
            while(array[i][j] < -1000 || array[i][j] > 1000){
                printf("You enter a wrong number! Please try again!\n");
                scanf("%d", &array[i][j]);
            }
        }
    }
}

void print_array(int N, int array[N][N]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N;j++){
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

void newArrayFunction(int N, int array1[N][N], int array2[N][N], int newArray[N]){
   for (int i = 0; i < N; i++) {
        newArray[i] = array1[i][i] + array2[i][i];
    }
}

void printNewArray(int N, int newArray[N]) {
    printf("The newArray is: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", newArray[i]);
    }
    printf("\n");
}

void bubble_sort(int N, int newArray[N]){
    int temp;
    for(int i = 0; i < N - 1; i++){
        for(int j = i+1; j < N; j++){
            if(newArray[i] > newArray[j]){
                temp = newArray[i];
                newArray[i]= newArray[j];
                newArray[j] = temp;
            }
        }
    }
}

int main()
{
    printf("This program combine and sort two arrays!\n");
    printf("Krasimir Gushmakov!\n");

    int N;
    printf("Enter the number of rows and cols of the matrix!\n");
    scanf("%d", &N);

    int array1[N][N];
    enter_array(N, array1);
    printf("\n");
    print_array(N, array1);
    printf("\n");

    int array2[N][N];
    enter_array(N, array2);
    printf("\n");
    print_array(N, array2);
    printf("\n");

    int newArray[N];
    newArrayFunction(N, array1, array2, newArray);
    printNewArray(N, newArray);

    bubble_sort(N, newArray);
    printf("The array after sorting is!\n");
    printNewArray(N, newArray);

    return 0;
}
