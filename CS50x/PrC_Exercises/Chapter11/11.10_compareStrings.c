/*  CS50x - Intro to Computer Science
 *  Programming in C
 *-----------------------------------------------------<>
 *  11.10_compareStrings
 *-----------------------------------------------------<>
 *  WNixaloy - 06-Aug-2016 23:15
 */

// 06-Aug-2016 23:15 - I think I'm starting to understand this black magic

/*  Rewrite the compareStrings function from Chapter 10 to use character
    pointers instead of arrays.     */

#include <stdio.h>

int compareStrings(const char *s1, const char *s2) {
    int i = 0, answer;
    while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0') {
        s1++;
        s2++;
        // printf("%s\n%s\n\n", s1, s2);
    }

    if (*s1 < *s2)
        answer = -1;
    else if (*s1 == *s2)
        answer = 0;
    else
        answer = 1;

    return answer;
}

int main (void) {
    const char s1[30] = "Marshalla du ho";
    const char s2[30] = "Marshalla du mil wu ho?";
    int j = compareStrings(s1, s2);
    printf("%i\n", j);

    return 0;
}

// What's going on inside the while loop:
//
// Waynes-MBP:Chapter11 WayNoxchi$ ./11.10_compareStrings
// arshalla du ho
// arshalla du mil wu ho?
//
// rshalla du ho
// rshalla du mil wu ho?
//
// shalla du ho
// shalla du mil wu ho?
//
// halla du ho
// halla du mil wu ho?
//
// alla du ho
// alla du mil wu ho?
//
// lla du ho
// lla du mil wu ho?
//
// la du ho
// la du mil wu ho?
//
// a du ho
// a du mil wu ho?
//
//  du ho
//  du mil wu ho?
//
// du ho
// du mil wu ho?
//
// u ho
// u mil wu ho?
//
//  ho
//  mil wu ho?
//
// ho
// mil wu ho?
// ----------------
// Terminal:
// -1


// first try garbage:
// ------------------
// int compareStrings(const char *s1, const char *s2) {
//     char *i1, *i2;
//     int answer;
//
//     i1 = s1;
//     i2 = s2;
//     while ( i1 == i2 && i1 != '\0' && s1 '\0' && s2 != '\0' ) {
//         i1++;
//         i2++;
//     }
//
//     if ( *s1 < *s2 )
//         answer = -1;     /*  s1 < s2  */
//     else if ( *s1 == *s2 )
//         answer = 0;      /*  s1 == s2  */
//     else
//         answer = 1;      /*  s1 > s2  */
//
//     return 0;
// }

// Function to compare two character strings (CHAPTER 10)
//
// int compareStrings (const char s1[], const char s2[])
// {
//     int i = 0, answer;
//
//     while ( s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' )
//         ++i;
//
//     if ( s1[i] < s2[i] )
//         answer = -1;        /*  s1 < s2  */
//     else if ( s1[i] == s2[i] )
//         answer = 0;         /*  s1 == s2  */
//     else
//         answer = 1;         /*  s1 > s2  */
//
//     return answer;
// }

// int main (void) {
//     const char s1[10] = "hhzello";
//     const char s2[5] = "hhi";
//     int i = compareStrings(s1, s2);
//     printf("\n%i\n", i);
// }
