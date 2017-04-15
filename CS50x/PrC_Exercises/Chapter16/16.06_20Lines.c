/*  CS50x - Intro to Computer Science
 *  Programming in C
 *-----------------------------------------------------<>
 *  16.04_altMergeLin.c
 *-----------------------------------------------------<>
 *  WNixaloy - 11-Aug-2016 17:32 - 17:54
 */

/*  Write a program that displays the contents of a file at the terminal 20
lines at a time. At the end of each 20 lines, have the program wait for a
character to be entered from the terminal. If the character is the letter q,
the program should stop the display of the file; any other character should
cause the next 20 lines from the file to be displayed.                  */

#include <stdio.h>

int main(void) {
    FILE *in;
    char inName[64], com, c;
    int line = 0;

    printf("Filename: ");
    scanf("%63s", inName);

    if ((in = fopen(inName, "r")) == NULL) {
        printf("Unable to open file\n");
        return 1;
    }

    while (com != 'q' && (c = getc(in)) != EOF) {
        putchar(c);
        if (c == '\n') {
            line++;
        }
        if (line == 20) {
            line = 0;
            printf("\nRead next 20 lines? (enter any key to continue; q to quit): ");
            scanf("%c", &com);
        }
    }
    fclose(in);
    return 0;
}
