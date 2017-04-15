/*  CS106B - Programming Abstractions
 *  Programming Abstractions in C++ (2012)
 *-------------------------------------------------<*>
 *  Wayne H. Noxchi - 6.04 card.cpp
 *-------------------------------------------------<*>
 *
*/

/*  Implementation of the Card class    */

#include <string>
#include <cctype>
#include <sstream>
#include <iostream>
#include "6.04_card.h"

/* • A default constructor that creates a card that can later be assigned a value */
Card::Card() {
    Rank = 0;
    Suit = 0;
}

/* • A constructor that takes a short string name like "10S" or "JD" */
Card::Card(std::string card) {
    int stringToInteger(const std::string& str, int radix);     // strlib.h helper function
    string temp = "";
    // number case:
    if (isdigit(card[0]) {
        for (int i = 0; i < card.length(); i++) {
            if (isdigit(card[i])
                temp += card[i];
        }
        Rank = stringToInteger(temp);
        temp = card[card.length() - 1];
        if (temp[0] == 'C') Suit = CLUBS;
        if (temp[0] == 'D') Suit = DIAMONDS;
        if (temp[0] == 'H') Suit = HEARTS;
        if (temp[0] == 'S') Suit = SPADES;
    }
    // letter case:
    if (card[0] == 'A') Rank = ACE;
    if (card[0] == 'J') Rank = JACK;
    if (card[0] == 'Q') Rank = QUEEN;
    if (card[0] == 'K') Rank = KING;
    if (card[1] == 'C') Suit = CLUBS;
    if (card[1] == 'D') Suit = DIAMONDS;
    if (card[1] == 'H') Suit = HEARTS;
    if (card[1] == 'S') Suit = SPADES;
}

/* • A constructor that takes separate values for the rank and the suit */
Card::Card(int rank, int suit) {
    Rank = rank;
    Suit = suit;
}

/* • A toString method that returns the short string representation of the card */
std::string Card::toString() {
    std::string integerToString(int n);
    return integerToString(Rank) + integerToString(Suit);
}
std::string integerToString(int n) {    // helper function for toString() - taken directly from strlib.h
    std::ostringstream stream;
    stream << n;
    return stream.str();
}

/* • The getter methods getRank and getSuit */
int Card::getRank() {

}
int Card::getSuit() {

}

/* helper function for Card constructor -- taken from strlib.h */
int stringToInteger(const std::string& str, int radix) {
    std::istringstream stream(trim(str));
    stream >> std::setbase(radix);
    int value;
    stream >> value;
    if (stream.fail() || !stream.eof()) {
        error("stringToInteger: Illegal integer format (" + str + ")");
    }
    return value;
}
