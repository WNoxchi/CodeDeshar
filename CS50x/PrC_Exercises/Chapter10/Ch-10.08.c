// CS50x - Intro to Computer Science
// Programming in C - Exercise 10.8
// WH Noxchi - 26-Mar-2016 20:14 - Debug: 21:04 - Finish: 21:31

/*
 *  Using findString, removeString, insertString, write a funct replaceString()
 *  tht takes 3 args: replaceString (source, s1, s2);
 *  & replaces s1 inside source with s2.
 *  Call findString to locate s1 in source, call removeString to remove s1 frm
 *  source, call insertString to insert s2 into source at position.
 */

/***
 *  NOTE: I found my printing issue: use a while loop instead of a for loop to
 *        print static char string arrays. A for loop will iterate past the
 *        EOL character and produce nonsense.
 ***/

#include <stdio.h>
#include <string.h>

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


/**  replaceString  **/
void replaceString(char source[], char s1[], char s2[]) {
    /* findString to det start index. */
    int index = findString(source, s1);
    if (index == -1) printf("\n----------------------------\nERROR: UNABLE TO FIND STRING\n----------------------------\n");

    /* removeString to remov s1 from source */
    int s1Len = strlen(s1);
    removeString(source, index, s1Len);

    /* insertString insrt s2 into source */
    insertString(source, s2, index);
}

/** Implementation **/
int main(void)
{
    char source[81] = "Marshalla du. Sa ce <<Hakan>> yu.";
    char s1[81] = "Hakan";
    char s2[81] = "Elina";

    printStr(source);
    printStr(s1);
    printStr(s2);

    replaceString(source, s1, s2);

    printStr(source);
}
