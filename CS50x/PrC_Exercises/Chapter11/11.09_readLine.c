/*  CS50x - Intro to Computer Science
 *  Programming in C
 *-----------------------------------------------------<>
 *  11.09_readLine.c
 *-----------------------------------------------------<>
 *  WNixaloy - 06-Aug-2016 22:50
 */

// 06-Aug-2016 22:50 - will need to revisit this to better understand it

/*  Rewrite the readLine function from Chapter 10 so that it uses a character
    pointer rather than an array.     */

#include <stdio.h>

void readLine(char *buffer) {
    char ch;
    int i = 0;

    do {
        ch = getchar();
        *buffer++ = ch;
    }
    while (ch != '\n');

    *(buffer - 1) = '\0';
}

int main (void) {
    char line[81];

    for (int i = 0; i < 3; i++) {
        readLine(line);
        printf("%s\n\n", line);
    }

    return 0;
}

// Author's Solution:
// ------------------
// 11-9
// ------
// /* Function to read a line of text from the terminal
//    (pointer version)    */
//
// void  readLine (char  *buffer)
// {
//     char  character;
//
//     do {
//         character = getchar ();
//         *buffer++ = character;
//     }
//     while ( character != '\n' );
//
//     *(buffer - 1) = '\0';
// }

// ------------------------
// from: https://github.com/peterforgacs/programming-in-c-book/blob/master/chapter11/ex9_readLine.c
//
// #include <stdio.h>
//
// void readLine ( char *ptr )
// {
//     char character;
//
//     do {
//         character = getchar ();
//         *ptr      = character;
//         ++ptr;
//     } while ( character != '\n');
//
//     *ptr = '\0';
// }
//
// int main(void){
//     char line[81];
//
//     readLine (line);
//
//     char *ptr = line;           // Printing out with a pointer
//     while ( *ptr != '\0' ){
//         printf("%c", *ptr);
//         ++ptr;
//     }
//
//     printf("%s", line);         // Printing out as a character string
//
//     return 0;
// }


// -------------------------------------
// // Program 10.6 Reading Lines of Data
// #include <stdio.h>
//
// int main (void)
// {
//     int i;
//     char line[81];
//     void readLine (char buffer[]);
//
//     for ( i = 0; i < 3; ++i )
//     {
//         readLine (line);
//         printf ("%s\n\n", line);
//     }
//
//     return 0;
// }
//
// // Function to read a line of text from the terminal
//
// void readLine (char buffer[])
// {
//     char character;
//     int i = 0;
//
//     do
//     {
//         character = getchar ();
//         buffer[i] = character;
//         ++i;
//     }
//     while ( character != '\n' );
//
//     buffer[i - 1] = '\0';
// }
