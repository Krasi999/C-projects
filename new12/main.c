#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//zadacha 1
typedef struct {
    char Names[56];
    char Number[7];
    float Price;
    int Code;
} Person;

int DynamicFunction(Person person[], int N) {
    FILE *fp = fopen("membersText.txt", "a");
    if (fp == NULL) {
        printf("File not found!");
        exit(1);
    }

    person = realloc(person, (N + 1) * sizeof(Person));
    if (person == NULL) {
        printf("The memory is not allocated!\n");
        exit(0);
    }

    else {
        printf("The memory is allocated successfully!\n");
        printf("Enter the two names of the person: ");
        fgets(person[N].Names, sizeof(person[N].Names), stdin);
        printf("Enter the number of the person: ");
        scanf("%7s", &person[N].Number);
        printf("Enter the price: ");
        scanf("%f", &person[N].Price);
        printf("Enter the code: ");
        scanf("%d", &person[N].Code);
        getchar();

        while (person[N].Code < 100 || person[N].Code > 999) {
            printf("You entered a wrong code!\n");
            printf("Enter the code again: ");
            scanf("%d", &person[N].Code);
        }
    }

    fprintf(fp, "%zu; %s; %s; %.2f; %d\n", strlen(person[N].Names), person[N].Names, person[N].Number, person[N].Price, person[N].Code);
    N++;

    fclose(fp);

    //free(person);
    return N;
}

//zadacha 2
void AveragePrice(Person* person, int N){
    float total=0.00;
    int count = 0;
    int flag = 0;
    for (int i = 0; i < N; i++) {
        total += person[i].Price;
        count++;
    }
    float average = total / count;

    for (int i = 0; i < N; i++) {
        if (person[i].Price < average) {
            printf("%s - %s - %.2f\n", person[i].Names, person[i].Number, person[i].Price);
            flag = 1;
        }
    }
    if(!flag){
        printf("There aren't any coincidences!\n");
    }
}

//zadacha 3
void CompareByCode(char *number1){
    FILE *fp = fopen("members.bin", "rb");
    if(fp==NULL){
        printf("File is not found!\n");
        exit(1);
    }
    Person person;
    while(fread(&person, sizeof(Person), 1, fp) == 1){
        if(strcmp(person.Number, number1) == 0){
            printf("Bin Names: %s", person.Names);
            printf("Bin ID: %s", person.Number);
            printf("Bin M_Price: %.2f", person.Price);
            printf("Bin Locker: %d", person.Code);
        }
    }
}


int main() {
    //zadacha 1
    int N;
    printf("Enter the size of the array: ");
    scanf("%d", &N);
    getchar();

    Person *person = (Person*)malloc(N * sizeof(Person));
    if (person == NULL) {
        printf("Memory allocation failed!\n");
        exit(0);
    }

    for (int i = 0; i < N; i++) {
        printf("Enter the data for person %d\n", i + 1);
        printf("Enter the two names of the person: ");
        fgets(person[i].Names, sizeof(person[i].Names), stdin);
        fflush(stdin);
        printf("Enter the number of the person: ");
        scanf("%7s", &person[i].Number);
        printf("Enter the price: ");
        scanf("%f", &person[i].Price);
        printf("Enter the code: ");
        scanf("%d", &person[i].Code);
        getchar();

        while (person[i].Code < 100 || person[i].Code > 999) {
            printf("You entered a wrong code!\n");
            printf("Enter the code again: ");
            scanf("%d", &person[i].Code);
            getchar();
        }
    }

    N = DynamicFunction(person, N);

    //zadacha 2

    AveragePrice(person,N);


    //zadacha 3
    char numberCompare[7];
    printf("Enter a code to compare: ");
    scanf("%7s", &numberCompare);

    CompareByCode(numberCompare);

    free(person);

    return 0;
}
