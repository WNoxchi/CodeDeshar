/*  CS106B - Programming Abstractions
 *  Programming Abstractions in C++ (2012)
 *-------------------------------------------------<*>
 *  Wayne H. Noxchi - 7.08 digital Root
 *-------------------------------------------------<*>
 * 09-Jun-2016 03:22 - 03:27
*/

/*
Write a function digitalRoot(n) that returns the digital root of its argument.
Although it is easy to implement digitalRoot using the digitSum function from
exercise 6 and a while loop, part of the challenge of this problem is to
write the function recursively without using any explicit loop constructs.
*/

#include <iostream>
#include <iomanip>
using namespace std;

/* protototo */
int digitSum(int t);

/* function */
int digitalRoot(int n) {
    if (n <= 9) {
        return n;
    }
    else {
        return digitalRoot(digitSum(n));    // thanks to SICP I LOVE this Inception shit
    }
}
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
    cout << "This program will test a digital-rooting function by running through"\
            " a few numbers.\n";
    for (int i = 0; i < 10; i++) {
        if (t % 10 >= 5) {
            t += 3;
            cout << setw(3) << "∆R(" << t << ") = " << " " << digitalRoot(t) << endl;
        } else {
            t *= 4;
            cout << setw(3) << "∆R(" << t << ") = " << " " << digitalRoot(t) << endl;
        }
    }
}

/*  Terminal:

Waynes-MBP:Chapter07 WayNoxchi$ ./7.08_digitalRoot
This program will test a digital-rooting function by running through a few numbers.
∆R(4) =  4
∆R(16) =  7
∆R(19) =  1
∆R(22) =  4
∆R(88) =  7
∆R(91) =  1
∆R(364) =  4
∆R(1456) =  7
∆R(1459) =  1
∆R(1462) =  4
Waynes-MBP:Chapter07 WayNoxchi$

*/
