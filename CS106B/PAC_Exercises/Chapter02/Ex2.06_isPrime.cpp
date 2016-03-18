/*
* File: isPrime.cpp
* ---------------------------
* Wayne H. Noxchi
* PAC++ ex 2.6
* CS106B Programming Abstractions
* 05-Mar-2016 05:25
*/

/* returns true if integer n is prime, false otherwise */

#include <iostream>
using namespace std;

bool isPrime(int n);

int main()
{
    cout << "This program will list every Prime number between 1 and 100." << endl;
    for (int i = 1; i < 100; i++)
    {
        if (isPrime(i) == true)
        {
            cout << i << " is prime." << endl;
        }
    }
}

bool isPrime(int n)
{
    if (n % 2 == 0) return false;
    for (int i = 3; i < n; i += 2)
    {
        if (n % i == 0) return false;
    }
    return true;
}
