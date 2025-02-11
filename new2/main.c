#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char Name[31];
    char Date[8];
    long long Code;
    float Price;
    int Quantity;
} Medicine;

void ReducePriceByExpiredDate(Medicine *medicine, int size, char date1[]){

    int found = 0;
    int inputMonth, inputYear;
    sscanf(date1, "%d.%d", &inputMonth, &inputYear);

    for (int i  = 0; i < size; i++) {
        int medicineMonth, medicineYear;
        sscanf(medicine[i].Date, "%d.%d", &medicineMonth, &medicineYear);

        if (inputYear > medicineYear || (inputYear == medicineYear && inputMonth > medicineMonth)) {
            float oldPrice = medicine[i].Price;
            float newPrice = oldPrice * 0.8;
            printf("%s - %s - %.2f leva - %.2f leva\n", medicine[i].Name, medicine[i].Date, oldPrice, newPrice);
            medicine[i].Price = newPrice;
            found = 1;
        }
    }
    if (!found) {
        printf("There is no medicines which date are before the input date - %s.\n", date1);
    }
}

void WriteMedicineToBinFile(Medicine *medicine, int size, int quantity1) {
    FILE *fp = fopen("offer.bin", "wb");
    if (fp == NULL) {
        printf("File not found!\n");
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        if (medicine[i].Quantity > quantity1) {
            int nameLen = strlen(medicine[i].Name) + 1;
            fwrite(&nameLen, sizeof(int), 1, fp);
            fwrite(medicine[i].Name, sizeof(char), nameLen, fp);
            fwrite(medicine[i].Date, sizeof(char), 8, fp);
            fwrite(&medicine[i].Code, sizeof(long long), 1, fp);
            fwrite(&medicine[i].Price, sizeof(float), 1, fp);
            fwrite(&medicine[i].Quantity, sizeof(int), 1, fp);
        }
    }

    fclose(fp);
}

void DeleteMedicineByCode(Medicine *medicine, int *size, long long code) {
    for (int i = 0; i < *size; i++) {
        if (medicine[i].Code == code) {
            for (int j = i; j < *size - 1; j++) {
                medicine[j] = medicine[j + 1];
            }

            (*size)--;
            printf("The medcine with this code %lld is removed.\n", code);
        }
    }

    printf("There is no medicine with this code %lld.\n", code);
}

int main() {

    FILE *fp = fopen("medicines.txt", "r");
    if (fp == NULL) {
        printf("File not found!\n");
        exit(1);
    }

    int count = 0;
    int size = 1;

    Medicine *medicine = (Medicine*)malloc(sizeof(Medicine) * size);
    if (medicine == NULL) {
        printf("The memory is not allocated successfully!\n");
        exit(0);
    }

    while (fscanf(fp, "%31s;%8s;%lld;%f;%d\n", medicine[count].Name, medicine[count].Date, &medicine[count].Code, &medicine[count].Price, &medicine[count].Quantity) == 5) {
        count++;
        if (count >= size) {
            size *= 2;
            medicine = (Medicine*)realloc(medicine, sizeof(Medicine) * size);
            if (medicine == NULL) {
                printf("The memory is not allocated successfully!\n");
                exit(0);
            }
        }
    }

    char expiredDate[8];
    printf("Enter a date to compare: ");
    scanf("%s", expiredDate);

    ReducePriceByExpiredDate(medicine, count, expiredDate);

    int minQuantity;
    printf("Enter a quantity to compare: ");
    scanf("%d", &minQuantity);

    WriteMedicineToBinFile(medicine, count, minQuantity);

    long long deleteCode;
    printf("Enter a code to compare: ");
    scanf("%lld", &deleteCode);

    DeleteMedicineByCode(medicine, &count, deleteCode);

    fclose(fp);

    free(medicine);

    return 0;
}
