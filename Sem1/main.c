#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double prices[] = {42.00, 13.99, 5.98, 21.02};

void calculateAdditionalItems(int num_guests, int items_bought[], int additional_items_needed[]) {
    additional_items_needed[0] = ceil((double)num_guests / 8) - items_bought[0];
    additional_items_needed[1] = num_guests - items_bought[1];
    additional_items_needed[2] = ceil((double)num_guests / 6) - items_bought[2];
    additional_items_needed[3] = ceil((double)num_guests / 6) - items_bought[3];
}

int main() {
    int num_guests;
    printf("Enter the number of the guests:\n");
    scanf("%d", &num_guests);

    int items_bought[4] = {0};

    char item[10];
    while (scanf("%s", item)) {
        if (strcmp(item, "PARTY!") == 0)
            break;
        if (strcmp(item, "Table") == 0)
            items_bought[0]++;
        else if (strcmp(item, "Chair") == 0)
            items_bought[1]++;
        else if (strcmp(item, "Cups") == 0)
            items_bought[2]++;
        else if (strcmp(item, "Dishes") == 0)
            items_bought[3]++;
    }

    int additional_items_needed[4];
    calculateAdditionalItems(num_guests, items_bought, additional_items_needed);

    double total_cost = 0;
    for (int i = 0; i < 4; i++) {
        total_cost += prices[i] * items_bought[i];
    }

    printf("\n----------------\n");

    printf("%.2f\n", total_cost);

    if (additional_items_needed[0] > 0) {
        printf("%d Table\n", additional_items_needed[0]);
    }
    if (additional_items_needed[1] > 0) {
        printf("%d Chair\n", additional_items_needed[1]);
    }
    if (additional_items_needed[2] > 0) {
        printf("%d Cups\n", additional_items_needed[2]);
    }
    if (additional_items_needed[3] > 0) {
        printf("%d Dishes\n", additional_items_needed[3]);
    }

    return 0;
}
