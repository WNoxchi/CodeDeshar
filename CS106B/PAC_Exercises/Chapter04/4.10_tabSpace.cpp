/*  CS106B - Programming Abstractions
 *  Programming Abstractions in C++ (2012)
 *-------------------------------------------------<*>
 *  Wayne H. Noxchi - 4.10 tabSpace.cpp
 *-------------------------------------------------<*>
 *  27-Jun-2016 09:31 - 27-Jun-2016 10:11
*/

/*  Write a program that copies an input file to an output file, replacing all
    tab characters by the appropriate number of spaces.                         */

/*  I'm assuming here the tab character is /t   */

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
    // variables
    ifstream infile;
    ofstream outfile;
    string line, outline = "", filename = "";
    int TABSIZE = 4;
    // prompt for file
    while (filename == "" || infile.fail()) {
        cout << "Filename: ";
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
    outfile.open("outputfile.txt");
    // copy operation
    while (!infile.eof()) {
        getline(infile, line);
        outline = "";
        // procedure over length of string
        for (int i = 0; i < line.length(); i++) {
            // check for tab
            if (line[i] != '/') {
                outline += line[i];
            }
            // handle tabs
            else {
                if (line[i+1] == 't' && (i + 1) < line.length()) {
                    for (int k = 0; k < TABSIZE; k++) {
                        outline += ' ';
                    }
                    i += 2;
                }
            }
        }
        // copy output line to output file
        outfile << outline << endl;
        outline = "";
    }
    // close files
    outfile.close();
    infile.close();
}
