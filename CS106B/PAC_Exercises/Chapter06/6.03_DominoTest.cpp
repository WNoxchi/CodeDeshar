/*  CS106B - Programming Abstractions
 *  Programming Abstractions in C++ (2012)
 *-------------------------------------------------<*>
 *  Wayne H. Noxchi - 6.03 DominoTest
 *-------------------------------------------------<*>
 * 07-Jul-2016 09:03 | 07-Jul-2016 12:10 - 07-Jul-2016 15:47
*/

#include <iostream>
#include <string>
#include <vector>
// #include <set>
#include "6.03_domino.h"

int main() {

    int left;
    int right;
    bool flag;

    std::vector<Domino> doVec;
    // std::set<Domino>::iterator iter;

/*
    if left of domino X does not match right of any domino Y:
        add domino X
    if left of domino X matches right of any domino Y:
        if right of domino X does not match left of domino Y:
            add domino X
*/
    // build vector of unique dominos:
    for (int i = 0; i < 7; i++) {
        for (int k = 0; k < 7; k++) {
            flag = false;
            Domino dom = Domino(i,k);
            if (!doVec.empty())
                for (int j = 0; j < doVec.size(); j++) {
                    if (dom.getLeft() == doVec[j].getRight()) {
                        if (dom.getRight() == doVec[j].getLeft()) {
                            flag = true;
                        }
                    }
                }
            if (flag == false) {
                doVec.push_back(dom);
            }
        }
    }

    // print all dominos in vector
    for(Domino element : doVec) {
        std::cout << element << std::endl;
    }

}

/*  Terminal Output:

Waynes-MacBook-Pro:Chapter06 WayNoxchi$ g++ DominoTest.cpp domino.cpp -o DominoTest
DominoTest.cpp:46:24: warning: range-based for loop is a C++11 extension
      [-Wc++11-extensions]
    for(Domino element : doVec) {
                       ^
1 warning generated.
Waynes-MacBook-Pro:Chapter06 WayNoxchi$ ./DominoTest
[0|0]
[0|1]
[0|2]
[0|3]
[0|4]
[0|5]
[0|6]
[1|1]
[1|2]
[1|3]
[1|4]
[1|5]
[1|6]
[2|2]
[2|3]
[2|4]
[2|5]
[2|6]
[3|3]
[3|4]
[3|5]
[3|6]
[4|4]
[4|5]
[4|6]
[5|5]
[5|6]
[6|6]
Waynes-MacBook-Pro:Chapter06 WayNoxchi$

*/

/*  WORK LOG:

07-Jul-2016 12:10 - I think my error was not having a private section for left, right
07-Jul-2016 12:45 - Just learned how to manually build object files, link them, and compile an executable in Terminal. Painful. Cathartic. Relieving.
<<BREAK>>
07-Jul-2016 13:15 - Back to work. Starting from scratch.
07-Jul-2016 13:51 - DominoTest compiled correctly & successfully printed .getLeft() of Domino class to Terminal. Fuck Yeah.
07-Jul-2016 13:58 - Successfully tested vector of Dominos & checking if empty.
07-Jul-2016 14:05 - Successfully tested printing all left Domino values in Vector to console. (compiler warning: for C++11 only)
07-Jul-2016 14:39 - Got program to print all dominos. However method for det unique dominos incorrect.
07-Jul-2016 15:38 - Finally got it to work, using vectors. Holy shit. Praise Jesus. Allahu Akbar. God Bless America.

*/

// // test 1: print element of Domino to Terminal
// int main() {
//     Domino dom = Domino();
//     std::cout << dom.getLeft() << std::endl;
// }

// // test2: print all left Domino values:
// for(Domino n : domVec) {
//     std::cout << n.getLeft() << '\n';
// }

// obsolete; using maps:
// // map to hold dominos
// std::map<int, Domino> doMap;
// std::map<int, Domino>::iterator iter;
//
// // build map of unique dominos
// for (int i = 0; i < 7; i++) {
//     for (int k = 0; k < 7; k++) {
//         iter = doMap.find(i+k);
//         if (iter == doMap.end())
//             doMap[i+k] = Domino(i,k);
//     }
// }
//
// // print all dominos in map
// for (iter = doMap.begin(); iter != doMap.end(); ++iter) {
//     std::cout << iter->second << std::endl;
// }
