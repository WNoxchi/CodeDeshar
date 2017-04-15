/*  CS50x - Intro to CS
 *  Programming in C
 *-----------------------------------------------------<>
 *  13.06 macroIsUpper.c
 *-----------------------------------------------------<>
 *  Wayne Noxchi - 05-Jun-2016 22:05 - 05-Jun-2016 22:14
 */

/*  Write a macro IS_UPPER_CASE that gives a nonzero value if a character is
    an uppercase letter.        */

# define IS_UPPER_CASE(x)   ((x - 'A' >= 0 && x - 'A' <= 25) ? 1 : 0)

#include <stdio.h>

int main() {
    char a1 = 'A';
    char a2 = 'a';
    char z1 = 'Z';
    char z2 = 'z';

    printf("%i\n", IS_UPPER_CASE(a1));
    printf("%i\n", IS_UPPER_CASE(a2));
    printf("%i\n", IS_UPPER_CASE(z1));
    printf("%i\n", IS_UPPER_CASE(z2));

    return 0;
}

/* TERMINAL OUTPUT:

Waynes-MBP:Chapter13 WayNoxchi$ ./13.06_macroIsUpper
1
0
1
0
Waynes-MBP:Chapter13 WayNoxchi$

 */
