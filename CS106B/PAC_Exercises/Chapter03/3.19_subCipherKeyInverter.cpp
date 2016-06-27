/*  CS106B - Programming Abstractions
 *  Programming Abstractions in C++ (2012)
 *-------------------------------------------------<*>
 *  Wayne H. Noxchi - 3.19 subCipherKeyInverter.cpp
 *-------------------------------------------------<*>
 * 08-Jun-2016 03:19 - 6:30 | 14:30 - 14:55
*/

/*  write a function invertKey that takes an encryption key and returns
the 26-letter key necessary to decrypt a message encoded with that
encryption key.     */

#include <iostream>
#include <string>
using namespace std;

/* Key Inverter */
string subKeyInverter(string cipher) {
    string inverterKey = "";
    for (int i = 0; i < cipher.length(); i++) {
        // inverterKey += 'A' + ((26 - (cipher[i] - 'A' + 1) ) % 26);
        inverterKey += 'A' + ((26 - (cipher[i] - 'A')) % 26);
    }
    return inverterKey;
}


string encodeSubCipher(string str, string cipher) {
    int cipherindex = cipher.length();
    string sifrtext;
    for (int i = 0; i < str.length(); i++) {
        if (isalpha(str[i])) {
            if (islower(str[i])) {
                sifrtext += (((str[i] - 'a') + tolower(cipher[i % cipherindex]) - 'a' + 0) % 26) + 'a';
            } else {
                sifrtext += (((str[i] - 'A') + toupper(cipher[i % cipherindex])  - 'A' + 0) % 26) + 'A';
            }
        } else sifrtext += str[i];
    }
    return sifrtext;
}

/* testing */
int main() {
    string text, cipher = "QWERTYUIOPASDFGHJKLZXCVBNM", option = "x";
    cout << "----------------------------------------------------" << endl;
    cout << "This program produces an Inverter Key to decode a text Cipher Key.\n";
    cout << "Substitution Cipher Key: << " << cipher << " >> " << endl;
    cout << "Inverter Key:            << " << subKeyInverter(cipher) << " >> " << endl;
    cout << "----------------------------------------------------" << endl;
    while (option != "") {
        cout << "Encode or Decode: ";
        getline(cin, option);
        if (tolower(option[0]) == 'e') {
            cout << "Substitution Cipher. Enter Cipher Key: ";
            getline(cin, cipher);
            cout << "Text to encode: ";
            getline(cin, text);
            cout << encodeSubCipher(text, cipher) << endl;
            cout << "----------------------------------------------------" << endl;
        }
        if (tolower(option[0]) == 'd') {
            cout << "Substitution Key Inverter. Enter Cipher Key: ";
            getline(cin, cipher);
            cout << "Text to encode: ";
            getline(cin, text);
            cout << "Inverted Key: " << subKeyInverter(cipher) << endl;
            cout << "Encode: " << encodeSubCipher(text, cipher) << endl;
            cout << "Decode: " << encodeSubCipher(encodeSubCipher(text, cipher), subKeyInverter(cipher)) << endl;
            cout << "----------------------------------------------------" << endl;
        }
    }
}

/* Pseudocode:
    Key letter - 26 = Inverted Key letter.
*/

/* NOTE:
The issue I had with this was that my encoder was reading a key of 'A' as a 0 shift,
instead of shift by 1. My Decoder is compatible with 'A' = shift(1).

To make it work either: modify encoder to read key 'A' = shift(1) OR:
                        modify decoder to read key 'A' = shift(0)
*/

/*  TERMINAL OUTPUT

Waynes-MBP:Chapter03-2012 WayNoxchi$ make 3.19_subCipherKeyInverter
make: `3.19_subCipherKeyInverter' is up to date.
Waynes-MBP:Chapter03-2012 WayNoxchi$ ./3.19_subCipherKeyInverter
----------------------------------------------------
This program produces an Inverter Key to decode a text Cipher Key.
Substitution Cipher Key: << QWERTYUIOPASDFGHJKLZXCVBNM >>
Inverter Key:            << KEWJHCGSMLAIXVUTRQPBDYFZNO >>
----------------------------------------------------
Encode or Decode: D
Substitution Key Inverter. Enter Cipher Key: QWER
Text to encode: AAAA
Inverted Key: KEWJ
Encode: QWER
Decode: AAAA
----------------------------------------------------
Encode or Decode: D
Substitution Key Inverter. Enter Cipher Key: DAYMOHK
Text to encode: THE WAYNAKH STATE OF CAUCASIA
Inverted Key: XACOMTQ
Encode: WHC KHIQAIT ZDDTC CM FASOOZSD
Decode: THE WAYNAKH STATE OF CAUCASIA
----------------------------------------------------
Encode or Decode:

*/
