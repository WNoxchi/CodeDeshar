/*  CS106B - Programming Abstractions
 *  Programming Abstractions in C++ (2012)
 *  ----------------------------------------
 *  Wayne H. Noxchi - 3.07_removeChar.cpp
 *  ----------------------------------------
 *  04-Jun-2016 18:46 - 04-Jun-2016 18:55
*/

/** write a function string removeCharacters(string str, string remove)
    that returns a new string of everything in str minus  whats in remove   **/

#include <iostream>
#include <string>
using namespace std;

string removeCharacters(string str, string remov) {
    string kerl = "";
    bool found = false;
    for (int i = 0; i < str.length(); i++) {
        for (int k = 0; k < remov.length(); k++) {
            if (str[i] == remov[k]) {
                found = true;
            }
        }
        if (!found) {
            kerl += str[i];
        }
        found = false;
    }
    return kerl;
}

/* testing */
int main() {
    string str, remov;
    cout << "Word or phrase: ";
    getline(cin, str);
    cout << "Characters to remove: ";
    getline(cin, remov);
    cout << removeCharacters(str, remov) << endl;
}
