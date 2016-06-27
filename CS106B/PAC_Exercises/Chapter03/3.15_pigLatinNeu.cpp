/*  CS106B - Programming Abstractions
 *  Programming Abstractions in C++ (2012)
 *  ----------------------------------------------
 *  Wayne H. Noxchi - 3.15 pigLatinNeu
 *  ----------------------------------------------
 *  08-Jun-2016 00:55 - 08-Jun-2016 01:14
*/

/*  Rewrite the wordToPigLatin function so that any word that begins with
    a capital letter in the English line still begins with a capital letter
    in Pig Latin.                                                        */


#include <iostream>
#include <string>
#include <cctype>
using namespace std;

/* Function prototypes */
string lineToPigLatin(string line);
string wordToPigLatin(string word);
int findFirstVowel(string word);
bool isVowel(char ch);

/* Main program */
int main() {
    cout << "This program translates English to Pig Latin." << endl;
    string line;
    cout << "Enter English text: ";
    getline(cin, line);
    string translation = lineToPigLatin(line);
    cout << "Pig Latin output: " << translation << endl;
    return 0;
}

/*
 * Function: lineToPigLatin
 * Usage: string translation = lineToPigLatin(line);
 * -------------------------------------------------
 * Translates each word in the line to Pig Latin, leaving all other
 * characters unchanged.  The variable start keeps track of the index
 * position at which the current word begins.  As a special case,
 * the code sets start to -1 to indicate that the beginning of the
 * current word has not yet been encountered.
 */

string lineToPigLatin(string line) {
    string result;
    int start = -1;
    for (int i = 0; i < line.length(); i++) {
        char ch = line[i];
        if (isalpha(ch)) {
            if (start == -1) start = i;
        } else {
            if (start >= 0) {
                result += wordToPigLatin(line.substr(start, i - start));
                start = -1;
            }
            result += ch;
        }
    }
    if (start >= 0) result += wordToPigLatin(line.substr(start));
    return result;
}

/*
 * Function: wordToPigLatin
 * Usage: string translation = wordToPigLatin(word);
 * -------------------------------------------------
 * This function translates a word from English to Pig Latin using
 * the rules specified in the text.  The translated word is
 * returned as the value of the function.
 */

string wordToPigLatin(string word) {
    bool upthatbitch = 0;                                                       // I did This
    if (isupper(word[0])) {                                                     // I did This
        upthatbitch = 1;                                                        // I did This
        word[0] = tolower(word[0]);                                             // I did This
    }                                                                           // I did This

    int vp = findFirstVowel(word);
    if (vp == -1) {
        if (upthatbitch == 1) word[0] = toupper(word[0]);                       // I did This
        return word;
    } else if (vp == 0) {
        if (upthatbitch == 1) word[0] = toupper(word[0]);                       // I did This
        return word + "way";
    } else {
        string head = word.substr(0, vp);
        string tail = word.substr(vp);
        if (upthatbitch == 1) tail[0] = toupper(tail[0]);                       // I did This
        return tail + head + "ay";
    }
}

/*
 * Function: findFirstVowel
 * Usage: int k = findFirstVowel(word);
 * ------------------------------------
 * Returns the index position of the first vowel in word.  If
 * word does not contain a vowel, findFirstVowel returns -1.
 */

int findFirstVowel(string word) {
    for (int i = 0; i < word.length(); i++) {
        if (isVowel(word[i])) return i;
    }
    return -1;
}

/*
 * Function: isVowel
 * Usage: if (isVowel(ch)) . . .
 * -----------------------------
 * Returns true if the character ch is a vowel.
 */

bool isVowel(char ch) {
    switch (ch) {
        case 'A': case 'E': case 'I': case 'O': case 'U':
        case 'a': case 'e': case 'i': case 'o': case 'u':
            return true;
        default:
            return false;
    }
}

/* Terminal Output:

Waynes-MBP:Chapter03-2012 WayNoxchi$ ./3.15_pigLatinNeu
This program translates English to Pig Latin.
Enter English text: Hello dude What is up?
Pig Latin output: Ellohay udeday Atwhay isway upway?
Waynes-MBP:Chapter03-2012 WayNoxchi$

*/
