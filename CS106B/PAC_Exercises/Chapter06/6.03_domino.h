/*  CS106B - Programming Abstractions
 *  Programming Abstractions in C++ (2012)
 *-------------------------------------------------<*>
 *  Wayne H. Noxchi - 6.03 domino.h
 *-------------------------------------------------<*>
 * 07-Jul-2016 09:03 | 07-Jul-2016 12:10 - 07-Jul-2016 15:47
*/

// 07-Jul-2016 12:10 - I think my error was not having a private section for left, right
// 07-Jul-2016 12:45 - Just learned how to manually build object files, link them, and compile an executable in Terminal. Painful. Cathartic. Relieving.


#ifndef _6_03_domino_h
#define _6_03_domino_h

#include <iostream>
#include <string>

/*  Interface file for the Domino class     */
class Domino {

public:
    /* default constructor */
    Domino();

    /* paramaterized constructor */
    Domino(int x, int y);

    /* string representation of domino */
    std::string toString();

    /* getter method: getLeftDots */
    int getLeft();

    /* getter method: getRightDots */
    int getRight();

    /* private instance variables */
private:

    int left;
    int right;

};

/**     As with the examples in the text, the interface should overload the
        << operator so that it is possible to print the string representation
        of a domino on any output stream.                                       **/

std::ostream & operator<<(std::ostream & os, Domino dom);

#endif
