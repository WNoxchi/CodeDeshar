/*  CS106B - Programming Abstractions
 *  Programming Abstractions in C++ (2012)
 *  ----------------------------------------------
 *  Wayne H. Noxchi - 3.14 addCommas
 *  ----------------------------------------------
 *  08-Jun-2016 00:08 - 08-Jun-2016 00:52
*/

#include <iostream>
#include <string>
using namespace std;

/* function */
string addCommas(string digits) {
    string terah;
    int Count = digits.length(), X = Count % 3;
    for (int i = 0; i < X; i++) {
        terah += digits[i];
    }
    while (X < Count) {
        terah += ",";
        for (int i = 0; i < 3; i++) {
            terah += digits[X];
            X++;
        }
    }
    return terah;
}

/* testing */
int main() {
    string digits;
    while(true) {
        cout << "Enter a number: ";
        getline(cin, digits);
        if (digits == "") break;
        cout << addCommas(digits) << endl;
    }
}

/*  Pseudocode:

Count = length of Number.
X = Count Modulo 3.
Add first X indices of Number to Terah.

While X < Count:
    Add Comma to Terah.
    Do 3 times:
        Add index X of Count to Terah.
        Add 1 to X.

return Terah

//////////////

TERMINAL:

Waynes-MBP:Chapter03-2012 WayNoxchi$ make 3.14_addCommas
c++     3.14_addCommas.cpp   -o 3.14_addCommas
Waynes-MBP:Chapter03-2012 WayNoxchi$ ./3.14_addCommas
Enter a number: 9000
9,000
Enter a number: 90000
90,000
Enter a number: 9000000000000000
9,000,000,000,000,000
Enter a number:
Waynes-MBP:Chapter03-2012 WayNoxchi$


//////////////


int x = 0, k = 0, i = digits.length() - 1;
while(k < digits.length()) {
    for (int j = x; j < x + (i % 3); j++) {
        terah += digits[j];
        k++;
        cout << k << endl;
    }
    x++;
    if (k != i) terah += ",";
}

*/
