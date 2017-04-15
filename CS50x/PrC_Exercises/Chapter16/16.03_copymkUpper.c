/*  CS50x - Intro to Computer Science
 *  Programming in C
 *-----------------------------------------------------<>
 *  16.03_copymkUpper.c
 *-----------------------------------------------------<>
 *  WNixaloy - 11-Aug-2016 15:28 - 15:56
 */

/* Write a program to copy one file to another, replacing all lowercase
characters with their uppercase equivalents.    */

#include <stdio.h>

int lowalpha(char c);
char mkUpper(char c);

int main(void) {
    char inName[64], outName[64];
    FILE *in, *out;
    int c;

    // get files
    printf ("File to copy: ");
    scanf ("%63s", inName);
    printf ("Output filename: ");
    scanf ("%63s", outName);

    // open files
    if ((in = fopen(inName, "r")) == NULL) {
        printf ("Unable to open %s\n", inName);
        return 1;
    }
    if ((out = fopen(outName, "w")) == NULL) {
        printf ("Unable to open %s\n", outName);
        return 2;
    }

    // copy in --> out
    while ((c = getc(in)) != EOF) {
        // change lower to upper case
        if (lowalpha(c)) {
            c = mkUpper(c);
        }
        putc (c, out);
    }

    // close files
    fclose (in);
    fclose (out);

    printf ("File copy successful.\n");

    return 0;
}

// helper functions:

int lowalpha(char c) {
    if ((c >= 'a') && (c <= 'z')) {
        return 1;
    } else {
        return 0;
    }
}

char mkUpper(char c) {
    c = (c - 'a' + 'A');
    return c;
}
