/*  CS50x - Intro to CS
 *  Programming in C
 *-----------------------------------------------------<>
 *  13.07 macroIsAlpha.c
 *-----------------------------------------------------<>
 *  Wayne Noxchi - 05-Jun-2016 22:20 - 05-Jun-2016 22:25
 */

/*  Write a macro IS_ALPHABETIC that gives a nonzero value if a character is
 *  an alphabetic character. Have the macro use the IS_LOWER_CASE macro defined
 *  in the chapter text and the IS_UPPER_CASE macro defined in exercise 6.    */

 # define IS_UPPER_CASE(x)  ((x - 'A' >= 0 && x - 'A' <= 25) ? 1 : 0)
 # define IS_LOWER_CASE(x)  ( ((x) >= 'a') && ((x) <= 'z') )
 # define IS_ALPHABETIC(x)  ((IS_UPPER_CASE(x) == 1 || IS_LOWER_CASE(x) == 1) ? 1 : 0)

 #include <stdio.h>

 int main() {
     char a1 = 'A';
     char a2 = 'a';
     char z1 = 'Z';
     char z2 = 'z';
     char x  = '4';

     printf("%i\n", IS_ALPHABETIC(a1));
     printf("%i\n", IS_ALPHABETIC(a2));
     printf("%i\n", IS_ALPHABETIC(z1));
     printf("%i\n", IS_ALPHABETIC(z2));
     printf("%i\n", IS_ALPHABETIC(x));

     return 0;
 }

/*  TERMINAL OUTPUT:

    Waynes-MBP:Chapter13 WayNoxchi$ make 13.07_macroIsAlpha
    cc     13.07_macroIsAlpha.c   -o 13.07_macroIsAlpha
    Waynes-MBP:Chapter13 WayNoxchi$ ./13.07_macroIsAlpha
    1
    1
    1
    1
    0
    Waynes-MBP:Chapter13 WayNoxchi$

 */
