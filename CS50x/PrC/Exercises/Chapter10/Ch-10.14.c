// CS50x - Intro to Computer Science
// Programming in C - Exercise 10.13
// WH Noxchi - 29-Mar-2016 01:10 - 29-Mar-2016 02:05

/**
    write a funct intToStr that converts an integer value into a char string.
    Be sure to handle negative integers properly.
**/

// pointers are covered in the next chapter, so I won't use them here.

#include <stdio.h>
#include <stdbool.h>

void intToStr(int numbers, char string[]) {
    int i = 0, omg = 0, temp;
    bool neg = false;
    char tempstr[32];

    if (numbers < 0) {
        neg = true;
        numbers *= -1;
    }

    do {
        temp = numbers % 10;
        numbers /= 10;
        tempstr[i] = temp + '0';
        i++;
    }
    while (numbers != 0);

    tempstr[i] = '\0';

    if (neg == true) {
        string[0] = '-';
        omg = 1;
        string[i+1] = '\0';
    }
    if (neg == false) {
        string[i] = '\0';
    }
    /* now to reverse the reversed string */
    for (int j = i - 1; j >= 0; j--) {
        string[omg] = tempstr[j];
        omg++;
    }

}

int main(void)
{
    int n1 = 123456;
    char s1[32];
    int n2 = -56;
    char s2[32];

    intToStr(n1, s1);
    intToStr(n2, s2);

    printf("%s\n%s\n", s1, s2);
}

// TERMINAL:
// Waynes-MBP:Chapter10 WayNoxchi$ ./Ch-10.14
// 123456
// -56
