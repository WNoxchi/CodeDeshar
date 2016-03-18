/*
* File: radioDecay.cpp
* ---------------------------
* Wayne H. Noxchi
* PAC++ ex 2.13
* CS106B Programming Abstractions
* 06-Mar-2016 23:19
*/

#include "random.h"
// #include <iomanip>
#include <iostream>
using namespace std;

int halfLife(int atoms);

int main() {
    int atoms = 10000;
    int year = 0;
    cout << "Copyright 2016 Wayne H Noxchi, Daymohk." << endl;
    cout << "---------------------------------------" << endl;
    cout << "Rudimentary simulation of 10,000 atoms with a 1-year Half-Life." << endl;
    cout << "There are" << atoms << " initially." << endl;
    while (atoms > 0) {
        year++;
        cout << "There are " << halfLife(atoms) << " atoms at the end of year " << year << "." << endl;
    }
}

int halfLife(int & atoms) {
    int remain = 0;
    for (int i = 0; i < atoms; i++) {
        remain += randomInteger(0, 1);
    }
    atoms = remain;
    return atoms;
}
