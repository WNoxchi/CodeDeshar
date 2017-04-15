/*  CS106B - Programming Abstractions
 *  Programming Abstractions in C++ (2012)
 *-------------------------------------------------<*>
 *  Wayne H. Noxchi - 4.11 stringReal.cpp
 *-------------------------------------------------<*>
 *  27-Jun-2016 10:20 - 11:30
*/

/*  Using the functions stringToInteger and integerToString as a model, write
    the code necessary to implement stringToReal and realToString.          */

/*  NOTE:   I only wrote this to properly handle positive real numbers  */

#include "strlib.h"
#include <string>
#include <iostream>
using namespace std;

// int stringToInteger(string s) { return 1;}           // to get it to compile
// string integerToString(int x) { return "asa";}       // w/o proper libraries

float stringToReal(string & str) {
    bool CXA = false;      // above or below 1
    float real = 0;
    int temp, depth = 1;    // depth is: tenth, hundredth, etc..
    string s = "";
    for (int i = 0; i < str.length(); i++) {
        if (isdigit(str[i])) {
            if (CXA == 0) {
                real *= 10;
                s += str[i];
                real += stringToInteger(s);
                s = "";
            }
            if (CXA == 1) {
                s += str[i];
                temp = stringToInteger(s);
                real += float(temp)/(10 * depth);
                depth += 10;
            }
        }
        if (str[i] == '.') {
            CXA = true;
        }
    }
    return real;
}

string realToString(float real) {
    int x, temp;
    float tempf, xf;
    string str;
    // convert to int to get whole number value
    temp = int(real);
    str = integerToString(temp);
    str += '.';
    // getting decimal value
    while (real > 1.0) {
        real -= 1;
    }
    while (real > 0.0) {
        real *= 10;
        temp = int(real);
        str += integerToString(temp);
        real -= temp;
    }
    // in case there was no decimal value, add a zero
    if (str[str.length() - 1] == '.') str += '0';
    return str;
}

/* just so it compiles */
int main() {
    return 0;
}


// while (real > 0) {
//     real *= 10;
//     temp = int(real);
//     str += integerToString(temp);
//
//     xf = 10 - real;
//     x = int(xf * 10);
//     if (x % 10 != 0) x += 10;
//     x /= 10;
//     str += integerToString(x);
//
// }
