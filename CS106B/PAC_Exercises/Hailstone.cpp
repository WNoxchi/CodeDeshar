/*
* File: Hailstone.cpp
* ---------------------------
* PAC++ ex 1.10
* CS106B Programming Abstractions
* 26-Feb-2016 00:19
*/

#include <iostream>
using namespace std;

int main()
{
    int stone;
    int count = 0;

    cout << "This program illustrates a Hailstone decomposition of a number." << endl;
    cout << "Enter any (+) number: ";
    cin >> stone;

    while (stone > 1)
    {
        if (stone % 2 == 0)
        {
            cout << stone << " is even so divide it by 2 to get ";
            stone /= 2;
            count++;
            cout << stone << endl;
        }
        else
        {
            cout << stone << " is odd so multiply it by 3 and add 1 to get ";
            stone = stone * 3 + 1;
            count++;
            cout << stone << endl;
        }
    }

    cout << "Steps: " << count << endl;
}
