#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    printf("Enter a binary number: ");
    scanf("%d", &num);
    int a;
    printf("Enter a number to check: ");
    scanf("%d", &a);

    if (recursion(num, a)) {
        printf("The number %d contains digit %d.\n", num, a);
    } else {
        printf("The number %d  doesn't contain digit %d.\n", num, a);
    }

    return 0;
}

int recursion(int num, int a){
    if(num == 0){
        return 0; //0 is equal to false
    }
    if(num % 10 == a){
        return 1; //1 is equal to true
    }
    return recursion(num / 10, a);
}
