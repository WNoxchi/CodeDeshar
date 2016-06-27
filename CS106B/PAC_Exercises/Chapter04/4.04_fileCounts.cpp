/*  CS106B - Programming Abstractions
 *  Programming Abstractions in C++ (2012)
 *-------------------------------------------------<*>
 *  Wayne H. Noxchi - 4.04 fileCounts.cpp
 *-------------------------------------------------<*>
 *  23-Jun-2016 20:54 | 22:17
*/

/*
    Write a program that reads a file and reports how many lines, words, and
    characters appear in it. For the purposes of this program, a word consists
    of a consecutive sequence of any characters except whitespace characters.
    The counts in the output should be displayed in a column that is aligned on
    the right but which expands to fit the data.
*/

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

/* struct */
struct FStats {
    int deshnash;
    int moghash;
    int chars;
};

/* function */
void calcStats(string & line, FStats & stats) {
    bool flip = 0;

    // increment lines
    stats.moghash += 1;

    int len = line.length();
    // count chars
    for (int i = 0; i < len; i++) {
        if (line[i] != ' ') {
            stats.chars += 1;
            if (!flip) {
                flip = 1;
                stats.deshnash += 1;
            }
        } else {
            flip = 0;
        }
    }
}

/* implementation */
int main() {
    // init stats
    FStats stats;
    stats.deshnash = 0;
    stats.moghash = 0;
    stats.chars = 0;

    ifstream infile;
    string filetext, filename = "";

    /* open file */
    while (infile.fail() || filename == "") {
        cout << "Filename: ";
        getline(cin, filename);
        infile.open(filename.c_str());

        /* if fail: report */
        if (infile.fail()) {
            cout << "File not found.\n";
        }
    }

    while (!infile.eof()) {
        getline(infile, filetext);
        calcStats(filetext, stats);
        // cout << stats.moghash << endl;
    }
    cout << "--------------------\n";
    cout << stats.deshnash << "  " << stats.moghash << "  " << stats.chars << endl;
}


// Old code:

// count words
// if (i > 0) {
//     if (line[i - 1] != ' ' && line[i] == ' ') {
//         stats.deshnash += 1;
//     }
    // count sentences
    // if ((line[i - 1] != "." || line[i - 1] != "!" || line[i - 1] != "?")\
    //     && (line[i] == "." || line[i] == "!" || line[i] == "?"))
    // {
    //     stats.sentences += 1;
    // }
// }
