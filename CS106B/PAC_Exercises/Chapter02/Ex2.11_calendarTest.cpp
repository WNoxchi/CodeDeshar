/*
 * File: calendarTest.cpp
 * ----------------------
 * Wayne H. Noxchi
 * PAC++ ex 2.11
 * CS106B Programming Abstractions
 * 06-Mar-2016 22:00
 * ----------------------
 * tests an implementation of calendar.h
 */

#include <string>
#include "calendar.h"
using namespace std;

/*
 * Implementation notes: daysInMonth, isLeapYear
 * ---------------------------------------------
 *
 */

bool isLeapYear(int year) {
    if (year % 4 == 0 && year % 400 == 0) return true;
    else return false;
}

int daysInMonth(Month butt, int year) {
    switch (butt) {
        case TAW:
        case TUSHOLI:
        case MANGAL:
        case ERXI:
            return 30;
        case MARXI: return (isLeapYear(year)) ? 29 : 28;
        default: return 31;
    }
}

/*
 * Implementation notes: monthToString
 * -----------------------------------
 *
 */

string monthToString(Month butt) {
    switch (butt) {
        case NAZHI: return "NAZHI";
        case MARXI: return "MARXI";
        case BIEKARG: return "BIEKARG";
        case TUSHOLI: return "TUSHOLI";
        case SELI: return "SELI";
        case MANGAL: return "MANGAL";
        case MYATSELI: return "MYATSELI";
        case EGISH: return "EGISH";
        case TAW: return "TAW";
        case ARDAR: return "ARDAR";
        case ERXI: return "ERXI";
        case OGOI: return "OGOI";
        default: return "wtf?";
    }
}

/* Main program to test */
int main() {
    cout << "Copyright Wayne H Noxchi 2016, Daymohk. Yes." << endl;
    cout << "Har sho h'u yu?";
    cin >> year;
    for (Month m = 1; m < 13; m++) {
        cout << monthToString(m) << ": " << daysInMonth(m) << " denosh."
    }
}
