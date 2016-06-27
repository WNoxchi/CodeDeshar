/*  CS106B - Programming Abstractions
 *  Programming Abstractions in C++ (2012)
 *-------------------------------------------------<*>
 *  Wayne H. Noxchi - 7.09 numComRecurs
 *-------------------------------------------------<*>
 * 09-Jun-2016 03:59 - 09-Jun-2016 04:08
*/

// ...write a recursive implementation of the c(n, k) function that uses no
// loops, no multiplication, and no calls to fact.

#include <iostream>
#include <iomanip>
using namespace std;

/* function */
int numComRecurs(int n, int k) {
    if (n == k || k == 0) {
        return 1;
    }
    else {
        return numComRecurs(n - 1, k - 1) + numComRecurs(n - 1, k);
    }
}

/* testing */
int main() {
    int n = 1, k;
    cout << "Test for a recursive numeric combination function.\nReturns value of coordinate of Pascal's triangle\n";
    while (n) {
        cout << "n: ";
        cin >> n;
        cout << "k: ";
        cin >> k;
        if (k > n) break;
        cout << "c(" << n << ", " << k << ") = " << numComRecurs(n, k) << endl;
    }
}


//                 c(0, 0)
//             c(1, 0) c(1, 1)
//         c(2, 0) c(2, 1) c(2, 2)
//     c(3, 0) c(3, 1) c(3, 2) c(3, 3)
// c(4, 0) c(4, 1) c(4, 2) c(4, 3) c(4, 4)

/* Terminal:

Test for a recursive numeric combination function.
Returns value of coordinate of Pascal's triangle
n: 2
k: 1
c(2, 1) = 2
n: 6
k: 2
c(6, 2) = 15
n: 0
k: 0
c(0, 0) = 1
Waynes-MBP:Chapter07 WayNoxchi$

*/
