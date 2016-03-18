/*
* File: rainbow.cpp
* ---------------------------
* Wayne H. Noxchi
* PAC++ ex 2.16
* CS106B Programming Abstractions
* 07-Mar-2016 00:04
*/

/* Use the graphics library to draw a rainbow.
 * sky: cyan. red, orange, yellow, green, blue, magenta.
 */

#include "graphics.h"
using namespace std;

int main() {
    initGraphics(600, 400);     // initialize graphics window
    setColor("CYAN");
    fillRect(0, 0, 600, 400);
    setColor("RED");
    fillArc(0, 50, 600, 200, 20, 160);
    setColor("ORANGE");
    fillArc(0, 60, 600, 200, 20, 160);
    setColor("YELLOW");
    fillArc(0, 70, 600, 200, 20, 160);
    setColor("GREEN");
    fillArc(0, 80, 600, 200, 20, 160);
    setColor("BLUE");
    fillArc(0, 90, 600, 200, 20, 160);
    setColor("MAGENTA");
    fillArc(0, 100, 600, 200, 20, 160);

    return 0;
}
