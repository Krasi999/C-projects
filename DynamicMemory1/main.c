#include <stdio.h>
#include <stdlib.h>

int push(int *a, int *size) {
    int element;
    printf("Enter an element to add:\n");
    scanf("%d", &element);

    (*size)++;
    int* tmp = realloc(a, (*size) * sizeof(int));
    if (tmp == NULL) {
        exit(1);
    } else {
        a[(*size) - 1] = element;
    }
    return *size;
}

int pop(int *a, int *size) {
    if (*size == 0) {
        printf("Stack underflow.\n");
        return -1;
    }
    (*size)--;
    return a[*size];
}

void print(int *a, int size) {
    if (size == 0) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Elements in the stack:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int size = 0;
    int* arr = (int*)malloc(size * sizeof(int));
    int exp = 1;
    while (exp != 0) {
        printf("Enter your choice: ");
        scanf("%d", &exp);
        switch (exp) {
            case 1:
                size = push(arr, &size);
                break;
            case 2: {
                int popped = pop(arr, &size);
                if (popped != -1)
                    printf("Popped element: %d\n", popped);
                break;
            }
            case 3:
                print(arr, size);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    free(arr);

    return 0;
}
