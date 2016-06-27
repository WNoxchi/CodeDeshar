/*  CS106B - Programming Abstractions
 *  Programming Abstractions in C++ (2012)
 *-------------------------------------------------<*>
 *  Wayne H. Noxchi - 4.06 defaultExtension.cpp
 *-------------------------------------------------<*>
 * 25-Jun-2016 03:00 - 03:17
*/

/*  write the fileLib.h function: defaultExtension that adds a default Extension
    onto a fileroot if abscent; w/ option to force.         */

#include <iostream>
#include <string>
using namespace std;

string getRoot(string filename);
string getExtension(string filename);

string defaultExtension(string filename, string extension) {
    bool Force = 0;
    if (extension[0] == '*') Force = true;
    int len = filename.length();
    string kerloFileName = "";
    if (getExtension(filename) == "") Force = true;    // if no extension then add extension
    if (Force == true) {
        kerloFileName = getRoot(filename);
        // handle missing period in extension
        if (extension[0] != '.' && extension[1] != '.') kerloFileName += ".";
        // add extension onto root
        for (int i = 0; i < extension.length(); i++) {
            if (extension[i] != '*') kerloFileName += extension[i];
        }
    }
    // return filename as is
    if (!Force) return filename;
    // return new filename
    return kerloFileName;

}

/* implementation */
int main() {
    string filename, extension;
    cout << "Enter File name or root: ";
    cin >> filename;
    cout << "Enter default extension (use «.*» to force default): ";
    cin >> extension;
    cout << "Updated filename: " << defaultExtension(filename, extension) << endl;
}

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
