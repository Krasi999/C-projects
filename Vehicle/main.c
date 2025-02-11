#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("How many kilometers are you going to travel?\n");
    scanf("%d", &n);
    getchar();
    char time;
    printf("Enter is it day(D) or night(N):\n");
    scanf("%c", &time);
    time = toupper(time);

    float prize = 0;

    if(n < 20 && time == 'D'){
        prize = 0.7 + 0.79*n;
        printf("The cheapest transport prize is:");
        printf("%.2f", prize);
    }

    else if(n < 20 && time == 'N'){
        prize = 0.7 + 0.90*n;
        printf("The cheapest transport prize is:");
        printf("%.2f", prize);
    }

    else if(20 < n < 100){
        prize = 0.09*n;
        printf("The cheapest transport prize is:");
        printf("%.2f", prize);
    }

    else{
        prize = 0.06*n;
        printf("The cheapest transport prize is:");
        printf("%.2f", prize);
    }

    return 0;
}
