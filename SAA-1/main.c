#include <stdio.h>
#include <stdlib.h>

void print_array(int array[], int size);
int* create_array(int* size);
void quick_sort(int array[], int low, int high);
void call_quick_sort();

int main() {
    call_quick_sort();
    return 0;
}

void print_array(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int* create_array(int* size) {
    printf("Enter the number of elements: ");
    scanf("%d", size);

    int* array = (int*)malloc(*size * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    printf("Enter %d elements:\n", *size);
    for (int i = 0; i < *size; i++) {
        scanf("%d", &array[i]);
    }

    return array;
}

void quick_sort(int array[], int low, int high) {
    int i = low, j = high;
    int pivot = array[(low + high) / 2];
    int temporary;

    do {
        while (array[i] < pivot) { i++; }
        while (array[j] > pivot) { j--; }

        if (i <= j) {
            temporary = array[i];
            array[i] = array[j];
            array[j] = temporary;
            i++;
            j--;
        }
    } while (i <= j);

    if (low < j) {
        quick_sort(array, low, j);
    }
    if (i < high) {
        quick_sort(array, i, high);
    }
}

void call_quick_sort() {
    int size;
    int* array = create_array(&size);

    printf("Array: ");
    print_array(array, size);

    quick_sort(array, 0, size - 1);

    printf("Sorted Array: ");
    print_array(array, size);

    free(array);
}
