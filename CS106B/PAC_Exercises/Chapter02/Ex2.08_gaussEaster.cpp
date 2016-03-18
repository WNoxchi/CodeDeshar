/*
* File: sqrtApprox.cpp
* ---------------------------
* Wayne H. Noxchi
* PAC++ ex 2.8
* CS106B Programming Abstractions
* 06-Mar-2016 03:20
*/

#include <iostream>
using namespace std;

void findEaster(int year, string & month, int & day);

int main()
{
    int year, day;
    string month;

    cout << "Copyright Wayne Hakan Noxchi, 2016 - Daymoxk. Trigger warning bitch" << endl;
    cout << "I will calculate the date of Easter in any year from 1700 to 1899. Enter a year: ";
    cin >> year;
    findEaster(year);
    cout << "Easter Anno Domini " << year << " falls on " << day << " " << month << "." << endl;
}

void findEaster(int year, string & month, int & day)
{
    int a, b, c, d, e;
    a = year % 19;
    b = year % 4;
    c = year % 7;
    d = (19 * a + 23) % 30;
    if (year >= 1700 && year < 1800)
    {
        e = (2*b + 4*c + 6*d + 3) % 7;
    }
    else if (year >= 1800 && year < 1900)
    {
        e = (2*b + 4*c + 6*d + 4) % 7;
    }
    if (d + e > 9)
    {
        month = 'April';
        day = d + e - 9;
    }
    else
    {
        month = 'March';
        day = 22 + d + e;
    }
}
