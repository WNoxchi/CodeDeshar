/*  CS106B - Programming Abstractions
 *  Programming Abstractions in C++ (2012)
 *-------------------------------------------------<*>
 *  Wayne H. Noxchi - 7.07 digit Sum
 *-------------------------------------------------<*>
 * 09-Jun-2016 03:07 - 03:15
*/

// Write a recursive function digitSum(n) that takes a nonnegative integer
// and returns the sum of its digits.

#include <iostream>
#include <iomanip>
using namespace std;

/* function */
int digitSum(int t) {
    if (t / 10 == 0) {
        return t;
    }
    else {
        return digitSum(t % 10) + digitSum(t/10);
    }
}

/* testing */
int main() {
    int t = 1;
    cout << "This program will test a digit-summing function by running through"\
            " a few numbers.\n";
    for (int i = 0; i < 10; i++) {
        if (t % 10 >= 5) {
            t += 3;
            cout << setw(3) << "∑(" << t << ") = " << " " << digitSum(t) << endl;
        } else {
            t *= 4;
            cout << setw(3) << "∑(" << t << ") = " << " " << digitSum(t) << endl;
        }
    }
}
