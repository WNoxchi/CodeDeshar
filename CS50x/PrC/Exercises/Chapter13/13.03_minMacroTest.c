/*  CS50x - Intro to CS
 *  Programming in C
 *  --------------------
 *  13.03 minMacroTest.c
 *  --------------------
 *  Wayne Noxchi
 *  05-Jun-2016 20:47 - 21:12
 */

# define MIN(x, y)  ((x) < (y) ? (x) : (y))

#include <stdio.h>

int main(void) {
    int x = 50, y = 51;
    printf("MIN(%i, %i): %i\n", x, y, MIN(x, y));
    return 0;
}
