/*  CS106B - Programming Abstractions
 *  Programming Abstractions in C++ (2012)
 *-------------------------------------------------<*>
 *  Wayne H. Noxchi - 4.07 Greek to Me
 *-------------------------------------------------<*>
 * 25-Jun-2016 03:26 - 03:48
*/

/*
    Write a program that reads characters from an input file and displays them
    on the console after making the appropriate random substitutions. Your
    program should replace every uppercase character in the input by a random
    uppercase character and every lowercase character by a random lowercase
    one. Nonalphabetic characters should remain unchanged.
*/

// For usage of rand() see: http://www.cplusplus.com/reference/cstdlib/rand/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

/* function */
string makeGreek(string line) {
    string Greek = "";
    int Lam;
    for (int i = 0; i < line.length(); i++) {
        if (isalpha(line[i])) {
            if (isupper(line[i])) Greek += ( 'A' + (Lam = rand() % 26));
            if (islower(line[i])) Greek += ( 'a' + (Lam = rand() % 26));
        } else {
            Greek += line[i];
        }
    }
    // cout << Greek << endl;
    return Greek;
}

/* implementation */
int main() {
    ifstream infile;
    string fileline, filename = "";

    while (filename == "" || infile.fail()) {
        cout << "Filename: ";
        getline(cin, filename);
        infile.open(filename.c_str());
        if (infile.fail()) {
            cout << "File not found" << endl;
        }
    }

    // display text of file:
    cout << "File text: " << endl;
    while (!infile.eof()) {
        getline(infile, fileline);
        cout << fileline << endl;
    }
    // resest filestream fail state
    infile.clear();
    infile.seekg(0, ios::beg);          // need to learn abt this line
    // display 'Greek' file text:
    cout << "\n'Greek' text: " << endl;
    while (!infile.eof()) {
        getline(infile, fileline);
        cout << makeGreek(fileline) << endl;
    }

    infile.close();
}
