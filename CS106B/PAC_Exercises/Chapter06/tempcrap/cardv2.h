/*  CS106B - Programming Abstractions
 *  Programming Abstractions in C++ (2012)
 *-------------------------------------------------<*>
 *  Wayne H. Noxchi - 6.04 card.h
 *-------------------------------------------------<*>
 *
*/

/*  Interface file for the Card class   */

#ifndef _6_04_card_h
#define _6_04_card_h

#include <iostream>
#include <string>

const int ACE = 1;
const int JACK = 11;
const int QUEEN = 12;
const int KING = 13;

/*  In addition to the Card class itself, the card.h interface should export
the Suit type, constant names for the ranks that are usually named rather than
numbered (ACE, JACK, QUEEN, KING), and any other definitions you need           */
enum Suit { CLUBS, DIAMONDS, HEARTS, SPADES };

class Card {

/*  The Card class should export the following methods: */
public:

    /* • A default constructor that creates a card that can later be assigned a value */
    Card();

    /* • A constructor that takes a short string name like "10S" or "JD" */
    Card(std::string cardstr);

    /* • A constructor that takes separate values for the rank and the suit */
    Card(int rank, Suit suit);

    /* • A toString method that returns the short string representation of the card */
    std::string toString();

    /* • The getter methods getRank and getSuit */
    int getRank();
    Suit getSuit();

private:

    int rank;
    Suit suit;

};

// operator overloading
std::ostream &operator<<(std::ostream &os, Card card);
Suit operator++(Suit &suit, int);

#endif
