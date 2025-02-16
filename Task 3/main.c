#include <stdio.h>
#include <stdlib.h>

int odd_even(int a){
    if(a%2 == 0){
        printf("The number is even:");
    }
    else{
        printf("The number is odd");
    }
}
int main()
{
    int a;
    printf("Enter a number:");
    scanf("%d",&a);
    odd_even(a);
}
