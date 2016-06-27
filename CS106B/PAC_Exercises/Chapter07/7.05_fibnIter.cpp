/*  CS106B - Programming Abstractions
 *  Programming Abstractions in C++ (2012)
 *-------------------------------------------------<*>
 *  Wayne H. Noxchi - 7.05 fibnIter
 *-------------------------------------------------<*>
 * 08-Jun-2016 23:58 - 09-Jun-2016 00:21
*/

// Write an iterative implementation of the function fib(n).

#include <iostream>
#include <string>
using namespace std;

/* function */
int fibnIter(int n) {
    int fib1 = 1, fib2 = 0, total = 0;
    if (n == 0) total = 1;
    for (int i = 0; i < n; i++) {
        total = fib1 + fib2;
        fib2 = fib1;
        fib1 = total;
    }
    return total;
}

/* testing */
int main() {
    int n = -1;
    cout << "fibn(n):\n";
    while (n) {
        cout << "n: ";
        cin >> n;
        if (n == -1) break;
        cout << "fibn(" << n << "): " << fibnIter(n) << endl;
    }
}

// 1 - 1 - 2 - 3 - 5 - 8 - 13 - 21 - ...
// total(n) = fib(n - 1) + fib(n - 2)
// total    =   fib1     + fib2
