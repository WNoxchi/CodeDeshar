/*  Program 13.1 Introducint the #define Statement
    Programming in C - ch 13        05-Jun-2016 20:02  */

#include <stdio.h>

#define YES 1
#define NO  0

// Function to determine if an integer is even

int isEven (int number)
{
    int answer;

    if ( number % 2 == 0 )
        answer = YES;
    else
        answer = NO;
    return answer;
}

int main (void)
{
    int isEven (int number);

    if ( isEven (17) == YES )
        printf ("yes ");
    else
        printf ("no ");

    if ( isEven (20) == YES )
        printf ("yes\n");
    else
        printf ("no\n");

    return 0;
}
