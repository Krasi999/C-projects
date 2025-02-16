#include <stdio.h>
#include <stdlib.h>

float change(float a, float b){
    float *N = &b;
    printf("%.2f\n", *N);
    b = a;
    printf("%.2f\n", b);
}

int main()
{
    float a, b;
    printf("Enter the first number:\n");
    scanf("%f", &a);
    printf("Enter the first number:\n");
    scanf("%f", &b);
    change(a, b);
    return 0;
}
