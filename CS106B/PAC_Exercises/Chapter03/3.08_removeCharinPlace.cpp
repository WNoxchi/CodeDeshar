/*  CS106B - Programming Abstractions
 *  Programming Abstractions in C++ (2012)
 *  --------------------------------------------
 *  Wayne H. Noxchi - 3.08_removeCharinPlace.cpp
 *  --------------------------------------------
 *  04-Jun-2016 19:50 - 04-Jun-2016 20:02
*/

/** write a function string removeCharacters(string str, string remove)
    that modifies str by removing parts of it in remove   **/

#include <iostream>
#include <string>
using namespace std;

void removeCharactersinPlace(string & str, string remov) {
    for (int i = 0; i < remov.length(); i++) {
        for (int k = 0; k < str.length(); k++) {
            if (str[k] == remov[i]) {
                str.erase(k, 1);
            }
        }
    }
}

/* testing */
int main() {
    string str, remov;
    cout << "Word or phrase: ";
    getline(cin, str);
    cout << "Characters to remove: ";
    getline(cin, remov);
    removeCharactersinPlace(str, remov);
    cout << str << endl;
}
