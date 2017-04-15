// CS50x - Introduction to Computer Science
// Programming in C - Exercise 7.4
// WH Noxchi - 18-Mar-2016 15:11

// Write a program that calcs the avg of an array of 10 floats

#include <stdio.h>

int main(void)
{
    float floats[10];
    float total = 0.0;
    int count = 0;
    float average;

    for (int i = 0; i < 10; i++) {
        floats[i] = i * 2.0 + 3.5;
        total += floats[i];
        // printf("(%.2f)\n", floats[i]);
        count++;
    }
    printf("\ncount = %i; total = %.2f\n", count, total);
    average = total / count;
    printf ("\nAverage = %.1f\n", average);
    printf ("\nArray:\n[");
    for (int i = 0; i < 9; i++) {
        printf ("%.2f, ", floats[i]);
    }
    printf("%.2f]\n", floats[9]);
}
