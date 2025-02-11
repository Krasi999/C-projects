#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int number;
    char date[11];
    char name[31];
    char diagnose[51];
}Treatment;

int count_treatment(Treatment *history, int size,char name1[], char diagnose1[]){
    int count = 0;
    int flag = 0;
    for(int i = 0; i < size; i++){
        if(strcmp(history[i].name, name1) == 0 && strcmp(history[i].diagnose, diagnose1) == 0){
            count++;
            flag = 1;
        }
    }
    if(flag){
        return count;
    }else{
        return 0;
    }
}

Treatment* add_new_treatment(Treatment *history, int *size){
    Treatment newHistory;
    printf("Enter the date for the new treatment!\n");
    printf("Number: ");
    scanf("%d", &newHistory.number);
    printf("Date: ");
    scanf("%11s", newHistory.date);
    printf("Name: ");
    scanf("%31s", newHistory.name);
    printf("Diagnose: ");
    scanf("%51", newHistory.diagnose);
    getchar();

    (*size)++;
    Treatment *history1 = (Treatment*)realloc(history, sizeof(Treatment) * (*size));
    if(history1 == NULL){
        printf("The memory is not allocated!\n");
        return NULL;
    }
    history1[*size - 1] = newHistory;
    return history1;
}

int write_text_file(Treatment *history, int size, char diagnose1[]){
    FILE *fp = fopen("illness.txt", "a");
    if(fp == NULL){
        printf("File is not found!\n");
        exit(5);
    }

    int count = 0;
    int flag = 0;
    for(int i = 0; i < size; i++){
        if(strcmp(history[i].diagnose, diagnose1) == 0){
            fprintf(fp, "Bolnichen perstoi na %s\n za lechenie na %s:\n %sg.\n",history[i].name, history[i].diagnose, history[i].date);
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

int main()
{
    FILE *fp = fopen("history.bin", "rb");
    if(fp == NULL){
        printf("File is not found!\n");
        exit(1);
    }

    int n;
    if(fread(&n, sizeof(int), 1, fp) != 1){
        printf("The number of epicrises is not found!\n");
        exit(2);
    }
    Treatment *history = (Treatment*)malloc(sizeof(Treatment)*n);
    if(history == NULL){
        printf("The memory is not allocated successfully!\n");
        exit(3);
    }

    if(fread(history, sizeof(Treatment), n, fp) != n){
        printf("The date in the file is not found!\n");
        exit(4);
    }

    char CompareName[31];
    printf("Enter a name to compare: ");
    scanf("%31s", CompareName);
    char CompareDiagnose1[51];
    printf("Enter a diagnose to compare: ");
    scanf("%51s", CompareDiagnose1);
    getchar();

    int count = count_treatment(history, n, CompareName, CompareDiagnose1);
    if(count != 0){
        printf("The count is %d!\n", count);
    }else{
        printf("There arent any coincidences!\n");
    }

    Treatment *history1 = add_new_treatment(history, &n);
    if(history1 != NULL){
        printf("The new treatment is saved!\n");
        history = history1;
    }else{
        printf("The reallocation failed!\n");
    }

    char CompareDiagnose2[51];
    printf("Enter a diagnose to compare: ");
    scanf("%51s", CompareDiagnose2);
    getchar();

    int num = write_text_file(history, n, CompareDiagnose2);
    if(num != 0){
        printf("The count is %d!\n", num);
    }else{
        printf("There arent any coincidences!\n");
    }

    fclose(fp);

    free(history);

    return 0;
}
