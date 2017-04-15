/*  CS106B - Programming Abstractions
 *  Programming Abstractions in C++ (2012)
 *-------------------------------------------------<*>
 *  Wayne H. Noxchi - 6.04 CardTest.cpp
 *-------------------------------------------------<*>
 *
*/

/*  Program testing the Card class  */

#include <iostream>
#include "card.h"

int main() {
    for (Suit suit = CLUBS; suit <= SPADES; suit++) {
        for (int rank = ACE; rank <= KING; rank++) {
            cout << " " << Card(rank, suit);
        }
        cout << endl;
    }
    return 0;
}
