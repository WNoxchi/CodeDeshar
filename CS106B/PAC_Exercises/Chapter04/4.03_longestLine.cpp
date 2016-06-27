/*  CS106B - Programming Abstractions
 *  Programming Abstractions in C++ (2012)
 *-------------------------------------------------<*>
 *  Wayne H. Noxchi - 4.03 longestLine.cpp
 *-------------------------------------------------<*>
 *  23-Jun-2016 11:36 - 11:57
*/

/*
    Write a program that prints out the longest line in a file entered by the
    user. If several lines are all equally long, your program should print out
    the first such line.
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/* implementation */
int main() {
    ifstream infile;
    string filename = "", fileline, longLine = "";
    int maxLen = 0;

    while (filename == "" || infile.fail()) {
        cout << "Filename: ";
        getline(cin, filename);
        infile.open(filename.c_str());
        if (infile.fail()) {
            cout << "File not found" << endl;
        }
    }

    while (!infile.eof()) {
        getline(infile, fileline);
        if (fileline.length() > maxLen) {
            maxLen = fileline.length();
            longLine = fileline;
        }
    }
    cout << "Longest line " << maxLen << " characters long:\n" \
            << longLine << endl;

    infile.close();
}
