// CS50x - Intro to Computer Science
// Programming in C - Exericse 10.01
// WH Noxchi - 25-Mar-2016 19:08

// Type in and run the 11 programs in this chapter.

// Program 10.1 Concatenating Character Arrays
// Function to concatenate two character arrays

#include <stdio.h>

void concat (char result[], const char str1[], int n1,
                  const char str2[], int n2)
{
    int i, j;

    // copy str1 to result

    for ( i = 0; i < n1; ++i )
        result[i] = str1[i];

    // copy str2 to result

    for ( j = 0; j < n2; ++j )
        result[n1 + j] = str2[j];
}

int main (void)
{
    void concat (char result[], const char str1[], int n1,
                      const char str2[], int n2);
    const char s1[5] = { 'T', 'e', 's', 't', ' '};
    const char s2[6] = { 'W', 'o', 'r', 'k', 's', '.' };
    char  s3[11];
    int   i;

    concat (s3, s1, 5, s2, 6);

    for ( i = 0; i < 11; ++i )
        printf ("%c", s3[i]);

    printf ("\n");

    return 0;
}
// -----------------------------------------------------------------------------
// Program 10.2 Counting the Characters in a String
// Function to count the number of characters in a string

#include <stdio.h>

int stringLength (const char string[])
{
    int count = 0;

    while ( string[count] != '\0' )
        ++count;

    return count;
}

int main (void)
{
    int stringLength (const char string[]);
    const char word1[] = { 'a', 's', 't', 'e', 'r', '\0' };
    const char word2[] = { 'a', 't', '\0' };
    const char word3[] = { 'a', 'w', 'e', '\0' };

    printf ("%i   %i   %i\n", stringLength (word1),
             stringLength (word2), stringLength (word3));

    return 0;
}
// -----------------------------------------------------------------------------
// Program 10.3 Concatenating Character Strings
#include <stdio.h>

int main (void)
{
    void concat (char result[], const char str1[], const char str2[]);
    const char s1[] = { "Test " };
    const char s2[] = { "works." };
    char  s3[20];

    concat (s3, s1, s2);

    printf ("%s\n", s3);

    return 0;
}

// Functiont to concatenate two character strings

void concat (char result[], const char str1[], const char str2[])
{
    int i, j;

    // copy str1 to result

    for ( i = 0; str1[i] != '\0'; ++i )
        result[i] = str1[i];

    // copy str2 to result

    for ( j = 0; str2[j] != '\0'; ++j )
        result[i + j] = str2[j];

    // Terminate the concatenated string with a null character

    result [i + j] = '\0';
}
// -----------------------------------------------------------------------------
// Program 10.4 Testing Strings for Equality
// Function to determine if two strings are equal

#include <stdio.h>
#include <stdbool.h>

bool equalStrings (const char s1[], const char s2[])
{
    int i = 0;
    bool areEqual;

    while ( s1[i] == s2[i] &&
                    s1[i] != '\0' && s2[i] != '\0' )
        ++i;

    if ( s1[i] == '\0' && s2[i] == '\0' )
        areEqual = true;
    else
        areEqual = false;

    return areEqual;
}

int main (void)
{
    bool equalStrings (const char s1[], const char s2[]);
    const char stra[] = "string compare test";
    const char strb[] = "string";

    printf ("%i\n", equalStrings (stra, strb));
    printf ("%i\n", equalStrings (stra, stra));
    printf ("%i\n", equalStrings (strb, "string"));

    return 0;
}
// -----------------------------------------------------------------------------
// Program 10.5 Reading Strings with scanf
// Program to illustrate the %s scanf format characters

#include <stdio.h>

int main (void)
{
    char s1[81], s2[81], s3[83];

    printf ("Enter text:\n");

    scanf ("%s%s%s", s1, s2, s3);

    printf ("\ns1 = %s\ns2 = %s\ns3 = %s\n", s1, s2, s3);
    return 0;
}
// -----------------------------------------------------------------------------
// Program 10.6 Reading Lines of Data
#include <stdio.h>

int main (void)
{
    int i;
    char line[81];
    void readLine (char buffer[]);

    for ( i = 0; i < 3; ++i )
    {
        readLine (line);
        printf ("%s\n\n", line);
    }

    return 0;
}

// Functoin to read a line of text from the terminal

void readLine (char buffer[])
{
    char character;
    int i = 0;

    do
    {
        character = getchar ();
        buffer[i] = character;
        ++i;
    }
    while ( character != '\n' );

    buffer[i - 1] = '\0';
}
// -----------------------------------------------------------------------------
// Program 10.7 Counting Words
// Function to dtermine if a character is alphabetic

#include <stdio.h>
#include <stdbool.h>

bool alphabetic (const char c)
{
    if ( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') )
        return true;
    else
        return false;
}

/* Function to count the number of words in a string */

int countWords (const char string[])
{
    int i, wordCount = 0;
    bool lookingForWord = true, alphabetic (const char c);

    for ( i = 0; string[i] != '\0'; ++i )
        if ( alphabetic(string[i]) )
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

int main (void)
{
    const char text1[] = "Well, here goes.";
    const char text2[] = "And here we go... again.";
    int countWords (const char string[]);

    printf ("%s - words = %i\n", text1, countWords (text1));
    printf ("%s - words = %i\n", text2, countWords (text2));

    return 0;
}
// -----------------------------------------------------------------------------
// Program 10.8 Counting Words in a Piece of Text
#include <stdio.h>
#include <stdbool.h>

/*****  Insert alphabetic function here  *****/
bool alphabetic (const char c)
{
    if ( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') )
        return true;
    else
        return false;
}

/*****  Insert readLine function here  *****/
void readLine (char buffer[])
{
    char character;
    int i = 0;

    do
    {
        character = getchar ();
        buffer[i] = character;
        ++i;
    }
    while ( character != '\n' );

    buffer[i - 1] = '\0';
}

/***** Insert countWords function here  *****/
int countWords (const char string[])
{
    int i, wordCount = 0;
    bool lookingForWord = true, alphabetic (const char c);

    for ( i = 0; string[i] != '\0'; ++i )
        if ( alphabetic(string[i]) )
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

int main (void)
{
    char text[81];
    int totalWords = 0;
    int countWords (const char string[]);
    void readLine (char buffer[]);
    bool endOfText = false;

    printf ("Type in your text.\n");
    printf ("When you are done, press 'RETURN'.\n\n");

    while ( ! endOfText )
    {
        readLine (text);

        if ( text[0] == '\0' )
            endOfText = true;
        else
            totalWords += countWords (text);
    }

    printf ("\nThere are %i words in the above text.\n", totalWords);

    return 0;
}
// -----------------------------------------------------------------------------
// Program 10.9 Using the Dictionary Lookup Program
// Program to use the udctionary lookup program

#include <stdio.h>
#include <stdbool.h>

struct entry
{
    char word[15];
    char definition[50];
};

/*****  Insert equalStrings function here *****/
bool equalStrings (const char s1[], const char s2[])
{
    int i = 0;
    bool areEqual;

    while ( s1[i] == s2[i] &&
                    s1[i] != '\0' && s2[i] != '\0' )
        ++i;

    if ( s1[i] == '\0' && s2[i] == '\0' )
        areEqual = true;
    else
        areEqual = false;

    return areEqual;
}

// function to look up a word inside a dictionary

int lookup (const struct entry dictionary[], const char search[],
            const int entries)
{
    int i;
    bool equalStrings (const char s1[], const char s2[]);

    for ( i = 0; i < entries; ++i )
        if ( equalStrings (search, dictionary[i].word) )
            return i;

    return -1;
}

int main (void)
{
    const struct entry dictionary[100] =
        { { "aardvark", "a burrowing African mammal"        },
          { "abyss",    "a bottomless put"                  },
          { "acumen",   "mentally sharp; keen"              },
          { "addle",    "to become confused"                },
          { "aerie",    "a high nest"                       },
          { "affix",    "to append; attach"                 },
          { "agar",     "a jelly made from seaweed"         },
          { "ahoy",     "a nautical call of greeting"       },
          { "aigrette", "an ornamental cluster of feathers" },
          { "ajar",     "partially opened"                  } };

    char word[10];
    int  entries = 10;
    int  entry;
    int  lookup (const struct entry dictionary[], const char search[],
                 const int entries);

    printf("Enter word: ");
    scanf ("%14s", word);
    entry = lookup (dictionary, word, entries);

    if ( entry != -1 )
        printf ("%s\n", dictionary[entry].definition);
    else
        printf ("Sorry, the word %s is not in my dictionary.\n", word);

    return 0;
}
// -----------------------------------------------------------------------------
// Program 10.10 Modifying the Dictionary Lookup Using Binary Search
// Dictionary lookup program

#include <stdio.h>

struct entry
{
    char word[15];
    char definition[50];
};

// Function to compare two character strings

int compareStrings (const char s1[], const char s2[])
{
    int i = 0, answer;

    while ( s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' )
        ++i;

    if ( s1[i] < s2[i] )
        answer = -1;        /*  s1 < s2  */
    else if ( s1[i] == s2[i] )
        answer = 0;         /*  s1 == s2  */
    else
        answer = 1;         /*  s1 > s2  */

    return answer;
}

// Function to look up a word inside a dictionary

int lookup (const struct entry dictionary[], const char search[],
            const int entries)
{
    int low = 0;
    int high = entries - 1;
    int mid, result;
    int compareStrings (const char s1[], const char s2[]);

    while ( low <= high )
    {
        mid = (low + high) / 2;
        result = compareStrings (dictionary[mid].word, search);

        if ( result == -1 )
            low = mid + 1;
        else if ( result == 1 )
            high = mid - 1;
        else
            return mid;     /*  found it  */
    }

    return -1;              /*  not found  */
}

int main (void)
{
    const struct entry dictionary[100] =
        { { "aardvark", "a burrowing African mammal"        },
          { "abyss",    "a bottomless put"                  },
          { "acumen",   "mentally sharp; keen"              },
          { "addle",    "to become confused"                },
          { "aerie",    "a high nest"                       },
          { "affix",    "to append; attach"                 },
          { "agar",     "a jelly made from seaweed"         },
          { "ahoy",     "a nautical call of greeting"       },
          { "aigrette", "an ornamental cluster of feathers" },
          { "ajar",     "partially opened"                  } };

    int entries = 10;
    char word[15];
    int entry;
    int lookup (const struct entry dictionary[], const char search[],
                const int entries);

    printf ("Enter word: ");
    scanf ("%14s", word);

    entry = lookup (dictionary, word, entries);

    if ( entry != -1 )
        printf ("%s\n", dictionary[entry].definition);
    else
        printf ("Sorry, the word %s is not in my dictionary.\n", word);

    return 0;
}
// -----------------------------------------------------------------------------
// Program 10.11 Converting a String to its Integer Equivalent

#include <stdio.h>

int strToInt (const char string[])
{
    int i, intValue, result = 0;

    for ( i = 0; string[i] >= '0' && string[i] <= '9'; ++i )
    {
        intValue = string[i] - '0';
        result = result * 10 + intValue;
    }

    return result;
}

int main (void)
{
    int strToInt (const char string[]);

    printf ("%i\n", strToInt("245"));
    printf ("%i\n", strToInt("100") + 25);
    printf ("%i\n", strToInt("13x5"));

    return 0;
}
