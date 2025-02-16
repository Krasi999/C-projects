#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[10];
    int age;
    int fnum;
};

int main() {
    FILE* ptr = fopen("students.bin", "wb+");
    if (ptr == NULL) {
        printf("The file is not exist!");
        return 1;
    }

    struct Student input1 = {"Ivan", 18, 1212};
    int flag = fwrite(&input1, sizeof(struct Student), 1, ptr);
    if (flag < 1) {
        printf("The fwrite function is not working!");
        return 1;
    }

    fseek(ptr, 0, SEEK_SET);

    int totalAge = 0;
    struct Student temp;

    for (int i = 0; i < 1; i++) {
       fread(&temp, sizeof(struct Student), 1, ptr);
       totalAge += temp.age;
    }

    fclose(ptr);

    int averageAge = totalAge / 1;
    printf("Average Age: %d\n", averageAge);

    return 0;
}
