/*  Program to ullustrate the use of the #include statement
    NOTE: This program assumes that definitions are
    set up in a file called metric.h
    Programming in C - ch 13        03-Jun-2016 09:35   */

#include <stdio.h>
#include "p13.3_metric.h"

int main(void) {
    float liters, gallons;

    printf ("*** Liters to Gallons ***\n\n");
    printf ("Enter the number of liters: ");
    scanf ("%f", &liters);

    gallons = liters * QUARTS_PER_LITER / 4.0;
    printf ("%g liters = %g gallons\n", liters, gallons);

    return 0;
}
