// CS50x - Intro to Computer Science
// Programming in C - Exercise 8.8
// WH Noxchi - 20-Mar-2016 05:17

// Write a program to find quadratic roots given a, b, c

#include <stdio.h>

const float epsilon = .00001;

void quad(float a, float b, float c);
float squareRoot(float x, float eps);
float absoluteValue(float x);

int main(void)
{
    float a, b, c;
    printf("\n   Copyright WNoxchi 2016, Daymoxk\n");
    printf("-------------------------------------\n");
    printf("QuadRoots: {x1,x2}: ax^2 + bx + c = 0\n");
    printf("a: ");
    scanf("%f", &a);
    printf("\nb: ");
    scanf("%f", &b);
    printf("\nc: ");
    scanf("%f", &c);
    printf("\n");
    quad(a, b, c);

    return 0;
}

void quad(float a, float b, float c) {
    float hiroot, loroot;
    float discr = (b*b) - 4 * a * c;
    if (discr < 0.0)
        printf("\nImaginary Roots\n");
    else
        hiroot = -b + discr / (2 * a);
        loroot = -b - discr / (2 * a);
        printf("\nRoots are: x1 = %f  |  x2 = %f\n", hiroot, loroot);
}

float absoluteValue (float x)
{
    if (x < 0)
        x = -x;
    return (x);
}

float squareRoot (float x, float eps)
{
    float guess = 1.0;

    while (absoluteValue ( (guess * guess) / x - 1) >= epsilon) {
        guess = (x / guess + guess) / 2.0;
        printf ("%f\n", guess);
    }

    return guess;
}
