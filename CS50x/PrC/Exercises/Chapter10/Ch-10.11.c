// CS50x - Intro to Computer Science
// Programming in C - Exercise 10.11
// WH Noxchi - 28-Mar-2016 23:55 - 29-Mar-2016 00:04

/** Extend strToInt from Program 10.11 st if the first char of the string
    is a minus sign, the value tht follows is taken as a negative number. **/

#include <stdio.h>

int strToInt (const char string[])
{
    int i, intValue, result = 0;

    for ( i = 1; string[i] >= '0' && string[i] <= '9'; ++i )
    {
        intValue = string[i] - '0';
        result = result * 10 + intValue;
    }
    if (string[0] == '-') {
        result *= -1;
    }

    return result;
}

int main (void)
{

    printf ("%i\n", strToInt("245"));
    printf ("%i\n", strToInt("100") + 25);
    printf ("%i\n", strToInt("13x5"));

    printf("%i\n", strToInt("-56"));

    return 0;
}

/**  Answer  **/
// #include <stdbool.h>
//
// int  strToInt (const char  string[])
// {
//     int  i = 0, intValue, result = 0;
//     int  negative = false;
//
//     // test for leading minus sign
//
//     if ( string[0] == '-') {
//         negative = true;
//         i = 1;
//     }
//
//     while ( string[i] >= '0' && string[i] <= '9' ) {
//         intValue = string[i] - '0';
//         result = result * 10 + intValue;
//         ++i;
//     }
//
//     if ( negative )
//         result  = -result;
//
//     return result;
// }
