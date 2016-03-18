/*
* File: NsumOdd.cpp
* ---------------------------
* PAC++ ex 1.4
* CS106B Programming Abstractions
* 25-Feb-2016
*/

#include <iostream>
using namespace std;

int main()
{
	int n;
	int adder = 1;
	int total = 0;

	cout << "This program calculates the sum of the first N odd numbers after zero." << endl;
	cout << "N: ";
	cin >> n;

	if (n == 0) total = 0;
	for (int i = 0; i < n; i++)
	{
		total += adder;
		adder += 2;
	}

	cout << "Sum of the first " << n << " odd integers: " << total << endl;
}
