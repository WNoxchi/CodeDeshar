/*  CS50x - Intro to Computer Science
 *  Programming in C
 *-----------------------------------------------------<>
 *  11.11_dateUpdate.c
 *-----------------------------------------------------<>
 *  WNixaloy - 06-Aug-2016 23:31
 */

#include <stdio.h>

int main(void) {
    // Given the following declarations:

    char *message = "Programming in C is fun\n";
    char message2[] = "You said it\n";
    char *format = "x = %i\n";
    int x = 100;

    // determine whether each printf call from the following sets is valid and
    // produces the same output as other calls from the set.

    /*** set 1 ***/
    printf ("Programming in C is fun\n");
    printf ("%s", "Programming in C is fun\n");
    printf ("%s", message);
    printf (message);
    /*** set 2 ***/
    printf ("You said it\n");
    printf ("%s", message2);
    printf (message2);
    printf ("%s", &message2[0]);
    /*** set 3 ***/
    printf ("said it\n");
    printf (message2 + 4);
    printf ("%s", message2 + 4);
    printf ("%s", &message2[4]);
    /*** set 4 ***/
    printf ("x = %i\n", x);
    printf (format, x);


    return 0;
}

/*
TERMINAL OUT:

make 11.12
cc     11.12.c   -o 11.12
11.12.c:26:13: warning: format string is not a string literal
      (potentially insecure) [-Wformat-security]
    printf (message);
            ^~~~~~~
11.12.c:30:13: warning: format string is not a string literal
      (potentially insecure) [-Wformat-security]
    printf (message2);
            ^~~~~~~~
11.12.c:34:13: warning: format string is not a string literal
      (potentially insecure) [-Wformat-security]
    printf (message2 + 4);
            ^~~~~~~~~~~~
3 warnings generated.

./11.12
Programming in C is fun
Programming in C is fun
Programming in C is fun
Programming in C is fun
You said it
You said it
You said it
You said it
said it
said it
said it
said it
x = 100
x = 100
*/
