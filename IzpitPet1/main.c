#include <stdio.h>
#include <stdlib.h>

//AZ OBICHAM KRASI

typedef struct{
    char Name[31];
    char Number[8];
    float Price;
}Pet;

Pet FileFunction(){
    Pet pet;
    printf("Enter the name of the owner: ");
    fgets(pet.Name, sizeof(pet.Name), stdin);
    pet.Name[strlen(pet.Name) - 1] = '\0';
    printf("Enter the number: ");
    scanf("%8s", &pet.Number);
    printf("Enter the Price: ");
    scanf("%f", &pet.Price);

    FILE *fp = fopen("animalsText.txt", "w");
    if(fp == NULL){
        printf("File is not found!");
        exit(1);
    }

    fprintf(fp, "%s, %.2f\n", pet.Name, pet.Price);

    fclose(fp);

    return pet;
}

void PriceFunction(Pet *pet, int size, float price1){
    for(int i = 0; i < size; i++){
        if(pet[i].Price == price1){
            printf("%s - %s\n", pet[i].Name, pet[i].Number);
        }
        else{
            printf("There arent any coincidences!\n");
            return 0;
        }
    }
}

void BinFunction(float price1){

    FILE *fp = fopen("animalsBin.bin", "rb");
    if(fp == NULL){
        printf("File is not found!");
        exit(1);
    }

    Pet pet;

    while(fread(&pet, sizeof(Pet), 1, fp) == 1){
        if(pet.Price == price1){
            printf("Bin Name: %s\n", pet.Name);
            printf("Bin Number: %s\n", pet.Number);
            printf("Bin Price: %f\n", pet.Price);
            printf("---------------\n");
        }
    }

    fclose(fp);
}

int main(){

    Pet *pet = (Pet*)malloc(100 * sizeof(Pet));
    if(pet == NULL){
        printf("The memory is not allocated successfully!\n");
        exit(0);
    }
    else{
        printf("Everything is alright!\n");
    }

    int numPets = 0;

    pet[numPets++] = FileFunction();

    FILE *fp = fopen("animalsText.txt", "r");
    if(fp == NULL){
        printf("File is not found!");
        exit(1);
    }

    char line[100];
    printf("The data in the file is:\n");
    while(fgets(line, sizeof(line), fp) != NULL){
        printf("%s", line);
    }

    float PriceCompare1;
    printf("Enter price to compare: ");
    scanf("%f", &PriceCompare1);

    PriceFunction(pet, numPets, PriceCompare1);

    float PriceCompare2;
    printf("Enter a price to compare: ");
    scanf("%f", &PriceCompare2);

    BinFunction(PriceCompare2);

    fclose(fp);

    free(pet);

    return 0;
}
