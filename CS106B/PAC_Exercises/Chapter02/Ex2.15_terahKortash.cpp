/*
* File: terahKortash.cpp
* ---------------------------
* Wayne H. Noxchi
* PAC++ ex 2.15
* CS106B Programming Abstractions
* 06-Mar-2016 23:50
*/

#include <iostream>
// #include <cmath>
#include "random.h"
using namespace std;

const int DARTS = 10000;

void setup();

int main() {
    int heads = 0;
    int flip;
    int count = 0;
    while (heads < 3) {
        flip = randomInteger(0, 1);
        if (flip == 1) {
            heads++;
            count++;
            cout << "kortash" << endl;
        }
        else {
            heads = 0;
            count++;
            cout << "kuygash" << endl;
        }
    }
    cout << "It took " << count << " flips to get 3 consecutive kortash." << endl;
}

void setup() {
    cout << "Copyright 2016, Wayne H Noxchi, Daymoxk." << endl;
    cout << "----------------------------------------" << endl;
    cout << "CS106B Programming Abstractions" << endl;
    cout << "Programming Abstractions in C++" << endl;
    cout << "Chapter 02, Exercise 15: terahKortash" << endl;
    cout << "----------------------------------------" << endl:
}
