/*  CS106B - Programming Abstractions
 *  Programming Abstractions in C++ (2012)
 *  --------------------------------------
 *  Wayne H. Noxchi - 3.02_trim.cpp
 *  --------------------------------------
 *  04-Jun-2016 17:06 - 04-Jun-2016 17:13
*/

/** write a corresponding implementation to the trim(str) function in strlib.h
    trim(str) returns a new string by removing all whitespace chars         **/

#include <iostream>
#include <string>
using namespace std;

string trim(string str) {
    int len = str.length();
    string newstr = "";
    for (int i = 0; i < len; i++) {
        if (str[i] != ' ') {
            newstr += str[i];
        }
    }
    return newstr;
}

/* testing */
int main() {
    string input;
    cout << "String: ";
    getline(cin, input);
    cout << trim(input) << endl;
}
