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
        printf("Enter the data for the element %d!\n", i + 1);
        printf("Code: ");
        scanf("%3s", icecreams[i].code);
        printf("Name: ");
        scanf("%21s", icecreams[i].name);
        printf("Weight: ");
        scanf("%d", &icecreams[i].weight);
        printf("Price: ");
        scanf("%f", &icecreams[i].price);
        getchar();
    }
}

float CompareBySymbol(IceCream *icecreams, int size, char symbol1){
    float sum = 0.0;
    int flag = 0;
    for(int i = 0; i < size; i++){
        if(toupper(icecreams[i].name[0]) == toupper(symbol1)){
            sum += icecreams[i].price;
            flag = 1;
        }
    }
    if(flag){
        return sum;
    }else{
        return 0;
    }
}

int CompareByWeightAndPrice(IceCream *icecreams, int size, int weight1, float price1){
    FILE *fp = fopen("info.txt", "a");
    if(fp == NULL){
        printf("File not found!\n");
        exit(2);
    }
    int flag = 0;
    int count = 0;
    for(int i = 0; i < size; i++){
        if(icecreams[i].weight > weight1 && icecreams[i].price < price1){
            fprintf(fp, "%s;%s;%d;%.2f leva", icecreams[i].code, icecreams[i].name, icecreams[i].weight, icecreams[i].price);
            flag = 1;
            count++;
        }
    }
    if(flag){
        return count;
    }else{
        return 0;
    }
    fclose(fp);
}

void CompareByCode(char code1[]){
    FILE *fp = fopen("icecream.bin", "rb");
    if(fp == NULL){
        printf("File is not found!\n");
        exit(3);
    }
    int flag = 0;
    IceCream icecreams;
    while(fread(&icecreams, sizeof(IceCream), 1, fp) == 1){
        if(strcmp(icecreams.code, code1) == 0){
            printf("-----------------\n");
            printf("IceCream - %s\n", icecreams.name);
            printf("Price - %.2f\n", icecreams.price);
            printf("-----------------\n");
            flag = 1;
        }
    }
    if(!flag){
        printf("There arent any coincidences!\n");
    }
    fclose(fp);
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    while(n < 0 || n > 14){
        printf("You enter a wrong number!\n");
        printf("Enter the number of elements again!\n");
        scanf("%d", &n);
    }

    IceCream *icecreams = (IceCream*)malloc(sizeof(IceCream) * n);
    if(icecreams == NULL){
        printf("The memory is not allocated successfully!\n");
        exit(1);
    }

    CreateElements(icecreams, n);

    char CompareSymbol;
    printf("Enter a symbol to compare: ");
    scanf("%c", &CompareSymbol);
    getchar();

    float num1 = CompareBySymbol(icecreams, n, CompareSymbol);
    if(num1 != 0){
        printf("The sum is %.2f!\n", num1);
    }else{
        printf("There arent any coincidences!\n");
    }

    int CompareWeight;
    printf("Enter a weight to compare: ");
    scanf("%d", &CompareWeight);
    float ComparePrice;
    printf("Enter a price to compare: ");
    scanf("%f", &ComparePrice);
    getchar();

    int num2 = CompareByWeightAndPrice(icecreams, n, CompareWeight, ComparePrice);
    if(num2 != 0){
        printf("The count is %d!\n", num2);
    }else{
        printf("There arent any coincidences!\n");
    }

    char CompareCode[3];
    printf("Enter a code to compare: ");
    scanf("%3s", CompareCode);
    getchar();

    CompareByCode(CompareCode);

    free(icecreams);

    return 0;
}
