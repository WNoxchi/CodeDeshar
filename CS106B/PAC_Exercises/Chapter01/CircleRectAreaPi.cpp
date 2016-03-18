/*
* File: CircleRectAreaPi.cpp
* ---------------------------
* PAC++ ex 1.12
* CS106B Programming Abstractions
* 26-Feb-2016 01:12
*/

#include <iostream>
#include <cmath>
using namespace std;

const int RES = 10000;

int main()
{

	double rad, width, x, y, height, rectArea;
	double totArea = 0.0;

	cout << "This program calculates the area of a circle by using 10,000 rectangles." << endl;
	cout << "Enter a radius: ";
	cin >> rad;

	width = rad / RES;
	//cout << width;
	x = width / 2.0;

	for (int i = 0; i < RES; i++)
	{

		y = x + ( width * i);
		height = sqrt(rad * rad - y * y);
		// << "x^2: " << (x * x) << " --- radius^2: " << (rad * rad) << endl;
		//cout << "   x =  " << x << endl;
		rectArea = height * width;
		totArea += rectArea;
	}
	// cout << "WIDTH: " << width << " RECTAREA: " << height << endl;

	cout << "Area approximation of quarter circle: " << totArea << endl;
	cout << "Full circle: " << (totArea * 4) << endl;

}
