/*
* File: windChill.cpp
* ---------------------------
* Wayne H. Noxchi
* PAC++ ex 2.4
* CS106B Programming Abstractions
* 05-Mar-2016 01:23
*/

/* Write a function windChill tht takes vals t & v and returns the wind chill.
 * If no wind: return temperature t. If t > 40F: call error w/ approp message.
 * --------------------------
 * Wind-Chill Formula:  35.74 + 0.6215t - 35.75v^(0.16) + 0.4275tv^(0.16)
 * --------------------------
 * Write a main program that uses windChill to produce a table.
 */

#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

/* Prototype windChill function */
int windChill(int t, int v);

/* Prototype rounder function */
int roundToNearestInt(double x);

void printChillTable();
// void error(string msg);

/* Main Program: builds table of windChill */
int main()
{
    int chill, t, v;

    cout << "This program will calculate the Wind-Chill, then print a table of " << endl;
    cout << "Wind-Chill values by windspeed (mph) and temperature (F)" << endl;
    for (int i = 0; i < 80; i++)
    {
        cout << "-";
    }
    cout << endl;
    cout << "Please enter a Fahrenheit temperature: ";
    cin >> t;
    cout << "Enter a windspeed: ";
    cin >> v;
    cout << endl;

    chill = windChill(t, v);

    cout << "The Wind-Chill is: " << chill << endl << endl;
    cout << "This program will now print a table of Wind-Chill values." << endl;
    for (int i = 0; i < 80; i++)
    {
        cout << "-";
    }
    cout << endl << endl;

    printChillTable();
}

/* windChill function */
int windChill(int t, int v)
{
    double chill = 0.0;
    int result = 0;

    // // if t > 40 call an error & print message
    // if (t > 40) error("Error: Wind-Chill is undefined for temperatures above 40F.");
    if (v == 0) return t;

    chill = 35.74 + 0.6215 * t - 35.75 * pow(v, 0.16) + 0.4275 * t * pow(v, 0.16);
    result = roundToNearestInt(chill);
    return result;
}

/* Function Rounds Float to Nearest Integer */
int roundToNearestInt(double x)
{
    x += 0.5;
    return x;
}

/* Procedure prints a table of Wind-Chill values */
void printChillTable()
{
    int v = 0;
    int t = 40;
    int chill = 0;
    int nexChill = 0;

    for (int i = 0; i < 33; i++)
    {
        cout << " ";
    }
    cout << "Temperature (F)" << endl;
    for (int i = 0; i < 80; i++)
    {
        cout << "-";
    }
    cout << "Wind|" << endl;

    for (int i = 0; i < 13; i++)
    // for (int i = 0; i < 1; i++)
    {
        v = i * 5;
        if (v < 10)
        {
            cout << "  " << v << " | ";
        }
        if (v >= 10)
        {
            cout << " " << v << " | ";
        }

        for (int j = 0; j < 18; j++)
        {
            chill = windChill((t - (j) * 5), (v + i * 5));
            nexChill = windChill((t - (j+1) * 5), (v + i * 5));
            if (nexChill < 10 && nexChill >= 0)
            {
                cout << chill << "   ";
            }
            if (nexChill >= 10)
            {
                cout << chill << "  ";
            }
            if (nexChill < 0 && abs(nexChill) < 10)
            {
                cout << chill << "  ";
            }
            if (nexChill < 0 && abs(nexChill) >= 10)
            {
                cout << chill << " ";
            }
        }
        cout << endl;
    }
    for (int i = 0; i < 80; i++)
    {
        cout << "-";
    }
    cout << endl;
}

/* Error function writes string msg to cerr stream & exits program */
// void error(string msg)
// {
//     cerr << msg << endl;
//     exit(EXIT_FAILURE);
// }
