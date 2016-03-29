// CS50x - Intro to Computer Science
// Programming in C - Exercise 10.11
// WH Noxchi - 29-Mar-2016 00:08 - 29-Mar-2016 00:45

/** Extend strToInt from Program 10.11 st if the first char of the string
    is a minus sign, the value tht follows is taken as a negative number. **/

#include <stdio.h>
#include <stdbool.h>

float strToInt (const char string[]) {
    bool neg = false;
    int i = 0, j = 0;
    float floVal, result = 0;

    if (string[0] == '-') {
        i++;
        neg = true;
    }
    while (string[i] >= '0' && string[i] <= '9') {
        floVal = string[i] - '0';
        result = result * 10 + floVal;
        i++;
    }
    if (string[i] == '.') {
        i++;
        // printf("%i\n", i);
        while (string[i] >= '0' && string[i] <= '9') {
            j++;
            floVal = string[i] - '0';
            for (int k = 0; k < j; k++) {
                floVal /= 10;
            }
            result += floVal;
            i++;
        }
    }
    if (neg == true) {
        result *= -1;
    }
    return result;
}

int main (void)
{
    printf ("%.4f\n", strToInt("-867.6921"));
    return 0;
}
