/*  CS50x - Intro to Computer Science
 *  Programming in C
 *-----------------------------------------------------<>
 *  16.04_altMergeLin.c
 *-----------------------------------------------------<>
 *  WNixaloy - 11-Aug-2016 16:56 - 17:28
 */

/*  Write a program that writes columns m through n of each line of a file to
stdout. Have the program accept the values of m and n from the terminal window. */

#include <stdio.h>

int main(void) {
    char inName[64], c;  // NOTE: can have c as int instead w same results
    int m, n, col;
    FILE *in;

    // get file and parameters
    printf("Filename: ");
    scanf("%63s", inName);
    printf("Start & End Columns (mn): ");
    scanf("%i%i", &m, &n);

    if ((in = fopen(inName, "r")) == NULL) {
        printf("Unable to open file.\n");
        return 1;
    }
    // do the thing
    else {
        col = 1;    // start at 1 xa ur not zero-indexing the parameters
        while ((c = getc(in)) != EOF) {
            if (c == '\n') {
                putchar('\n');
                col = 0;
            }
            else if (col < m) {     // adds whitespace before
                putchar(' ');
            }
            else if (col >= m && col <= n) {    // use else st you don't double RETURN
                putchar(c);
            }
            col++;  // note loop will always start w col = 1
        }
    }
    fclose(in);

    return 0;
}
