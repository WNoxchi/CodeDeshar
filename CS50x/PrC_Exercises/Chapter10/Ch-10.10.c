// CS50x - Intro to Computer Science
// Programming in C - Exercise 10.10
// WH Noxchi - 28-Mar-2016 05:51

/*
 * Write a funct dictionarySort() tht sorts a dictionary as defined in
 * Programs 10.9 & 10.10 into alphabetical order.
 */

 /* Clean Solution Function: */

 // Restart: 28-Mar-2016 20:00
 // Finish: 28-Mar-2016 23:14

 void dictionarySort( struct entry dictionary[]) {

     /* determine # Э's in dictionary */
     int entries = 0;
     while (dictionary[entries].word[0] != '\0') {
         entries++;
     }

     /* build place-holder */
     struct entry temp[entries];

     /* cycle through entries */
     for (int i = 0; i < entries - 1; i++) {
         for (int j = 1; j < entries; j++) {
             if (compareStrings(dictionary[i].word, dictionary[i+1].word) == 1) {

                 /* swapping Э's */
                 temp[i] = dictionary[j];
                 dictionary[j] = dictionary[i];
                 dictionary[i] = temp[i];
             }
         }
     }
 }

 /***
 // Solution from: http://stackoverflow.com/questions/30948290/cant-sort-array-of-structures-alphabetically
 void dictionarySort(struct entry dictionary[]) {

     struct entry temp[100];
     int entries = 0;

     while (dictionary[entries].word[0] != '\0') {
         entries++;
     }

     for (int i = 0; i < entries - 1; i++) {
         for (int k = 0; dictionary[i].word[k] != '\0'; k++) {
             if (dictionary[i].word[k] > dictionary[i+1].word[k]) {
                 temp[i] = dictionary[i];
                 dictionary[i] = dictionary[i+1];
                 dictionary[i+1] = temp[i];
                 break;
             }
             else if (dictionary[i].word[k] < dictionary[i+1].word[k]) {
                 break;
             }
         }
     }
 }

  ***/

 /***    WORKING IMPLEMENTATION:     ***/

 // #include <stdio.h>
 // #include <string.h>
 //
 // struct entry
 // {
 //     char word[15];
 //     char definition[50];
 // };
 //
 // int compareStrings(const char s1[], const char s2[]);
 //
 // void dictionarySort( struct entry dictionary[]) {
 //
 //     /* determine # Э's in dictionary */
 //     int entries = 0;
 //     while (dictionary[entries].word[0] != '\0') {
 //         entries++;
 //     }
 //
 //     /* build place-holder */
 //     // struct entry temp[100];
 //     struct entry temp[entries];
 //
 //
 //     /* cycle through entries */
 //     for (int i = 0; i < entries - 1; i++) {
 //         for (int j = 1; j < entries; j++) {
 //             if (compareStrings(dictionary[i].word, dictionary[i+1].word) == 1) {
 //
 //                 /* replaceString() temp[i].word & .definition with dictionary[j] */
 //                 // replaceString(temp[i].word, temp[i].word, dictionary.word[j]);
 //                 // replaceString(temp[i].definition, temp[i].definition, dictionary[j].definition);
 //                 temp[i] = dictionary[j];
 //
 //                 /* dictionary[i] to dictionary[j] */
 //                 // replaceString(dictionary[j].word, dictionary[j].word, dictionary[i].word);
 //                 // replaceString(dictinoary[j].definition, dictionary[j].definition, dictionary[i].definition);
 //                 dictionary[j] = dictionary[i];
 //
 //                 /* temp[i] to dictionary[i] */
 //                 // replaceString(dictionary[i].word, dictionary[i].word, temp[i].word);
 //                 // replaceString(dictionary[i].definition, dictionary[i].definition, temp[i].definition);
 //                 dictionary[i] = temp[i];
 //             }
 //         }
 //     }
 // }
 //
 // int main(void)
 // {
 //     struct entry dictionary[100] =
 //         { { "aardvark", "a burrowing African mammal"        },
 //           { "abyss",    "a bottomless put"                  },
 //           { "acumen",   "mentally sharp; keen"              },
 //           { "addle",    "to become confused"                },
 //           { "aerie",    "a high nest"                       },
 //           { "affix",    "to append; attach"                 },
 //           { "agar",     "a jelly made from seaweed"         },
 //           { "ahoy",     "a nautical call of greeting"       },
 //           { "aigrette", "an ornamental cluster of feathers" },
 //           { "ajar",     "partially opened"                  } };
 //
 //     char word[10];
 //     int  entries = 10;
 //
 //     dictionarySort(dictionary);
 //
 //     for (int i = 0; i < 10; i++) {
 //         printf("\n%s\n", dictionary[i].word);
 //     }
 //
 //     return 0;
 // }
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

 // -----------------------------------------------------------------------------
 // -----------------------------------------------------------------------------
 // -----------------------------------------------------------------------------

 /***        OLD JUNK        ***/
 // #include <stdio.h>
 // #include <string.h>
 //
 // _Bool replaceString(char source[], char s1[], char s2[]);
 // int compareStrings(const char s1[], const char s2[]);
 // void insertString(char source[], char target[], int pos);
 // void removeString(char source[], int index, int number);
 // int findString(char source[], char target[]);
 // void printStr(char stringp[]);
 //
 // struct entry
 // {
 //     char word[15];
 //     char definition[50];
 // };
 //
 // void dictionarySort(const struct entry dictionary[]) {
 //     int j = 0;
 //     while (dictionary[j].word[0] != '\0') {
 //         j++;
 //     }
 //     for (int i = 0; i < j; i++) {
 //         if ( compareStrings(dictionary[i].word, dictionary[i+1].word) == 1 ) {
 //             /* swap entries by rewriting them */
 //             insertString(dictionary[99].word, dictionary[i].word, 0);
 //             replaceString(dictionary[i].word, dictionary[i].word, dictionary[i+1].word);
 //             replaceString(dictionary[i+1].word, dictionary[i+1].word, dictionary[99].word);
 //         }
 //     }
 // }
 //
 // /* Implementation */
 // int main(void)
 // {
 //     const struct entry dictionary[100] =
 //         { { "aardvark", "a burrowing African mammal"        },
 //           { "abyss",    "a bottomless put"                  },
 //           { "acumen",   "mentally sharp; keen"              },
 //           { "addle",    "to become confused"                },
 //           { "aerie",    "a high nest"                       },
 //           { "affix",    "to append; attach"                 },
 //           { "agar",     "a jelly made from seaweed"         },
 //           { "ahoy",     "a nautical call of greeting"       },
 //           { "aigrette", "an ornamental cluster of feathers" },
 //           { "ajar",     "partially opened"                  } };
 //
 //     int entries = 10;
 //     char word[15];
 //     int entry;
 //
 //     printf(">>Dictionary:\n\n");
 //     for (int i = 0; i < 10; i++) {
 //         printf("%s\n", dictionary[i].word);
 //     }
 //
 //     dictionarySort(dictionary);
 //
 //     for (int i = 0; i < 10; i++) {
 //         printf("%s\n", dictionary[i].word);
 //     }
 //
 //     return 0;
 // }
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
 //
 // _Bool replaceString (char source[], char s1[], char s2[])
 // {
 //     int index;
 //
 //     // first locate s1 inside the source
 //
 //     index = findString (source, s1);
 //
 //     if ( index == -1 )
 //         return 0;
 //
 //     // now delete s1 from the source
 //
 //     removeString (source, index, stringLength (s1));
 //
 //     // now insert the new string
 //
 //     insertString (source, s2, index);
 //
 //     return 1;
 // }
 //
 // int findString(char source[], char target[]) {
 //     int tindex = 0;
 //     int sindex = 0;
 //     while (target[tindex] != '\0') {
 //         tindex++;
 //     }
 //     while (source[sindex] != '\0') {
 //         sindex++;
 //     }
 //     if (tindex > sindex) return -1;
 //     for (int k = 0; k < (sindex - tindex); k++) {
 //         int i = 0;
 //         while (source[k + i] == target[i]) {
 //             i++;
 //         }
 //         if (i == tindex) return k;
 //     }
 //     return -1;
 // }
 //
 // void removeString(char source[], int index, int number) {
 //     char newstring[81];
 //     int  holder = strlen(source);
 //     int  x = 0;
 //
 //     /* build newstring */
 //     for (int i = 0; i < strlen(source); i++) {
 //         if (i < index || i >= (index + number)) {
 //             newstring[x] = source[i];
 //             x++;
 //         }
 //     }
 //     /* update source to newstring */
 //     for (int i = 0; i < strlen(newstring); i++ ) {
 //         source[i] = newstring[i];
 //     }
 //     source[strlen(newstring)] = '\0';
 //
 // }
 //
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
 //
 // void printStr(char string[]) {
 //     int i = 0;
 //     while (string[i] != '\0') {
 //         printf("%c", string[i]);
 //         i++;
 //     }
 //     printf("\n");
 // }
 //
 // /**  Sorting Algorithm:
 //
 //         dictionarySort() uses lookup() to iterate through each entry in the dict
 //         and sorts them according to the results of compareStrings().
 //
 //  **/
 //
 //
 // /*  OLD JUNK  */
 // // void dictionarySort(const char dictionary[]) {
 // //
 // //     // /* use lookup() to iterate through each Э in the dict */
 // //     // entry = lookup(dictionary
 // //
 // //     /* could I just skip lookup() & iterate myself? */
 // //     int i = 0;
 // //     int temp = 81;
 // //     while ( dictionary[i] != '\0' ) {
 // //         i++;
 // //     }
 // //     for (int j = 0; j < i; j++) {
 // //         if ( compareStrings(dictionary[i], dictionary[i+1]) == -1 ) {
 // //             dictionary[temp] = dictionary[i];
 // //             dictionary[i] = dictionary[i+1];
 // //             dictionary[i+1] = dictionary[temp];
 // //         }
 // //         if ( compareStrings(dictionary[i], dictionary[i+1]) == 1 ) {
 // //             dictionary[temp] = dictionary[i+1];
 // //             dictionary[i+1] = dictionary[i];
 // //             dictionary[i] = dictionary[temp];
 // //         }
 // //     }
 // // }
 //
 // // struct entry dictionarySort(const struct entry dictionary[]) {
 // //     printf("\n>>Dictionary Sort:\n\n");
 // //     int j = 0;
 // //     struct entry newDict[100];
 // //     for (int i = 9; i > -1; i--) {
 // //         newDict[j] = dictionary[i];
 // //     }
 // //     return newDict;
 // // }
