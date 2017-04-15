/*  CS50x - Intro to Computer Science
 *  Programming in C
 *-----------------------------------------------------<>
 *  11.01.c
 *-----------------------------------------------------<>
 *  Wayne Nixaloy - 05-Aug-2016 09:53
 */

// // Program 11.1    Illustrating Pointers
// // Program to illustrate pointers
#include <stdio.h>

int main (void) {
    int count = 10, x;
    int *int_pointer;

    int_pointer = &count;
    x = *int_pointer;

    printf ("count = %i, x = %i\n", count, x);

    return 0;
}

// -----------------------------------------------------------------------------

// // Program 11.2    More Pointer Basics
// // Further examples of pointer
#include <stdio.h>

int main (void) {
    char c = 'Q';
    char *char_pointer = &c;

    printf("%c %c\n", c, *char_pointer);

    *char_pointer = '/';
    printf("%c %c\n", c, *char_pointer);

    *char_pointer = '(';
    printf("%c %c\n", c, *char_pointer);

    return 0;
}

// -----------------------------------------------------------------------------

// Program 11.3 Using Pointers in Expressions
// More on pointers

#include <stdio.h>

int main(void) {
    int i1, i2;
    int *p1, *p2;

    i1 = 5;
    p1 = &i1;
    i2 = *p1 / 2 + 10;
    p2 = p1;

    printf("i1 = %i, i2 = %i, *p1 = %i, *p2 = %i\n", i1, i2, *p1, *p2);

    return 0;
}

// Terminal:
// Waynes-MBP:Chapter11 WayNoxchi$ ./11.01
// i1 = 5, i2 = 12, *p1 = 5, *p2 = 5

// -----------------------------------------------------------------------------

// Program 11.4 Using Pointers to Structures
// Program to illustrate structure pointers

#include <stdio.h>

int main(void)
{
    struct date
    {
        int month;
        int day;
        int year;
    };

    struct date today, *datePtr;

    datePtr = &today;

    datePtr->month = 9;
    datePtr->day = 25;
    datePtr->year = 2004;

    printf("Today's date is %i/%i/%.2i.\n",
                datePtr->month, datePtr->day, datePtr->year % 100);

    return 0;
}

// -----------------------------------------------------------------------------

// Program 11.5 Using Structures Containing Pointers
// Function to use structures containing pointers

#include <stdio.h>

int main (void)
{
    struct intPtrs
    {
        int *p1;
        int *p2;
    };

    struct intPtrs pointers;
    int i1 = 100, i2;

    pointers.p1 = &i1;
    pointers.p2 = &i2;
    *pointers.p2 = -97;

    printf("i1 = %i, *pointers.p1 = %i\n", i1, *pointers.p1);
    printf("i2 = %i, *pointers.p2 = %i\n", i2, *pointers.p2);
}

// Terminal:
// Waynes-MBP:Chapter11 WayNoxchi$ ./11.01
// i1 = 100, *pointers.p1 = 100
// i2 = -97, *pointers.p2 = -97

// -----------------------------------------------------------------------------

// Program 11.6 Using Linked Lists
// Function to use linked Lists

#include <stdio.h>

int main (void)
{
    struct entry
    {
        int             value;
        struct entry    *next;
    };

    struct entry n1, n2, n3;
    int         i;

    n1.value = 100;
    n2.value = 200;
    n3.value = 300;

    n1.next = &n2;
    n2.next = &n3;

    i = n1.next->value;
    printf("%i  ", i);

    printf("%i\n", n2.next->value);

    return 0;
}

// Terminal:
// Waynes-MBP:Chapter11 WayNoxchi$ ./11.01
// 200  300

// -----------------------------------------------------------------------------

// Program 11.7 Traversing a Linked List
// Program to traverse a linked list

#include <stdio.h>

int main (void)
{
    struct entry
    {
        int             value;
        struct entry    *next;
    };

    struct entry    n1, n2, n3;
    struct entry    *list_pointer = &n1;

    n1.value = 100;
    n1.next = &n2;

    n2.value = 200;
    n2.next = &n3;

    n3.value = 300;
    n3.next = (struct entry *) 0;   // mark list end with null pointer

    while (list_pointer != (struct entry *) 0) {
        printf("%i\n", list_pointer->value);
        list_pointer = list_pointer->next;
    }

    return 0;
}

// Terminal:
// aynes-MBP:Chapter11 WayNoxchi$ ./11.01
// 100
// 200
// 300

// -----------------------------------------------------------------------------

// Program 11.8 Using Pointers and Functions
// Program to illustrate using pointers and functions

#include <stdio.h>

void test (int *int_pointer)
{
    *int_pointer = 100;
}

int main (void)
{
    void test (int *int_pointer);
    int i = 50, *p = &i;

    printf("Before the call to test i = %i\n", i);

    test(p);
    printf("After the call to test i = %i\n", i);

    return 0;
}

// Terminal:
// Waynes-MBP:Chapter11 WayNoxchi$ ./11.01
// Before the call to test i = 50
// After the call to test i = 100

// -----------------------------------------------------------------------------

// Program 11.9 Using Pointers to Exchange Values
// More on pointers and functions

#include <stdio.h>

void exchange (int * const pint1, int * const pint2)
{
    int temp;

    temp = *pint1;
    *pint1 = *pint2;
    *pint2 = temp;
}

int main (void)
{
    void exchange (int * const pint1, int * const pint2);
    int i1 = -5, i2 = 66, *p1 = &i1, *p2 = &i2;

    printf("i1 = %i, i2 = %i\n", i1, i2);

    exchange (p1, p2);
    printf("i1 = %i, i2 = %i\n", i1, i2);

    exchange (&i1, &i2);
    printf("i1 = %i, i2 = %i\n", i1, i2);

    return 0;
}

// Terminal:
// Waynes-MBP:Chapter11 WayNoxchi$ ./11.01
// i1 = -5, i2 = 66
// i1 = 66, i2 = -5
// i1 = -5, i2 = 66

// -----------------------------------------------------------------------------

// Program 11.10 Returning a Pointer from a Function
#include <stdio.h>

struct entry
{
    int value;
    struct entry *next;
};

struct entry *findEntry (struct entry *listPtr, int match)
{
    while (listPtr != (struct entry *) 0)
        if (listPtr->value == match)
            return (listPtr);
        else
            listPtr = listPtr->next;

    return (struct entry *) 0;
}

int main (void)
{
    struct entry *findEntry (struct entry *listPtr, int match);
    struct entry n1, n2, n3;
    struct entry *listPtr, *listStart = &n1;

    int search;

    n1.value = 100;
    n1.next = &n2;

    n2.value = 200;
    n2.next = &n3;

    n3.value = 300;
    n3.next = 0;

    printf ("Enter value to locate: ");
    scanf ("%i", &search);

    listPtr = findEntry (listStart, search);

    if (listPtr != (struct entry *) 0)
        printf ("Found %i.\n", listPtr->value);
    else
        printf ("Not found.\n");

    return 0;
}

// Terminal:
// Waynes-MBP:Chapter11 WayNoxchi$ ./11.01
// Enter value to locate: 21
// Not found.
// Waynes-MBP:Chapter11 WayNoxchi$ ./11.01
// Enter value to locate: 200
// Found 200.

// -----------------------------------------------------------------------------

// Program 11.11 Working with Pointers to Arrays
// Fucntion to sum the elements of an integer array

#include <stdio.h>

int arraySum (int array[], const int n)
{
    int sum = 0, *ptr;
    int * const arrayEnd = array + n;

    for (ptr = array; ptr < arrayEnd; ++ptr)
        sum += *ptr;
    return sum;
}

int main (void)
{
    int arraySum (int array[], const int n);
    int values[10] = { 3, 7, -9, 3, 6, -1, 7, 9, 1, -5 };

    printf ("The sum is %i\n", arraySum (values, 10));

    return 0;
}

// Terminal:
// Waynes-MBP:Chapter11 WayNoxchi$ ./11.01
// The sum is 21

// -----------------------------------------------------------------------------

// Program 11.12 Summing the Elements of an Array
// Function to sum the leements of an integer array Ver. 2

#include <stdio.h>

int arraySum (int *array, const int n)
{
    int sum = 0;
    int * const arrayEnd = array + n;

    for ( ; array < arrayEnd; ++array)
        sum += *array;

    return sum;
}

int main (void)
{
    int arraySum (int *array, const int n);
    int values[10] = {3, 7, -9, 3, 6, -1, 7, 9, 1, -5};

    printf ("The sum is %i\n", arraySum (values, 10));

    return 0;
}

// Terminal:
// Waynes-MBP:Chapter11 WayNoxchi$ ./11.01
// The sum is 21

// -----------------------------------------------------------------------------

// Program 11.13 Pointer Version of copyString
#include <stdio.h>

void copyString (char *to, char *from)
{
    for ( ; *from != '\0'; ++from, ++to)
        *to = *from;

    *to = '\0';
}

int main (void)
{
    void copyString (char *to, char *from);
    char string1[] = "A string to be copied.";
    char string2[50];

    copyString (string2, string1);
    printf ("%s\n", string2);

    copyString (string2, "So is this.");
    printf ("%s\n", string2);

    return 0;
}

// Terminal:
// Waynes-MBP:Chapter11 WayNoxchi$ ./11.01
// A string to be copied.
// So is this.

// -----------------------------------------------------------------------------

// Program 11.14 Revised Version of the copyString Function
// Function to copy one string to another. Pointer Ver. 2

#include <stdio.h>

void copyString (char *to, char *from)
{
    while ( *from )
        *to++ = *from++;

    *to = '\0';
}

int main (void)
{
    void copyString (char *to, char *from);
    char string1[] = "Astring to be copied.";
    char string2[50];

    copyString (string2, string1);
    printf ("%s\n", string2);

    copyString (string2, "So is this.");
    printf ("%s\n", string2);

    return 0;
}

// Terminal:
// Waynes-MBP:Chapter11 WayNoxchi$ ./11.01
// Astring to be copied.
// So is this.

// -----------------------------------------------------------------------------

// Program 11.15 Using Pointers to Find the Length of a String
// Function to count the characters in a string - Pointer version

#include <stdio.h>

int stringLength (const char *string)
{
    const char *cptr = string;

    while ( *cptr )
        ++cptr;
    return cptr - string;
}

int main (void)
{
    int stringLength (const char *string);

    printf ("%i  ", stringLength ("stringLength test"));
    printf ("%i  ", stringLength (""));
    printf ("%i\n", stringLength ("complete"));

    return 0;
}

// Terminal:
// Waynes-MBP:Chapter11 WayNoxchi$ ./11.01
// 17  0  8

// -----------------------------------------------------------------------------
