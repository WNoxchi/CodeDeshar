// CS106B Programming Abstractions
// Programming Abstractions in C++
// --------------------------------------------
// Wayne H. Noxchi - 3.10_MadLibs.cpp
// --------------------------------------------
// 30-May-2016 02:22 - 02:33|15:59 - 23:04

/* mad-lib program */
/* display new text file on screen */


#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void ReplaceSubstring(string &str1, string str2, int pos, int len);

int main() {

    string file, temp = "temp.txt", filetext = "", prompt = "", replace = "";
    int pos, len;
    bool endline = 0, tagfound = 0;
    ifstream infile;
    ofstream outfile;

    cout << "Input File: ";
    cin >> file;

    infile.open(file.c_str());
    outfile.open(temp.c_str());

    if (infile.fail()) {
        cout << "File not found.\n";
        return 1;
    }

    while (!infile.eof()) {
        getline(infile, filetext);
        while (endline == 0 && filetext.length() > 0) {
            for (int i = 0; i < filetext.length(); i++) {
                if (filetext[i] == '<') {
                    pos = i;
                }
                if (filetext[i] == '>') {
                    len = i - pos + 1;
                    tagfound = 1;
                    break;
                }
                if (i == filetext.length() - 1) {
                    endline = 1;
                }
            }
            if (tagfound == 1) {
                for (int i = pos; i < pos + len; i++) {
                    prompt += filetext[i];
                }
                cout << prompt << ": ";
                cin >> replace;
                ReplaceSubstring(filetext, replace, pos, len);
                prompt = "", replace = "";
            }
            tagfound = 0;
        }
        outfile << filetext << endl;
        endline = 0;
        // filetext = "";
    }
    infile.close();
    outfile.close();

    cout << "-------------------------------------------" << endl;

    infile.open(temp.c_str());
    if (infile.fail()) {
        cout << "Error openning temporary file.\n";
        return 1;
    }
    while (!infile.eof()) {
        getline(infile, filetext);
        cout << filetext << endl;
        // filetext = "";
    }
    infile.close();

    // cin.ignore();
    cout << "     bam baby!" << endl;
}


void ReplaceSubstring(string & str1, string str2, int pos, int len) {
    if (pos == -1) return;
    str1.erase(pos, len);
    str1.insert(pos, str2);
}
