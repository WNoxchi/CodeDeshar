/*  CS106B - Programming Abstractions
 *  Programming Abstractions in C++ (2012)
 *  ----------------------------------------------
 *  Wayne H. Noxchi - 3.11_isSentencePalindrom.cpp
 *  ----------------------------------------------
 *  07-Jun-2016 22:59 - 07-Jun-2016 23:22
*/

/*  Write a predicate function isSentencePalindrome(str) that returns true
    if the string str fits this definition of a sentence palindrome.    */

#include <iostream>
#include <string>
using namespace std;

/* I'll do this recursively by creating a new alfanumeric string */

/* recursive function */
bool checkPal(string alfanu, int p1, int p2) {
    if (p1 >= p2) {
        return true;
    } else {
        return alfanu[p1] == alfanu[p2] && checkPal(alfanu, p1 + 1, p2 - 1);
    }
}

/* wrapper function */
bool isSentencePalindrome(string str) {
    string alfanu;                                                              // C++ auto inits <string> to empty string
    for (int i = 0; i < str.length(); i++) {
        if (isalnum(str[i])) {
            alfanu += tolower(str[i]);
        }
    }
    // cout << alfanu << endl;
    if (alfanu.length() == 1) {
        return true;
    } else {
        return checkPal(alfanu, 0, alfanu.length() - 1);
    }
}

/* testing */

int main () {
    bool baq;
    string sent;
    cout << "This program tests for sentence palindromes.\n"\
            "Indicate the end of input with a blank line." << endl;
    getline(cin, sent);
    baq = isSentencePalindrome(sent);
    if (baq == true) {
        cout << "This sentence is a palindrome." << endl;
    } else if (baq == false) {
        cout << "This sentence is not a palindrome." << endl;
    }
}
