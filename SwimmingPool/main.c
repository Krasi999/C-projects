#include <stdio.h>
#include <stdlib.h>

int main()
{
    float obem;
    printf("Enter the obem of the pool:\n");
    scanf("%f", &obem);

    float a1, a2;
    printf("Enter the debit of the truba 1 and 2:\n");
    scanf("%f", &a1);
    scanf("%f", &a2);

    while(a1 > obem || a2 > obem){
        printf("This is imposible!");
        printf("Enter the debit of the truba 1 and 2 again:\n");
        scanf("%d", &a1);
        scanf("%d", &a2);
    }

    float time1;
    printf("Enter the time when the employee left:\n");
    scanf("%f", &time1);

    getchar();

    float time2;
    printf("Enter the time when the employee return:\n");
    scanf("%f", &time2);

    float N = (time2 - time1) * 60;
    printf("%f", N);

    printf("\n------------\n");

    float capacity;
    capacity = obem - ((a1 + a2) * N) /60;
    printf("%.2f", capacity);

    return 0;
}
