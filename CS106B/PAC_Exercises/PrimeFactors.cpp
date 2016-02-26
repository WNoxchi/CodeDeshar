/*
* File: PrimeFactors.cpp
* ---------------------------
* PAC++ ex 1.9
* CS106B Programming Abstractions
* 25-Feb-2016 23:46
*/

#include <iostream>
using namespace std;

int main()
{
	int terah;

	cout << "This program factors a number by primes." << endl;
	cout << "Enter a (+) number to be factored: ";
	cin >> terah;

	if (terah % 2 == 0)
	{
		cout << 2;
		terah /= 2;
	}

	for (int i = 2; i <= terah; i++)
	{
		if (terah % i == 0)
		{
			terah /= i;
			cout << " x " << i;
		}
	}
	cout << endl;
}
