/*  CS106B - Programming Abstractions
 *  Programming Abstractions in C++ (2012)
 *-------------------------------------------------<*>
 *  Wayne H. Noxchi - 4.05 fileLib.cpp
 *-------------------------------------------------<*>
 * 25-Jun-2016 02:38 - 02:54
*/

/* implement the functions getRoot and getExtension, described in fileLib.h     */

/* this is a very simple version and will not check for filenames with multiple
   periods, & will return an empty string if no root or exten found.            */

#include <iostream>
#include <string>
using namespace std;

string getRoot(string filename) {
    string root = "";
    int i = 0, len = filename.length();
    while (filename[i] != '.' && i < len) {
        root += filename[i];
        i++;
    }
    return root;
}

string getExtension(string filename) {
    int len = filename.length();
    string exten = "";
    int i = 0;
    while (i < len && filename[i] != '.') {
        i++;
        if (filename[i] == '.') {
            for (int k = 0; k < len - i; k++) {
                exten += filename[k + i];
            }
        }
    }
    return exten;
}

/* implementation */
int main() {
    string filename;
    cout << "Enter Filename: ";
    cin >> filename;
    cout << "Filename Extension: «" << getExtension(filename) << "» "\
            << "Filename Root: «" << getRoot(filename) << "»" << endl;
}
