/*  CS50x - Intro to Computer Science
 *  Programming in C 3rd Ed
 *-------------------------------------------------<*>
 *  Wayne H. Noxchi - 9.03 elapsed Time
 *-------------------------------------------------<*>
 *  06-Jul-2016 14:14 - 06-Jul-2016 14:44
*/

/*
    Write a function elapsed_time that takes as it sarguments two time
    structures and returns a time structure that represents the elapsed time
    (in hours, minutes, and seconds) between the two times.
    Be careful with times that cross midnight.
*/

#include <stdio.h>

struct time {
    int seconds;
    int minutes;
    int hours;
};

/* function */
struct time elapsedTime(struct time t1, struct time t2) {
    struct time eT;
    int sec1 = 0, sec2 = 0, secT;
    sec1 = t1.seconds + t1.minutes * 60 + t1.hours * 3600;
    sec2 = t2.seconds + t2.minutes * 60 + t2.hours * 3600;
    if (t2.hours < t1.hours) {
        sec2 += 24 * 3600;
    }
    secT = sec2 - sec1;
    eT.hours = secT / 3600;
    secT %= 3600;
    eT.minutes = secT / 60;
    secT %= 60;
    eT.seconds = secT;

    return eT;
}

/* implementation */
int main(void) {
    struct time time1, time2, eT;       // legal way to init structs?
    printf("Time One (hh:mm:ss): ");
    scanf("%i:%i:%i", &time1.hours, &time1.minutes, &time1.seconds);
    printf("Time Two (hh:mm:ss): ");
    scanf("%i:%i:%i", &time2.hours, &time2.minutes, &time2.seconds);
    eT = elapsedTime(time1, time2);
    printf("Elapsed time: %i hours, %i minutes, %i seconds.\n",
                eT.hours, eT.minutes, eTc.seconds);
    return 0;
}

/** Terminal Output:
Waynes-MacBook-Pro:Chapter09 WayNoxchi$ ./9.03_elapsedTime
Time One (hh:mm:ss): 01:00:00
Time Two (hh:mm:ss): 02:30:00
Elapsed time: 1 hours, 30 minutes, 0 seconds.
Waynes-MacBook-Pro:Chapter09 WayNoxchi$ ./9.03_elapsedTime
Time One (hh:mm:ss): 23:00:00
Time Two (hh:mm:ss): 01:30:30
Elapsed time: 2 hours, 30 minutes, 30 seconds.
Waynes-MacBook-Pro:Chapter09 WayNoxchi$                   **/
