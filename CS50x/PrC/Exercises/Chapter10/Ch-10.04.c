// CS50x - Intro to Computer Science
// Programming in C - Exericse 10.04
// WH Noxchi - 26-Mar-2016 01:30 - 02:27

/*  Write a funct substring() to extract a portion of a character string.
 *  substring ( source, start, count, result);
 *  start is index number into source, indicating 1st number of characters
 *  count is number of characters to be extracted.
 *  result is array of characters to contain substring.
 *  make sure funct inserts a null character at end of substring result.
 *  Make funct check the number of charactes is in string. If not, just end
 *  at end of string.
 */

#include <stdio.h>

void substring ( char source[], int start, int count, char result[] ) {
    for (int i = 0; i < count; i++) {
        if (source[start + i] == '\0') {
            break;
        }
        else {
            result[i] = source[start + i];
            // printf("%c", result[i]);
        }
    }
    result += '\0';
    // return result;
}

int main(void)
{
    char result[81];
    // substring ("YOLO 4 EVA", 5, 5, result);
    substring ("two words", 4, 20, result);

    printf ("\n");
    for (int i = 0; i < 5; i++) {
        printf("%c", result[i]);
    }
    printf("\n");
}
