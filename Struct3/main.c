#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[20];
    char surname[20];
    float grade;
} Student;

typedef struct {
    Student students[5];
    int numStudents;
    float classAvg;
} Class;

typedef struct {
    Class classes[5];
    int numClasses;
    int gradYear;
    float gradAvg;
} Graduation;

float classAverage(Class class) {
    float totalGrade = 0.0;
    for (int i = 0; i < class.numStudents; i++) {
        totalGrade += class.students[i].grade;
    }
    return totalGrade / class.numStudents;
}

float graduationAverage(Graduation graduation) {
    float totalGrade = 0.0;
    int totalStudents = 0;
    for (int i = 0; i < graduation.numClasses; i++) {
        totalGrade += graduation.classes[i].classAvg * graduation.classes[i].numStudents;
        totalStudents += graduation.classes[i].numStudents;
    }
    return totalGrade / totalStudents;
}

int main() {
    int numClasses;
    printf("Enter the number of classes: ");
    scanf("%d", &numClasses);

    Graduation myGraduation;
    myGraduation.numClasses = numClasses;
    printf("Enter the graduation year: ");
    scanf("%d", &myGraduation.gradYear);

    for (int i = 0; i < numClasses; i++) {
        Class currentClass;
        printf("Enter number of students in class %d: ", i + 1);
        scanf("%d", &currentClass.numStudents);
        printf("Enter students' data for class %d:\n", i + 1);
        for (int j = 0; j < currentClass.numStudents; j++) {
            scanf("%s %s %f", currentClass.students[j].name, currentClass.students[j].surname, &currentClass.students[j].grade);
        }
        currentClass.classAvg = classAverage(currentClass);
        myGraduation.classes[i] = currentClass;
    }

    for (int i = 0; i < numClasses; i++) {
        printf("Average grade for class %d: %.2f\n", i + 1, myGraduation.classes[i].classAvg);
    }

    myGraduation.gradAvg = graduationAverage(myGraduation);
    printf("Graduation average: %.2f\n", myGraduation.gradAvg);

    return 0;
}
