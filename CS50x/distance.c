// 07-Aug-2016 11:25 - WNixaloy

#include <math.h>
#include <stdio.h>

typedef struct
{
    float x;
    float y;
} Point;

double distance (Point p1, Point p2) {
    double diffx, diffy;

    diffx = p1.x - p2.x;
    diffy = p1.y - p2.y;

    return sqrt (diffx * diffx + diffy * diffy);
}

int main(void) {
    // Point coord1, coord2;
    Point coord1 = { .x = 0.5, .y = 2.5 };
    Point coord2 = { .x = 1.5, .y = 3.1 };

    printf("\nCoordinate 1: (%.1f, %.1f), Coordinate 2: (%.1f, %.1f)\n\n",\
                        coord1.x, coord1.y, coord2.x, coord2.y);
    double d = distance (coord1, coord2);
    printf("Distance between coordinates: %.2f\n\n", d);
}
