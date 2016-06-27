/*  CS106B - Programming Abstractions
 *  Programming Abstractions in C++ (2012)
 *  ----------------------------------------------
 *  Wayne H. Noxchi - 3.17 Caesar Sifr
 *  ----------------------------------------------
 *  08-Jun-2016 02:50 - 08-Jun-2016 03:05
*/

// string encodeCaesarCipher(string str, int shift);

#include <iostream>
#include <string>
using namespace std;

/* Encoder */
string encodeCaesarCipher(string str, int shift) {
    string sifrtext;
    for (int i = 0; i < str.length(); i++) {
        if (isalpha(str[i])) {
            if (islower(str[i])) {
                sifrtext += (((str[i] - 'a') + shift) % 26) + 'a';
            } else {
                sifrtext += (((str[i] - 'A') + shift) % 26) + 'A';
            }
        } else sifrtext += str[i];
    }
    return sifrtext;
}

/* testing */
int main() {
    int sifr;
    string text;
    cout << "This program encodes a message using a Caesar cipher.\n"\
            "Enter the number of character positions to shift: ";
    cin >> sifr;
    cin.ignore();
    cout << "Enter a message: ";
    getline(cin, text);
    cout << "Encoded message: " << encodeCaesarCipher(text, sifr) << endl;
}
