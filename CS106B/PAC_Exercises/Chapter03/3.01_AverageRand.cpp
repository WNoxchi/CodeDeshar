// CS106B - Programming Abstractions
// Programming Abstractions in C++ (2008)
// Exercise 3.01 AverageRand.cpp
// --------------------------------------
// Wayne H. Noxchi - 28-May-2016 15:33 - 29-May-2016 12:42
// (t= 1:43:24 -- compiler issues, Linux)
// --------------------------------------

#include "random.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){
    string input;
    int trials, total = 0;
    float average;
    cout << "This program averages a series of random numbers between 0 and 1.\n";

    // get input
    while(true){
        cout << "How many trials: ";
        getline(cin, input);

        // convert input string to number
        stringstream myStrm(input);
        if (myStrm >> trials)
            break;
        cout << "Invalid input, try again" << endl;
    }

    // display Trials number
    cout << "You've selected: " << trials << " trials" << endl;

    // run trials
    for (int i = 0; i < trials; i++){
            total += randomInteger(0, 1);
    }
    average = float(total)/trials;

    // display result
    cout << "Random Average (t = " << trials << " ): " << average << endl;
}
