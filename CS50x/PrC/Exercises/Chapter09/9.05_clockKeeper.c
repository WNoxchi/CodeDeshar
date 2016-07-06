/*  CS50x - Intro to Computer Science
 *  Programming in C 3rd Ed
 *-------------------------------------------------<*>
 *  Wayne H. Noxchi - 9.05 clockKeeper.c
 *-------------------------------------------------<*>
 *  06-Jul-2016 15:48 - 06-Jul-2016 16:35
*/

/*
    Write a function called clockKeeper that takes as its argument a
    dateAndTime structure as defined in this chapter.The function should call
    the timeUpdate func- tion, and if the time reaches midnight, the function
    should call the dateUpdate function to switch over to the next day. Have
    the function return the updated dateAndTime structure.
*/

#include <stdio.h>
#include <stdbool.h>

struct date {
    int day;
    int month;
    int year;
};

struct time {
    int seconds;
    int minutes;
    int hours;
};

struct dateAndTime {
    struct date sdate;
    struct time stime;
};

/* function */
struct dateAndTime clockKeeper(struct dateAndTime dateTime) {
    struct time timeUpdate (struct time now);
    struct date dateUpdate (struct date today);
    int flag = 0;
    if (dateTime.stime.hours == 23) flag = 1;
    dateTime.stime = timeUpdate(dateTime.stime);
    if (dateTime.stime.hours == 0)
        dateTime.sdate = dateUpdate(dateTime.sdate);
    return dateTime;
}

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

// Function to update the time by one second
struct time timeUpdate (struct time now)
{
    ++now.seconds;

    if ( now.seconds == 60 ) {      // next minute
        now.seconds = 0;
        ++now.minutes;

        if ( now.minutes == 60 ) {  // next hours
            now.minutes = 0;
            ++now.hours;

            if ( now.hours == 24 )   // midnight
                now.hours = 0;
        }
    }

    return now;
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

/* implementation */
int main(void) {
    struct dateAndTime Now;
    printf("Today's Date (dd mm yyyy): ");
    scanf("%i%i%i", &Now.sdate.day, &Now.sdate.month, &Now.sdate.year);
    printf("Current Time (hh:mm:ss): ");
    scanf("%i:%i:%i", &Now.stime.hours, &Now.stime.minutes, &Now.stime.seconds);
    Now = clockKeeper(Now);
    printf("Updated Date and Time (hh:mm:ss -- dd/mm/yyy): %i:%i:%i -- %i/%i/%i\n",
            Now.stime.hours, Now.stime.minutes, Now.stime.seconds,
            Now.sdate.day, Now.sdate.month, Now.sdate.year);
    return 0;
}


/*  what
struct dateAndTime clockKeeper(struct dateAndTime dateTime) {
    struct time timeUpdate (struct time now);
    struct date dateUpdate (struct date today);
    struct date todayDate;
    struct time currentTime;
    int flag = 0;          // using this a boolean
    if (currentTime.hourss == 23) flag = 1;
    printf("Today's Date (dd mm yyyy): ");
    scanf("%i%i%i", &todayDate.day, &todayDate.month, &todayDate.year);
    printf("Current Time (hh:mm:ss): ");
    scanf("%i:%i:%i", &currentTime.hourss, &currentTime.minutes, &currentTime.seconds);
    currentTime = timeUpdate(currentTime);
    if (flag == 1 && currentTime.hourss == 0)
        todayDate = dateUpdate(todayDate);
    printf("Updated Date and Time (hh:mm:ss -- dd/mm/yyy): %i:%i:%i -- %i/%i/%i\n",
            currentTime.hourss, currentTime.minutes, currentTime.seconds,
            todayDate.day, todayDate.month, todayDate.year);
}
*/
