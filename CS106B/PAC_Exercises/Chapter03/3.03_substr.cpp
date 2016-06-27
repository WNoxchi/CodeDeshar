/*  CS106B - Programming Abstractions
 *  Programming Abstractions in C++ (2012)
 *  --------------------------------------
 *  Wayne H. Noxchi - 3.03_substr.cpp
 *  --------------------------------------
 *  04-Jun-2016 17:14 - 04-Jun-2016 17:29
*/

/** implement a free function substr(str, pos, n) that returns the substring
    of str starting at pos, containing at most n chars.     **/

#include <string>
#include <iostream>
using namespace std;

string substr(string str, int pos, int n) {
    string sub = "";
    /* make sure position is in target */
    if (pos > (str.length() + 1) ) {
        return sub;
    }
    for (int i = 0; i < str.length() - pos; i++) {
        sub += str[pos + i];
        if (i == n) {
            break;
        }
    }
    return sub;
}

/* testing */
int main() {
    string str;
    int pos, n;
    cout << "String: ";
    getline(cin, str);
    cout << "Position: ";
    cin >> pos;
    cout << "Number: ";
    cin >> n;
    cout << "Substring: " << substr(str, pos, n) << endl;
}
