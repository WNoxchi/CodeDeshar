// CS50x - Intro to Computer Science
// Programming in C - Exercise 10.7
// WH Noxchi - 26-Mar-2016 19:05 - 20:01

/*
 *  Write a funct insertString() to insert one char string into another.
 *  args: source, insertstring, position to be inserted.
 */

#include <stdio.h>
#include <string.h>

void insertString( char source[], char target[], int pos ) {
    char newstring[81];

    /* build up newstring until reach insert position */
    for (int i = 0; i < pos; i++) {
        newstring[i] = source[i];
    }

    /* add target string to newstring */
    for (int i = 0; i < strlen(target); i++) {
        newstring[pos + i] = target[i];
    }

    /* add source past insert position to newstring */
    for (int i = 0; i < ( strlen(source) - pos ); i++) {
        newstring[i + (pos + strlen(target))] = source[pos + i];
    }

    /* another way to update source to newstring */
    for (int i = 0; i < strlen(newstring); i++) {
        source[i] = newstring[i];
    }
    source[strlen(newstring)] = '\0';
}

/* Implementation */
int main(void)
{
    char source[81] = "Marshalla du. Sa ce <<>> yu.";

    /* print original string */
    for (int i = 0; i < strlen(source); i++) {
        printf("%c", source[i]);
    }
    printf("\n");

    insertString (source, "Hakan", 22);

    /* print updated string */
    for (int i = 0; i < strlen(source); i++) {
        printf("%c", source[i]);
    }
    printf("\n");
}
