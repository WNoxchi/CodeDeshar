// CS106B - Programming Abstractions
// Programming Abstractions in C++
// ------------------------------------------
// Wayne H. Noxchi - 3.05_Capitalize.cpp
// ------------------------------------------
// 29-May-2016 21:48 - 22:00|22:58 - 23:02

/** Implement a function Capitalize(str) that returns a string in which the
    initial character is capitalized (if it is a letter) and all other letters
    are converted so that they appear in lowercase form. Characters other than
    letters are not affected. For example, Capitalize("BOOLEAN") and
    Capitalize("boolean") should each return the string "Boolean".  **/

#include <string>
#include <iostream>
#include <ctype.h>
using namespace std;

/* function */
string Capitalize(string &str){
    // error handling
    if (str.size() == 0){
        cout << "Error: 'nothing' doesn't count." << endl;
        return str;
    }
    if (isalpha(str[0]) != 0)
        str[0] = toupper(str[0]);
        return str;
}

/* testing */
int main(){
    string text;
    cout << "write something" << endl;
    cin >> text;
    text = Capitalize(text);
    cout << text << endl;
}
