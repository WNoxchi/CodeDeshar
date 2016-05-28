/*
 *  CS106B Programming Abstractions
 *  Problem Set 1
 *  -------------------------------
 *  Wayne H. Noxchi
 *  25-May-2016 12:45 - 25-May-2016 19:38
 */

// Write a function CensorString tht takes 2 strings as input and returns first
// string w all characters present in 2nd, removed.
// Write method modifying orig string; & method returning new string

#include <iostream>
#include <string>
using namespace std;

string CensorString1(string text, string remov);
void CensorString2(string & text, string remov);

int main(){
    // copyright; prompt version; display version; prompt strings
    int version = 1, verdisplay;
    string text, remov;
    cout << "          CensorString 2016 Wayne H Noxchi          " << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "Version 1: returns new string. Version 2: modify orig." << endl;
    cout << "Enter '1' for Ver1, any character for Ver2:" << endl;
    cin >> version;

    if (version == 1) {
        verdisplay = 1;
    } else {
        verdisplay = 2;
    }
    // realized I can just use \n
	cin.ignore();
    cout << "Version " << verdisplay << " chosen.\nPlease say some sentence or phrase:\n";
    getline(cin, text);
    cout << "Text to search & remove:\n";
    getline(cin, remov);
    if (version == 1) {
        cout << CensorString1(text, remov) << endl;
    } else {
        CensorString2(text, remov);
        cout << text << endl;
    }
    return 0;
}

// returns a new string
string CensorString1(string text, string remov){
    string newstring = "";
    for (int i = 0; i < text.length(); i++){
        bool in = false;
        for (int j = 0; j < remov.length(); j++){
            if (text[i] == remov[j]){
                in = true;
                break;
            }
        }
        if (!in){
            newstring += text[i];
        }
    }
    return newstring;
}

// modifies original string
void CensorString2(string & text, string remov){
    for (int i = 0; i < remov.length(); i++){
        int pos = 0;
        // stopping before end const; .find(string, pos) <-- starts from string[pos]
        while((pos = text.find(remov[i], pos)) != string::npos){
            text.replace(pos, 1, "");
        }
    }
}

// Files and Structs - define a struct containing max/min/avg scores. Then Write
// a function taking a filename, reading scores, (1 per line; 0 <= score <= 100)
// and returning struct you defined. Function should only make 1 pass per line.

struct Stats {
    int min;
    int max;
    double avg;
}

CalcStats(string filename){
    // initialize the Stats struct
    Stats stats;
    stats.min = -1;
    stats.max = 101;

    int total = 0;
    int count = 0;

    // open file
    ifstream infile;
    infile.open(filename.c_str());
    if (infile.fail()) Error("Could not open '" + filename + "'");

    // run thru data/update
    while(true) {
        int num;
        infile >> num;  // so the input file stream will automatically go line by line; (>>) stops at white space
        // check successful read
        if (infile.fail()) break;
        if (num > stats.max) stats.max = num;
        if (num < stats.min) stats.min = num;
        count ++;
        total += num;
    }
    // calc avg & close file
    stats.avg = double(total)/count;
    infile.close();
    return stats;
}

// Problem 3: Vectors  - 26-May-2016 08:41 - 10:07
// Write a function CountLetters that takes a filename & prints # of times each
// letter of alphabet appears in that file.

void CountLetters(string filename);

const int Alpha = 26;

CountLetters(string filename){
    ifstream infile;
    infile.open(filename, c_str());
    if (infile.fail()) Error("error");

    Vector<int> countVec;

    for (int i = 0; i < Alpha; i++){
        countVec.add(0);
    }

    string line;
    int prevTot, index;

    while(true){
        getline(infile, line);
        if (infile.fail()) break;
        line = ConvertToLowerCase(line);
        for (int j = 0; j < line.length(); j++){
            // if (line[j] - 'a' <= 0 && line[j] - 'a' >= Alpha){
            //     index = line[i] - 'a';
            index = line[i] - 'a';
            if (index >= 0 && index <= Alpha){
                prevTot = countVec[index];
                countVec[index] = prevTot + 1;
            }
        }
    }
    infile.close();
    for (int k = 0; k < Alpha; k++){
        letter = 'A' + k;
        cout << letter << ": " << countVec[k] << endl;
    }
}
