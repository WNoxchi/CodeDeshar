/*
* File: AverageList.cpp
* ---------------------------
* PAC++ ex 1.7
* CS106B Programming Abstractions
* 25-Feb-2016 22:50
*/

#include <iostream>
using namespace std;

const int SENTINEL = -1;

/* Main Program */

int main() {

    int total = 0;
    int count = 0;
    float average = 0.0;

    cout << "This program adds a list of numbers." << endl;
    cout << "Use " << SENTINEL << " to signal the end." << endl;

    while (true) {
        int value;
        cout << " ? ";
        cin >> value;
        if (value == SENTINEL) break;
        total += value;
        count++;
    }

    average = (float)total / count;
    cout << "The total is: " << total << ", average: " << average << endl;
}
