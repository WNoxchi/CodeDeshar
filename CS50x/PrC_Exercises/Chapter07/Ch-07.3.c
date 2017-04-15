// CS50x - Introduction to Computer Science
// Programming in C - Exercise 7.3
// WH Noxchi - 18-Mar-2016 14:25

// Modify prg 7.2 st any number of responses can be entered. Set 999 as sentinel.

#include <stdio.h>

const int SENT = 999;

int main(void)
{
    int ratingCounters[11], i, response;

    for (i = 1; i <= 10; ++i)
        ratingCounters[i] = 0;

    printf ("Enter your responses\n");
    printf ("(Enter < 999 > to finish)\n");

    while(SENT == 999) {
        scanf ("%i", &response);

        if (response == 999) break;
        else if (response < 1 || (response > 10 && response != 999) )
            printf ("Bad response: %i\n", response);
        else
            ++ratingCounters[response];
    }

    printf ("\n\nRating   Number of Responses\n");
    printf ("------   -------------------\n");

    for (i = 1; i <= 10; ++i)
        printf ("%4i %14i\n", i, ratingCounters[i]);

    return 0;
}
