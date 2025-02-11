#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void recursion1(int number){
    if(number > 1){
        recursion1(number / 2);
    }
    printf("%d", number % 2);
}

double recursion2(int x, int n) {
    if (n == 0) {
        return 1;
    }
    else if (n < 0) {
        return 1 / recursion2(x, -n);
    }
    else {
        return x * recursion2(x, n - 1);
    }
}

int recursion3(int arr[], int length) {
    if (length <= 0) {
        return 0;
    }
    return arr[length - 1] + recursion3(arr, length - 1);
}

int main() {

    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    recursion1(num);

    printf("\n-----------\n");

    int x;
    printf("Enter a number: ");
    scanf("%d", &x);

    int power;
    printf("Enter a power: ");
    scanf("%d", &power);

    double rec2 = recursion2(x, power);
    printf("The result is %lf", rec2);

    printf("\n-----------\n");

    int arr1[] = {1, 2, 3, 4, 5};
    int len = sizeof(arr1) / sizeof(int);

    int sum = recursion3(arr1, len);
    printf("Sum of array elements: %d\n", sum);

    return 0;
}
