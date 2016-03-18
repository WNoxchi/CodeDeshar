/*
* File: isPerfect.cpp
* ---------------------------
* Wayne H. Noxchi
* PAC++ ex 2.5
* CS106B Programming Abstractions
* 05-Mar-2016 03:36
*/

/* Write a predicate function isPerfect tht takes an integer n and returns true
 * if perfect, false if not. Test by writing a main program using isPerfect to
 * test n from 1 to 9999.
 */

#include <iostream>
using namespace std;

bool isPerfect(int n);

int main()
{
    cout << "Checking for perfect Numbers between 1 and 9,999.." << endl;
    for (int i = 1; i < 10000; i++)
    {
        if (isPerfect(i) == true)
        {
            cout << i << " is a perfect number." << endl;
        }
    }
}

bool isPerfect(int n)
{
    int tot = 0;
    for (int i = 0; i < n; i++)
    {
        if (n % i == 0) tot += i;
    }
    if (tot == n) return true;
    else return false;
}
