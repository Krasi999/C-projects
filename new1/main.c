#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Medicine{
    char name[30];
    long id;
    char year[7];
    float price;
};
//DISCLAIMER: NE E POLZVANO CHATGPT
struct Medicine* fresh(struct Medicine* arr, int size, char* date){
    char* month = strtok(date, "."); // razdelq meseca
    char* year = strtok(month, NULL); // razdelq godinata
    int len = 1; // razmer na din masiv
    int counter = 0; // index za masiva
    struct Medicine* meds =(struct Medicine*)malloc(sizeof(struct Medicine)*len);
    for(int i = 0;i<size;i++){
        char *med_date = meds[i].year;
        char* med_month = strtok(med_date, ".");
        char* med_year = strtok(med_year, NULL);
        if(strcmp(med_year, year) > 0 || (strcmp(med_month, month) >= 0 && strcmp(med_year, year) == 0)){ // proverqvame dali izticha po-kusno ot dadeniq date
            if(counter == len){ // ako index == razmera, yvelichavame razmera
                len++; // yvelichavame razmera s 1
                meds = realloc(meds, sizeof(struct Medicine)*len);
           }
            meds[counter] = meds[i]; // initzializirame na index counter
            counter++; // i vdigame indexa s edno
        }
    }
    return meds;
}
//DISCLAIMER: NE E POLZVANO CHATGPT

void remove_medicine(struct Medicine* arr,int size, float max, float min){ // raboti na principa na gornata
    int len = 1;
    int index = 0;
    struct Medicine* meds =(struct Medicine*)malloc(sizeof(struct Medicine)*size);
    for(int i=0;i<size;i++){
        if(arr[i].price >= min && arr[i].price <= max){
            if(index == len){
                len++;
                meds = realloc(meds, sizeof(struct Medicine)*len);
            }
            meds[index] = arr[i];
            index++;
        }
    }
    arr = meds;
}

int main(){
    FILE* file;
    file = fopen("medicine.bin", "rb");
    if(file == NULL){
        exit(1);
    }
    int size = 1;
    int index = 0;
    struct Medicine* medicines =(struct Medicine*)malloc(sizeof(struct Medicine)*size);
    struct Medicine m;
    while(fread(&m, sizeof(struct Medicine), 1, file)){
        if(index == size){
            size++;
            medicines = realloc(medicines, sizeof(struct Medicine)*size);
        }
        medicines[index] = m;
        index++;
    }
    fclose(file);
    return 0;
}
