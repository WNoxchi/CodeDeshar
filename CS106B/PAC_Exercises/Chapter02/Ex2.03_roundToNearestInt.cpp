/*
* File: roundToNearestInt.cpp
* ---------------------------
* Wayne H. Noxchi
* PAC++ ex 2.3
* CS106B Programming Abstractions
* 05-Mar-2016 01:12
*/

/* Write a function tht rounds a floating-point number X to the nearest integer.
 * Write a main program to test tht it works.
 */

/* Can round float to closest integer by adding 0.5, then truncating result to
 * integer.
 */

#include <iostream>
using namespace std;

/* Prototype rounder function */
int roundToNearestInt(float x);

/* Main Program */
int main()
{
    float x;
    int result;

    cout << "This program will round a positive number to the nearest integer." << endl;
    cout << "Enter a decimal number: ";
    cin >> x;

    result = roundToNearestInt(x);

    cout << x << " rounded to the nearest integer is: " << result << endl;
}

/* Function Rounds Float to Nearest Integer */
int roundToNearestInt(float x)
{
    x += 0.5;
    return x;
}
