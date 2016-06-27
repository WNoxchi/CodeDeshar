/*******************************************************************
 * File: FleschKincaid.cpp
 * -----------------------
 * CS106B - Programming Abstractions
 * A program that approximates the Flesch-Kincaid grade level of a
 * piece of text.
 * -----------------------
 * Wayne Noxhci
 * 05-Jun-2016 10:34 - 05-Jun-2016 16:08
 ******************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "tokenscanner.h"
using namespace std;

/* Flesch-Kincaid Statistics object */
struct FKStats {
    int deshnash;
    int sentences;
    int syllables;
};

bool isVowel(char x);
float FKCalc(int deshnash, int sentences, int syllables);

int main() {
    /* init FK */
    FKStats FK;
    FK.deshnash = 0;
    FK.sentences = 0;
    FK.syllables = 0;

    string filetext, filename = "", token, nextoken;
    ifstream infile;
    TokenScanner scanner;

    int len, vowel, sentences;

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

    // int count = 0, counter = 0, boomzi = 0;                                  //DEBUG
    while (!infile.eof()) {
        // counter++;                                                           //DEBUG
        // cout << "IM HERE: " << counter << endl;                              //DEBUG

        /* get line input to Tokenscanner */
        getline(infile, filetext);
        scanner.setInput(filetext);
        sentences = 0;

        /* update FKStats w/ TokenScanner */
        while (scanner.hasMoreTokens()) {
            token = scanner.nextToken();

            /* check if end sentence */
            // if (token == "." || token == "!" || token == "?") {
            //     sentences += 1;
            // }
            /* accept token only if 1st char alphanum */
            while (!isalnum(token[0])) {
                if (token == "." || token == "!" || token == "?") {
                    sentences += 1;
                }
    			if (scanner.hasMoreTokens()) {
    				token = scanner.nextToken();
				} else {
                    break;
                }
                // boomzi++;                                                    //DEBUG
                // cout << " - BOOM!" << boomzi << endl;                        //DEBUG
				// cout << token << endl;                                       //DEBUG
    		}
            /* handle dashes & apostrophes */
            if (scanner.hasMoreTokens()) {
                nextoken = scanner.nextToken();
                if (nextoken == "." || nextoken == "!" || nextoken == "?") {
                    sentences += 1;
                }
                if (nextoken == "-" || nextoken == "'") {       // at this point need check fur more letters/numbers
                    token += nextoken;
                    while (scanner.hasMoreTokens()) {
                        nextoken = scanner.nextToken();
                        if (nextoken == "." || nextoken == "!" || nextoken == "?") {
                            sentences += 1;
                        }
                        if (isalnum(nextoken[0])) {
                            token += nextoken;
                        } else {
                            break;
                        }
                    }
                } else if (isalnum(nextoken[0])) {
                    token += nextoken;
                }
            }
            /* operate on token only if Not both 1 char long & not alphanum */
            if (!(token.length() == 1 && !isalnum(token[0]))) {
                /* word count */
                FK.deshnash += 1;

                /* count syllables */
                vowel = 0;
                len = token.length();
                if (len == 1 && isalpha(token[0])) {
                    vowel = 1;
                } else {
                    for (int i = 1; i < len; i++) {
                        if (isVowel(token[i]) && !isVowel(token[i-1])) {
                            vowel++;
                        }
                    }
                    if (token[len-1] == 'e' && !isVowel(token[len-2])) {
                        vowel--;
                    }
                    if (vowel == 0) {
                        vowel = 1;
                    }
                }
                FK.syllables += vowel;


            }
        }
        sentences -= 1;
        if (sentences <= 0) {
            sentences = 1;
        }
        FK.sentences += sentences;
        // count++;                                                             //DEBUG
        // cout << "IM THERE: " << count << endl;                               //DEBUG
    }
    infile.close();

    // FK.sentences -= 1;                                                         // accnt for endline double counting

    cout << "Deshnash: " << FK.deshnash << endl;
    cout << "Sentences: " << FK.sentences << endl;
    cout << "Syllables: " << FK.syllables << endl;

    float FKGrade = FKCalc(FK.deshnash, FK.sentences, FK.syllables);
    cout << "------------------------------\n";
    cout << "Flesch-Kincaid Grade: " << FKGrade << endl;
}

bool isVowel(char x) {
    x = tolower(x);
    if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == 'y') {
        return true;
    } else {
        return false;
    }
}

float FKCalc(int deshnash, int sentences, int syllables) {
    float grade, C0 = -15.59, C1 = 0.39, C2 = 11.8;
    grade = C0 + C1 * float(deshnash)/sentences + C2 * float(syllables)/deshnash;
    return grade;
}

/*  NOTE: smth I learned: if you're comparing a whole string, use (str == "x")
 *        but if you're comparing an index of that string, use (str[n] == 'x')
 */
