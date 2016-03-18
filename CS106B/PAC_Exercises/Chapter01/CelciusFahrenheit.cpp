/*
* File: CelciusFahrenheit.cpp
* ---------------------------
* PAC++ ex 1.1
* CS106B Programming Abstractions
* 25-Feb-2016 21:00
*/

#include <iostream>
using namespace std;

int main()
{
	int celcius, fahrenheit;
	while (true)
	{
		cout << "Enter a Celcius value: " << endl;
		cin >> celcius;
		fahrenheit = 9 * celcius / 5 + 32;
		cout << "Fahrenheit: " << fahrenheit << endl;
	}
}
