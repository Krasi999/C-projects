#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float sqr(float a){
    return a*a;
}

float rect(float a, float b){
    return a*b;
}

float tri(float a, float b){
    return (a*b)/2;
}

float circle(float a){
    return M_PI*a*a;
}

int main()
{
    int f;
    float S;
    float a,b;
    printf("Enter the first number:");
    scanf("%f", &a);
    printf("Enter a second number:");
    scanf("%f", &b);
    printf("Enter a number from 1 to 4:");
    scanf("%d", &f);


    while (f < 1 || f > 4){
        printf("You enter a wrong number:\n");
        printf("Enter a number from 1 to 4 again:");
        scanf("%d", &f);
    }

    switch(f){
    case 1:
        {
            printf("The figure is square:\n");
            S = sqr(a);
            //printf("The area of the square is: %.2f", S);
            break;
        }

    case 2:
        {
            printf("The figure is rectangle:\n");
            S = rect(a,b);
            //printf("The area of the rectangle is: %.2f", S);
            break;
        }

    case 3:
        {
            printf("The figure is right-angled triangle:\n");
            S = tri(a,b);
            //printf("The area of the triangle is: %.2f", S);
            break;
        }

    case 4:
        {
            printf("The figure is circle:\n");
            S = circle(a);
            //printf("The area of the circle is: %.2f", S);
            break;
        }
    }

    float *P = &S;
    printf("The area of this figure is: %.2f", *P);

    return 0;
}
