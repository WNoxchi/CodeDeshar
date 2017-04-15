/*
 *  File: Hangman.cpp - Wayne H. Noxchi
 *  -----------------------------------
 *  CS106B - Programming Abstractions
 *  Programming Abstractions in C++ (2008)
 *  -----------------------------------
 *  30-May-2016 23:50 - 31-May-2016 01:27|31-May-2016 13:30 - 15:18
 */

#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include "randword.h"
using namespace std;

void setupGame();
int main() {

    /* load words, welcome */
    setupGame();

    /* while chances > 0 */

    /* display */

    /* ask guess */

    /* check guess */

    /* update display */

    /* Win */

    /* Lose */

}

void setupGame() {
    string filename, playgame = "";
    cout << "\n        Welcome to the game of Hangman.   -   Wayne Noxchi - 31-May-2016\n";
    for (int i = 0; i < 80; i++) cout << "-";
    cout << "\nWould you like to play a game? (n: no, RETURN: yes): ";
    cin >> playgame;

    if (playgame == "n") {
        return;
    } else {
        cout << "\nHangman requires a text file of words to start. Text file: ";
        cin >> filename;
        InitDictionary(filename);
        cout << "\nDictionary loaded. Let's get started.\n";
    }
}













/* completed hangman */
// cout << "+-------+\n"
// cout << "|       |\n"
// cout << "|       0 \n"
// cout << "|     /-+-/'\n"
// cout << "|    `  |\n"
// cout << "|      / \\\n"
// cout << "|     ^   ^\n"
// cout << "|\n"
// cout << "|\n"
// cout << "+---------\\\n"
