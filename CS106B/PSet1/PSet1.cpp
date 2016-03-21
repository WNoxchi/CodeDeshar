// CS106B - Programming Abstractions
// Problem Set 1
// Wayne H Noxchi - 20-Mar-2016 00:44

// Problem 1: Removing all occurences of characters:
// Write a func <CensorString> tht takes 2 strings as input and returns the 1st
// string w all of the chars present in the 2nd removed.

#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int len;
    string tsxa, shi;
    string kxo = "";
    bool yomama = true;

    cout << "Copyright Wayne H Noxchi, 2016 Daymoxk." << endl;
    cout << "---------------------------------------" << endl;
    cout << "Enter 2 strings of text. 1st will be displayed with all characters \
             also in 2nd removed." << endl;
    cout << "H'alxara: ";
    getline(cin, tsxa);
    cout << "Sholgha: ";
    getline(cin, shi);

    for (int i = 0; i < tsxa.length(); i++) {
        yomama = false;
        for (int j = 0; j < shi.length(); j++) {
            if (shi[j] == tsxa[i] && shi[j] != ' ')
                yomama = true;
        }
        if (yomama == false)
            kxo += tsxa[i];
    }

    cout << "---------------------------------------" << endl;
    cout << "Kerlo h'alxara <string>: " << kxo << endl;
}

// ----------------------------------------------------------------------------

// Problem 2: Files and Structs  -  20-Mar-2016 01:33
// Define a struct containing stats: min, max, avg scores. Write a function that
// takes a filename, reads scores from it (1 per line) and returns the struct you
// defined.

// 21-Mar-2016 11:59 (using soln: Ht#8S)

struct statistics {
    int max;
    int min;
    int avg;
}

// Function to read file, keep track of max, min, & total, count to calc avg
statistics CalcStats(string filename) {
    statistics stats;
    // For simple set bounds just beyond known range
    stats.min = 101;
    stats.max = -1;

    int total = 0;
    int count = 0;

    // Open new filestream & check successful
    ifstream infile;
    infile.open(filename.c_str());
    if (infile.fail()) Error("Couldn't read '" + filename + "'");

    while (true) {
        int num;
        in >> num;
        // Check read successful
        if (infile.fail()) break;
        // Update data if needed
        if (num < stats.low) stats.low = num;
        if (num > stats.high) stats.high = num;
        total += num;
        count++;
    }

    stats.avg = double(total)/count;
    infile.close();
    return stats;

}

// ----------------------------------------------------------------------------

// Problem 3: Vectors  -  21-Mar-2016 12:09
// write func <CountLetters> tht takes filename and prints number of times each
// letter of alphabet in file. Bc need print 26 letters, <CountLetters> creates
// a vector.
// (PAC^2 Fig 5-2)

// function prototype
void CountLetters(string filename);

void CountLetters(string filename) {
    Vector<int> alphaList(26)
    ifstream infile;
    infile.open(filename.c_str());
    if (infile.fail()) Error("OH SHIT WE'RE GOIN DOWN LADDY!");
    while (true) {
        int ch = infile.get();
        if (ch == EOF) break;
        if (isalpha(ch)) {
            CountLetters[toupper(ch) - 'A']++;
        }
    }
    infile.close();

    // display
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        cout << CountLetters[ch - 'A'] << " - " << ch << endl;
    }
    return 0;
}

// PSet Solution:
// -------------------------------------------------------------
const int AlphabetSize = 26;

void CountLetters(string filename)
{
    // Open a new filestream and make sure it worked
    ifstream in;
    in.open(filename.c_str());
    if (in.fail()) Error("Couldn't read '" + filename + "'");

    Vector<int> result;

    for (int i = 0;; i < AlphabetSize; i++)
    {
        result.add(0); // must initialize contents
    }

    string line;
    while (true)
    {
        getline(in, line);
        // Check that we got a line
        if (in.fail()) break;

        line = ConvertToLowerCase(line);
        for (int j = 0; j < line.length(); j++)
        {
            int index = line[j] - 'a';                                          // converts character into a number
            if (index >= 0 && index < AlphabetSize) {                           // this makes sure index is a letter (0 - 26)
                int prevTotal = result[index];                                  // prevTotal = value of index of result-vector
                result[index] = prevTotal + 1;                                  // index of result-vector = prevTotal + 1
            }
        }
    }

    for (int k = 0; k < AlphabetSize; k++)
    {
        char currLetter = 'a' + k;
        cout << currLetter << ": " << result [k] << endl;
    }
}
