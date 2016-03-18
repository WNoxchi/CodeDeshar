/*
* File: LargestInteger.cpp
* ---------------------------
* PAC++ ex 1.5
* CS106B Programming Abstractions
* 25-Feb-2016 22:18
*/

#include <iostream>
using namespace std;

int main()
{
	int SENTINEL = 0;
	int value, largest;
	bool firstRun = true;

	cout << "This program will return the largest number of an input list. \nEnter below. Enter \"0\" to stop." << endl;

	while (true)
	{
		cout << "?: ";
		cin >> value;

		if (firstRun == true)
		{
			largest = value;
			firstRun = false;
		}

		if (value > largest) largest = value;
		if (value == SENTINEL) break;
	}

	cout << "The largest value was: " << largest << endl;
}
