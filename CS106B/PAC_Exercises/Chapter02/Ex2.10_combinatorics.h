/*
* File: combinatorics.h
* ---------------------------
* This interface exports functions for combinations & permutations
* ---------------------------
* Wayne H. Noxchi
* PAC++ ex 2.10
* CS106B Programming Abstractions
* 06-Mar-2016 04:37
*/

#ifndef _combinatorics_h
#define _combinatorics_h

/*
 * Function: combine
 * Usage: int x = combine(n, k);
 * -----------------------------
 * Returns result of combination of integers n and k.
 * Aldashna, combine(5, 3) returns 10
 */

int combine(int n, int k);

/*
 * Function: permute
 * Usage: int x = permute(n, k);
 * -----------------------------
 * Returns result of combination of integers n and k.
 * Aldashna, combine(5, 3) returns 10
 */

int permute(int n, int k);

#endif
