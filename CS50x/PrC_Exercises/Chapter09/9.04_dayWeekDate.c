/*  CS50x - Intro to Computer Science
 *  Programming in C 3rd Ed
 *-------------------------------------------------<*>
 *  Wayne H. Noxchi - 9.04 dayWeekDate.c
 *-------------------------------------------------<*>
 *  06-Jul-2016 14:49 - 06-Jul-2016 15:29
*/

/*
    If you take the value of N as computed in exercise 2, subtract 621,049
    from it, and then take that result modulo 7, you get a number from 0 to 6
    that represents the day of the week

    Use the functions developed in the previous exercise to develop a program
    that displays the day of the week on which a particular date falls. Make
    certain that the program displays the day of the week in English (such
    as “Monday”).
*/

#include <stdio.h>

struct date {
    int day;
    int month;
    int year;
};

int main(void) {
    int calcN(struct date d);
    const char *wd(int N);
    int N1, day;
    struct date date1;
    printf("Date: (dd mm yyyy): ");
    scanf("%i%i%i", &date1.day, &date1.month, &date1.year);
    N1 = calcN(date1);
    day = (N1 - 621049) % 7;
    printf("That's a %s.\n", wd(day));
    return 0;
}

const char *wd(int N) {
    return ((const char *[]) {"Sunday", "Monday", "Tuesday", "Wednesday",
                              "Thursday", "Friday", "Saturday"}) [N];
}

int calcN(struct date d) {
    int f(int year, int month);
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
