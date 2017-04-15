/*  CS50x - Intro to Computer Science
 *  Programming in C 3rd Ed
 *-------------------------------------------------<*>
 *  Wayne H. Noxchi - 9.02 Days between Dates
 *-------------------------------------------------<*>
 *  006-Jul-2016 13:33 - 06-Jul-2016 14:09
*/

/*
    Write a program that permits the user to type in two dates and then
    calculates the number of elapsed days between the two dates.
*/

#include <stdio.h>

struct date {
    int day;
    int month;
    int year;
};

int main(void) {
    int calcN(struct date d);
    int N1, N2, days;
    struct date date1, date2;
    printf("Date One: (dd mm yyyy): ");
    scanf("%i%i%i", &date1.day, &date1.month, &date1.year);
    printf("Date Two: (dd mm yyyy): ");
    scanf("%i%i%i", &date2.day, &date2.month, &date2.year);
    N1 = calcN(date1);
    N2 = calcN(date2);
    days = N2 - N1;
    printf("Days between %i/%i/%i and %i/%i/%i: %i\n",
                date1.day, date1.month, date1.year,
                date2.day, date2.month, date2.year,
                days);
    return 0;
}

int calcN(struct date d) {
    int f(int year, int month);      // do I need to send whole struct or can just a piece? (ha')
    int g(int month);
    int N;
    N = 1461 * f(d.year, d.month) / 4 + 153 * g(d.month) / 5 + d.day;
    return N;
}

int f(int year, int month) {
    int f;
    if (month <= 2)
        f = year - 1;
    else
        f = year;
    return f;
}

int g(int month) {
    int g;
    if (month <= 2)
        g = month + 13;
    else
        g = month + 1;
    return g;
}

/*
    (1 must be added to N for dates from March 1, 1800, to February 28, 1900,
    and 2 must be added for dates between March 1, 1700, and February 28, 1800)
*/
