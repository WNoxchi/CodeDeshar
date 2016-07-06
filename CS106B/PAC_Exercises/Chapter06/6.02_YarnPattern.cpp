/*  CS106B - Programming Abstractions
 *  Programming Abstractions in C++ (2012)
 *-------------------------------------------------<*>
 *  Wayne H. Noxchi - 6.02
 *-------------------------------------------------<*>
 *  06-Jul-2016 17:15 - 06-Jul-2016 18:43
*/

/*  for whatever reason, looks like whatever I draw in UbuntuMATE using the
    Stanford Libraries has to be drawn 100 times to safely stay on canvas.      */

#include <string>
#include "gtypes.h"
#include "vector.h"
#include "gwindow.h"
#include "gobjects.h"

const int N_ACROSS = 50;
const int N_DOWN = 30;
const int DELTA = 67;
const int SPACE = 10;

int main() {
    GWindow gw;
    Vector<GPoint> Coords;
    double xc = 0;
    double yc = 0;
    // Create Vector of GPoints in a square
    for (int i = 0; i < N_ACROSS; i++) {
        Coords.add(GPoint(xc + i * SPACE, yc));
    }
    for (int i = 0; i < N_DOWN; i++) {
        Coords.add(GPoint(xc + (N_ACROSS - 1) * SPACE, yc + i * SPACE));
    }
    for (int i = 0; i < N_ACROSS; i++) {
        Coords.add(GPoint(xc + (N_ACROSS - 1) * SPACE - (i * SPACE), yc + (N_DOWN - 1) * SPACE));
    }
    for (int i = 0; i < N_DOWN; i++) {
        Coords.add(GPoint(xc, yc + (N_DOWN - 1) * SPACE - (i * SPACE)));
    }

    int index = 0, VECSIZE = Coords.size();
    bool firstrun = true;
    while (!(index == 0 && firstrun == false)) {
        if (firstrun == true) firstrun = false;
        for (int i = 0; i < 100; i++)
            gw.drawLine(Coords[index], Coords[(index + DELTA) % VECSIZE]);
        index = (index + DELTA) % VECSIZE;
    }

    // cout << Coords.size() << endl;       // checking, we got 160 elements here
    return 0;
}

// Testing ways to draw lines:
// GLine(Coords[0].getX(), Coords[0].getY(), Coords[70].getX(), Coords[70].getY());
// gw.drawLine(Coords[0].getX(), Coords[0].getY(), Coords[70].getX(), Coords[70].getY());
// for (int i = 0 ; i < 100; i++) {
//     gw.drawLine(Coords[0], Coords[70]);
// }

// // test thing
// int main() {
//     GWindow gw;
//     cout << "This program draws a diamond, rectangle, and oval." << endl;
//     double width = gw.getWidth();
//     double height = gw.getHeight();
//     gw.drawLine(0, height / 2, width / 2, 0);
//     gw.drawLine(width / 2, 0, width, height / 2);
//     gw.drawLine(width, height / 2, width / 2, height);
//     gw.drawLine(width / 2, height, 0, height / 2);
//     gw.setColor("BLUE");
//     gw.fillRect(width / 4, height / 4, width / 2, height / 2);
//     gw.setColor("GRAY");
//     gw.fillOval(width / 4, height / 4, width / 2, height / 2);
//     return 0;
// }

// int main() {
//     GWindow gw;
// 	for (int i = 0; i < 90; i++) {
// 	    gw.drawOval(30, 30, 30, 30);
// 	}
//     return 0;
// }

// 06-Jul-2016 18:31   -   Got Line drawing to work between 2 points in the Vector
// 06-Jul-2016 18:43   -   Holy shit I actually did this. 
