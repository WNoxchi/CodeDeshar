#include <iostream>
#include <string>
#include <sstream>
#include "card.h"

using namespace std;

/* Function Prototypes */
string suitToString(Suit st);


/* Constructors */
Card::Card() {
	/* Empty */
}

Card::Card(string str) {
	/* parse the short string to get rank and suit */
}

Card::Card(int rk, Suit st) {
	rank = rk;
	suit = st;
}

/* Methods */
int Card::getRank() {
	return rank;
}

Suit Card::getSuit() {
	return suit;
}

std::string integerToString(int n) {    // helper function for toString() - taken directly from strlib.h
    std::ostringstream stream;
    stream << n;
    return stream.str();
}

string Card::toString() {
	switch (rank) {
		case 1: return "A" + suitToString(suit);
		case 11: return "J" + suitToString(suit);
		case 12: return "Q" + suitToString(suit);
		case 13: return "K" + suitToString(suit);
		default: return integerToString(rank) + suitToString(suit);
 	}

}

/* Operator overloads */

Suit operator++(Suit &suit, int) {
	Suit old = suit;
	suit = Suit(suit + 1);
	return old;
}

ostream &operator<<(ostream &os, Card car) {
	return os << car.toString();
}

/* Helper Functions */
string suitToString(Suit st) {
	switch (st) {
		case CLUBS: return "C";
		case DIAMONDS: return "D";
		case HEARTS: return "H";
		case SPADES: return "S";
		default: return "?";
	}
}
