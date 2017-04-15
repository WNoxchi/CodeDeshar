/*  CS50x - Intro to Computer Science
 *  Programming in C 3rd Ed
 *-------------------------------------------------<*>
 *  Wayne H. Noxchi - 9.01 programs
 *-------------------------------------------------<*>
 *  06-Jul-2016 08:44 - 09:33
*/

/*
    Type in and run the seven programs presented in this chapter. Compare the
    output produced by each program with the output presented after each
    program in the text.
*/

// -----------------------------------------------------------------------------
// Program 9.1 Illustrating a Structure
// Program to illustrate a structure
// ---------------------------------------
#include <stdio.h>

int main (void)
{
    struct date
    {
        int month;
        int day;
        int year;
    };

    struct date today;

    today.month = 9;
    today.day = 25;
    today.year = 2004;

    printf ("Today's date is %i/%i/%.2i.\n", today.month, today.day,
                today.year % 100);

    return 0;
}

// Output:
// Waynes-MBP:Chapter09 WayNoxchi$ ./9.01_programs
// Today's date is 9/25/04.

// -----------------------------------------------------------------------------
// Program 9.2 Determining Tomorrow's Date
// Program to determine tomorrow's date
// ---------------------------------------
#include <stdio.h>

int main (void)
{
    struct date
    {
        int month;
        int day;
        int year;
    };

    struct date     today, tomorrow;

    const int   daysPerMonth[12] = { 31, 28, 31, 30, 31, 30,
                                     31, 31, 30, 31, 30, 31 };

    printf ("Enter today's date (mm dd yyyy): ");
    scanf ("%i%i%i", &today.month, &today.day, &today.year);

    if ( today.day != daysPerMonth[today.month - 1] ) {
        tomorrow.day = today.day + 1;
        tomorrow.month = today.month;
        tomorrow.year = today.year;
    }
    else if ( today.month == 12) {      // end of year
        tomorrow.day = 1;
        tomorrow.month = 1;
        tomorrow.year = today.year + 1;
    }
    else {                              // end of month
        tomorrow.day = 1;
        tomorrow.month = today.month + 1;
        tomorrow.year = today.year;
    }

    printf ("Tomorrow's date is %i/%i/%.2i.\n", tomorrow.month,
            tomorrow.day, tomorrow.year % 100);

    return 0;
}

// Output:
// Enter today's date (mm dd yyyy): 02 01 2016
// Tomorrow's date is 2/2/16.

// -----------------------------------------------------------------------------
// Program 9.3 Revising the Program to Determine Tomorrow's Date
// Program to determine tomorrow's date
// ---------------------------------------
#include <stdio.h>
#include <stdbool.h>

struct date
{
    int month;
    int day;
    int year;
};

int main (void)
{
    struct date     today, tomorrow;
    int numberOfDays (struct date d);

    printf ("Enter today's date (mm dd yyyy): ");
    scanf ("%i%i%i", &today.month, &today.day, &today.year);

    if ( today.day != numberOfDays (today) ) {
        tomorrow.day = today.day + 1;
        tomorrow.month = today.month;
        tomorrow.year = today.year;
    }
    else if ( today.month == 12 ) {     // end of year
        tomorrow.day = 1;
        tomorrow.month = 1;
        tomorrow.year = today.year + 1;
    }
    else {                              // end of month
        tomorrow.day = 1;
        tomorrow.month = today.month + 1;
        tomorrow.year = today.year;
    }

    printf ("Tomorrow's date is %i/%i/%.2i.\n", tomorrow.month,
                tomorrow.day, tomorrow.year % 100);

    return 0;
}

// Function to find the number of days in a month

int numberOfDays (struct date d)
{
    int     days;
    bool    isLeapYear (struct date d);
    const int   daysPerMonth[12] =
        { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if ( isLeapYear (d) == true && d.month == 2 )
        days = 29;
    else
        days = daysPerMonth[d.month - 1];

    return days;
}

// Function to determine if it's a leap year

bool isLeapYear (struct date d)
{
    bool    leapYearFlag;

    if ( (d.year % 4 == 0 && d.year % 100 != 0) ||
                d.year % 400 == 0 )
        leapYearFlag = true;    // It's a leap year
    else
        leapYearFlag = false;   // Not a leap year

    return leapYearFlag;
}

// Output:
// Enter today's date (mm dd yyyy): 07 06 2016
// Tomorrow's date is 7/7/16.
// Waynes-MBP:Chapter09 WayNoxchi$ ./9.01_programs
// Enter today's date (mm dd yyyy): 02 28 2000
// Tomorrow's date is 2/29/00.

// -----------------------------------------------------------------------------
// Program 9.4 Revising the Program to Determine Tomorrow's Date, Version 2
// Program to determine tomorrow's date
// ---------------------------------------
#include <stdio.h>
#include <stdbool.h>

struct date
{
    int month;
    int day;
    int year;
};

// Function to calculate tomorrow's date

struct date dateUpdate (struct date today)
{
    struct date tomorrow;
    int numberOfDays (struct date d);

    if (today.day != numberOfDays (today)) {
        tomorrow.day = today.day + 1;
        tomorrow.month = today.month;
        tomorrow.year = today.year;
    }
    else if (today.month == 12) {       // end of year
        tomorrow.day = 1;
        tomorrow.month = 1;
        tomorrow.year = today.year + 1;
    }
    else {                              // end of month
        tomorrow.day = 1;
        tomorrow.month = today.month + 1;
        tomorrow.year = today.year;
    }

    return tomorrow;
}

// Function to find the number of days in a month

int numberOfDays (struct date d)
{
    int days;
    bool isLeapYear (struct date d);
    const int daysPerMonth[12] =
        { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (isLeapYear(d) && d.month == 2)      // <-- can't believe I found a typo in the book
        days = 29;                          // isLeapYear(d) needed a paramter...
    else
        days = daysPerMonth[d.month - 1];

    return days;
}

// Function to determine if it's a leap year

bool isLeapYear (struct date d)
{
    bool leapYearFlag;

    if ( (d.year % 4 == 0 && d.year % 100 != 0) ||
                d.year % 400 == 0 )
        leapYearFlag = true;    // It's a leap year
    else
        leapYearFlag = false;   // Not a leap year

    return leapYearFlag;
}

int main (void)
{
    struct date dateUpdate (struct date today);
    struct date thisDay, nextDay;

    printf ("Enter today's date (mm dd yyyy): ");
    scanf ("%i%i%i", &thisDay.month, &thisDay.day,
                &thisDay.year);

    nextDay = dateUpdate (thisDay);

    printf ("Tomorrow's date is %i/%i/%.2i.\n", nextDay.month,
                nextDay.day, nextDay.year % 100);

    return 0;
}

// Output:
// Enter today's date (mm dd yyyy): 02 28 2001
// Tomorrow's date is 3/1/01.

// -----------------------------------------------------------------------------
// Program 9.5 Updating the Time by One Second
// Program to update the time by one second
// ---------------------------------------
#include <stdio.h>

struct time
{
    int hour;
    int minutes;
    int seconds;
};

int main (void)
{
    struct time timeUpdate (struct time now);
    struct time currentTime, nextTime;

    printf ("Enter the time (hh:mm:ss): ");
    scanf ("%i:%i:%i", &currentTime.hour,
            &currentTime.minutes, &currentTime.seconds);

    nextTime = timeUpdate (currentTime);

    printf ("Updated time is %.2i:%.2i:%.2i\n", nextTime.hour,
                nextTime.minutes, nextTime.seconds );

    return 0;
}

// Function to update the time by one second

struct time timeUpdate (struct time now)
{
    ++now.seconds;

    if ( now.seconds == 60 ) {      // next minute
        now.seconds = 0;
        ++now.minutes;

        if ( now.minutes == 60 ) {  // next hour
            now.minutes = 0;
            ++now.hour;

            if ( now.hour == 24 )   // midnight
                now.hour = 0;
        }
    }

    return now;
}

// -----------------------------------------------------------------------------
// Program 9.6 Illustrating Arrays of Structures
// Program to illustrate arrays of structures
// ---------------------------------------
#include <stdio.h>

struct time
{
    int hour;
    int minutes;
    int seconds;
};

int main (void)
{
    struct time timeUpdate (struct time now);
    struct time testTimes[5] =
        { {11, 59, 59}, {12, 0, 0}, {1, 29, 59},
          {23, 59, 59}, {19, 12, 27} };

    int i;

    for (i = 0; i < 5; ++i) {
        printf ("Time is %.2i:%.2i:%.2i", testTimes[i].hour,
            testTimes[i].minutes, testTimes[i].seconds);

        testTimes[i] = timeUpdate (testTimes[i]);

        printf (" ... one second later it's %.2i:%.2i:%.2i\n",
            testTimes[i].hour, testTimes[i].minutes, testTimes[i].seconds);
    }

    return 0;
}

// ***** Include the timeUpdate function here *****
struct time timeUpdate (struct time now)
{
    ++now.seconds;

    if ( now.seconds == 60 ) {      // next minute
        now.seconds = 0;
        ++now.minutes;

        if ( now.minutes == 60 ) {  // next hour
            now.minutes = 0;
            ++now.hour;

            if ( now.hour == 24 )   // midnight
                now.hour = 0;
        }
    }

    return now;
}

// Output:
// Waynes-MBP:Chapter09 WayNoxchi$ ./9.01_programs
// Time is 11:59:59 ... one second later it's 12:00:00
// Time is 12:00:00 ... one second later it's 12:00:01
// Time is 01:29:59 ... one second later it's 01:30:00
// Time is 23:59:59 ... one second later it's 00:00:00
// Time is 19:12:27 ... one second later it's 19:12:28

// -----------------------------------------------------------------------------
// Program 9.7 Illustrating Structures and Arrays
// Program to illustrate structures and arrays
// ---------------------------------------
#include <stdio.h>

int main (void)
{
    int i;

    struct month
    {
        int numberOfDays;
        char name[3];
    };

    const struct month months[12] =
    { { 31, {'J', 'a', 'n'}}, { 28, {'F', 'e', 'b'}},
      { 31, {'M', 'a', 'r'}}, { 30, {'A', 'p', 'r'}},
      { 31, {'M', 'a', 'y'}}, { 30, {'J', 'u', 'l'}},
      { 31, {'J', 'u', 'n'}}, { 31, {'A', 'u', 'g'}},
      { 30, {'S', 'e', 'p'}}, { 31, {'O', 'c', 't'}},
      { 30, {'N', 'o', 'v'}}, { 31, {'D', 'e', 'c'}}, };

    printf ("Month    Number of Days\n");
    printf ("-----    --------------\n");

    for (i = 0; i < 12; ++i)
        printf (" %c%c%c           %i\n",
            months[i].name[0], months[i].name[1],
            months[i].name[2], months[i].numberOfDays);

    return 0;
}

// Output:
// Waynes-MBP:Chapter09 WayNoxchi$ ./9.01_programs
// Month    Number of Days
// -----    --------------
//  Jan           31
//  Feb           28
//  Mar           31
//  Apr           30
//  May           31
//  Jul           30
//  Jun           31
//  Aug           31
//  Sep           30
//  Oct           31
//  Nov           30
//  Dec           31
// Waynes-MBP:Chapter09 WayNoxchi$
