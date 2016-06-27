/*  CS106B - Programming Abstractions
 *  Programming Abstractions in C++ (2012)
 *  ---------------------------------------------
 *  Wayne H. Noxchi - 3.10_replaceAll.cpp
 *  ---------------------------------------------
 *  04-Jun-2016 20:20 - 04-Jun-2016 20:46
*/

/** write function replaceAll(string str, char c1, char c2); that returns copy
    of str w/ every instnce of c1 replaced by c2        **/

#include <string>
#include <cctype>
#include <iostream>
using namespace std;

string replaceAll(string str, char c1, char c2) {
    string kerl = "";
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != c1) {
            kerl += str[i];
        } else if (str[i] == c1) {
            kerl += c2;
        }
    }
    return kerl;
}

/* testing */
int main() {
    string dosh;
    char c1, c2;
    cout << "Enter word or phrase: ";
    getline (cin, dosh);
    cout << "Character to be replaced: ";
    cin >> c1;
    cout << "Replacement Character: ";
    cin >> c2;
    cout << replaceAll(dosh, c1, c2) << endl;
}
