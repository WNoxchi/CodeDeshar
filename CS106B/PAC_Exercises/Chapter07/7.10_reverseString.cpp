/*  CS106B - Programming Abstractions
 *  Programming Abstractions in C++ (2012)
 *-------------------------------------------------<*>
 *  Wayne H. Noxchi - 7.10 reverse String
 *-------------------------------------------------<*>
 * 09-Jun-2016 04:09 - 04:23
*/

// Write a recursive function that takes a string as argument and returns the
// reverse of that string. The prototype for this function should be
//     string reverse(string str);
// and the statement
//     cout << reverse("program") << endl;

#include <iostream>
#include <string>
using namespace std;

/* function */
string reverse(string str) {
    if (str.length() == 1) return str;
    else {
        return reverse(str.substr(str.length() - 1, 1)) += reverse(str.substr(0, str.length() - 1));
    }
}

/* testing */
int main() {
    string text;
    cout << "Enter text to be reversed: " << endl;
    getline(cin, text);
    cout << reverse(text) << endl;
}
