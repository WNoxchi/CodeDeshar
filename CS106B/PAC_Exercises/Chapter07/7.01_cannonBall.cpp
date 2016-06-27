/*  CS106B - Programming Abstractions
 *  Programming Abstractions in C++ (2012)
 *-------------------------------------------------<*>
 *  Wayne H. Noxchi - 7.01 Cannon Ball
 *-------------------------------------------------<*>
 * 08-Jun-2016 18:30 - 19:01|22:01 - 22:17
*/

/*  Write a recursive function cannonball that takes as its argument the
height of the pyramid and returns the number of cannonballs it contains.    */

#include <iostream>
#include <string>
using namespace std;

/* function */
int cannonBall(int height) {
    if (height == 0) {
        return height;
    }
    else {
        return height * height + cannonBall(height - 1);
    }
}

/* testing */
int main() {
    int height = -1;
    cout << "This program will calculate the number of cannon balls in a pyramid, given its height." << endl;
    while (height != 0) {
        cout << "Cannon Ball Pyramid Height (0 = Exit): ";
        cin >> height;
        cout << "Cannon balls in pyramid base: " << cannonBall(height) << endl;
    }
}

// This should not have taken me so long. Mix of not reading the question and
// refusing to believe the implementation could be so simple. Note to self.
