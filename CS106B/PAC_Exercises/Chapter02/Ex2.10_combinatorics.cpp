/*
* File: combinatorics.cpp
* ---------------------------
* This file implements the combinatorics.h interface
* ---------------------------
* Wayne H. Noxchi
* PAC++ ex 2.10
* CS106B Programming Abstractions
* 06-Mar-2016 04:35
*/

#include "combinatorics.h"

/*
 * Implementation notes: combine
 * -----------------------------
 * uses fact that C(n, k) = P(n, k)/(n - k) to calculate and return a
 * combination of 2 integers.
 * Mathematical definition: C(n, k) = n! / (k! * (n - k)!)
 */

int combine(int n, int k) {
    return permute(n, k) / (n - k);
}

/*
 * Implementation notes: permute
 * -----------------------------
 * calculates permutation of two integers using fact that
 * Mathematical definition: P(n, k) = n! / (n - k)!
 */

int permute(int n, int k)
{
    int x = 1;
    for (int i = 0; i < (n - k); i++)
    {
        x *= n - i;
    }
    return x;
}
