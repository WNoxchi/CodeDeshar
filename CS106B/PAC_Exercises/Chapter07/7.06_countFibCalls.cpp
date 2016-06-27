/*  CS106B - Programming Abstractions
 *  Programming Abstractions in C++ (2012)
 *-------------------------------------------------<*>
 *  Wayne H. Noxchi - 7.06 count Fib Calls
 *-------------------------------------------------<*>
 * 09-Jun-2016 00:36 - 09-Jun-2016 01:01|01:52 - 02:45
*/

/*  For each of the two recursive implementations of the function fib(n)
presented in this chapter, write a recursive function (you can call these
countFib1 and countFib2 for the two algorithms) that counts the number of
function calls made during the evaluation of the corresponding Fibonacci
calculation. Write a main program that uses these functions to display a table
showing the number of calls made by each algorithm for various values of n,   */

#include <iostream>
// #include <string>
#include <iomanip>
using namespace std;

/* functions from book */
int additiveSequence(int n, int t0, int t1, int* count) {
    (*count)++;
    if (n == 0) return t0;
    if (n == 1) return t1;
    return additiveSequence(n - 1, t1, t0 + t1, count);
}
int fibAdditv(int n, int* count) {
    (*count)++;
    return additiveSequence(n, 0, 1, count);
}

int fib(int n, int* count) {
    if (n < 2) {
        (*count)++;
        return n;
    } else {
        return fib(n - 1, count) + fib(n - 2, count);
    }
}

/* counter function */
int countFib1(int n) {
    int fibCalls = 0;
    fib(n, &fibCalls);
    return fibCalls;
}
/* (additive) counter function */
int countFib2(int n) {
    int fibCalls = 0;
    fibAdditv(n, &fibCalls);
    return fibCalls;
}

/* testing */
int main() {
    cout << "This program counts the number of calls made by the two "\
            "algorithms used to compute the Fibonacci sequence.\n\n";
    cout << "  n   fib1  fib2(adv)\n"\
            " ---  ----  ---------\n";
    for (int i = 0; i < 25; i++) {
        cout << setw(3) << i << setw(6) << countFib1(i) << setw(6) << countFib2(i) << endl;
    }
}

// First time using < setw() > yaaay
// used this guy to get a pointer on pointers:
// https://github.com/mtharrison/cs106b/blob/master/ch5_recursion/ex5.c
