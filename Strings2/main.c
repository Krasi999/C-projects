#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

int function1(char *arr1, char *arr2){
    int count = 0;
    int arr2Len = strlen(arr2);

    char *p = strstr(arr1, arr2);

    while (p != NULL) {
        count++;

        p = strstr(p + arr2Len, arr2);
    }

    return count;
}


int main()
{
    char arr1[MAX_SIZE] = {};
    fgets(arr1, MAX_SIZE, stdin);

    char arr2[5] = {};
    fgets(arr2, 5, stdin);

    arr1[strcspn(arr1, "\n")] = '\0';
    arr2[strcspn(arr2, "\n")] = '\0';

    int times = function1(arr1, arr2);
    printf("The smaller string '%s' occurs %d times in the larger string.\n", arr2, times);

    return 0;
}
