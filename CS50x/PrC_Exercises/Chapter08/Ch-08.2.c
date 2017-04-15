// CS50x - Intro to Computer Science
// Programming in C - Exercise 8.2
// WH Noxchi - 20-Mar-2016 04:22

// Modify Program 8.4 st val of triangularNumber is returned by the function.
// Mod Prg 8.5 st it calls the new version of calculateTriangularNumber function.

#include <stdio.h>

int calculateTriangularNumber (int n)
{
    int i, triangularNumber = 0;

    for (i = 1; i <= n; ++i)
        triangularNumber += i;

    // printf ("Triangular number %i is %i\n", n, triangularNumber);
    return triangularNumber;
}

// int main (void)
// {
//     calculateTriangularNumber (10);
//     calculateTriangularNumber (20);
//     calculateTriangularNumber (50);
//
//     return 0;
// }


// Program 5.5 Using Nested for Loops (modified)
// #include <stdio.h>

int main (void)
{
    int n, number, triangularNumber, counter;

    for ( counter = 1; counter <= 5; ++counter ) {
        printf ("What triangular number do you want? ");
        scanf  ("%i", &number);

        triangularNumber = calculateTriangularNumber(number);

        printf ("Triangular number %i is %i\n\n", number, triangularNumber);
    }

    return 0;
}
