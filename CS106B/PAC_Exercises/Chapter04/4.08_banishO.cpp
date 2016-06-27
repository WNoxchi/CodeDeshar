/*  CS106B - Programming Abstractions
 *  Programming Abstractions in C++ (2012)
 *-------------------------------------------------<*>
 *  Wayne H. Noxchi - 4.08 Banish O
 *-------------------------------------------------<*>
 * 25-Jun-2016 03:55 - 04:48
*/

/* write a program that removes every instances of a specified set of
   characters from an input file, and write to an output file.          */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/* prototypes */
string getRoot(string filename);
string getExtension(string filename);

/* function */
string banishO(string & line, string & banish) {
    bool bdizh;
    string kerlaline = "";
    for (int i = 0; i < line.length(); i++) {
        bdizh = false;
        for (int k = 0; k < banish.length(); k++) {
            if (line[i] == banish[k]) bdizh = true;
        }
        if (!bdizh) kerlaline += line[i];
    }
    return kerlaline;
}

/* proogram */
int main() {
    cout << endl;
    string filename = "", fileline, banish, Greek = "-Greek";
    ifstream infile;
    ofstream outfile;

    // prompt for file
    while (filename == "" || infile.fail()) {
        cout << "Text Filename: ";
        getline(cin, filename);
        infile.open(filename.c_str());
        if (infile.fail()) {
            cout << "File not found" << endl;
        }
    }
    // reset filestream fail state if it failed
    if (infile.fail()) {
        infile.clear();
        infile.seekg(0, ios::beg);
    }

    Greek = (getRoot(filename).append(Greek).append(getExtension(filename)));
    // cout << Greek;       //  test stub
    outfile.open(Greek.c_str());

    cout << "File loaded." << "Characters to banish: ";
    getline(cin, banish);
    cout << "Characters loaded. Processing." << endl;

    // display original file
    cout << "Original file: " << filename << "\n---------------------------------" << endl;
    while (!infile.eof()) {
        getline(infile, fileline);
        cout << fileline << endl;
    }
    // resest filestream fail state
    infile.clear();
    infile.seekg(0, ios::beg);

    // display banished file
    cout << "Banished file: " << Greek << "\n---------------------------------" << endl;
    while (!infile.eof()) {
        getline(infile, fileline);
        outfile << banishO(fileline, banish) << endl;
        // getline(outfile, fileline);
        // cout << fileline << endl;
    }

    infile.close();
    outfile.close();
}

/* helpers */
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
