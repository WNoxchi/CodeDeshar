/*
* File: MonteCarlo.cpp
* ---------------------------
* Wayne H. Noxchi
* PAC++ ex 2.14
* CS106B Programming Abstractions
* 06-Mar-2016 23:34
*/

#include <iostream>
// #include <cmath>
#include "random.h"
using namespace std;

const int DARTS = 10000;

void setup();
void monteCarlo(double & approx);

int main() {
    double approx;
    setup();
    monteCarlo(approx);
    cout << "Approximation pi/4 = " << approx;
}

void setup() {
    cout << "Copyright 2016, Wayne H Noxchi, Daymoxk." << endl;
    cout << "----------------------------------------" << endl;
    cout << "Monte Carlo Approximation: 10,000 darts:" << endl;
    cout << "----------------------------------------" << endl:
}

double monteCarlo() {
    double hit = 0;
    double x, y;
    for (int i = 0; i < DARTS; i++) {
        x = randomReal(-1, 1);
        y = randomReal(-1, 1);
        if (x*x + y*y < 1) hit++;
    }
    approx = hit / DARTS;
}
