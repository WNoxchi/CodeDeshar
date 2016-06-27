/*  CS106B - Programming Abstractions
 *  Programming Abstractions in C++ (2012)
 *-------------------------------------------------<*>
 *  Wayne H. Noxchi - 4.01 TrigTable
 *-------------------------------------------------<*>
 *  23-Jun-2016 09:46 - 23-Jun-2016 10:17
*/

/*  Using the <iomanip> library, Write a program that displays a table of
    trigonometric sines and cosines st: the numeric columns should all be
    aligned on the right, and the columns containing the trigonometric
    functions (which are listed here for angles in degrees at 15-degree
    intervals) should all have seven digits after the decimal point.            */

#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const double п = 3.14159265358979323846;

double degRad(int &degree) {
    double result;
    result = п * degree / 180;
    return result;
}

int main() {
    int thet = -105;
    cout << "  theta  |  sin(theta)  |  kos(theta)  |\n"\
            "---------+--------------+--------------+" << endl;
    for (int i = 0; i < 13; i++) {
        thet += 15;
        cout << setw(8) << thet << " |" << setw(13) << fixed << setprecision(7) << sin(degRad(thet)) \
                << " |" << setw(13) << fixed << setprecision(7) << cos(degRad(thet)) << " |" << endl;
    }
}
/*  Terminal Output:
Waynes-MBP:Chapter04 WayNoxchi$ ./4.01_TrigTable
  theta  |  sin(theta)  |  kos(theta)  |
---------+--------------+--------------+
     -90 |   -1.0000000 |    0.0000000 |
     -75 |   -0.9659258 |    0.2588190 |
     -60 |   -0.8660254 |    0.5000000 |
     -45 |   -0.7071068 |    0.7071068 |
     -30 |   -0.5000000 |    0.8660254 |
     -15 |   -0.2588190 |    0.9659258 |
       0 |    0.0000000 |    1.0000000 |
      15 |    0.2588190 |    0.9659258 |
      30 |    0.5000000 |    0.8660254 |
      45 |    0.7071068 |    0.7071068 |
      60 |    0.8660254 |    0.5000000 |
      75 |    0.9659258 |    0.2588190 |
      90 |    1.0000000 |    0.0000000 |
Waynes-MBP:Chapter04 WayNoxchi$
*/

/* NOTE:
    I found out that C++ doesn't allow binding non-const temporaries to non-const references.
    Meaning you can't define a pass by reference function, and then give it a
    non-variable (just a number value) as argument. That's at least the behavior here.      */
