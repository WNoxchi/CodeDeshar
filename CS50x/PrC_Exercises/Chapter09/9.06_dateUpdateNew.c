/*  CS50x - Intro to Computer Science
 *  Programming in C 3rd Ed
 *-------------------------------------------------<*>
 *  Wayne H. Noxchi - 9.06_dateUpdateNew
 *-------------------------------------------------<*>
 *  06-Jul-2016 16:36 - 06-Jul-2016 16:42
*/

/*
    Replace the dateUpdate function from Program 9.4 with the modified one that
    uses compound literals as presented in the text. Run the program to verify
    its proper operation.
*/

// Function to calculate tomorrow's date - using compound literals (p181)

struct date dateUpdate (struct date today) {
    struct date tomorrow;
    int numberOfDays (struct date d);

    if (today.date != numberOfDays (today) )
        tomorrow = (struct date) { today.month, today.day + 1, today.year };
    else if (today.month == 12)     // end of year
        tomorrow = (struct date) { 1, 1, today.year + 1 };
    else                            // end of month
        tomorrow = (struct date) { today.month + 1, 1, today.year };

    return tomorrow;
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
