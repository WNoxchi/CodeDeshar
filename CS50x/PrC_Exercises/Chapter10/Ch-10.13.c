// CS50x - Intro to Computer Science
// Programming in C - Exercise 10.13
// WH Noxchi - 29-Mar-2016 00:49 - Debug: 0:52 - Finish: 00:58

/**
    Write a funct uppercase that converts all lowercase characters in a string
    to their uppercase vers.
**/

#include <stdio.h>
#include <string.h>

void uppercase(char string[]) {
    int i = 0;
    while (string[i] != '\0') {
        if (string[i] >= 'a' && string[i] <= 'z') {
            string[i] -= ('a' - 'A');
        }
        i++;
    }
}

int main(void)
{
    char string[] = "Abracadabra!";
    printf("%s\n", string);
    uppercase(string);
    printf("%s\n", string);

    return 0;
}

/** TERMINAL:

Waynes-MBP:Chapter10 WayNoxchi$ ./Ch-10.13
Abracadabra!
ABRACADABRA!
Waynes-MBP:Chapter10 WayNoxchi$

**/
