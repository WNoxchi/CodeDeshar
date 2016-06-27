/*  CS106B - Programming Abstractions
 *  Programming Abstractions in C++ (2012)
 *  --------------------------------------
 *  Wayne H. Noxchi - 3.01_endsWith.cpp
 *  --------------------------------------
 *  04-Jun-2016 16:51 - 04-Jun-2016 17:05
*/

#include <string>
#include <iostream>
using namespace std;

/**  1st checks if str long enough to hold suffix. Then starts check at position
 *  suffix-length from end of str; returns true if reaches end.
 **/
bool endsWith(string str, string suffix) {
    int len = suffix.length(), targetlen = str.length();
    /* length check */
    if ( len > targetlen ) {
        return false;
    }
    /* main check */
    for (int i = 0; i < len; i++) {
        if ( str[targetlen - len + i] != suffix[i] ) {
            return false;
        }
    }
    return true;
}

/* testing */

int main() {
    string target, suffix;
    cout << "string 1: ";
    getline(cin, target);
    cout << "string 2: ";
    getline(cin, suffix);
    cout << endsWith(target, suffix) << endl;
}
