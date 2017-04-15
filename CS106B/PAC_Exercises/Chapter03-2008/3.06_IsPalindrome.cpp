// CS106B Programming Abstractions
// Programming Abstractions in C++
// ---------------------------------------
// Wayne H. Noxchi - 3.06_IsPalindrome.cpp
// ---------------------------------------
// 29-May-2016 23:05 - 23:23

/** A palindrome is a word that reads identically backward and forward, such
    as level or noon. Write a predicate function IsPalindrome(str) that returns
    true if the string str is a palindrome. In addition, design and write a
    test program that calls IsPalindrome to demonstrate that it works.  **/

#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

/* function */
bool IsPalindrome(string str){
    bool truth = 1;
    int size = str.size();
    for (int i = 0; i < (size-1)/2; i++){
        cout << "[" << i << ":" << str[i] << "] - [" << size-1-i << ":" << str[size-1-i] << "]" << endl;
        if (str[i] != str[size-1-i]){
            truth = 0;
            return truth;
        }
    }
    return truth;
}

/* testing */
int main(){
    string text = "amanaplanacanalpanama";
    cout << "       IsPalindrome - Wayne Noxchi - 29-Sel-2016 23:07" << endl;
    for (int i = 0; i < 80; i++)
        cout << "-";
    cout << endl;
    if (IsPalindrome(text) == 1)
        cout << "Palindrom yu" << endl;
    else
        cout << "Palindrom yats" << endl;
}
