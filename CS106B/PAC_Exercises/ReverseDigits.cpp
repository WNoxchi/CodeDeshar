/*
* File: ReverseDigits.cpp
* ---------------------------
* PAC++ ex 1.8
* CS106B Programming Abstractions
* 25-Feb-2016 23:00
*/

#include <iostream>
using namespace std;

/* Function takes a number; returns a number w digits reversed. */
// 1234 --> 4321
int digiRev(int n)
{
    int nRev = 0;
    while (n > 0)
    {
        nRev *= 10;
        nRev += n % 10;
        n /= 10;
    }
    return nRev;
}

/* Main Program */
int main()
{

    int terah, revTerah;

    cout << "This program reverses the digits in an integer." << endl;
    cout << "Enter a positive integer: ";
    cin >> terah;
    revTerah = digiRev(terah);
    cout << "The reversed integer is: " << revTerah << endl;

}
