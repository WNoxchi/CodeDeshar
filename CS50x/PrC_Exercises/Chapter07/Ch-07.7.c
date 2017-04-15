// CS50x - Introduction to Computer Science
// Programming in C - Exercise 7.7
// WH Noxchi - 19-Mar-2016 03:18

// Write a prg tht implmnts the Sieve of Erastosthenes to find Primes.
// Find all primes up to 150.

#include <stdio.h>

const int n = 150;
int main(void)
{
    int P[n];
    for (int i = 0; i < n; i++) {
        P[i] = i;
    }
    for (int i = 2; i < n; i++) {
        P[i] = 0;
    }
    int i = 2;
    while (i <= n) {
        // if (i > n) break;
        if (P[i] == 0) {
            printf("%i is Prime.\n", i);
        }
        for (int j = 0; j < (n / i); j++) {
            if ( (i * j) <= n ) {
                P[i*j] = 1;
            }
        }
        i++;
    }

}

// OSX TERMINAL OUTPUT:

// Waynes-MacBook-Pro:Chapter07 WayNoxchi$ make Ch-07.7
// cc     Ch-07.7.c   -o Ch-07.7
// Waynes-MacBook-Pro:Chapter07 WayNoxchi$ ./Ch-07.7
// 2 is Prime.
// 3 is Prime.
// 5 is Prime.
// 7 is Prime.
// 11 is Prime.
// 13 is Prime.
// 17 is Prime.
// 19 is Prime.
// 23 is Prime.
// 29 is Prime.
// 31 is Prime.
// 37 is Prime.
// 41 is Prime.
// 43 is Prime.
// 47 is Prime.
// 53 is Prime.
// 59 is Prime.
// 61 is Prime.
// 67 is Prime.
// 71 is Prime.
// 73 is Prime.
// 79 is Prime.
// 83 is Prime.
// 89 is Prime.
// 97 is Prime.
// 101 is Prime.
// 103 is Prime.
// 107 is Prime.
// 109 is Prime.
// 113 is Prime.
// 127 is Prime.
// 131 is Prime.
// 137 is Prime.
// 139 is Prime.
// 143 is Prime.
// 149 is Prime.
// Waynes-MacBook-Pro:Chapter07 WayNoxchi$
