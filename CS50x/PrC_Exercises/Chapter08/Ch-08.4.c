// CS50x - Intro to Computer Science
// Programming in C - Exercise 8.4
// WH Noxchi - 20-Mar-2016 04:44

// Mod Program 8.8 st val of guess is printed each time thru while loop.

#include <stdio.h>

const float epsilon = .00001;

float absoluteValue (float x)
{
    if (x < 0)
        x = -x;
    return (x);
}


// // Function to compute the square root of a number

float squareRoot (float x, float eps)
{
    float       guess   = 1.0;

    while (absoluteValue (guess * guess - x) >= epsilon) {
        guess = (x / guess + guess) / 2.0;
        printf ("%f\n", guess);
    }

    return guess;
}


int main (void)
{
    printf ("squareRoot (2.0) = %f\n", squareRoot (2.0, epsilon));
    printf ("squareRoot (144.0) = %f\n", squareRoot (144.0, epsilon));
    printf ("squareRoot (17.5) = %f\n", squareRoot (17.5, epsilon));

    return 0;
}
