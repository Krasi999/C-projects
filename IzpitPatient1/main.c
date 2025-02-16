#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char name[31];
    char chipNumber[8];
    float price;
}Patient;

Patient CreateOneElement(){
    FILE *fp = fopen("animalsText.txt", "a");
    if(fp == NULL){
        printf("File not found!\n");
        exit(0);
    }

    Patient newPatients;
    printf("Enter the data for the new patient!\n");
    printf("Name: ");
    scanf("%31s", newPatients.name);
    printf("ChipNumber: ");
    scanf("%8s", newPatients.chipNumber);
    printf("Price: ");
    scanf("%f", &newPatients.price);
    getchar();

    fprintf(fp, "%s,%.2f\n", newPatients.name, newPatients.price);

    fclose(fp);

    return newPatients;
}

void CompareByPrice(Patient patients[], int size, float price1){
    int flag = 0;
    for(int i = 0; i < size; i++){
        if(patients[i].price == price1){
            printf("The name of the owner for this price is: %s\n", patients[i].name);
            printf("The chipNumber for this price is: %s\n", patients[i].chipNumber);
            flag = 1;
        }
    }
    if(!flag){
        printf("There arent any coincidences!\n");
    }
}

void ReadFromBinary(price1){
    FILE *fp = fopen("animalsBin.bin", "rb");
    if(fp == NULL){
        printf("File not found!\n");
        exit(1);
    }

    int flag = 0;

    Patient patients;
    while(fread(&patients, sizeof(Patient), 1, fp) == 1){
        if(patients.price >= price1){
            printf("Bin OwnerName: %s\n", patients.name);
            printf("Bin Chip: %s\n", patients.chipNumber);
            printf("Bin Price: %.2f\n", patients.price);
            printf("--------------\n");
            flag =1;
        }
    }
    if(!flag){
        printf("There arent any coincidences!\n");
    }
}

int main()
{

    Patient patients[100];

    int size = 0;
    patients[size++] = CreateOneElement();

    float ComparePrice1;
    printf("Enter price to compare: ");
    scanf("%f", &ComparePrice1);

    CompareByPrice(patients, size, ComparePrice1);

    float ComparePrice2;
    printf("Enter a price to compare: ");
    scanf("%f", &ComparePrice2);

    ReadFromBinary(ComparePrice2);

    return 0;
}
