#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter the number of element of the array:\n");
    scanf("%d", &n);

    int found = 0, index = 0;

    int arrayA[n];
    for(int i = 1; i < n; i++){
        arrayA[0] = 2;
        arrayA[i] = 2 * arrayA[i-1] + 3;

        if (arrayA[i] > 10000 && !found) {
            found = 1;
            index = i;
        }
    }

    for(int i =0; i < n; i++){
        printf("%d ", arrayA[i]);
    }
    printf("\n");

    int sum = 0;
    for(int i = 0; i < index + 1; i++){
        if(arrayA[i] > 100 && arrayA[i] % 2 == 1){
            sum += arrayA[i];
        }
    }

    printf("%d", sum);

    return 0;
}
