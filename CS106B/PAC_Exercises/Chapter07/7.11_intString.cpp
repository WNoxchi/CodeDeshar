/*  CS106B - Programming Abstractions
 *  Programming Abstractions in C++ (2012)
 *-------------------------------------------------<*>
 *  Wayne H. Noxchi - 7.11 integerToString
 *-------------------------------------------------<*>
 * 09-Jun-2016 17:05 - 17:15
*/

// The strlib.h library contains a function integerToString. Reimplement this
// function without using streams by exploiting the recursive decomposition of
// an integer outlined in exercise 7.

#include <iostream>
#include <string>
using namespace std;

/* function */
string integerToString(int n) {
    string s;
    if (n < 10) {
        return s += n + '0';
    }
    else {
        return integerToString(n/10) += integerToString(n % 10);
    }
}

/* testing */
int main()  {
    int n;
    cout << "Function: Integer to String. Enter number: ";
    cin >> n;
    cout << integerToString(n) << endl;
}

/* Terminal:

Function: Integer to String. Enter number: 43
43
Waynes-MBP:Chapter07 WayNoxchi$

*/
