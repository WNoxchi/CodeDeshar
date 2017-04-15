/*  CS50x - Intro to CS
 *  Programming in C
 *-----------------------------------------------------<>
 *  13.05 macroShift.c
 *-----------------------------------------------------<>
 *  Wayne Noxchi - 05-Jun-2016 21:37 - 05-Jun-2016 22:02
 */

/* write a SHIFT macro that does the same thing as Program 12.3 shift */

# define SHIFT(val, n)  ( (n) > 0 ? ((val) << (n)) : ((val) >> (-n)) )

#include <stdio.h>

int main(void) {
    unsigned int w1 = 0177777u, w2 = 0444u;
    // unsigned int SHIFT(unsigned int value, int n);

    printf ("%o\t%o\n", SHIFT(w1, 5), w1 << 5);
    printf ("%o\t%o\n", SHIFT(w1, -6), w1 >> 6);
    printf ("%o\t%o\n", SHIFT(w2, 0), w2 >> 0);
    printf ("%o\n", SHIFT(SHIFT(w1, -3), 3));

    return 0;
}

/* Program 12.3
    #include <stdio.h>
    // Function to shift an unsigned int left if
    // the count is positive, and right if negative

    unsigned int shift (unsigned int value, int n)
    {
        if ( n > 0 )    // left shuft
            value <<= n;
        else            // right shuft
            value >>= -n;

        return value;
    }
 */

// author's soln:
// // #define SHIFT(value, n)  (((n) > 0) ? ((value) << (n))  \
// //                                     : ((value) >> -(n)))
