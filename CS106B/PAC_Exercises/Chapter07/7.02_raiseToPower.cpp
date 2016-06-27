/*  CS106B - Programming Abstractions
 *  Programming Abstractions in C++ (2012)
 *-------------------------------------------------<*>
 *  Wayne H. Noxchi - 7.02 Raise to Power
 *-------------------------------------------------<*>
 * 08-Jun-2016 22:22 - 22:28
*/

/*
write a recursive implementation of a function
    int raiseToPower(int n, int k)
that calculates nk. The recursive insight that you need to solve this problem
is the mathematical property that
    n^k = { 1, if k = 0; n*n^(k-1) otherwise }
*/

#include <iostream>
#include <string>
using namespace std;

/* function */
int raiseToPower(int n, int k) {
    if (k == 0) {
        return 1;
    }
    else {
        return n * raiseToPower(n, k - 1);
    }
}

/* testing */
int main() {
    int n, k;
    cout << "Exponent calculation (n^k). n: ";
    cin >> n;
    cout << "k: ";
    cin >> k;
    cout << n << "^" << k << " = " << raiseToPower(n, k) << endl;
}
