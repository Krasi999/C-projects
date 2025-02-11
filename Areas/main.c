#include <stdio.h>
#include <math.h>

float SqrArea(float a)
{
    return a*a;
}
float RecArea(float a,float b)
{
    return a*b;
}
float TrianglArea(float a, float b)
{
    return (a*b)/2;
}
float CircleArea(float a)
{
    return M_PI*a*a;
}

int main()
{
    float S, a, b;
    float (*areaFunc)(float, float);
    printf("Enter a number from 1 to 4: ");
    int f;
    scanf("%d", &f);

    if(f == 1)
    {
        printf("The figure is square.\n");
        areaFunc = SqrArea;
    }
    else if(f == 2)
    {
        printf("The figure is rectangle.\n");
       areaFunc = RecArea;
    }
    else if(f == 3)
    {
        printf("The figure is right-angled triangle.\n");
        areaFunc = TrianglArea;
    }
    else if(f == 4)
    {
        printf("The figure is circle.\n");
        areaFunc = CircleArea;
    }
    else
    {
        printf("Invlaid number!\n");
    }

    if (f == 1 || f == 4)
    {
        printf("Enter a: ");
        scanf("%f", &a);
        S = areaFunc(a, 0);
    } else
    {
        printf("Enter values for a and b: ");
        scanf("%f %f", &a, &b);
        S = areaFunc(a, b);
    }

    printf("The area is %.2f\n", S);
    return 0;
}
