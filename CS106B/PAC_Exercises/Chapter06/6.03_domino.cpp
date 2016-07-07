/*  CS106B - Programming Abstractions
 *  Programming Abstractions in C++ (2012)
 *-------------------------------------------------<*>
 *  Wayne H. Noxchi - 6.03 domino.cpp
 *-------------------------------------------------<*>
 * 07-Jul-2016 09:03 | 07-Jul-2016 12:10 - 07-Jul-2016 15:47
*/

#include <string>
#include <iostream>
#include <sstream>
#include "6.03_domino.h"

Domino::Domino() {
    left = 0;
    right = 0;
}

Domino::Domino(int x, int y) {
    left = x;
    right = y;
}

int Domino::getLeft() {
    return left;
}

int Domino::getRight() {
    return right;
}

std::string integerToString(int n) {    // helper function for toString() - taken directly from strlib.h
    std::ostringstream stream;
    stream << n;
    return stream.str();
}

std::string Domino::toString() {
    return "[" + integerToString(left) + "|" + integerToString(right) + "]";
}

std::ostream & operator<<(std::ostream & os, Domino dom) {
    return os << dom.toString();
}
