/*
* File: MetersImperial.cpp
* ---------------------------
* PAC++ ex 1.2
* CS106B Programming Abstractions
* 25-Feb-2016 21:14
*/

#include <iostream>
using namespace std;

int main()
{
	float meters, inches;
	int feet = 0;

	cout << "This program converts Meters to Feet & Inches." << endl;
	cout << "Enter a distance in meters: ";
	cin >> meters;
	inches = meters / 0.0254;

	while (inches >= 12.0)
	{
		feet += 1;
		inches -= 12;
	}

	cout << "Feet: " << feet << ", Inches: " << inches << endl;

//	cout << "Inches: " << inches << endl;
}
