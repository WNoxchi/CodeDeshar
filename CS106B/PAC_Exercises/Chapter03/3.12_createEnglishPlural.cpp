/*  CS106B - Programming Abstractions
 *  Programming Abstractions in C++ (2012)
 *  ----------------------------------------------
 *  Wayne H. Noxchi - 3.12_createEnglishPlural.cpp
 *  ----------------------------------------------
 *  07-Jun-2016 23:27 - 07-Jun-2016 23:51
*/


/*  Write a function createRegularPlural(word) that returns the plural of
word formed by following these standard English rules:

a. If the word ends in s,x,z,ch,or sh, add es to the word.
b. If the word ends in a y preceded by a consonant, change the y to ies.
c. In all other cases, add just an s.
Write a test program and design a set of test cases to verify that your
program works.                                                          */

#include <iostream>
#include <string>
using namespace std;

bool isVowel(char x) {
    x = tolower(x);
    if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == 'y') {
        return true;
    } else {
        return false;
    }
}

/* plural function */
string createRegularPlural(string dosh) {
    string EngPlur = dosh;
    int end = dosh.length() - 1;
    if (dosh[end] == 'h') {
        if (dosh[end - 1] == 's' || dosh[end - 1] == 'c') {
            EngPlur += "es";
            return EngPlur;
        } else {
            EngPlur += "s";
            return EngPlur;
        }
    }
    if (dosh[end] == 's' || dosh[end] == 'x' || dosh[end] == 'z') {
        EngPlur += "es";
        return EngPlur;
    }
    if (dosh[end] == 'y') {
        if (!isVowel(dosh[end - 1])) {
            EngPlur[end] = 'i';
            EngPlur += "es";
            return EngPlur;
        }
    } else {
        EngPlur += "s";
        return EngPlur;
    }
    return EngPlur;
}

/* test */
int main() {
    string dosh;
    cout << "This program returns the English-plural of any entered word.\n"\
            "Enter a word then press RETURN." << endl;
    cin >> dosh;
    cout << "English plural of \"" << dosh << "\" - " << createRegularPlural(dosh)\
                                                        << endl;
}
