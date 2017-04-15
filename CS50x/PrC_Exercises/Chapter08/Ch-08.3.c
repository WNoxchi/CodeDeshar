// CS50x - Intro to Computer Science
// Programming in C - Exercise 8.3
// WH Noxchi - 20-Mar-2016 04:42

// Modify Program 8.8 st the val of epsilon is passed as an arg to func.

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

    while (absoluteValue (guess * guess - x) >= epsilon)
        guess = (x / guess + guess) / 2.0;

    return guess;
}


int main (void)
{
    printf ("squareRoot (2.0) = %f\n", squareRoot (2.0, epsilon));
    printf ("squareRoot (144.0) = %f\n", squareRoot (144.0, epsilon));
    printf ("squareRoot (17.5) = %f\n", squareRoot (17.5, epsilon));

    return 0;
}
