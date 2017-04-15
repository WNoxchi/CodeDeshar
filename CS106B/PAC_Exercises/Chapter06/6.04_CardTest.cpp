/*  CS106B - Programming Abstractions
 *  Programming Abstractions in C++ (2012)
 *-------------------------------------------------<*>
 *  Wayne H. Noxchi - 6.04 CardTest.cpp
 *-------------------------------------------------<*>
 *   08-Jul-2016 08:20 - 9:39 | 09-Jul-2016 16:46 - 17:25 |
 *  17:57 - 09-Jul-2016 18:05 | 10-Jul-2016 09:03 - 09:41 | 14:52
*/

/*  Program testing the Card class  */

#include <iostream>
#include "6.04_card.h"
#include <string>
using namespace std;

int main() {
    for (Suit suit = CLUBS; suit <= SPADES; suit++) {
        for (int rank = ACE; rank <= KING; rank++) {
            cout << " " << Card(rank, suit);
        }
        cout << endl;
    }
    return 0;
}

/* Terminal Output:
    Waynes-MacBook-Pro:Chapter06 WayNoxchi$ g++ 6.04_CardTest.cpp 6.04_card.cpp -o 6.04_CardTest
    Waynes-MacBook-Pro:Chapter06 WayNoxchi$ ./6.04_CardTest
     AC 2C 3C 4C 5C 6C 7C 8C 9C 10C JC QC KC
     AD 2D 3D 4D 5D 6D 7D 8D 9D 10D JD QD KD
     AH 2H 3H 4H 5H 6H 7H 8H 9H 10H JH QH KH
     AS 2S 3S 4S 5S 6S 7S 8S 9S 10S JS QS KS
    Waynes-MacBook-Pro:Chapter06 WayNoxchi$
*/
