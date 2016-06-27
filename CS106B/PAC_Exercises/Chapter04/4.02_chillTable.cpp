/*  CS106B - Programming Abstractions
 *  Programming Abstractions in C++ (2012)
 *-------------------------------------------------<*>
 *  Wayne H. Noxchi - 4.02 wChillTable.cpp
 *-------------------------------------------------<*>
 *  23-Jun-2016 10:26 - 23-Jun-2016 11:13
*/

/*
    In exercise 4 in Chapter 2, you wrote a function windChill that calculated
    the wind chill for a given temperature and wind velocity. Write a program
    that uses this function to display these values in tabular form, as
    illustrated by the table from the National Weather service shown in
    Figure 2-17 on page 117.
*/

// table cols(temp) from 40 -> -45 by 5   | rows(wind) from 5 -> 60 by 5

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

/* prototypes */
int roundToNearestInt(double x);
int windChill(int tempF, int windVel);

/* function */
void chillTable() {
    int temp, wind;
    cout << "      ";
    for (int i = 0; i < 18; i++) {
        temp = 40 - i*5;
        cout << setw(4) << temp;
    }
    cout << "\n     +------------------------------------------------------------------------\n";
    for (int i = 0; i < 12; i++) {
        wind = 5 + i*5;
        cout << setw(4) << wind << " |";
        for (int k = 0; k < 18; k++) {
            temp = 40 - k*5;
            cout << setw(4) << fixed << setprecision(2) << windChill(temp, wind);
        }
        cout << endl;
    }
}

/* implementation */
int main() {
    chillTable();
}

/* Function Rounds Float to Nearest Integer */
int roundToNearestInt(double x)
{
    x += 0.5;
    return x;
}

/* windChill function */
int windChill(int tempF, int windVel)
{
    double chill = 0.0;
    int result = 0;

    // // if t > 40 call an error & print message
    // if (t > 40) error("Error: Wind-Chill is undefined for temperatures above 40F.");
    if (windVel == 0) return tempF;

    chill = 35.74 + 0.6215 * tempF - 35.75 * pow(windVel, 0.16) + 0.4275 * tempF * pow(windVel, 0.16);
    result = roundToNearestInt(chill);
    return result;
}

/*  Terminal Output:

Waynes-MBP:Chapter04 WayNoxchi$ ./4.02_chillTable
        40  35  30  25  20  15  10   5   0  -5 -10 -15 -20 -25 -30 -35 -40 -45
     +------------------------------------------------------------------------
   5 |  36  31  25  19  13   7   1  -4 -10 -15 -21 -27 -33 -39 -45 -51 -56 -62
  10 |  34  27  21  15   9   3  -3  -9 -15 -21 -27 -34 -40 -46 -52 -58 -65 -71
  15 |  32  25  19  13   6   0  -6 -12 -18 -25 -31 -38 -44 -50 -57 -63 -70 -76
  20 |  30  24  17  11   4  -1  -8 -14 -21 -28 -34 -41 -47 -54 -60 -67 -73 -80
  25 |  29  23  16   9   3  -3 -10 -16 -23 -30 -36 -43 -50 -57 -63 -70 -77 -83
  30 |  28  22  15   8   1  -4 -11 -18 -25 -32 -38 -45 -52 -59 -66 -72 -79 -86
  35 |  28  21  14   7   0  -6 -13 -20 -26 -33 -40 -47 -54 -61 -68 -75 -81 -88
  40 |  27  20  13   6   0  -7 -14 -21 -28 -35 -42 -49 -56 -63 -70 -77 -83 -90
  45 |  26  19  12   5  -1  -8 -15 -22 -29 -36 -43 -50 -57 -64 -71 -78 -85 -92
  50 |  26  19  12   4  -2  -9 -16 -23 -30 -37 -44 -51 -59 -66 -73 -80 -87 -94
  55 |  25  18  11   4  -2 -10 -17 -24 -31 -38 -45 -53 -60 -67 -74 -81 -88 -96
  60 |  25  17  10   3  -3 -10 -18 -25 -32 -39 -47 -54 -61 -68 -75 -83 -90 -97
Waynes-MBP:Chapter04 WayNoxchi$

*/
