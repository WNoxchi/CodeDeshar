// CS106B Programming Abstractions
// Programming Abstractions in C++
// --------------------------------------------
// Wayne H. Noxchi - 3.09_LineWordCharCount.cpp
// --------------------------------------------
// 30-May-2016 00:30 - 30-May-2016 01:52

/** program reads .txt file (user input), displays word, char, line counts. **/

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

/* input filename, output text */
// string readFile(string filename, int & line){

// }

/* implementation */
int main(){
    int dosh = 0, chars = 0, line = 0;

    /* getting file */
    string filename, filetext;
    cout << "Filename: ";
    cin >> filename;

    /* open/read file */
    ifstream infile;
    infile.open(filename.c_str());
    if (infile.fail()) cout << ("File not found.\n");
    // while (infile.get() != EOF){
    while (!infile.eof()){
        line++;
        getline(infile, filetext);
        for (int i = 0; i < filetext.length(); i++){
            if (i == 0 && isalpha(filetext[i]) != 0) dosh++;
            if (filetext[i] == ' ' && isalpha(filetext[i+1]) != 0) dosh++;
            if (filetext[i] != ' ') chars++;
        }
    }
    /* close file */
    infile.close();

    /* display analysis */
    cout << "Lines: " << line << endl;
    cout << "Words: " << dosh << endl;
    cout << "Chars: " << chars << endl;
}
