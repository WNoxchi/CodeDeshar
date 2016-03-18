/*
* File: SumGauss.cpp
* ---------------------------
* PAC++ ex 1.3
* CS106B Programming Abstractions
* 25-Feb-2016
*/

#include <iostream>
using namespace std;

int main()
{
    int start = -1;
    int startUse = start;
    int end = start;
    int total = 0;

    cout << "This program computes a Gaussian sum of a range of two numbers." << endl;
    cout << "Enter a starting point, zero or greater: ";
    cin >> start;

    while (start < 0)
    {
        cout << "Error. Enter a starting point zero or greater: ";
        cin >> start;
    }

    cout << "Enter an ending point: ";
    cin >> end;

    while (end < start)
    {
        cout << "Error. End point must be greater than start point." << endl;
        cout << "Enter an ending point: ";
        cin >> end;
    }

    for (int i = 0; i < (end - start); i++)
    {
        total += startUse;
        startUse++;
    }

    cout << "Gaussian sum of " << start << " and " << end << " is: " << total << endl;
}
