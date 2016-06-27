/*  CS106B - Programming Abstractions
 *  Programming Abstractions in C++ (2012)
 *-------------------------------------------------<*>
 *  Wayne H. Noxchi - 7.03 Get Titius Bode Distance
 *-------------------------------------------------<*>
 * 08-Jun-2016 22:33 - 08-Jun-2016 23:33
*/

/*
Write a recursive function getTitiusBodeDistance(k) that calculates the
expected distance between the sun and the kth planet, numbering outward
from Mercury starting with 1. Test your function by writing a program
that displays the distances to each of these planets in tabular form.

b1 = 1, b2 = 3, b3 = 6, b4 = 12 .... each subsequent element in the sequence is
twice the preceding one.
di = (4 + bi)/10
*/

#include <iostream>
#include <string>
using namespace std;

/* helper prototype */
int calcBi(int k);

/* function */
float getTitiusBodeDistance(int k) {
    return (4 + calcBi(k))/float(10);
}

/* test */
int main() {
    int zhop = -1;
    cout << "This program calculates the Titius-Bode Distance approximation of planets\n"\
            "from Malkh in astronomical units." << endl;
    while (zhop != 0) {
        cout << "Enter planetary position (1, 2, ...) or enter 0 to exit: ";
        cin >> zhop;
        if (zhop == 0) break;
        cout << "Planet " << zhop << ": " << getTitiusBodeDistance(zhop) << " astronomcal units from Malkh/Sol." << endl;
    }
}

int calcBi(int k) {
    if (k <= 2) {
        return 2 * k - 1;
    }
    else {
        return 2 * calcBi(k - 1);
    }
}

/* Terminal:

Waynes-MBP:Chapter07 WayNoxchi$ make 7.03_getTitiusBodeDistance
c++     7.03_getTitiusBodeDistance.cpp   -o 7.03_getTitiusBodeDistance
Waynes-MBP:Chapter07 WayNoxchi$ ./7.03_getTitiusBodeDistance
This program calculates the Titius-Bode Distance approximation of planets
from Malkh in astronomical units.
Enter planetary position (1, 2, ...) or enter 0 to exit: 1
Planet 1: 0.5 astronomcal units from Malkh/Sol.
Enter planetary position (1, 2, ...) or enter 0 to exit: 2
Planet 2: 0.7 astronomcal units from Malkh/Sol.
Enter planetary position (1, 2, ...) or enter 0 to exit: 3
Planet 3: 1 astronomcal units from Malkh/Sol.
Enter planetary position (1, 2, ...) or enter 0 to exit: 4
Planet 4: 1.6 astronomcal units from Malkh/Sol.
Enter planetary position (1, 2, ...) or enter 0 to exit: 5
Planet 5: 2.8 astronomcal units from Malkh/Sol.
Enter planetary position (1, 2, ...) or enter 0 to exit: 6
Planet 6: 5.2 astronomcal units from Malkh/Sol.
Enter planetary position (1, 2, ...) or enter 0 to exit: 7
Planet 7: 10 astronomcal units from Malkh/Sol.
Enter planetary position (1, 2, ...) or enter 0 to exit: 8
Planet 8: 19.6 astronomcal units from Malkh/Sol.
Enter planetary position (1, 2, ...) or enter 0 to exit: 9
Planet 9: 38.8 astronomcal units from Malkh/Sol.
Enter planetary position (1, 2, ...) or enter 0 to exit: 10
Planet 10: 77.2 astronomcal units from Malkh/Sol.
Enter planetary position (1, 2, ...) or enter 0 to exit: 0
Waynes-MBP:Chapter07 WayNoxchi$

*/
