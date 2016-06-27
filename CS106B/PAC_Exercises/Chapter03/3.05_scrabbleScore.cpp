/*  CS106B - Programming Abstractions
 *  Programming Abstractions in C++ (2012)
 *  ----------------------------------------
 *  Wayne H. Noxchi - 3.05_scrabbleScore.cpp
 *  ----------------------------------------
 *  04-Jun-2016 17:49 - 04-Jun-2016 18:22
*/

/** write a program that redas in words and prints their score in Scrabble  **/

#include <string>
#include <iostream>
#include <cctype>
using namespace std;

// int score(char x);
int calcScore(char letter);
int main() {
    string dosh;
    int score = 0;
    cout << "Word or phrase for scrabble score: ";
    getline(cin, dosh);

    /* tally score */
    for (int i = 0; i < dosh.length(); i++) {
        score += calcScore(dosh[i]);
    }
    cout << "Word Score: " << score << " points." << endl;
}

int calcScore(char letter) {
    switch (toupper(letter)) {
        case 'A': case 'E': case 'I': case 'L': case 'N':
        case 'O': case 'R': case 'S': case 'T': case 'U':
            return 1;
        case 'D': case 'G':
            return 2;
        case 'B': case 'C': case 'M': case 'P':
            return 3;
        case 'F': case 'H': case 'V': case 'W': case 'Y':
            return 4;
        case 'K':
            return 5;
        case 'J': case 'X':
            return 8;
        case 'Q': case 'Z':
            return 10;
        default:
            return 0;
    }
}

/*
int daysInMonth(Month month, int year) {
    switch (month) {
        case APRIL: case JUNE:
        case SEPTEMBER:
        case NOVEMBER:
            return 30;
        case FEBRUARY:
            return (isLeapYear(year)) ? 29 : 28;
        default:
            return 31;
    }
}

bool isVowel(char ch) {
    switch (ch) {
        case 'A': case 'E': case 'I': case 'O': case 'U':
        case 'a': case 'e': case 'i': case 'o': case 'u':
            return true;
        default:
           return false;
    }
}

*/
