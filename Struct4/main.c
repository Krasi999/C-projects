#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char name[10];
    char surname[10];
    float grade;

}Student;

typedef struct{
    Student students[5];
    char className[10];
}Class;

typedef struct{
    Class classes[5];
    int gradYear;
}Vipusk;

float AvgGradeClasses(Student* st1, int a, int b){
    float Grade = 0;
    float AvgGrade = 0;
    for(int i = 0; i < a; i++){
        for(int j = 0; j < b; j++){
            Grade += st1->grade;
        }

        AvgGrade = Grade / b;
        printf("The Average Grade of the students is %.2f:", AvgGrade);
    }
}

int main()
{
    Student students;
    Class classes;

    int a;
    printf("Enter the number of classes: ");
    scanf("%d", &a);

    int num = 0;
    int b;

    do{
        for(int i = 0; i < a; i++){
            printf("Enter the number of students of class_%d: ", i+1);
            scanf("%d", &b);
        printf("Enter the student's data:\n");
            for(int j = 0; j < b; j++){
                scanf("%s %s %f", &students.name, &students.surname, &students.grade);
                getchar();
            }
        }
        num++;
        break;

    }while(a > num);

    AvgGradeClasses(&students.grade, a, b);

    return 0;
}

