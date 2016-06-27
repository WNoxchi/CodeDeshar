/*  CS50x - Intro to CS
 *  Programming in C
 *-----------------------------------------------------<>
 *  13.08 macroIsDigit.c
 *-----------------------------------------------------<>
 *  Wayne Noxchi - 05-Jun-2016 22:27 - 05-Jun-2016 22:33
 */

/*  Write a macro IS_DIGIT that gives a nonzero value if a character is a
 *  digit '0' through '9'. Use this macro in the definition of another
 *  macro IS_SPECIAL, which gives a nonzero result if a character is a
 *  special character; that is, not alpha- betic and not a digit. Be certain
 *  to use the IS_ALPHABETIC macro developed in exercise 7.                 */

# define IS_UPPER_CASE(x)  ((x - 'A' >= 0 && x - 'A' <= 25) ? 1 : 0)
# define IS_LOWER_CASE(x)  ( ((x) >= 'a') && ((x) <= 'z') )
# define IS_ALPHABETIC(x)  ((IS_UPPER_CASE(x) == 1 || IS_LOWER_CASE(x) == 1) ? 1 : 0)

# define IS_DIGIT(x)       ((x - '0' >= 0 && x - '0' <= 9) ? 1 : 0)
# define IS_SPECIAL(x)     ((IS_ALPHABETIC(x) == 0 && IS_DIGIT(x) == 0) ? 1 : 0)

#include <stdio.h>

int main() {
    char a1 = 'A';
    char a2 = 'a';
    char z1 = 'Z';
    char z2 = 'z';
    char x  = '4';
    char y  = '!';
    // char z  = 'Λ';
    // char w  = 'ლ';
    // lambda & lasi apparently don't work in basic ASCII/C

    printf("%i\n", IS_SPECIAL(a1));
    printf("%i\n", IS_SPECIAL(a2));
    printf("%i\n", IS_SPECIAL(z1));
    printf("%i\n", IS_SPECIAL(z2));
    printf("%i\n", IS_SPECIAL(x));
    printf("%i\n", IS_SPECIAL(y));
    // printf("%i\n", IS_SPECIAL(z));
    // printf("%i\n", IS_SPECIAL(w));

    return 0;
}

/*
Waynes-MBP:Chapter13 WayNoxchi$ ./13.08_macroIsDigit
0
0
0
0
0
1
Waynes-MBP:Chapter13 WayNoxchi$
*/
