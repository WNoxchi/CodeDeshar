/*  CS106B - Programming Abstractions
 *  Programming Abstractions in C++ (2012)
 *-----------------------------------------------------<>
 *  6.05-6_calender.h
 *-----------------------------------------------------<>
 *  WNixaloy - 13-Aug-2016 17:10 - 17:33 | ~21:42~
 */

// I haven't checked this for functionality - I may come back to it
// The operator overloads seem right but I'm not sure about using the same
// var names in class methods as private instance vars & how this affects
// the overloading -- perhaps the friend declaration of '==' is enough

// NOTE: Will deffinitely have to come back and strengthen my skill in C++ classes

/* extend the calender.h interface from Ch2 ex11 s.t. it exports a Date class
    that exports the following methods: default constructor set date to Jan 1,
    1970. Constructor tht takes a month, day, year, and inits Date to those
    vals: Date moonLanding(JULY, 20, 1969); A overloaded versn of constructor
    in Day-Month order: Date moonLanding(20, JULY, 1969); The getter methods:
    getDay, getMonth, getYear. A toString method tht returns date in form
    dd-mmm-yyyy --> toString(moonLanding) returns string "20-Jul-1969"      */

/*  Extend the calendar.h interface still further by adding overloaded versions
    of the following operators:

• The insertion operator <<.
• The relational operators ==, !=, <, <=, >, and >=
• The expression date + n, which returns the date n days after date
• The expression date - n, which returns the date n days before date
• The expression d1 - d2, which returns how many days separate d1 and d2
• The shorthand assignment operators += and -= with an integer on the right
• The ++ and -- operators in both their prefix and suffix form.                 */

// wow I'm using code I wrote 5 months ago..

#ifndef _6_05_calendar_h
#define _6_05_calendar_h

#include <iostream>
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

/*  Date class  */
class Date {

public:
    /* default constructor */
    Date();

    /* American constructor */
    Date(Month M, int day, int sho);

    /* Eurasian constructor */
    Date(int day, Month M, int sho);

    /* returns day from Date */
    int getDay();

    /* return month from Date */
    Month getMonth();

    /* return year from Date */
    int getYear();

    std::string toString();



    /* friend declaration */
    friend bool operator==(Date date1, Date date2);

/* Instance Vars */
private:
    Month butt;
    int day;
    int sho;

};

/* operator overloading: (prototypes) */
Date operator+(Date & date, int n);
Date operator-(Date & date, int n);
int operator-(Date date1, Date date2);
Date operator++(Date & date);   // prefix ++
Date operator++(Date & date, int);  // suffix ++
Date operator--(Date & date);   // prefix --
Date operator--(Date & date, int);  // suffix --
Date operator+=(Date & date, int n);
Date operator+=(Date & date, int n);
std::ostream & operator<<(std::ostream &os, Date date); // insertion <<
bool operator==(Date date1, Date date2);
bool operator!=(Date date, Date date2);
bool operator<(Date date, Date date2);
bool operator>(Date date, Date date2);
bool operator<=(Date date, Date date2);
bool operator>=(Date date, Date date2);

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
