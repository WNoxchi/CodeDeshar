/*  CS106B - Programming Abstractions
 *  Programming Abstractions in C++ (2012)
 *  ---------------------------------------------
 *  Wayne H. Noxchi - 3.09_removeDoubleLetter.cpp
 *  ---------------------------------------------
 *  04-Jun-2016 20:04 - 04-Jun-2016 20:12
*/

/** write a string that returns a new string with all double letters removed **/

#include <iostream>
#include <string>
using namespace std;

string removeDoubleLetter(string str) {
    string kerl = "";
    kerl += str[0];
    for (int i = 1; i < str.length(); i++) {
        if (str[i] != str[i-1] || !isalpha(str[i])) {
            kerl += str[i];
        }
    }
    return kerl;
}

/* testing */
int main() {
    string dosh;
    cout << "Enter word or phrase with doubled letters: ";
    getline (cin, dosh);
    cout << removeDoubleLetter(dosh) << endl;
}
