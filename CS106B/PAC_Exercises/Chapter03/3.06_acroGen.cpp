/*  CS106B - Programming Abstractions
 *  Programming Abstractions in C++ (2012)
 *  ----------------------------------------
 *  Wayne H. Noxchi - 3.06_acroGen.cpp
 *  ----------------------------------------
 *  04-Jun-2016 18:29 - 04-Jun-2016 18:37
*/

/** write a program that automatically generates acronyms from input string  **/

#include <iostream>
#include <string>
using namespace std;

string acroGen(string str) {
    string acro = "";
    if (isalpha(str[0])) {
        acro += toupper(str[0]);
    }
    for (int i = 1; i < str.length(); i++) {
        if (isalpha(str[i]) && !isalpha(str[i-1])) {
            acro += toupper(str[i]);
        }
    }
    return acro;
}

int main() {
    string dosh;
    cout << "Enter somthing to be Acronymized: ";
    getline(cin, dosh);
    cout << acroGen(dosh) << " - \"" << dosh << "\"" << endl;
}
