// CS106B - Programming Abstractions
// Programming Abstractions in C++
// ------------------------------------------
// Wayne H. Noxchi - 3.04_EqualIgnoreCase.cpp
// ------------------------------------------
// 29-May-2016 21:07 - 29-May-2016 21:42



/** Implement a function EqualIgnoringCase(str1, str2) that returns true if the
two string parameters contain the same sequence of characters ignoring case
distinctions. Implement this once using the convenience functions
from strutils.h and again without.      **/

/* with strutils.h */
// The "easy way" will req. setting up the 2008 StfdC++Lib, & I'm just gonna pass on that.

/* without strutils.h */
#include <string>
#include <iostream>
using namespace std;

bool EqualIgnoringCase(string str1, string str2){
    bool truth = 1;
    int s1 = str1.size(), s2 = str2.size();
    if (s1 != s2)
        truth = 0;
    for (int i = 0; i < s1; i++){
        if (str1[i] != str2[i]){
            truth = 0;
            break;
        }
    }
    cout << "String 1: " << str1.size() << endl;
    cout << "String 2: " << str2.size() << endl;
    return truth;
}

/* testing */
int main(){
    string str1 = "marshal du shug.";
    // string str2 = "marshal du shug.";
    string str2 = "de dik xil. hey.";
    bool truth = EqualIgnoringCase(str1, str2);
    if (truth != 0)
        cout << "True" << endl;
    else
        cout << "False" << endl;
}
