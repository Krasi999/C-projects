#include <stdio.h>
#include <stdlib.h>

struct Student{
    char name[10];
    int age;
    int fnum;
};

int main(){

    FILE* ptr = fopen("students.txt", "w+");
    if(ptr == NULL){
        printf("The file is not exist!");
        return 1;
    }

    struct Student* students[3];

    for (int i = 0; i < 3; i++) {
        struct Student* temp = (struct Student*)malloc(sizeof(struct Student));
        if (temp == NULL) {
            printf("Memory allocation failed!");
            return 1;
        }

        snprintf(temp->name, sizeof(temp->name), "Ivan");
        temp->age = 18 + i;
        temp->fnum = 1212 + i;

        students[i] = temp;
    }


    int totalAge = 0;

    for (int i = 0; i < 3; i++) {
        fprintf(ptr, "%s %d %d\n", students[i]->name, students[i]->age, students[i]->fnum);
        totalAge += students[i]->age;
        free(students[i]);
    }

    fclose(ptr);

    int averageAge = totalAge / 3;
    printf("Average Age: %d\n", averageAge);

    rename("students.txt", "rename_students1.txt");

    return 0;
}
