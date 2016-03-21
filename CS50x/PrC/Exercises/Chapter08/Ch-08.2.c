// CS50x - Intro to Computer Science
// Programming in C - Exercise 8.1
// WH Noxchi - 19-Mar-2016 03:53

// Type in and run the 16 programs in this chapter. compare output to that in text.


// Program 8.1 Writing a Function in C
// -----------------------------------
#include <stdio.h>

void printMessage (void)
{
    printf ("Programming is fun.\n");
}

int main (void)
{
    printMessage ();

    return 0;
}
// -----------------------------------
// TEXTBK OUTPUT:
// Programming is fun.

// TERMINAL OUTPUT:
// Programming is fun.


// Program 8.2 Calling Functions
// -----------------------------
#include <stdio.h>

void printMessage (void)
{
    printf ("Programming is fun.\n");
}

int main (void)
{
    printMessage ();
    printMessage ();

    return 0;
}
// -----------------------------
// TEXTBK OUTPUT:
// Programming is fun.
// Programming is fun.
//
// TERMINAL OUTPUT:
// Programming is fun.
// Programming is fun.


// Program 8.3 More on Calling Functions
// -------------------------------------
#include <stdio.h>

void printMessage (void)
{
    printf ("Programming is fun.\n");
}

int main (void)
{
    int i;

    for (i = 1; i <= 5; ++i)
        printMessage();

    return 0;
}
// -------------------------------------
// TEXTBK OUT:
// Programming is fun.
// Programming is fun.
// Programming is fun.
// Programming is fun.
// Programming is fun.
//
// TERMINAL OUT:
// <SAME>


// Program 8.4 Calculating the nth Triangular Number
// -------------------------------------------------
// Function to calculate the nth triangular number

#include <stdio.h>

void calculateTriangularNumber (int n)
{
    int i, triangularNumber = 0;

    for (i = 1; i <= n; ++i)
        triangularNumber += i;

    printf ("Triangular number %i is %i\n", n, triangularNumber);
}

int main (void)
{
    calculateTriangularNumber (10);
    calculateTriangularNumber (20);
    calculateTriangularNumber (50);

    return 0;
}
// -------------------------------------------------
// TEXTBK OUT:
// Triangular number 10 is 55
// Triangular number 20 is 210
// Triangular number 50 is 1275

// TERMINAL OUT:
// <SAME>


// Program 8.5 Revising the Program to Find the Greatest Common Divisor
// --------------------------------------------------------------------
/* Function to find the greatest common divisor
        of two nonnegative integer values           */

#include <stdio.h>

void gcd (int u, int v)
{
    int temp;

    printf ("The gcd of %i and %i is ", u, v);

    while (v != 0) {
        temp = u % v;
        u = v;
        v = temp;
    }

    printf ("%i\n", u);
}

int main (void)
{
    gcd (150, 35);
    gcd (1026, 405);
    gcd(83, 240);

    return 0;
}
// --------------------------------------------------------------------
// TEXTBK OUT:
// The gcd of 150 and 35 is 5
// The gcd of 1026 and 405 is 27
// The gcd of 83 and 240 is 1

// TERMINAL OUT:
// <SAME>


// Program 8.6 Finding the Greatest Common Divisor and Returning the Results
// -------------------------------------------------------------------------
/* Function to find the greatest common divisor of two
    nonnegative integer values and to return the result.    */

#include <stdio.h>

int gcd (int u, int v)
{
    int temp;

    while (v != 0) {
        temp = u % v;
        u = v;
        v = temp;
    }

    return u;
}

int main (void)
{
    int result;

    result = gcd (150, 35);
    printf ("The gcd of 150 and 35 is %i\n", result);

    result = gcd (1026, 405);
    printf ("The gcd of 1026 and 405 is %i\n", result);

    printf ("The gcd of 83 and 240 is %i\n", gcd (83, 240));

    return 0;
}
// -------------------------------------------------------------------------
// TEXTBK OUT:
// The gcd of 150 and 35 is 5
// The gcd of 1026 and 405 is 27
// The gcd of 83 and 240 is 1
//
// TERMINAL OUT:
// <SAME>


// Program 8.7 Calculating the Absolute Value
// ------------------------------------------
// Function to calculate the absolute value

#include <stdio.h>

float absoluteValue (float x)
{
    if (x < 0)
        x = -x;

    return x;
}

int main (void)
{
    float f1 = -15.5, f2 = 20.0, f3 = -5.0;
    int   i1 = -716;
    float result;

    result = absoluteValue (f1);
    printf ("result = %.2f\n", result);
    printf ("f1 = %.2f\n", f1);

    result = absoluteValue (f2) + absoluteValue (f3);
    printf ("result = %.2f\n", result);

    result = absoluteValue ( (float) i1 );
    printf ("result = %.2f\n", result);

    result = absoluteValue (i1);
    printf ("result = %.2f\n", result);

    printf ("%.2f\n", absoluteValue (-6.0) / 4 );

    return 0;
}
// ----------------------------------------
// TEXTBK OUT:
// result = 15.50
// f1 = -15.50
// result = 25.00
// result = 716.00
// result = 716.00
// 1.50
//
// TERMINAL OUT:
// <SAME>


// Program 8.8 Calculating the Square Root of a Number
// ---------------------------------------------------
// Function to calculate the absolute value of a number

#include <stdio.h>

float absoluteValue (float x)
{
    if (x < 0)
        x = -x;
    return (x);
}


// // Function to compute the square root of a number

float squareRoot (float x)
{
    const float epsilon = .00001;
    float       guess   = 1.0;

    while (absoluteValue (guess * guess - x) >= epsilon)
        guess = (x / guess + guess) / 2.0;

    return guess;
}


int main (void)
{
    printf ("squareRoot (2.0) = %f\n", squareRoot (2.0));
    printf ("squareRoot (144.0) = %f\n", squareRoot (144.0));
    printf ("squareRoot (17.5) = %f\n", squareRoot (17.5));

    return 0;
}
// ---------------------------------------------------
// TEXTBK OUT:
// squareRoot (2.0) = 1.414216
// squareRoot (144.0) = 12.000000
// squareRoot (17.5) = 4.183300
//
// TERMINAL OUT:
// <SAME>


// Program 8.9 Finding the Minimum Value in an Array
// -------------------------------------------------
// Function to find the minumum value in an array

#include <stdio.h>

int minimum (int values[10])
{
    int minValue, i;

    minValue = values[0];

    for (i = 1; i < 10; ++i)
        if (values[i] < minValue)
            minValue = values[i];

    return minValue;
}

int main (void)
{
    int scores[10], i, minScore;
    int minimum (int values[10]);

    printf ("Enter 10 scores\n");

    for (i = 0; i < 10; ++i)
        scanf ("%i", &scores[i]);

    minScore = minimum (scores);
    printf ("\nMinumum score is %i\n", minScore);

    return 0;
}
// -------------------------------------------------
// TEXTBK OUT:
// Enter 10 scores
// 69
// 97
// 65
// 87
// 69
// 86
// 78
// 67
// 92
// 90
// Minimum score is 65

// TERMINAL OUT:
// <SAME>


// Program 8.10 Revising the Function to Find the Minimum Value in an Array
// ------------------------------------------------------------------------
// Function to find the minimum value in an array

#include <stdio.h>

int minimum (int values[], int numberOfElements)
{
    int minValue, i;

    minValue = values[0];

    for (i = 1; i < numberOfElements; ++i)
        if (values[i] < minValue)
            minValue = values[i];

    return minValue;
}

int main (void)
{
    int array1[5] = { 157, -28, -37, 26, 10 };
    int array2[7] = { 12, 45, 1, 10, 5, 3, 22 };
    int minimum (int values[], int numberOfElements);

    printf ("array1 minimum: %i\n", minimum (array1, 5));
    printf ("array2 minimum: %i\n", minimum (array2, 7));

    return 0;
}
// ------------------------------------------------------------------------
// TEXTBK OUT:
// array1 minimum: -37
// array2 minimum: 1

// TERMINAL OUT:
// <SAME>


// Program 8.11 Changing Array Elements in Functions
// -------------------------------------------------
#include <stdio.h>

void multiplyBy2 (float array[], int n)
{
    int i;

    for (i = 0; i < n; ++i)
        array[i] *= 2;
}

int main (void)
{
    float floatVals[4] = { 1.2f, -3.7f, 6.2f, 8.55f };
    int i;
    void multiplyBy2 (float array[], int n);

    multiplyBy2 (floatVals, 4);

    for (i = 0; i < 4; ++i)
        printf ("%.2f  ", floatVals[i]);

    printf ("\n");

    return 0;
}
// -------------------------------------------------
// TEXTBK OUT:
// 2.40   -7.40   12.40   17.10

// TERMINAL OUT:
// <SAME>


// Program 8.12 Sorting an Array of Integers into Ascending Order
// --------------------------------------------------------------
// Program to sort an array of integers into ascending order

#include <stdio.h>

void sort (int a[], int n)
{
    int i, j, temp;

    for (i = 0; i < n - 1; ++i)
        for (j = i + 1; j < n; ++j)
            if (a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
}

int main (void)
{
    int i;
    int array[16] = { 34, -5, 6, 0, 12, 100, 56, 22,
                      44, -3, -9, 12, 17, 22, 6, 11 };
    void sort (int a[], int n);

    printf ("The array before the sort:\n");

    for (i = 0; i < 16; ++i)
        printf ("%i ", array[i]);

    sort (array, 16);

    printf ("\n\nThe array after the sort:\n");

    for (i = 0; i < 16; ++i)
        printf ("%i ", array[i]);

    printf ("\n");

    return 0;
}
// --------------------------------------------------------------
// TEXTBK OUT:
// he array before the sort:
// 34 -5 6 0 12 100 56 22 44 -3 -9 12 17 22 6 11
// The array after the sort:
// -9 -5 -3 0 6 6 11 12 12 17 22 22 34 44 56 100

// TERMINAL OUT:
// <SAME>


// Program 8.13 Using Multidimensional Arrays and Functions
// --------------------------------------------------------
#include <stdio.h>

int main (void)
{
    void scalarMultiply (int matrix[3][5], int scalar);
    void displayMatrix (int matrix[3][5]);
    int sampleMatrix[3][5] =
        {
            {  7, 16, 55, 13, 12 },
            { 12, 10, 52,  0,  7 },
            { -2,  1,  2,  4,  9 }
        };

    printf ("Original matrix:\n");
    displayMatrix (sampleMatrix);

    scalarMultiply (sampleMatrix, 2);

    printf ("\nMultiplied by 2:\n");
    displayMatrix (sampleMatrix);

    scalarMultiply (sampleMatrix, -1);

    printf ("\nThen multiplied by -1:\n");
    displayMatrix (sampleMatrix);

    return 0;
}

// // Function to multiply a 3 x 5 array by a scalar

void scalarMultiply (int matrix[3][5], int scalar)
{
    int row, column;

    for (row = 0; row < 3; ++row)
        for (column = 0; column < 5; ++column)
            matrix[row][column] *= scalar;
}

void displayMatrix (int matrix[3][5])
{
    int row, column;

    for (row = 0; row < 3; ++row) {
        for (column = 0; column < 5; ++column)
            printf ("%5i", matrix[row][column]);
            printf ("\n");
    }
}

// --------------------------------------------------------
// TEXTBK OUT:
// Original matrix:
// 7 16 55 13 12
// 12 10 52 0  7
// -2  1  2 4  9
// Multiplied by 2:
// 14 32 110 26 24
// 24 20 104  0 14
// -4  2   4  8 18
// Then multiplied by -1:
// -14 -32 -110 -26 -24
// -24 -20 -104  0  -14
//   4  -2   -4 -8  -18

// TERMINAL OUT:
// Waynes-MacBook-Pro:Chapter08 WayNoxchi$ ./Ch-08.1
// Original matrix:
//     7   16   55   13   12
//    12   10   52    0    7
//    -2    1    2    4    9
//
// Multiplied by 2:
//    14   32  110   26   24
//    24   20  104    0   14
//    -4    2    4    8   18
//
// Then multiplied by -1:
//   -14  -32 -110  -26  -24
//   -24  -20 -104    0  -14
//     4   -2   -4   -8  -18


// Program 8.13A Multidimensional Variable-Length Arrays
// -----------------------------------------------------
#include <stdio.h>

int main (void)
{
    void scalarMultiply (int nRows, int nCols,
                         int matrix[nRows][nCols], int scalar);
    void displayMatrix (int nRows, int nCols, int matrix[nRows][nCols]);
    int sampleMatrix[3][5] =
        {
            {  7, 16, 55, 13, 12 },
            { 12, 10, 52,  0,  7 },
            { -2,  1,  2,  4,  9 }
        };

    printf ("Original matrix:\n");
    displayMatrix (3, 5, sampleMatrix);

    scalarMultiply (3, 5, sampleMatrix, 2);
    printf ("\nMultiplied by 2:\n");
    displayMatrix (3, 5, sampleMatrix);

    scalarMultiply (3, 5, sampleMatrix, -1);
    printf ("\nThen multiplied by -1:\n");
    displayMatrix (3, 5, sampleMatrix);

    return 0;
}

// // Function to multiply a matrix by a scalar

void scalarMultiply (int nRows, int nCols,
                     int matrix[nRows][nCols], int scalar)
{
    int row, column;

    for (row = 0; row < nRows; ++row)
        for (column = 0; column < nCols; ++column)
            matrix[row][column] *= scalar;
}

void displayMatrix (int nRows, int nCols, int matrix[nRows][nCols])
{
    int row, column;

    for (row = 0; row < nRows; ++row) {
        for (column = 0; column < nCols; ++column)
            printf ("%5i", matrix[row][column]);

        printf ("\n");
    }
}
// -----------------------------------------------------
// TEXTBK OUT:
// Original matrix:
// 7  16 55 13 12
// 12 10 52  0  7
// -2  1  2  4  9
// Multiplied by 2:
// 14 32 110 26 24
// 24 20 104  0 14
// -4  2   4  8 18
// Then multiplied by -1:
// -14 -32 -110 -26 -24
// -24 -20 -104   0 -14
//   4  -2   -4  -8 -18
//
// // TERMINAL OUT:
// Waynes-MacBook-Pro:Chapter08 WayNoxchi$ ./Ch-08.1
// Original matrix:
//     7   16   55   13   12
//    12   10   52    0    7
//    -2    1    2    4    9
//
// Multiplied by 2:
//    14   32  110   26   24
//    24   20  104    0   14
//    -4    2    4    8   18
//
// Then multiplied by -1:
//   -14  -32 -110  -26  -24
//   -24  -20 -104    0  -14
//     4   -2   -4   -8  -18


// Program 8.14 Converting a Positve Integer to Another Base
// ---------------------------------------------------------
// Program to convert a positive integer to another base

#include <stdio.h>

int         convertedNumber[64];
long int    numberToConvert;
int         base;
int         digit = 0;

vo1id getNumberAndBase (void)
{
    printf ("Number to be converted? ");
    scanf ("%li", &numberToConvert);

    printf ("Base? ");
    scanf ("%i", &base);

    if ( base < 2 || base > 16 ) {
        printf ("Bad base - must be between 2 and 16\n");
        base = 10;
    }
}

void convertNumber (void)
{
    do {

        convertedNumber[digit] = numberToConvert % base;
        ++digit;
        numberToConvert /= base;
    }
    while (numberToConvert != 0);
}

void displayConvertedNumber (void)
{
    const char baseDigits[16] =
            { '0', '1', '2', '3', '4', '5', '6', '7',
              '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
    int nextDigit;

    printf ("Converted number = ");

    for (--digit; digit >= 0; --digit) {
        nextDigit = convertedNumber[digit];
        printf ("%c", baseDigits[nextDigit]);
    }

    printf ("\n");
}

int main (void)
{
    void getNumberAndBase (void), convertNumber (void),
         displayConvertedNumber (void);

    getNumberAndBase ();
    convertNumber ();
    displayConvertedNumber ();

    return 0;
}
// ---------------------------------------------------------
// TEXTBK OUT:
// Number to be converted? 100 Base? 8
// Converted number = 144

// Number to be converted? 1983
// Base? 0
// Bad base - must be between 2 and 16 Converted number = 1983

// TERMINAL OUT:
// <SAME>


// Program 8.15 Illustrating Static and Automatic Variables
// --------------------------------------------------------
// Program to illustrate static and automatic variables
#include <stdio.h>

void auto_static (void)
{
    int         autoVar = 1;
    static int  staticVar = 1;

    printf ("automatic = %i, static = %i\n", autoVar, staticVar);

    ++autoVar;
    ++staticVar;
}


int main (void)
{
    int i;
    void auto_static (void);

    for (i = 0; i < 5; ++i)
        auto_static ();

    return 0;
}
// --------------------------------------------------------
// TEXTBK OUT:
// automatic = 1, static = 1
// automatic = 1, static = 2
// automatic = 1, static = 3
// automatic = 1, static = 4
// automatic = 1, static = 5

// TERMINAL OUT:
// <SAME>


// Program 8.16 Calculating Factorials Recursively
// -----------------------------------------------
#include <stdio.h>

int main (void)
{
    unsigned int j;
    unsigned long int factorial (unsigned int n);

    for (j = 0; j < 11; ++j)
        printf ("%2u! = %lu\n", j, factorial (j));

    return 0;
}

// Recursive function to calculate the factorial of a positive integer
unsigned long int factorial (unsigned int n)
{
    unsigned long int result;

    if (n == 0)
        result = 1;
    else
        result = n * factorial (n - 1);

    return result;
}
// -----------------------------------------------
// TEXTBK OUT:
// 0! = 1
// 1! = 1
// 2! = 2
// 3! = 6
// 4! = 24
// 5! = 120
// 6! = 720
// 7! = 5040
// 8! = 40320
// 9! = 362880
// 10! = 3628800

// TERMINAL OUT:
// <SAME>
