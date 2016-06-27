/*
 * File: NumericConversion.cpp
 * ---------------------------
 * Name: Wayne Noxchi
 * UbuntuMATE - terminal
 * This file is the starter project for the numeric-conversion problem
 * in which you implement the functions intToString and stringToInt.
 * Assignment 1 - NumericConversion
 * ---------------------------
 * 04-Jun-2016 23:13 - 05-Jun-2016 00:03
 */

#include <iostream>
#include <string>
#include "console.h"
using namespace std;

/* Function prototypes */

string intToString(int n);
int stringToInt(string str);

/* Main program */

int main() {
    string str = "-9919";
    int n;
    cout << "Numeric Conversion." << endl;
    cin >> n;
    cout << "Integer to Text: " << intToString(n) << endl;
    cout << "Text to Integer: " << stringToInt(str) << endl;
    return 0;
}

string intToString(int n) {
    char ch;
    int x;
	string str = "";
    /* neg check */
    if (n < 0) {
        n *= -1;
        return "-" + intToString(n);
    }
    /* base case */
    if (n < 10) {
        ch = char(n + '0');
        str += string() + ch;
        return str;
    }
    x = n % 10;
    n /= 10;
    return intToString(n) + intToString(x);

}

int stringToInt(string str) {
    /* neg check */
    if (str[0] == '-') {
        str = str.substr(1, str.length() - 1);
        return (-1) * stringToInt(str);
    }
    /* base case */
    string sub = "";
    if (str.length() == 1) {
        return int(str[0] - '0');
    }
    sub = str.substr(str.length() - 1, 1);
    str = str.substr(0, str.length() - 1);
    return 10 * stringToInt(str) + stringToInt(sub);
}
