// CS50x - Intro to Computer Science
// Programming in C - Exercise 10.9
// WH Noxchi - 27-Mar-2016 04:04 - 27-Mar-2016 04:12 - Fin: 04:20

/*
 *  Extend replaceString to return bool true or false if the replacement
 *  succeeds. Example use:
 *  do
 *      stillFound = replaceString (text, " ", "");
 *  while   ( stillFound = true );
 * to remove all blank spaces from a text.
 */

/***
 *  NOTE: Noticed a funny bug: the last character of the source string is
 *        copied onto the end at every iteration. I'm leaving it in.
 ***/

#include <stdio.h>
#include <string.h>

/**  function prototypes  **/
void printStr(char string[]);
int findString(char source[], char target[]);
void removeString(char source[], int index, int number);
void insertString(char source[], char target[], int pos);

/**  replaceString extended **/
_Bool replaceString(char source[], char s1[], char s2[]) {
    /* findString to det start index. */
    int index = findString(source, s1);
    if (index == -1) return 0;

    /* removeString to remov s1 from source */
    int s1Len = strlen(s1);
    removeString(source, index, s1Len);

    /* insertString insrt s2 into source */
    insertString(source, s2, index);

    return 1;
}

// replaceString ANSWER:
// bool  replaceString (char  source [], char  s1[], char  s2[])
// {
//     int  index;
//
//     // first locate s1 inside the source
//
//     index = findString (source, s1);
//
//     if ( index == -1 )
//        return  false;
//
//     // now delete s1 from the source
//
//     removeString (source, index, stringLength (s1));
//
//     // now insert the new string
//
//     insertString (source, s2, index);
//
//     return true;
// }

/**  Implementation  **/
int main(void)
{
    char text[] = "This text should have spaces removed.";
    _Bool stillFound = 1;
    printStr(text);
    do {
        stillFound = replaceString (text, " ", "");
    } while( stillFound == 1 );

    printStr(text);
}

/** --------- function definitions --------- **/

void printStr(char string[]) {
    int i = 0;
    while (string[i] != '\0') {
        printf("%c", string[i]);
        i++;
    }
    printf("\n");
}

/**  findString  **/
int findString(char source[], char target[]) {
    int tindex = 0;
    int sindex = 0;
    while (target[tindex] != '\0') {
        tindex++;
    }
    while (source[sindex] != '\0') {
        sindex++;
    }
    if (tindex > sindex) return -1;
    for (int k = 0; k < (sindex - tindex); k++) {
        int i = 0;
        while (source[k + i] == target[i]) {
            i++;
        }
        if (i == tindex) return k;
    }
    return -1;
}

/**  removeString  **/
void removeString(char source[], int index, int number) {
    char newstring[81];
    int  holder = strlen(source);
    int  x = 0;

    /* build newstring */
    for (int i = 0; i < strlen(source); i++) {
        if (i < index || i >= (index + number)) {
            newstring[x] = source[i];
            x++;
        }
    }
    /* update source to newstring */
    for (int i = 0; i < strlen(newstring); i++ ) {
        source[i] = newstring[i];
    }
    source[strlen(newstring)] = '\0';

    /* printf check */
    printf("removeString: ");
    printStr(source);

}

/**  insertString  **/
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

    /* printf check */
    printf("insertString: ");
    printStr(source);
}

// ANSWER:
// void insertString (char source[], char s[], int i) {
//     int j, lenStr, lenSrc;
//
//     /* first, find out how big the two strings are */
//     lenSrc = stringLength(source);
//     lenStr = stringLength(s);
//
//     /* sanity check here -- note that i == lenSrc effectively
//        concatenates s onto the end of source */
//
//     if (i > lenSrc)
//         return;
//
//     /* now we have to move the characters in source down from the point
//        to make room for s. Note that we copy the string from the end to
//        avoid overwriting characters in source. We also copy the
//        terminating null (j starts at lenStr) as well since the final
//        result must be null-terminated. */
//
//     for ( j = 0; j < lenStr; ++j )
//         source [j + i] = s[j];
// }


/*** TERMINAL OUT:

Waynes-MacBook-Pro:Chapter10 WayNoxchi$ ./Ch-10.09
This text should have spaces removed.
removeString: Thistext should have spaces removed.
insertString: Thistext should have spaces removed.
removeString: Thistextshould have spaces removed..
insertString: Thistextshould have spaces removed..
removeString: Thistextshouldhave spaces removed...
insertString: Thistextshouldhave spaces removed...
removeString: Thistextshouldhavespaces removed....
insertString: Thistextshouldhavespaces removed....
removeString: Thistextshouldhavespacesremoved.....
insertString: Thistextshouldhavespacesremoved.....
Thistextshouldhavespacesremoved.....
Waynes-MacBook-Pro:Chapter10 WayNoxchi$

 ***/
