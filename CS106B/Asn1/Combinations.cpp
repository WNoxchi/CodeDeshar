/*
 * File: Combinations.cpp
 * ----------------------
 * Name: Wayne H. Noxchi
 * UbuntuMATE - terminal
 * This file is the starter project for the recursive combinations problem.
 * Assignment 1 - Combinations
 * ----------------------
 * 04-Jun-2016 22:17 - 04-Jun-2016 23:00
 */

#include <iostream>
#include "console.h"
#include "simpio.h"
using namespace std;

/* combination function */
int c(int n, int k) {
    if (n < k) {
        return 0;
    }
    // if (n == 0 && k == 0) {
    if (n == k || k == 0) {
		// cout << "1:n(" << n << "):k(" << k << ")" << endl;
        return 1;
    }
    return ( c(n - 1, k - 1) + c(n - 1, k) );
}

/* implementation */
int main() {
    int n, k;
    cout << "Pascal Numeric Combination: C(n, k)\n-----------------------------------" << endl;
    cout << "n: ";
    cin >> n;
    cout << "k: ";
    cin >> k;
    cout << "C(" << n << ", " << k << ") = " << c(n, k) << endl;
    return 0;
}
