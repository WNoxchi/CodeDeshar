/*
 *  File: randword.cpp - Wayne H. Noxchi
 *  Implementation of the randword class
 *  -----------------------------------
 *  CS106B - Programming Abstractions
 *  Programming Abstractions in C++ (2008)
 *  -----------------------------------
 *  31-May-2016 12:29 - 31-May-2016 13:21
 */

#include "randword.h"
#include <iostream>
#include <string>
#include <fstream>
#include "random.h"
using namespace std;

// *  Takes the name of a data file contianing a list
// *  of words, 1 per line, & reads them into an array
// *  declared as a static global var in the implementation.
void InitDictionary(string filename) {
    int arraySize = 0;
    string text, *globalArray;
    ifstream infile;

    /* open file, check for failure */
    infile.open(filename.c_str());
    if (infile.fail()) {
        cout << "Could not find file: \"" << filename << "\""<< endl;
        return;
    }

    /* build static array */
    while (true) {
        getline(infile, text);
        arraySize++;

        /* termination condition */
        if (infile.fail()) break;
    }
    globalArray = new string[arraySize];

    /* clear failstate to reuse file while open */
    infile.clear();
    /* reset input stream position of file */
    infile.seekg(0);

    /* write words to static array */
    for (int i = 0; i < arraySize; i++) {
        getline(infile, text);
        globalArray[i] = text;
    }
}

// *  Returns a word chosen at random from the internally
// *  maintained array.
string ChooseRandomWord() {
    string dosh;
    int index;
    index = randomInteger(0, arraySize - 1);
    dosh = globalArray[index];
    return dosh;
}
