#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    double price;
    int product_number;
} Product;

typedef struct {
    char address[100];
    int product_number;
} Order;

int main() {
    Product products[100];
    Order orders[100];
    int num_products = 0;
    int num_orders = 0;

    char command[10];

    while (scanf("%s", command) != EOF) {
        if (strcmp(command, "Product") == 0) {
            scanf("%s %lf %d", products[num_products].name, &products[num_products].price, &products[num_products].product_number);
            for (int i = 0; i < num_orders; i++) {
                if (orders[i].product_number == products[num_products].product_number) {
                    printf("Client %s ordered %s\n", orders[i].address, products[num_products].name);
                    for (int j = i; j < num_orders - 1; j++) {
                        orders[j] = orders[j + 1];
                    }
                    num_orders--;
                    i--;
                }
            }
            num_products--;
        } else if (strcmp(command, "Order") == 0) {
            scanf("%s %d", orders[num_orders].address, &orders[num_orders].product_number);
            int found = 0;
            for (int i = 0; i < num_products; i++) {
                if (products[i].product_number == orders[num_orders].product_number) {
                    printf("Client %s ordered %s\n", orders[num_orders].address, products[i].name);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("Client %s waiting for the product\n", orders[num_orders].address);
                num_orders++;
            }
        } else if (strcmp(command, "END") == 0) {
            break;
        }
    }

    return 0;
}
