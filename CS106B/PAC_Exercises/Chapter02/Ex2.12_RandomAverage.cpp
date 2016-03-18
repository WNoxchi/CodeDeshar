/*
* File: RandomAverage.cpp
* ---------------------------
* Generates random real numbers between 0 & 1, and displays average after
* n trials.
* ---------------------------
* Wayne H. Noxchi
* PAC++ ex 2.12
* CS106B Programming Abstractions
* 06-Mar-2016 22:41
*/

#include "random.h"
// #include <iomanip>
#include <iostream>
using namespace std;

double randAvg(int n);

int main() {
    int n;
    cout << "Copyright 2016 Wayne H Noxchi, Daymohk. Yup." << endl;
    cout << "--------------------------------------------" << endl;
    cout << "This program will average a set of N random real numbers between 0 and 1.";
    cout << "Enter a number of trials to average random numbers, N: ";
    cin >> n;
    cout << "Average: " << randAvg(n) << endl;
}

double randAvg(int n) {
    double x;
    double numer = 0;
    double denom = 0;
    for (int i = 0; i < n; i++) {
        x = randomReal(0, 1);
        numer += x;
        denom += 1;
    }
    return numer / denom;
}
