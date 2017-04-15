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

/*  The Card class should export the following methods: */
class Card {

public:

    /* • A default constructor that creates a card that can later be assigned a value */
    Card();

    /* • A constructor that takes a short string name like "10S" or "JD" */
    Card(std::string card);

    /* • A constructor that takes separate values for the rank and the suit */
    Card(int rank, int suit);

    /* • A toString method that returns the short string representation of the card */
    std::string toString();

    /* • The getter methods getRank and getSuit */
    int getRank();
    int getSuit();

    /* private section */
// private:
//     int rank;
//     int suit;
};

/*  In addition to the Card class itself, the card.h interface should export
the Suit type, constant names for the ranks that are usually named rather than
numbered (ACE, JACK, QUEEN, KING), and any other definitions you need           */

enum Suit = { CLUBS = 0, DIAMONDS = 1, HEARTS = 2, SPADES = 3 };
enum Rank = { ACE = 1, JACK = 11, QUEEN = 12, KING = 13 };

#endif
