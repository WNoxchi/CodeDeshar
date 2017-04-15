/*  CS50x - Intro to CS
 *  Programming in C
 *-----------------------------------------------------<>
 *  13.04 maxMacroTest.c
 *-----------------------------------------------------<>
 *  Wayne Noxchi - 05-Jun-2016 21:15 - 05-Jun-2016 21:20
 */

/*  Define a macro that returns the max of 3 numbers */

# define MAX(w, x, y)  ((w) > (((x) < (y) ? (x) : (y))) ? (w) : (((x) > (y) ? (x) : (y))))

#include <stdio.h>

int main(void) {
    int w = 52, x = 50, y = 51;
    printf("MAX(%i, %i, %i): %i\n", w, x, y, MAX(w, x, y));
    return 0;
}

// int max (int w, int x, int y) {
//     if (w < x)
//         if (w < y)
//             return w
//         else
//             return y
//     if (x < y)
//         return x
//     else
//         return y
// }

/* this is hell to understand so follow:

Compare 2:     MAX(x, y)    = ( (x) > (y) ? (x) : (y) )
Compare 3:     MAX(w, x, y) = ( (w) > (MAX(x,y)) ? (w) : (MAX(x,y)) )
                            = ( (w) > ( ( (x) > (y) ? (x) : (y) ) ) ? (w) : ( ( (x) > (y) ? (x) : (y) ) ) )
                            = ( (w) > (
                                        ( (x) > (y) ? (x) : (y) )
                                      ) ? (w) :
                                        ( ( (x) > (y) ? (x) : (y) ) )
                              )
 */
