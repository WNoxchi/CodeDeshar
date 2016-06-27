/*  CS106B - Programming Abstractions
 *  Programming Abstractions in C++ (2012)
 *  --------------------------------------
 *  Wayne H. Noxchi - 3.04_capitalize.cpp
 *  --------------------------------------
 *  04-Jun-2016 17:37 - 04-Jun-2016 17:46
*/

/** implement a function capitalize(str) that returns a string in which initial
    char capitalized and all others converted to lowercase.     **/

#include <string>
#include <iostream>
#include <cctype>
using namespace std;

/* I'm going to cheat & use isalpha() instead of ASCII char codes */
string capitalize(string str) {
    int len = str.length();
    for (int i = 0; i < len; i++) {
        if (i == 0 && isalpha(str[i])) {
            str[i] = toupper(str[i]);
        }
        else if (isalpha(str[i])) {
            str[i] = tolower(str[i]);
        }
    }
    return str;
}

/* testing */
int main() {
    string input;
    cout << "Enter string: ";
    getline(cin, input);
    cout << capitalize(input) << endl;
}
