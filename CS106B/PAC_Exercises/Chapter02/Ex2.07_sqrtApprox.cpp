/*
* File: sqrtApprox.cpp
* ---------------------------
* Wayne H. Noxchi
* PAC++ ex 2.7
* CS106B Programming Abstractions
* 06-Mar-2016 03:02
*/

#include <iostream>
using namespace std;

float sqrt(float x);

int main()
{
    cout << "Copyright Wayne Hakan Noxchi, 2016, Daymoxk. I will fucking cut you" << endl;
    for (int i = 0; i < 80; i++) cout << "-";
    cout << endl << "Number to square root: ";
    cin >> x;
    cout << "Sqrt(" << x << ") = " sqrt(x);
}

float sqrt(float x)
{
    // guess g, accuracy acc
    float acc = 0.001;
    float g = x / 2;

    while (g - x/g > acc)
    {
        g = (g + x/g)/2;
    }
    return g;
}
