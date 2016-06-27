/*  CS106B - Programming Abstractions
 *  Programming Abstractions in C++ (2012)
 *  ----------------------------------------------
 *  Wayne H. Noxchi - 3.13 createOrdinalForm
 *  ----------------------------------------------
 *  07-Jun-2016 23:54 - 08-Jun-2016 00:07
*/

/*  Devise a rule that determines what suffix should be added to each
 *  number, and then use this rule to write a function createOrdinalForm(n)
 *  that returns the ordinal form of the number n as a string.          */

#include <iostream>
#include <string>
using namespace std;

/* function */
string createOrdinalForm(string terah) {
    int len = terah.length();
    if (len >= 2 && terah[len - 2] - '0' == 1) {
        terah += "th";
    }
    else if (terah[len - 1] - '0'== 1) {
        terah += "st";
    }
    else if (terah[len - 1] - '0'== 2) {
        terah += "nd";
    }
    else if (terah[len - 1] - '0'== 3) {
        terah += "rd";
    }
    else {
        terah += "th";
    }
    return terah;
}

/* test */
int main () {
    string terah;
    cout << "Create Ordinal Form: X >> Xth\nEnter number then press RETURN:\n";
    cin >> terah;
    cout << createOrdinalForm(terah) << endl;
}
