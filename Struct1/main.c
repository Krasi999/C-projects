#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    float x;
    float y;
    float z;
}Point;

float distance(Point point1, Point point2){
    return sqrt(pow(point2.x - point1.x, 2) + pow(point2.y - point1.y, 2) + pow(point2.z - point1.z, 2));
}

int main()
{
    Point points[3];

    points[0].x = 1.0;
    points[0].y = 2.0;
    points[0].z = 3.0;

    points[1].x = 4.0;
    points[1].y = 5.0;
    points[1].z = 6.0;

    points[2].x = 7.0;
    points[2].y = 8.0;
    points[2].z = 9.0;

    float side1 = distance(points[0], points[1]);
    float side2 = distance(points[1], points[2]);
    float side3 = distance(points[2], points[0]);

    printf("Side 1: %.2f\n", side1);
    printf("Side 2: %.2f\n", side2);
    printf("Side 3: %.2f\n", side3);

    return 0;
}
