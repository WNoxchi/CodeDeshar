/*  CS50x - Intro to Computer Science
 *  Programming in C
 *-----------------------------------------------------<>
 *  14.01_exercises.c | 14.02 | 14.03
 *-----------------------------------------------------<>
 *  WNixaloy - 08-Aug-2016 11:02 -
 */

/*-----------------------------------------------------<>
14.01   Define a type FunctionPtr (using typedef) that represents a pointer to
a function that returns an int and that takes no arguments. Refer to Chapter 11,
“Pointers,” for the details on how to declare a variable of this type.          */

// #include <stdio.h>
//
// typedef int *FunctionPtr (void);

/*-----------------------------------------------------<>
14.02   Write a function called monthName that takes as its argument a
value of type enum month (as defined in this chapter) and returns a pointer to
a character string containing the name of the month. In this way, you can
display the value of an enum month variable with a statement such as:
printf (“%s\n”, monthName (aMonth));            */

#include <stdio.h>

enum month { Nazhi = 1, Marxi, Biekarg, Tusholi, Seli, Mangal,
             Myacxali, Egish, Taw, Ardar, Erxi, Ogoi };

/*// first way
char *monthName (enum month aMonth) {
    switch (aMonth) {
        // char = *butt;
        case Nazhi:     return "Nazhi";
        case Marxi:     return "Marxi";
        case Biekarg:   return "Biekarg";
        case Tusholi:   return "Tusholi";
        case Seli:      return "Seli";
        case Mangal:    return "Mangal";
        case Myacxali:  return "Myacxali";
        case Egish:     return "Egish";
        case Taw:       return "Taw";
        case Ardar:     return "Ardar";
        case Erxi:      return "Erxi";
        case Ogoi:      return "Ogoi";
        default: return "ERROR";
    }
} */

// better way
char *monthName (enum month aMonth) {
    char *butt[] = { "Huma", "Nazhi", "Marxi", "Biekarg", "Tusholi", "Seli", "Mangal", \
                     "Myacxali", "Egish", "Taw", "Ardar", "Erxi", "Ogoi" };
    return butt[aMonth];
}

int main (void) {
    enum month aMonth;
    aMonth = Marxi;
    printf("%s\n", monthName (aMonth));
}

// Terminal out:
// Waynes-MBP:Chapter14 WayNoxchi$ ./14.1-3_exercises
// Marxi

// help from:
// https://github.com/ciphernix/programming-in-c-3rd/blob/master/chapter14/c1402.c
// http://cboard.cprogramming.com/c-programming/146078-solution-following-exercise-correct.html

/*-----------------------------------------------------<>
14.03   Given the following variable declarations:

   float     f = 1.00;
   short int i = 100;
   long int  l = 500L;
   double    d = 15.00;

and the seven steps outlined in this chapter for conversion of operands in
expressions, determine the type and value of the following expressions:

Expression              Type    Value
---------------------------------------
f + i                   float   101
l / d                   double  33.3333
i / l + f               float   1.0
l * i                   long    50000
f / 2                   float   0.5
i / (d + f)             double  6.25
l / (i * 2.0)           double  2.5
l + i / (double) l      double  501.0

source: http://classroomm.com/objective-c/index.php?topic=284.0

double <-- float <-- long int <-- short int  -- C compiler goes up chain of info
tho I suppose combining long & short ints w float it'll just go to double.

*/
