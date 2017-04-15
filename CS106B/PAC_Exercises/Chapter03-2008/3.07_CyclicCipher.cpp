// CS106B Programming Abstractions
// Programming Abstractions in C++
// ---------------------------------------
// Wayne H. Noxchi - 3.07_CyclicCipher.cpp
// ---------------------------------------
// 29-May-2016 23:27 - 23:53

#include <iostream>
#include <ctype.h>
#include <string>
using namespace std;

/* function */
string CyclicCipher(string & str, int key){
    int size = str.size();
    for (int i = 0; i < size; i++){
        if (isalpha(str[i]) != 0){
            if (islower(str[i]) != 0){
                str[i] = (str[i] - 'a' + key) % 26 + 'a';
            }
            else {
                str[i] = (str[i] - 'A' + key) % 26 + 'A';
            }
        }
    }
    return str;
}

/* program */
int main(){
    string text = "Marshal du, sa ce Hakan yu. I ce Elina yu. We are gonna rock the boat. Hard.";
    int key = 4;
    cout << text << endl;
    cout << CyclicCipher(text, key) << endl;
}

// did testing: C++ strings are very easy: can just add & treat index as ASCII
// string text = "a";
// text[0] += 'b' - 'a';
// cout << text << endl;
// Result: input 'a', output 'b'
