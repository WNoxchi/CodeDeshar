/*  CS106B - Programming Abstractions
 *  Programming Abstractions in C++ (2012)
 *-------------------------------------------------<*>
 *  Wayne H. Noxchi - 6.04 card.cpp
 *-------------------------------------------------<*>
 *
*/

/*
    Defines a Card class suitable for representing a standard playing card,
    which is identified by two components: a rank and a suit. The rank is
    stored as an integer between 1 and 13 in which an ace is a 1, a jack is an
    11, a queen is a 12, and a king is 13. The suit is one of the four
    constants in an enumeration type
*/

/*  Implementation of the Card class    */

#include "6.04_card.h"
#include <string>
#include <iostream>
#include <sstream>
#include <cctype>

/* • A default constructor that creates a card that can later be assigned a value */
Card::Card() {
    rank = 0;
    suit = SPADES;   // is this legal for enum types?
}

/* • A constructor that takes a short string name like "10S" or "JD" */
Card::Card(std::string cardstr) {
    // if 1st char is letter
    if (toupper(cardstr[0]) == 'A')
        rank = 1;
    if (toupper(cardstr[0]) == 'J')
        rank = 11;
    if (toupper(cardstr[0]) == 'Q')
        rank = 12;
    if (toupper(cardstr[0]) == 'K')
        rank = 13;

    // if 1st char is number
    if (isdigit(cardstr[0])) {
        // if 2nd char is number
        if (isdigit(cardstr[1])) {
            rank = (cardstr[0] - '0' * 10) + (cardstr[1] - '0');
        } else {
            rank = cardstr[0] - '0';
        }
    }

    // get suit
    if (toupper(cardstr[cardstr.length() - 1]) == 'C')
        suit = CLUBS;
    if (toupper(cardstr[cardstr.length() - 1]) == 'H')
        suit = HEARTS;
    if (toupper(cardstr[cardstr.length() - 1]) == 'D')
        suit = DIAMONDS;
    if (toupper(cardstr[cardstr.length() - 1]) == 'S')
        suit = SPADES;
}

/* • A constructor that takes separate values for the rank and the suit */
Card::Card(int rank, Suit suit) {
    this->rank = rank;
    this->suit = suit;
}

std::string integerToString(int n) {    // helper function for toString() - taken directly from strlib.h
    std::ostringstream stream;
    stream << n;
    return stream.str();
}

/* • A toString method that returns the short string representation of the card */
std::string toString() {
    switch (rank) {
        case 1: return "A";
        case 11: return "J";
        case 12: return "Q";
        case 13: return "K";
        default: return integerToString(rank);
    }
    // std::string str = "";
    // str += integertoString(rank);
    // if (suit == CLUBS)
    //     return str + "C";
    // if (suit == HEARTS)
    //     return str + "H";
    // if (suit == DIAMONDS)
    //     return str + "D";
    // if (suit == SPADES)
    //     return str + "S";
}

/* • The getter methods getRank and getSuit */
int getRank() {
    return rank;
}
Suit getSuit() {
    return suit;
}

// operator overloading
Suit operator++(Suit &suit, int) {
    Suit old = suit;
    suit = Suit(suit + 1);
    return old;
}

std::ostream &operator<<(std::ostream &os, Card card) {
    return os << card.toString();
}
