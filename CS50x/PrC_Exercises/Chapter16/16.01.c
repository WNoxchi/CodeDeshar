/*  CS50x - Intro to Computer Science
 *  Programming in C
 *-----------------------------------------------------<>
 *  16.01.c
 *-----------------------------------------------------<>
 *  WNixaloy - 11-Aug-2016 15:26
 */

//*-----------------------------------------------------<>
// // Program 16.1 Illustrating the printf Formats
// #include <stdio.h>
//
// int main(void) {
//     char        c = 'X';
//     char        s[] = "abcdefghijklmnopqrstuvwxyz";
//     int         i = 425;
//     short int   j = 17;
//     unsigned int    u = 0xf179U;
//     long int    l = 75000L;
//     long long int   L = 0x1234567812345678LL;
//     float       f = 12.978F;
//     double      d = -97.4583;
//     char        *cp = &c;
//     int         *ip = &i;
//     int         c1, c2;
//
//     printf ("Integers:\n");
//     printf ("%i %o %x %u\n", i, i, i, i);
//     printf ("%x %x %#x %#X\n", i, i, i, i);
//     printf ("%+i % i %07i %.7i\n", i, i, i, i);
//     printf ("%i, %o %x %u\n", j, j, j, j);
//     printf ("%i %o %x %u\n", u, u, u, u);
//     printf ("%ld %lo %lx %lu\n", l, l, l, l);
//     printf ("%lli %llo %llx %llu\n", L, L, L, L);
//
//     printf ("\nFloats and Doubles:\n");
//     printf ("%f %e %g\n", f, f, f);
//     printf ("%.2f %.2e\n", f, f);
//     printf ("%.0f %.0e\n", f, f);
//     printf ("%7.2f %7.2e\n", f, f);
//     printf ("%f %e %g\n", d, d, d);
//     printf ("%.*f\n", 3, d);
//     printf ("%*.*f\n", 8, 2, d);
//
//     printf ("\nCharacters:\n");
//     printf ("%c\n", c);
//     printf ("%3c%3c\n", c, c);
//     printf ("%x\n", c);
//
//     printf ("\nStrings:\n");
//     printf ("%s\n", s);
//     printf ("%.5s\n", s);
//     printf ("%30s\n", s);
//     printf ("%20.5s\n", s);
//     printf ("%-20.5s\n", s);
//
//     printf ("\nPointers:\n");
//     printf ("%p %p\n\n", ip, cp);
//
//     printf ("This%n is fun.%n\n", &c1, &c2);
//     printf ("c1 = %i, c2 = %i\n", c1, c2);
//
//     return 0;
// }
//*-----------------------------------------------------<>
// Program 16.2 Copying Characters from Standard Input to Standard Output
// // Program to echo characters until an end of file
//
// #include <stdio.h>
//
// int main(void) {
//     int c;
//
//     while ( (c = getchar()) != EOF )
//         putchar (c);
//
//     return 0;
// }
//*-----------------------------------------------------<>
// Program 16.3 Copying Files
// Program to copy one file to another

#include <stdio.h>

int main(void) {
    char inName[64], outName[64];
    FILE *in, *out;
    int c;

    // get file and output files

    printf ("Enter name of file to be copied: ");
    scanf ("%63s", inName);
    printf ("Enter name of output file: ");
    scanf ("%63s", outName);

    // open input and output files

    if ( (in = fopen (inName, "r")) == NULL ) {
        printf ("Can't open %s for reading.\n", inName);
        return 1;
    }

    if ( (out = fopen (outName, "w")) == NULL ) {
        printf ("Can't open %s for writing.\n", outName);
        return 2;
    }

    // copy in to out

    while ( (c = getc (in)) != EOF )
        putc (c, out);

    // Close open files

    fclose (in);
    fclose (out);

    printf ("File has been copied.\n");

    return 0;
}
// okay holy shit this thing actually copies pdfs.. damn C!
