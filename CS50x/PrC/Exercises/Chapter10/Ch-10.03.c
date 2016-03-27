// CS50x - Intro to Computer Science
// Programming in C - Exericse 10.03
// WH Noxchi - 26-Mar-2016 01:15 - 26-Mar-2016 01:27

// the countWords funct from program 10.7 and 10.8 incorrectly counts a word
// containing apostraphes as two separate words. Modify to correct
// Extend funct to count a sequence of positive or negative numbers,
// including any embedded commas and periods, as a single word.

/* NOTE: Not sure I understand the bit about a sequence of numbers. For that
 *       just have the function ignore 1 space between number values.
 */
int countWords (const char string[])
{
    int i, wordCount = 0;
    bool lookingForWord = true, alphabetic (const char c);

    for ( i = 0; string[i] != '\0'; ++i )
        if ( alphabetic(string[i]) || string[i] != ' ' )
        {
            if ( lookingForWord )
            {
                ++wordCount;
                lookingForWord = false;
            }
        }
        else
            lookingForWord = true;

    return wordCount;
}

// IMPLEMENTATION:
// #include <stdio.h>
// #include <stdbool.h>
//
// /*****  Insert alphabetic function here  *****/
// bool alphabetic (const char c)
// {
//     if ( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') )
//         return true;
//     else
//         return false;
// }
//
// /*****  Insert readLine function here  *****/
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
//
// /***** Insert countWords function here  *****/
// int countWords (const char string[])
// {
//     int i, wordCount = 0;
//     bool lookingForWord = true, alphabetic (const char c);
//
//     for ( i = 0; string[i] != '\0'; ++i )
//         if ( alphabetic(string[i]) || string[i] != ' ' )
//         {
//             if ( lookingForWord )
//             {
//                 ++wordCount;
//                 lookingForWord = false;
//             }
//         }
//         else
//             lookingForWord = true;
//
//     return wordCount;
// }
//
// int main (void)
// {
//     char text[81];
//     int totalWords = 0;
//     int countWords (const char string[]);
//     void readLine (char buffer[]);
//     bool endOfText = false;
//
//     printf ("Type in your text.\n");
//     printf ("When you are done, press 'RETURN'.\n\n");
//
//     while ( ! endOfText )
//     {
//         readLine (text);
//
//         if ( text[0] == '\0' )
//             endOfText = true;
//         else
//             totalWords += countWords (text);
//     }
//
//     printf ("\nThere are %i words in the above text.\n", totalWords);
//
//     return 0;
// }
