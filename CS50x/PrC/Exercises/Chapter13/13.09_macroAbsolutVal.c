/*  CS50x - Intro to CS
 *  Programming in C
 *-----------------------------------------------------<>
 *  13.09 macroAbsolutVal.c
 *-----------------------------------------------------<>
 *  Wayne Noxchi - 05-Jun-2016 22:41 - 05-Jun-2016 22:45
 */

/*  Write a macro ABSOLUTE_VALUE that computes the absolute value of its
 *  argument. Make certain that an expression such as
 *  ABSOLUTE_VALUE (x + delta)       is properly evaluated by the macro.    */

# define ABSOLUTE_VALUE(x)      ((x) >= 0 ? (x) : (-(x)))

#include <stdio.h>

int main() {
    int x = 999;

    printf("%i\n", ABSOLUTE_VALUE(x));
    printf("%i\n", ABSOLUTE_VALUE(25 - 26));

    return 0;
}

/*
Waynes-MBP:Chapter13 WayNoxchi$ ./13.09_macroAbsolutVal
999
1
Waynes-MBP:Chapter13 WayNoxchi$
*/
