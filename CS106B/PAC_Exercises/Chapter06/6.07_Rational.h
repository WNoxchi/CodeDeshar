/*  CS106B - Programming Abstractions
 *  Programming Abstractions in C++ (2012)
 *-----------------------------------------------------<>
 *  6.07_Rational.h
 *-----------------------------------------------------<>
 *  WNixaloy - 14-Aug-2016 00:02 - 0:26
 */

/* Chapter 6 Exercise 7 -- extending Rational.h interface to match implementation changes.  */


/*
 * File: rational.h
 * ----------------
 * This interface exports a class for representing rational numbers.
 */

#ifndef _rational_h
#define _rational_h

#include <string>
#include <iostream>

/*
 * Class: Rational
 * ---------------
 * The Rational class is used to represent rational numbers, which
 * are defined to be the quotient of two integers.
 */

class Rational {

public:

/*
 * Constructor: Rational
 * Usage: Rational zero;
 *        Rational num(n);
 *        Rational r(x, y);
 * ------------------------
 * Creates a Rational object.  The default constructor creates the
 * rational number 0.  The single-argument form creates a rational
 * equal to the specified integer, and the two-argument form creates
 * a rational number corresponding to the fraction x/y.
 */

    Rational();
    Ratoinal(int n);
    Rational(int x, int y);

/*
 * Method: toString()
 * Usage: string str = r.toString();
 * ---------------------------------
 * Returns the string representation of this rational number.
 */

    std::string toString();

// #include "rationalpriv.h"
/* friends here  -- declare operator functions as friends */

    friend Rational operator+(Ratioanl r1, Rational r2);
    friend Rational operator-(Rational r1, Rational r2);
    friend Rational operator*(Rational r1, Rational r2);
    friend Rational operator/(Rational r1, Rational r2);
    // new friend operators:
    friend bool operator==(Ratioanl r1, Rational r2);
    friend bool operator!=(Rational r1, Rational r2);
    friend bool operator<(Rational r1, Rational r2);
    friend bool operator<=(Rational r1, Rational r2);
    friend bool operator>(Rational r1, Rational r2);
    friend bool operator>=(Rational r1, Rational r2);
    friend Rational operator+=(Rational & r1, Rational & r2);
    friend Rational operator-=(Rational & r1, Rational & r2);
    friend Rational operator*=(Rational & r1, Rational & r2);
    friend Rational operator/=(Rational & r1, Rational & r2);
    // prefix ++
    friend Rational operator++(Rational & r1);
    // suffix ++
    friend Rational operator++(Rational & r1, int);
    // prefix --
    friend Rational operator--(Rational & r1);
    // suffix --
    friend Rational operator--(Rational & r1, int);

private:

/* Instance variables */
   int num;    /* The numerator of this Rational object   */
   int den;    /* The denominator of this Rational object */

};

/*
 * Operator: <<
 * ------------
 * Overloads the << operator so that it is able to display Rational values.
 */

std::ostream & operator<<(std::ostream & os, Rational rat);

/*
 * Operator: +
 * Usage: r1 + r2
 * --------------
 * Overloads the + operator so that it performs addition on two
 * rational numbers.
 */

Rational operator+(Rational r1, Rational r2);

/*
 * Operator: -
 * Usage: r1 - r2
 * --------------
 * Overloads the - operator so that it performs subtraction on two
 * rational numbers.
 */

Rational operator-(Rational r1, Rational r2);

/*
 * Operator: *
 * Usage: r1 * r2
 * --------------
 * Overloads the * operator so that it performs multiplication on two
 * rational numbers.
 */

Rational operator*(Rational r1, Rational r2);

/*
 * Operator: /
 * Usage: r1 / r2
 * --------------
 * Overloads the / operator so that it performs division on two
 * rational numbers.
 */

Rational operator/(Rational r1, Rational r2);

/* exercise 7: all da rest: */

bool operator==(Ratioanl r1, Rational r2);
bool operator!=(Rational r1, Rational r2);
bool operator<(Rational r1, Rational r2);
bool operator<=(Rational r1, Rational r2);
bool operator>(Rational r1, Rational r2);
bool operator>=(Rational r1, Rational r2);
Rational operator+=(Rational & r1, Rational & r2);
Rational operator-=(Rational & r1, Rational & r2);
Rational operator*=(Rational & r1, Rational & r2);
Rational operator/=(Rational & r1, Rational & r2);
// prefix ++
Rational operator++(Rational & r1);
// suffix ++
Rational operator++(Rational & r1, int);
// prefix --
Rational operator--(Rational & r1);
// suffix --
Rational operator--(Rational & r1, int);

#endif
