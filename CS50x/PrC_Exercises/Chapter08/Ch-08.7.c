// CS50x - Intro to Computer Science
// Programming in C - Exercise 8.7
// WH Noxchi - 20-Mar-2016 04:56

// Write a func that raises an int to a pos int power.
// Return long int represnting x^n

#include <stdio.h>

long int x_to_the_n(int x, int n);

int main(void)
{
    int x, n;
    while (1 == 1) {
        printf ("x_to_the_n(x, n)\n----------------\n");
        printf ("x: ");
        scanf  ("%i", &x);
        printf ("\ny: ");
        scanf  ("%i", &n);
        printf ("\n%i^%i = %li\n\n", x, n, x_to_the_n(x, n));
    }


    return 0;
}

long int x_to_the_n(int x, int n) {
    long result = 1;

    while (n > 0) {
        result *= x;
        n--;
    }
    return result;
}
