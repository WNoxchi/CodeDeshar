/*
* File: MetersImperial_V2.cpp
* ---------------------------
* Wayne H. Noxchi
* PAC++ ex 2.2
* CS106B Programming Abstractions
* 05-Mar-2016 00:42
*/

/* Rewrite distance conversion program to use a funciton.
 * Function must produce number of feet and inches, meaning you need to use call
 * by reference to return these values.
 */

#include <iostream>
using namespace std;

/* Prototype for distance conversion */
void distanceConvert(float meters, int & feet, float & inches);

/* Main program */
int main()
{
    int feet;
    float inches, meters;

    cout << "Enter a distance in meters to be converted into Feet and Inches." << endl;
    cout << "?: ";
    cin >> meters;

    distanceConvert(meters, feet, inches);

    cout << "Feet: " << feet << ", Inches: " << inches << endl;
}

/* Procedure to convert distance. Reference calls to vars feet & inches */
void distanceConvert(float meters, int & feet, float & inches)
{
    feet = 0;

    inches = meters / 0.0254;

    while (inches >= 12.0)
    {
        feet += 1;
        inches -= 12.0;
    }
}
