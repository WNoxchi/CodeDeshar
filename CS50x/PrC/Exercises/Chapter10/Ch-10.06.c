// CS50x - Intro to Computer Science
// Programming in C - Exercise 10.6
// WH Noxchi - 26-Mar-2016 03:28 - 05:00

/***
 *  Write a funct removeString() to remove a specified number of characters
 *  from a char string. 3 args: source string, number chars to remove,
 *  source index.
 ***/

 #include <stdio.h>
 #include <string.h>

int removeString(char source[], int index, int number) {
    int sindex = 0;
    int y = 0;
    // while (source[sindex] != '\0') {
    //     sindex++;
    // }
    sindex = strlen(source);

    char newstring[sindex - number];
    // for (int i = 0; i < strlen(newstring); i++) {
    //     printf("%c", newstring[i]);
    // }

    if ( (index + number) > sindex ) {
        printf("Error: invalid range\n");
        return 1;
    }
    for (int i = 0; i < strlen(source); i++) {
        if (i < index || i > (index + number)) {                            // oy what a mess. dont ask what the - 4 is for..
            newstring[y] = source[i];
            printf("%c", source[i]);                        // it's to stop random chars being added. why? idk..
            y++;
        }
        // x++;
    }
    newstring[strlen(newstring)] = '\0';
    // for (int i = 0; i < strlen(newstring); i++) {
    //     printf("%c", newstring[i]);
    // }
    printf("\n");
    // printf("%c", newstring[25]);
    for (int i = 0; i <= (strlen(source) - strlen(newstring) + 1); i++) {
        printf("%c", newstring[i]);
    }
    printf("\n");
    int m = (strlen(newstring));
    printf("Length newstring: [%i]\n", m);
    printf("[%c]\n", newstring[2]);
    int n = (strlen(source));
    printf("Length Source: [%i]\n", n);
    printf("[%c]\n", source[51]);
    return 0;
}

int main(void) {
    printf("removeString(\"My Anaconda don't want none unless you got Buns Hon!\", 12, 26)\n");
    removeString("My Anaconda don't want none unless you got Buns Hon!", 12, 26);
}

/***
TERMINAL:
Waynes-MBP:Chapter10 WayNoxchi$ ./Ch-10.06
removeString("My Anaconda don't want none unless you got Buns Hon!", 12, 26)
My Anaconda got Buns Hon!
My Anaconda got Buns Hon!
Length newstring: [29]
[ ]
Length Source: [52]
[!]
 ***/
