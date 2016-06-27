/*  CS106B - Programming Abstractions
 *  Programming Abstractions in C++ (2012)
 *  ----------------------------------------------
 *  Wayne H. Noxchi - 3.16 Obenglobish
 *  ----------------------------------------------
 *  08-Jun-2016 02:28 - 08-Jun-2016 02:45
*/

/*  Write a function obenglobish that takes an English word and returns its
    Obenglobish equivalent:
        ob should be added before every vowel in the English word except
        • Vowels that follow other vowels
        • An e that occurs at the end of the word
 */

#include <iostream>
#include <string>
using namespace std;

/* prototype */
bool isVowel(char ch);

/* function */
string obenglobish(string dosh) {
    string oben;
    for (int i = 0; i < dosh.length(); i++) {
        if (!isVowel(dosh[i])) oben += dosh[i];
        else {
            if (i == 0) {
                oben += "ob";
                oben += dosh[i];
            }
            else if (i > 0 && !isVowel(dosh[i - 1]) && !(i == dosh.length() - 1 && dosh[i] == 'e')) {
                oben += "ob";
                oben += dosh[i];
            }
        }
    }
    return oben;
}

/* test */
int main() {
    string dosh, oben;
    while (true) {
        cout << "Enter a word: ";
        getline(cin, dosh);
        if (dosh == "") break;
        string oben = obenglobish(dosh);
        cout << dosh << " -> " << oben << endl;
    }
    return 0;
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

/*  Terminal:

Waynes-MBP:Chapter03-2012 WayNoxchi$ make 3.16_obenglobish
c++     3.16_obenglobish.cpp   -o 3.16_obenglobish
Waynes-MBP:Chapter03-2012 WayNoxchi$ ./3.16_obenglobish
Enter a word: English
English -> obEnglobish
Enter a word: english
english -> obenglobish
Enter a word: spanish
spanish -> spobanobish
Enter a word: Chechen
Chechen -> Chobechoben
Enter a word: Noxchi
Noxchi -> Noboxchobi
Enter a word: Nohchi
Nohchi -> Nobohchobi
Enter a word: Waynakh
Waynakh -> Wobaynobakh
Enter a word: Caucasian
Caucasian -> Cobacobasobin
Enter a word: Turkish
Turkish -> Toburkobish
Enter a word: Zayna
Zayna -> Zobaynoba
Enter a word: Hakan
Hakan -> Hobakoban
Enter a word: Elina
Elina -> obElobinoba
Enter a word:
Waynes-MBP:Chapter03-2012 WayNoxchi$

*/
