// CS106B - Programming Abstractions
// Programming Abstractions in C++ (2008)
// Exercise 3.02 ConsecutiveHeads.cpp
// --------------------------------------
// Wayne H. Noxchi - 29-May-2016 12:55 - 29-May-2016 13:32
// --------------------------------------

// Write a program that sims flipping a coin until 3 consec heads, then displays

#include <iostream>
#include <string>
#include <sstream>
#include "random.h"
using namespace std;

int main(){
    cout << "This program will simulate flipping a coin repeatedly until 3 \
consecutive heads are reached.\n";
    int flip, kort = 0, count = 0;
    while(kort < 3){
        flip = randomInteger(0, 1);
        // cout << "[" << flip << "]" << endl;
        count++;
        cout << "Flip: " << count << endl;
        if (flip == 1){
            kort++;
            cout << "Heads\n";
        }
        else {
            kort = 0;
            cout << "Tails\n";
        }
    }
    cout << "It took " << count << " flips to get 3 heads in a row." << endl;
}
