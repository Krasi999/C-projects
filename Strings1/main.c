#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 50

int function1(char arr[]) {
    int counter = 0;
    for (int i = 0; arr[i] != 0; i++) {
        counter++;
    }
    printf("The size is: %d\n", counter);
    return counter;
}

int main(void) {
    char arr[MAX_SIZE];
    fgets(arr, MAX_SIZE, stdin);
    int size = function1(arr);
    printf("Returned size from function: %d\n", size);
    return 0;
}
