/*  CS50x - Intro to Computer Science
 *  Programming in C
 *-----------------------------------------------------<>
 *  16.04_altMergeLin.c
 *-----------------------------------------------------<>
 *  WNixaloy - 11-Aug-2016 15:58 - 16:41
 */

/*  Write a program that merges lines alternately from two files and writes the
results to stdout. If one file has less lines than the other, the remaining
lines from the larger file should simply be copied to stdout.       */

#include <stdio.h>

int main(void) {
    char inName1[64], inName2[64], outName[64];
    FILE *in1, *in2, *out;
    int c, end = 0, flag = 0;

    // get files
    printf ("1st File: ");
    scanf ("%63s", inName1);

    printf ("2nd File: ");
    scanf ("%63s", inName2);

    printf ("Output filename: ");
    scanf ("%63s", outName);

    // open files
    if ((in1 = fopen(inName1, "r")) == NULL) {
        printf("Unable to open %s\n", inName1);
        return 1;
    }
    if ((in2 = fopen(inName2, "r")) == NULL) {
        printf("Unable to open %s\n", inName2);
        return 2;
    }
    if ((out = fopen(outName, "w")) == NULL) {
        printf("Unable to open %s\n", outName);
        return 3;
    }

    // copy alternate lines of inputs to out
    while (end < 2) {
        c = !flag ? getc(in1) : getc(in2);  // c = getc(in1) if flag = 0, else = getc(in2)
        if (c != EOF) {
            putc (c, out);
        }
        if (c == EOF) {
            end++;
        }
        if (c == '\n' && end == 0) {
            flag = !flag ? 1 : 0; // if flag = 0, set to 1, else = 1 so set to 0
        }
    }

    // close files
    fclose (in1);
    fclose (in2);
    fclose (out);

    printf ("File copy successful.\n");

    return 0;
}
