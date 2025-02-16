#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char code[3];
    char name[21];
    int weight;
    float price;
}IceCream;

void CreateElements(IceCream *icecreams, int size){
    for(int i = 0; i < size; i++){
        printf("Enter the data for the IceCream %d!\n", i + 1);
        printf("Enter code: ");
        scanf("%3s", icecreams[i].code);
        printf("Enter name: ");
        scanf("%21s", icecreams[i].name);
        printf("Enter weight: ");
        scanf("%d", &icecreams[i].weight);
        printf("Enter price: ");
        scanf("%f", &icecreams[i].price);
        getchar();
    }
}

float CompareBySymbol(IceCream *icecream, int size, char symbol1){
    int flag = 0;
    float sum = 0.0;

    for(int i = 0; i< size; i++){
        if(toupper(icecream[i].name[0]) == toupper(symbol1)){
            sum += icecream[i].price;
            flag = 1;
        }
    }

    if(flag){
        return sum;
    }else{
        return 0;
    }
}

int CompareByPriceAndWeight(IceCream *icecream, int size, float price1, int weight1){
    FILE *fp = fopen("info.txt", "a");
    if(fp == NULL){
        printf("File is not found!\n");
        exit(2);
    }

    int count = 0;
    int flag = 0;

    for(int i = 0; i < size; i++){
        if(icecream[i].price < price1 && icecream[i].weight > weight1){
            fprintf(fp, "%s;%s;%d;%.2f leva", icecream[i].code, icecream[i].name, icecream[i].weight, icecream[i].price);
            count++;
            flag = 1;
        }
    }
    if(flag){
        return count;
    }else{
        return 0;
    }

    fclose(fp);
}

void ReadFromBinary(char code1[]){
    FILE *fp = fopen("icecream.bin", "rb");
    if(fp == NULL){
        printf("File is not found!\n");
        exit(3);
    }

    int flag = 0;

    IceCream icecreams;
    while(fread(&icecreams, sizeof(IceCream), 1, fp) == 1){
        if(strcmp(icecreams.code,code1) == 0){
            printf("===============\n");
            printf("IceCream - %s\n", icecreams.name);
            printf("Price - %.2f BGN", icecreams.price);
            printf("===============\n");
            flag = 1;
        }
    }
    if(!flag){
        printf("Ther arent any coincidences!\n");
    }
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    while(n < 0 || n > 14){
        printf("You enter a wrong number!\n");
        printf("Enter the number of elements again: ");
        scanf("%d", &n);
    }

    IceCream *icecreams = (IceCream*)malloc(sizeof(IceCream)* n);
    if(icecreams == NULL){
        printf("The memory is not allocated successfully!\n");
        exit(1);
    }

    CreateElements(icecreams, n);

    char Symbol;
    printf("Enter a symbol to compare: ");
    scanf("%c", &Symbol);
    getchar();

    float num1 = CompareBySymbol(icecreams, n, Symbol);
    if(num1 != 0){
        printf("The sum is %.2f!\n", num1);
    }else{
        printf("There arent any coincidences!\n");
    }

    float ComparePrice;
    printf("Enter a price to compare: ");
    scanf("%f", &ComparePrice);
    int CompareWeight;
    printf("Enter a weight to compare: ");
    scanf("%d", &CompareWeight);
    getchar();

    int num2 = CompareByPriceAndWeight(icecreams, n, ComparePrice, CompareWeight);
    if(num2 != 0){
        printf("The count is %d!\n", num2);
    }else{
        printf("There arent any coincidences!\n");
    }

    char CompareCode[3];
    printf("Enter code to compare: ");
    scanf("%3s", CompareCode);

    ReadFromBinary(CompareCode);

    free(icecreams);

    return 0;
}
