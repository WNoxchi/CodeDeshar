/*
* File: LargestInteger.cpp
* ---------------------------
* PAC++ ex 1.6
* CS106B Programming Abstractions
* 25-Feb-2016 22:33
*/

#include <iostream>
using namespace std;

int main()
{
	int SENTINEL = 0;
	int value, largest, nextLargest;
	bool firstRun = true;

	cout << "This program will return the two largest numbers of an input list. \nEnter below. Enter \"0\" to stop." << endl;

	while (true)
	{
		cout << "?: ";
		cin >> value;

		if (firstRun == true)
		{
			largest = value;
			nextLargest = largest;
			firstRun = false;
		}

		// this if() makes sure 2nd largest is updated if value > both:
		if (value > largest && value > nextLargest)
		{
			nextLargest = largest;
			largest = value;
		}

		if (value < largest && value > nextLargest) nextLargest = value;
		if (value == SENTINEL) break;

		cout << "LARG: " << largest << " --- 2LARG: " << nextLargest << "\n" << endl;
	}

	cout << "The largest value was: " << largest << endl;

	if (largest != nextLargest)
	{
		cout << "The second largest value was: " << nextLargest << endl;
	}

}
