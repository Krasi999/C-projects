#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Car{
    char** brand;
}Car;

int main()
{
    Car *myCarPtr;
    int inputSize;
    char temp[20];
    printf("How many car brands are you going to input?\n");
    scanf("%d", &inputSize);
    myCarPtr = malloc(sizeof(Car));
    getchar();
    myCarPtr->brand = (char*)malloc(inputSize * sizeof(char*));
    int strSize;
    for(int i = 0; i < inputSize; i++){
        fgets(temp, 20, stdin);             //Ivan\n
        temp[strlen(temp)-1] = '\0';        //Ivan\0
        strSize = strlen(temp) + 1;
        myCarPtr->brand[i] = malloc(strSize);
        strcpy(myCarPtr->brand[i], temp);
    }

    printf("\n-----------------\n");

    for(int i =0; i < inputSize; i++){
            printf("%s\n", myCarPtr->brand[i]);
    }

    return 0;
}
