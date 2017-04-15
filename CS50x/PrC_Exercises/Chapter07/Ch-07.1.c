// CS50x - Introduction to Computer Science
// Programming in C - Exercise 7.01

// Program 7.1 Working with an Array
// 01-Mar-2016 00:18
#include <stdio.h>

int main (void)
{
    int values[10];
    int index;

    values[0] = 197;
    values[2] = -100;
    values[5] = 350;
    values[3] = values[0] + values[5];
    values[9] =
    values[5] / 10;
    --values[2];

    for ( index = 0; index < 10; ++index )
         printf ("values[%i] = %i\n", index, values[index]);

    return 0;
}

// OUTPUT:
// values[0] = 197
// values[1] = 32767
// values[2] = -101
// values[3] = 547
// values[4] = 4195968
// values[5] = 350
// values[6] = 4195568
// values[7] = 0
// values[8] = 1907181344
// values[9] = 35

// Program 7.2 Demonstrating an Array of Counters
// 01-Mar-2016 00:29

#include <stdio.h>

int main (void)
{
    int ratingCounters[11], i, response;

    for ( i = 1; i <= 10; ++i )
         ratingCounters[i] = 0;

    printf ("Enter your responses\n");

    for ( i = 1; i <= 20; i++ ) {
         scanf ("%i", &response);

        if ( response < 1 || response > 10 )
             printf ("Bad response: %i\n", response);
        else
             ++ratingCounters[response];
    }

    printf ("\n\nRating   Number of Responses\n");
    printf ("------ -------------------\n");

    for ( i = 1; i <= 10; ++i )
         printf ("%4i %14i\n", i, ratingCounters[i]);

    return 0;
}

// INPUT/OUTPUT:
// Enter your responses
// 5
// 5
// 1
// 7
// 4
// 10
// 5
// 5
// 6
// 8
// 9
// 9
// 9
// 9
// 9
// 9
// 9
// 9
// 9
// 10
//
//
// Rating   Number of Responses
// ------   -------------------
//    1              1
//    2              0
//    3              0
//    4              1
//    5              4
//    6              1
//    7              1
//    8              1
//    9              9
//   10              2

// Program 7.3 Generating Fibonacci Numbers
// 01-Mar-2016 00:44
// Program to generate the first 15 Fibonacci numbers
#include <stdio.h>

int main (void)
{
    int Fibonacci[15], i;

    Fibonacci[0] = 0;   // by definition
    Fibonacci[1] = 1;   // ditto

    for ( i = 2; i < 15; ++i )
         Fibonacci[i] = Fibonacci[i-2] + Fibonacci[i-1];

    for ( i = 0; i < 15; ++i )
         printf ("%i\n", Fibonacci[i]);

    return 0;
}

// Program 7.4 Revising the Program to Generate Prime Numbers, Version 2
// 01-Mar-2016 00:50
#include <stdio.h>
#include <stdbool.h>

// Modified program to generate prime numbers

int main (void)
{
    int p, i, primes[50], primeIndex = 2;
    bool isPrime;

    primes[0] = 2;
    primes[1] = 3;

    for ( p = 5; p <= 50; p = p + 2 ) {
        isPrime = true;

        for ( i = 1; isPrime && p / primes[i] >= primes[i]; ++i )
             if ( p % primes[i] == 0 )
                  isPrime = false;

        if ( isPrime == true ) {
             primes[primeIndex] = p;
             ++primeIndex;
        }
    }

    for ( i = 0; i < primeIndex; ++i )
         printf("%i  ", primes[i]);

    printf("\n");

    return 0;
}

// OUTPUT:
// 2  3  5  7  11  13  17  19  23  29  31  37  41  43  47

// Program 7.5 Initializing Arrays
// 01-Mar-2016 00:57
#include <stdio.h>

int main (void)
{
    int array_values[10] = { 0, 1, 4, 9, 16 };
    int i;

    for ( i = 5; i < 10; ++i )
        array_values[i] = i * i;

    for ( i = 0; i < 10; ++i )
        printf ("array_values[%i] = %i\n", i, array_values[i]);

    return 0;
}

// OUTPUT:
// array_values[0] = 0
// array_values[1] = 1
// array_values[2] = 4
// array_values[3] = 9
// array_values[4] = 16
// array_values[5] = 25
// array_values[6] = 36
// array_values[7] = 49
// array_values[8] = 64
// array_values[9] = 81

// Program 7.6 Introducing Character Arrays
// 01-Mar-2016 01:00
#include <stdio.h>

int main (void)
{
    char word[] = { 'H', 'e', 'l', 'l', 'o', '!' };
    int i;

    for ( i = 0; i < 6; ++i )
         printf ("%c", word[i]);

    printf ("\n");


    return 0;
}

// OUTPUT:
// Hello!

// Program 7.7 Converting a Positive Integer to Another Base
// 01-Mar-2016 01:03

#include <stdio.h>

int main (void)
{
    const char baseDigits[16] = {
            '0', '1', '2', '3', '4', '5', '6', '7',
            '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
    int        convertedNumber[64];
    long int   numberToConvert;
    int        nextDigit, base, index = 0;

    // get the number and the base

    printf ("Number to be converted? ");
    scanf ("%ld", &numberToConvert);
    printf ("Base? ");
    scanf ("%i", &base);

    // convert to the indicated base

    do {
        convertedNumber[index] = numberToConvert % base;
        ++index;
        numberToConvert = numberToConvert / base;
    }
    while ( numberToConvert != 0 );


    // display the results in reverse order:

    printf ("converted number = ");

    for (--index; index >= 0; --index ) {
        nextDigit = convertedNumber[index];
        printf ("%c", baseDigits[nextDigit]);
    }

    printf ("\n");
    return 0;
}

// OUTPUT:
// Number to be converted? 10
// Base? 2
// converted number = 1010
//
// Number to be converted? 128362
// Base? 16
// converted number = 1F56A

// Program 7.8 Generating FIbonacci Numbers Using Variable-Length Arrays
// 01-Mar-2016 01:13

#include <stdio.h>

int main (void)
{
    int i, numFibs;

    printf ("How many Fibonacci numbers do you want (bewteen 1 and 75)? ");
    scanf ("%i", &numFibs);

    if (numFibs < 1 || numFibs > 75) {
        printf ("Bad number, sorry!\n");
        return 1;
    }
    unsigned long long int  Fibonacci[numFibs];

    Fibonacci[0] = 0;   // by definition
    Fibonacci[1] = 1;   // ditto

    for ( i = 2; i < numFibs; ++i )
         Fibonacci[i] = Fibonacci[i-2] + Fibonacci[i-1];

    for ( i = 0; i < numFibs; ++i )
         printf ("%llu  ", Fibonacci[i]);

    printf ("\n");

    return 0;
}

// OUTPUT:
// How many Fibonacci numbers do you want (bewteen 1 and 75)? 50
// 0  1  1  2  3  5  8  13  21  34  55  89  144  233  377  610  987  1597  2584  4181  6765  10946  17711  28657  46368  75025  121393  196418  317811  514229  832040  1346269  2178309  3524578  5702887  9227465  14930352  24157817  39088169  63245986  102334155  165580141  267914296  433494437  701408733  1134903170  1836311903  2971215073  4807526976  7778742049
