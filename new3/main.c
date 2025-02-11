#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char name[31];
    char date[8];
    long long Code;
    float price;
    int quantity;
}Medicine;

void CompareByDate(Medicine *medicine, int size, char code1[]){
    int flag = 0;
    int code1Mounth, code1Year;
    sscanf(code1, "%d.%d", &code1Mounth, &code1Year);

    for(int i = 0; i < size; i++){
        int medicineMounth, medicineYear;
        sscanf(medicine[i].date, "%d.%d" , &medicineMounth, &medicineYear);

        if(code1Year > medicineYear || (code1Year == medicineYear && code1Mounth > medicineMounth)){
            float oldPrice = medicine[i].price;
            float newPrice = oldPrice * 0.8;
            printf("%s - %s - %.2f leva - %.2f leva", medicine[i].name, medicine[i].date, oldPrice, newPrice);
            medicine[i].price = newPrice;
            flag = 1;
        }
    }

    if(!flag){
        printf("The arent any coincidences!\n");
    }
}

void CompareByQuantity(Medicine *medicine, int size, int quantity1){
    int flag = 0;
    FILE *fp = fopen("offer.bin", "ab");
    if(fp == NULL){
        printf("File is not found!\n");
        exit(1);
    }

    for(int i = 0; i < size; i++){
        if(medicine[i].quantity > quantity1){
            int nameLen = strlen(medicine[i].name) + 1;
            fwrite(&nameLen, sizeof(int), 1, fp);
            fwrite(medicine[i].name, sizeof(char), nameLen, fp);
            fwrite(medicine[i].date, sizeof(char), 8, fp);
            fwrite(&medicine[i].Code, sizeof(long long), 1, fp);
            fwrite(&medicine[i].price, sizeof(float), 1, fp);
            fwrite(&medicine[i].quantity, sizeof(int), 1, fp);
            flag = 1;
        }
    }

    if(!flag){
        printf("The arent any coincidences!\n");
    }

    fclose(fp);
}

void CompareByCode(Medicine *medicine, int *size, long long code) {
    int flag = 0;
    for (int i = 0; i < *size; i++) {
        if (medicine[i].Code == code) {
            for (int j = i; j < *size - 1; j++) {
                medicine[j] = medicine[j + 1];
            }

            (*size)--;
            flag = 1;
            break;
        }
    }
    if(flag){
        if(*size > 0){
            Medicine *newMedicine = (Medicine*)realloc(medicine, sizeof(Medicine)* (*size));
            if(newMedicine == NULL){
                printf("The memory is not allocated successfully!\n");
                exit(0);
            }
            else{
                printf("The element is removed!\n");
                medicine = newMedicine;
            }
        }
        else{
            free(medicine);
            printf("The element is removed! The array is empty!\n");
        }
    }
    printf("The arent any coincidences!/n");
}

int main()
{
    FILE *fp = fopen("medicines.txt", "r");
    if(fp == NULL){
        printf("File is not found!\n");
        exit(1);
    }

    int count = 0;
    int size = 1;
    Medicine *medicine = (Medicine*)malloc(sizeof(Medicine)*size);
    if(medicine == NULL){
        printf("The memory is not allocated successfully!\n");
        exit(0);
    }

    while(fscanf(fp, "%31s;%8s;%lld;%f;%d\n", medicine[count].name, medicine[count].date, medicine[count].Code, medicine[count].price, medicine[count].quantity) == 5){
        count++;
        if(count >= size){
            size*=2;
            medicine = (Medicine*)realloc(medicine, sizeof(Medicine) * size);
            if(medicine == NULL){
                printf("The memory is not allocated successfully!\n");
                exit(0);
            }
        }
    }

    char DateCompare[8];
    printf("Enter date to compare: ");
    scanf("%8s", DateCompare);

    CompareByDate(medicine, count, DateCompare);

    int QuantityCompare;
    printf("Enter a quantity to compare: ");
    scanf("%d", &QuantityCompare);

    CompareByQuantity(medicine, count, QuantityCompare);

    long long CodeCompare;
    printf("Enter a code to compare: ");
    scanf("%lld", &CodeCompare);

    CompareByCode(medicine, &count, CodeCompare);

    fclose(fp1);

    fclose(fp);

    free(medicine);

    return 0;
}
