/*  CS50x - Intro to Computer Science
 *  Programming in C
 *-----------------------------------------------------<>
 *  11.11_dateUpdate.c
 *-----------------------------------------------------<>
 *  WNixaloy - 06-Aug-2016 23:31
 */

/*   Given the definition of a date structure as defined in this chapter, write
a function called dateUpdate that takes a pointer to a date structure as its
argument and that updates the structure to the following day (see Program 9.4). */

#include <stdio.h>
#include <stdbool.h>

struct date
{
    int month;
    int day;
    int year;
};

void dateUpdate(struct date *today) {
        int numberOfDays (struct date d);

        if (today->day != numberOfDays (*today)) {
            today->day += 1;
        }
        else if (today->month == 12) {       // end of year
            today->year += 1;
            today->day = 1;
            today->month = 1;
        }
        else {                              // end of month
            today->month += 1;
            today->day = 1;
        }
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
    void dateUpdate (struct date *today);
    struct date thisDay;

    printf ("Enter today's date (mm dd yyyy): ");
    scanf ("%i%i%i", &thisDay.month, &thisDay.day,
                &thisDay.year);

    dateUpdate (&thisDay);

    printf ("Tomorrow's date is %i/%i/%.2i.\n", thisDay.month,
                thisDay.day, thisDay.year % 100);

    return 0;
}

// TERMINAL OUT:
//
// Waynes-MBP:Chapter11 WayNoxchi$ make 11.11_dateUpdate
// cc     11.11_dateUpdate.c   -o 11.11_dateUpdate
// Waynes-MBP:Chapter11 WayNoxchi$ ./11.11_dateUpdate
// Enter today's date (mm dd yyyy): 02 01 1990
// Tomorrow's date is 2/2/90.
// Waynes-MBP:Chapter11 WayNoxchi$


// Author Solution:
// ----------------
// /* Function to calculate tomorrow's date
//    (pointer version) */
//
// void  dateUpdate (struct date  *today)
// {
//     int  numberOfDays (struct date  d);
//
//     if ( today->day != numberOfDays (*today) )
//         ++today->day;
//     else if ( today->month == 12 ) {  /* end of year */
//         today->day = 1;
//         today->month = 1;
//         ++today->year;
//     }
//     else {                            /* end of month */
//         today->day = 1;
//         ++today->month;
//     }
// }


// // -----------------------------------------------------------------------------
// // Program 9.4 Revising the Program to Determine Tomorrow's Date, Version 2
// // Program to determine tomorrow's date
// // ---------------------------------------
// #include <stdio.h>
// #include <stdbool.h>
//
// struct date
// {
//     int month;
//     int day;
//     int year;
// };
//
// // Function to calculate tomorrow's date
//
// struct date dateUpdate (struct date today)
// {
//     struct date tomorrow;
//     int numberOfDays (struct date d);
//
//     if (today.day != numberOfDays (today)) {
//         tomorrow.day = today.day + 1;
//         tomorrow.month = today.month;
//         tomorrow.year = today.year;
//     }
//     else if (today.month == 12) {       // end of year
//         tomorrow.day = 1;
//         tomorrow.month = 1;
//         tomorrow.year = today.year + 1;
//     }
//     else {                              // end of month
//         tomorrow.day = 1;
//         tomorrow.month = today.month + 1;
//         tomorrow.year = today.year;
//     }
//
//     return tomorrow;
// }
//
// // Function to find the number of days in a month
//
// int numberOfDays (struct date d)
// {
//     int days;
//     bool isLeapYear (struct date d);
//     const int daysPerMonth[12] =
//         { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//
//     if (isLeapYear(d) && d.month == 2)      // <-- can't believe I found a typo in the book
//         days = 29;                          // isLeapYear(d) needed a paramter...
//     else
//         days = daysPerMonth[d.month - 1];
//
//     return days;
// }
//
// // Function to determine if it's a leap year
//
// bool isLeapYear (struct date d)
// {
//     bool leapYearFlag;
//
//     if ( (d.year % 4 == 0 && d.year % 100 != 0) ||
//                 d.year % 400 == 0 )
//         leapYearFlag = true;    // It's a leap year
//     else
//         leapYearFlag = false;   // Not a leap year
//
//     return leapYearFlag;
// }
//
// int main (void)
// {
//     struct date dateUpdate (struct date today);
//     struct date thisDay, nextDay;
//
//     printf ("Enter today's date (mm dd yyyy): ");
//     scanf ("%i%i%i", &thisDay.month, &thisDay.day,
//                 &thisDay.year);
//
//     nextDay = dateUpdate (thisDay);
//
//     printf ("Tomorrow's date is %i/%i/%.2i.\n", nextDay.month,
//                 nextDay.day, nextDay.year % 100);
//
//     return 0;
// }
