/*
* File: CelciusFahrenheit_V2.cpp
* ---------------------------
* Wayne H. Noxchi
* PAC++ ex 2.1
* CS106B Programming Abstractions
* 05-Mar-2016 00:30
*/

// Rewrite Celcius to Fahrenheit to use functions

#include <iostream>
using namespace std;

/* prototype function for C-F conversion */
float convertCF(float C);

/* main program */
int main()
{
    int C, F;
    cout << "Enter a temperature in Celcius: ";
    cin >> C;
    F = convertCF(C);
    cout << endl;
    cout << "Temperature in Fahrenheit: " << F << " degrees." << endl;
}

/* function for C-F conversion */
float convertCF(float C)
{
    float conversion;
    conversion = 9 * C / 5 + 32;
    return conversion;
}
