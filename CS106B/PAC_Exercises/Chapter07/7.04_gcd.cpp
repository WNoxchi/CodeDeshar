/*  CS106B - Programming Abstractions
 *  Programming Abstractions in C++ (2012)
 *-------------------------------------------------<*>
 *  Wayne H. Noxchi - 7.04 gcd
 *-------------------------------------------------<*>
 * 08-Jun-2016 23:45 - 23:57
*/

/*
• If x is evenly divisible by y, then y is the greatest common divisor.
• Otherwise, the greatest common divisor of x and y is always equal to the
greatest common divisor of y and the remainder of x divided by y.
Use Euclid’s insight to write a recursive function gcd(x, y) that computes the
greatest common divisor of x and y.
*/

#include <iostream>
#include <string>
using namespace std;

/* function */
int gcd(int x, int y) {
    if (x % y == 0) {
        return y;
    }
    else {
        return gcd(y, x % y);
    }
}

/* testing */
int main() {
    // cout << 2 % 4;
    int x = -1, y;
    cout << "gcd(x, y):\n";
    while (x != 0) {
        cout << "x: ";
        cin >> x;
        if (x == 0) break;
        cout << "y: ";
        cin >> y;
        cout << "gcd(" << x << ", " << y << ") = " << gcd(x, y) << endl;
    }
}

/* NOTE:
    Hah, so, modulo operator: W = X % Y <==> W = remainder of X divided by Y
    had it backwards. Probably why my cipher program had issues.
*/

/* Terminal output:

Waynes-MBP:Chapter07 WayNoxchi$ ./7.04_gcd
2gcd(x, y):
x: 900
y: 60
gcd(900, 60) = 60
x: 900
y: 750
gcd(900, 750) = 150
x:

*/
