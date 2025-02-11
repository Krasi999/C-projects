#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char names[56];
    char number[7];
    float price;
    int code;
}Fitness;

Fitness* AddNewElement(Fitness *fitnesses, int *size){
    FILE *fp = fopen("membersText.txt", "a");
    if(fp == NULL){
        printf("File not found!\n");
        exit(2);
    }

    (*size)++;
    Fitness *fitnesses1 = (Fitness*)realloc(fitnesses, sizeof(Fitness) * (*size));
    if(fitnesses1 == NULL){
        printf("The memory is not allocated successfully!\n");
        exit(3);
    }

    Fitness newFitnesses;
    printf("Enter the data for the new element!\n");
    printf("Names: ");
    fgets(newFitnesses.names, sizeof(newFitnesses.names), stdin);
    printf("Number: ");
    scanf("%7s", newFitnesses.number);
    printf("Price: ");
    scanf("%f", &newFitnesses.price);
    printf("Code: ");
    scanf("%d", &newFitnesses.code);
    getchar();
    while(newFitnesses.code < 100 || newFitnesses.code > 999){
        printf("You enter a wrong code!\n");
        printf("Enter a code again: ");
        scanf("%d", &newFitnesses.code);
        getchar();
    }

    fitnesses1[*size - 1] = newFitnesses;

    int strLen;
    strLen = strlen(newFitnesses.names) + 1;
    fprintf(fp, "%d;%s;%s;%.2f;%d", strLen, newFitnesses.names,
           newFitnesses.number, newFitnesses.price, newFitnesses.code);

    fclose(fp);

    return fitnesses1;
}

void PrintUnderAverage(Fitness *fitnesses, int size){
    float sum, avg;
    int count = 0;
    for(int i = 0; i < size; i++){
        sum += fitnesses[i].price;
        count++;
    }
    avg = sum / count;

    for(int i = 0; i < size; i++){
        if(fitnesses[i].price < avg){
            printf("%s - %s - %.2f\n", fitnesses[i].names, fitnesses[i].number, fitnesses[i].price);
        }
    }
}

void CompareByNumber(char number1[]){
    FILE *fp = fopen("members.bin", "rb");
    if(fp == NULL){
        printf("File is not found!\n");
        exit(4);
    }

    Fitness fitnesses;
    while(fread(&fitnesses, sizeof(Fitness), 1, fp) == 1){
        if(strcmp(fitnesses.number, number1)==0){
            printf("Bin Name: %s\n", fitnesses.names);
            printf("Bin ID: %s\n", fitnesses.number);
            printf("Bin M_Price: %.2f\n", fitnesses.price);
            printf("Bin Looker: %d\n", fitnesses.code);
        }
    }
    fclose(fp);
}

int main()
{
    int size = 1;
    Fitness *fitnesses = (Fitness*)malloc(sizeof(Fitness) * size);
    if(fitnesses == NULL){
        printf("The memory is not allocated successfully!\n");
        exit(1);
    }

    fitnesses = AddNewElement(fitnesses, &size);

    PrintUnderAverage(fitnesses, size);

    char CompareNumber[7];
    printf("Enter number to compare: ");
    scanf("%7s", CompareNumber);

    CompareByNumber(CompareNumber);

    free(fitnesses);

    return 0;
}
