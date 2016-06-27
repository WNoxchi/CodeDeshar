/*  CS106B - Programming Abstractions
 *  Programming Abstractions in C++ (2012)
 *-------------------------------------------------<*>
 *  Wayne H. Noxchi - 3.20 findDNAMatch
 *-------------------------------------------------<*>
 * 08-Jun-2016 17:26 - 17:58
*/

/*
Write a function
    int findDNAMatch(string s1, string s2, int start = 0);
that returns the first position at which the DNA strand s1 can attach to
the strand s2. As in the find method for the string class, the optional
start parameter indicates the index position at which the search should start.
 If there is no match, findDNAMatch should return –1.
*/

#include <iostream>
#include <string>
using namespace std;

/* helper function */
bool match(char t, char a) {
    if ((tolower(t) == 't' && tolower(a) == 'a') || (tolower(t) == 'a' && tolower(a) == 't')) {
        return true;
    }
    if ((tolower(t) == 'c' && tolower(a) == 'g') || (tolower(t) == 'g' && tolower(a) == 'c')) {
        return true;
    }
    else return false;
}

/* function */
int findDNAMatch(string s1, string s2, int start = 0) {
    for (int i = 0; i < s1.length(); i++) {
        if (match(s1[i], s2[0])) {
            for (int k = 0; k < s2.length(); k++) {
                if (!match(s1[i+k], s2[k])) {
                    break;
                }
                if ((k = s2.length() - 1) && match(s1[i+k], s2[k])) {
                    return i;
                }
            }
        }
    }
    return -1;
}

/* testing */
int main() {
    string strand1 = "TAACGGTACGTC", strand2 = "TTGCC";
    cout << "--------------------------------------------------" << endl;
    cout << "This program simulates DNA strand matching.\n";
    cout << "Target Strand: " << strand1 << endl;
    cout << "Attach Strand: " << strand2 << endl;
    int match = findDNAMatch(strand1, strand2);




    if (match == -1) {
        cout << "No possible match" << endl;
    } else {
        string space, dash;
        for (int i = 0; i < match; i++) space += " ";
        for (int i = 0; i < strand2.length(); i++) dash += "|";

        cout << "Strands can attach at index [" << match << "] of the Target Strand." << endl;
        cout << "Attachment: " << strand1 << endl;
        cout << "            " << space << dash << endl;
        cout << "            " << space << strand2 << endl;

    }
    cout << "--------------------------------------------------" << endl;
}

/* Pseudocode:

T <-> A
G <-> C

For as many indices in s1:
    if 1st index s2 match index s1:
        for as many indices in s2:
            if next index s2 match next index s1:
                repeat until finish
                if last index s2 match s1:
                    Return index s2 minus its length;
            else:
                go to next index s1
                break;
    if last index s2 No match s1:
        Return -1;
    else go to next index of s1
    repeat





*/
