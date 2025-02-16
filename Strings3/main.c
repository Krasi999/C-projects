#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 50

void function1(char *arr){
    int count[256] = {0};
    int length = strlen(arr);

    if (arr[length - 1] == '\n') {
        length--;
        arr[length] = '\0';
    }

    for(int i = 0; i < length; i++){
        count[(unsigned char)arr[i]]++;
    }

    for(int i = 0; i < 256; i++){
        if (count[i] != 0){
            printf("The number of %c is %d.\n", (char)i, count[i]);
        }
    }
}

int main()
{
    char arr[MAX_SIZE] = {};
    fgets(arr, MAX_SIZE, stdin);

    function1(arr);

    return 0;
}



/*
void function1(char *arr){
    int count;
    for(int i = 0; i <= 255; i++){
        count = 0;
        for(int j = 0; j < MAX_SIZE; j++){
            if(arr[j] == i){
                count++;
            }
        }
        if (count != 0){
            printf("The number of %c is %d.\n", i, count);
        }
    }
}

int main()
{
    char arr[MAX_SIZE] = {};
    fgets(arr, MAX_SIZE, stdin);

    function1(arr);

    return 0;
}
*/
