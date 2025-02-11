#include <stdio.h>
#include <stdlib.h>

void enterElements(int n, int array[n]){
    printf("Enter elements of the array:\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &array[i]);
        while(array[i] < 0){
            printf("You enter a wrong number! Please try again!\n");
            scanf("%d", &array[i]);
        }
    }
}

void printElements(int n, int array[n]){
    for(int i = 0; i < n; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

void MainExerciseFunction(int n, int arrayA[n], int arrayB[n], int arrayC[n]){
    for(int i = 0; i < n; i++){
        if(arrayA[i] > arrayB[i]){
            arrayC[i] = arrayA[i];
        }else{
            arrayC[i] = arrayB[i];
        }
    }
}

void printArrayC(int n, int arrayC[n]){
    printf("The new array is:\n");
    for(int i = 0; i < n; i++){
        printf("%d ", arrayC[i]);
    }
    printf("\n");
}

void SumOfTheElements(int n, int arrayC[n]){
    int sum = 0;
    int lastNum = 0;

    for(int i = 0; i < n; i++){
        sum += arrayC[i];
    }

    printf("The sum of the elements is %d!\n", sum);

    if(sum > 99){
        lastNum = sum % 10;
        printf("The last number is %d!\n", lastNum);
    }else{
        printf("This sum is not a tree digit number!\n");
    }
}

int main()
{
    int n;
    printf("Enter the number of elements in each array:\n");
    scanf("%d", &n);

    int arrayA[n];
    int arrayB[n];

    enterElements(n, arrayA);
    printElements(n, arrayA);

    enterElements(n, arrayB);
    printElements(n, arrayB);

    int arrayC[n];
    MainExerciseFunction(n, arrayA, arrayB, arrayC);
    printArrayC(n, arrayC);

    SumOfTheElements(n, arrayC);

    return 0;
}
