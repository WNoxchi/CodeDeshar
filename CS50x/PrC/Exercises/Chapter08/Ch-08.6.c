// CS50x - Intro to Computer Science
// Programming in C - Exercise 8.6
// WH Noxchi - 20-Mar-2016 04:53

// Mod Program 8.8 st squareRoot func accepts a double & returns double.

#include <stdio.h>

const double epsilon = .0000000001;

double absoluteValue (double x)
{
    if (x < 0)
        x = -x;
    return (x);
}


// // Function to compute the square root of a number

double squareRoot (double x, double eps)
{
    double       guess   = 1.0;

    while (absoluteValue ( (guess * guess) / x - 1) >= epsilon) {
        guess = (x / guess + guess) / 2.0;
        printf ("%f\n", guess);
    }

    return guess;
}


int main (void)
{
    printf ("squareRoot (2.0) = %f\n", squareRoot (2.0, epsilon));
    printf ("squareRoot (144.0) = %f\n", squareRoot (144.0, epsilon));
    printf ("squareRoot (17,500,000) = %f\n", squareRoot (17500000, epsilon));

    return 0;
}
