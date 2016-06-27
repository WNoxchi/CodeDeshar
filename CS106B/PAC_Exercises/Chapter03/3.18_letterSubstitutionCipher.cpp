/*  CS106B - Programming Abstractions
 *  Programming Abstractions in C++ (2012)
 *-------------------------------------------------<*>
 *  Wayne H. Noxchi - 3.18 Letter Substitution Sifer
 *-------------------------------------------------<*>
 * 08-Jun-2016 03:09 - 08-Jun-2016 03:16
*/

/* Implement at 26 character letter substitution cipher. */

#include <iostream>
#include <string>
using namespace std;

/* Encoder */
string encodeSubCipher(string str, string cipher) {
    int cipherindex = cipher.length();
    string sifrtext;
    for (int i = 0; i < str.length(); i++) {
        if (isalpha(str[i])) {
            if (islower(str[i])) {
                sifrtext += (((str[i] - 'a') + tolower(cipher[i % cipherindex]) - 'a') % 26) + 'a';
            } else {
                sifrtext += (((str[i] - 'A') + toupper(cipher[i % cipherindex])  - 'A') % 26) + 'A';
            }
        } else sifrtext += str[i];
    }
    return sifrtext;
}

/* testing */
int main() {
    string text, cipher = "QWERTYUIOPASDFGHJKLZXCVBNM";
    cout << "This program encodes a message using a letter substitution cipher.\n";
    cout << "Substitution Cipher Key: << " << cipher << " >> " << endl;
    cout << "Enter a message: ";
    getline(cin, text);
    cout << "Encoded message: " << encodeSubCipher(text, cipher) << endl;
}

/*

Waynes-MBP:Chapter03-2012 WayNoxchi$ make 3.18_letterSubstitutionCipher
c++     3.18_letterSubstitutionCipher.cpp   -o 3.18_letterSubstitutionCipher
Waynes-MBP:Chapter03-2012 WayNoxchi$ ./3.18_letterSubstitutionCipher
This program encodes a message using a letter substitution cipher.
Substitution Cipher Key: << QWERTYUIOPASDFGHJKLZXCVBNM >>
Enter a message: The Waynakh State of Caucasia.
Encoded message: Jdi Pysvozh Vygan ze Evvpmiee.
Waynes-MBP:Chapter03-2012 WayNoxchi$

*/
