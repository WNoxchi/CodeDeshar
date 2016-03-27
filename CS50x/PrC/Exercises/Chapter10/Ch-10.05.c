// CS50x - Intro to Computer Science
// Programming in C - Exericse 10.5
// WH Noxchi - 26-Mar-2016 02:29 - 03:23

/*
 *  Write a funct findString() to det if one character string exists inside
 *  another. If string found: return position. If not found return -1.
 */
#include <stdio.h>

int findString(char source[], char target[]) {
    int tindex = 0;
    int sindex = 0;
    while (target[tindex] != '\0') {
        tindex++;
    }
    while (source[sindex] != '\0') {
        sindex++;
    }
    if (tindex > sindex) return -1;
    for (int k = 0; k < (sindex - tindex); k++) {
        int i = 0;
        while (source[k + i] == target[i]) {
            i++;
        }
        if (i == tindex) return k;
    }
    return -1;
}

int main(void)
{
    int result;
    printf("\nfindString(\"I like big butts and I cannot lie!\", \"butts\")\n");
    result = findString("I like big butts and I cannot lie!", "butts");
    printf("Position: %i\n", result);

    return 0;
}

/***
TERMINAL:
Waynes-MBP:Chapter10 WayNoxchi$ ./Ch-10.05

findString("I like big butts and I cannot lie!", "butts")
Position: 11
 ***/
