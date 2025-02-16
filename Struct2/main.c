#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char brand[10];
    char model[10];
    char color[10];
    int horse_powers;
    int year;
} Car;

typedef struct {
    char brand[10];
    char model[10];
    char color[10];
    int horse_powers;
    int year;
} Motorcycle;

typedef struct {
    char brand[10];
    char model[10];
    char color[10];
    int horse_powers;
    int year;
} Boat;

typedef struct {
    char brand[10];
    char model[10];
    char color[10];
    int horse_powers;
    int year;
} Plane;

typedef struct {
    Car car;
    Motorcycle motorcycle;
    Boat boat;
    Plane plane;
} Vehicle;

void CompareColor(Vehicle v1, Vehicle v2) {
    if (strcmp(v1.car.color, v2.plane.color) == 0) {
        printf("The color of the car and plane are the same!\n");
    } else {
        printf("The color of the car and plane are NOT the same!\n");
    }
}

int main() {
    Vehicle vehicle1, vehicle4;

    strcpy(vehicle1.car.brand, "Ford");
    strcpy(vehicle1.car.model, "Mustang");
    strcpy(vehicle1.car.color, "Blue");
    vehicle1.car.horse_powers = 420;
    vehicle1.car.year = 2019;

    strcpy(vehicle4.plane.brand, "Airbus");
    strcpy(vehicle4.plane.model, "A320");
    strcpy(vehicle4.plane.color, "Blue");
    vehicle4.plane.horse_powers = 25420;
    vehicle4.plane.year = 2021;

    CompareColor(vehicle1, vehicle4);

    return 0;
}
