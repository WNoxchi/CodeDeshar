/*
 *  File: randword.h - Wayne H. Noxchi
 *  -----------------------------------
 *  CS106B - Programming Abstractions
 *  Programming Abstractions in C++ (2008)
 *  -----------------------------------
 *  30-May-2016 23:50 - (complete): 31-May-2016 00:44
 */

/** randword.h defines two functions: InitDictionary and ChooseRandomWord.
    InitDictionary takes the name of a data file containing a list of words,
    1 per line, & reads it into an array declared as a static global var
    in the implementation.
    ChooseRandomWord takes no args, and returns a word chosen at random from
    the internally maintained array.
**/

#ifndef _randword_h
#define _randword_h
#include <string>
using namespace std;

/*
 *  Function: InitDictionary
 *  Usage: arr = InitDictionary(string filename);
 *  ---------------------------------------------
 *  Takes the name of a data file contianing a list
 *  of words, 1 per line, & reads them into an array
 *  declared as a static global var in the implementation.
 */

void InitDictionary(string filename);

/*
 *  Function: ChooseRandomWord
 *  Usage: ChooseRandomWord();
 *  ---------------------------------------------
 *  Returns a word chosen at random from the internally
 *  maintained array.
 */

string ChooseRandomWord();

#endif
