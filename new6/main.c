#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char name[21];
    int code;
    char endDate[11];
    float price;
}Product;

void CreateProducts(Product *products, int size){
    for(int i = 0; i < size; i++){
        printf("Enter the data for the products %d!\n", i+1);
        printf("Name: ");
        scanf("%21s", products[i].name);
        printf("Code:");
        scanf("%d", &products[i].code);
        while(products[i].code < 100 || products[i].code > 999){
            printf("You enter a wrong code!\n");
            printf("Enter again please: ");
            scanf("%d", &products[i].code);
        }
        printf("EndDate: ");
        scanf("%11s", products[i].endDate);
        printf("Price: ");
        scanf("%f", &products[i].price);
        getchar();
    }
}

float avrg_by_price(Product *products, int size, float price1){
    int flag = 0;
    int count = 0;
    float sub, avg;
    for(int i = 0; i < size; i++){
        if(products[i].price < price1){
            sub += products[i].price;
            count++;
            flag = 1;
        }
        avg = sub / count;
    }
    if (flag){
        return avg;
    }else{
        return 0;
    }
}

int write_text_file(Product *products, int size, char date1[], float price1){
    FILE *fp = fopen("products.txt", "a");
    if(fp == NULL){
        printf("File i not found!\n");
        exit(1);
    }

    int InputYear, InputMouth, InputDay;
    sscanf(date1, "%d.%d.%d", &InputYear, &InputMouth, &InputDay);

    int count = 0;
    int flag = 0;

    for(int i = 0; i < size; i++){
        int ProductYear, ProductMonth, ProductDay;
        sscanf(products[i].endDate, "%d.%d.%d", &ProductYear, &ProductMonth, &ProductDay);
        if(InputYear > ProductYear && price1 < products[i].price ||
           (InputYear == ProductYear && InputMouth > ProductMonth && price1 < products[i].price) ||
           (InputYear == ProductYear && InputMouth == ProductMonth && InputDay > ProductDay && price1 < products[i].price)){
            fprintf(fp, "%s-%d-%s-%f leva", products[i].name, products[i].code, products[i].endDate, products[i].price);
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

void print_info(char name1[], int code1){
    FILE *fp = fopen("products.bin", "rb");
    if(fp == NULL){
        printf("File not found!\n");
        exit(1);
    }

    Product products;
    int flag = 0;
    while(fread(&products, sizeof(Product), 1, fp) == 1){
        if(strcmp(products.name, name1) == 0 && products.code == code1){
            printf("Date for products: %s - use before %s - price %.2f leva", products.name, products.endDate, products.price);
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
    printf("Enter the number of the products: ");
    scanf("%d", &n);
    while(n < 0 || n > 29){
        printf("You enter a wrong number!\n");
        printf("Enter the number of products again: ");
        scanf("%d", &n);
    }

    Product *products = (Product*)malloc(sizeof(Product)*n);
    if(products == NULL){
        printf("The memory is not allocated successfully!\n");
        exit(0);
    }

    CreateProducts(products, n);

    float ComparePrice1;
    printf("Enter a price to compare: ");
    scanf("%f", &ComparePrice1);
    getchar();

    float num = avrg_by_price(products, n, ComparePrice1);
    if(num != 0){
        printf("The average price is %.2f!\n", num);
    }else{
        printf("There arent any coincidences!\n");
    }

    char CompareDate[11];
    printf("Enter date to compare: ");
    scanf("%11s", CompareDate);
    float ComparePrice2;
    printf("Enter a price to compare: ");
    scanf("%f", &ComparePrice2);
    getchar();

    int count  = write_text_file(products, n, CompareDate, ComparePrice2);
    if(count != 0){
        printf("The count is %d!", count);
    }else{
        printf("There arent any coincidences!\n");
    }
    char CompareName[21];
    printf("Enter a name to compare: ");
    scanf("%21s", CompareName);
    int CompareCode;
    printf("Enter code to compare: ");
    scanf("%d", &CompareCode);

    print_info(CompareName, CompareCode);

    free(products);

    return 0;
}
