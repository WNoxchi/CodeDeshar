/*
 * File: calendar.h
 * ----------------
 * Wayne H. Noxchi
 * PAC++ ex 2.11
 * CS106B - Programming Abstractions
 * 06-Mar-2016 21:57
 * ----------------
 * This interface exports a Month type and the functions
 * daysInMonth, isLeapYear, and monthToString that returns
 * a cosntant name for a value of type Month.
 */

#ifndef _calendar_h
#define _calendar_h

#include <string>

/*
 * Type: Month
 * -----------
 * This enumerated type is used to represent the 12 months.
 */

enum Month {
    NAZHI = 1,
    MARXI,
    BIEKARG,
    TUSHOLI,
    SELI,
    MANGAL,
    MYATSELI,
    EGISH,
    TAW,
    ARDAR,
    ERXI,
    OGOI
};

/*
 * Function: daysInMonth
 * Usage: int days = daysInMonth(butt)
 * ---------------------
 * Returns the number of days in a given month.
 */

int daysInMonth(Month butt);

/*
 * Function: isLeapYear
 * Usage: bool leapYear = isLeapYear(year);
 * --------------------
 * Returns true or false whether an input year is a leap year.
 * Aldashna: isLeapYear(1999) returns false;
 */

 bool isLeapYear(int year);

/*
 * Function: monthToString
 * Usage: string str = monthToString(butt);
 * -----------------------
 * Returns name of month as a string, from month value
 */

std::string monthToString(Month butt)
#endif
