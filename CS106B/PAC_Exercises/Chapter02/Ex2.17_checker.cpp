/*
* File: checker.cpp
* ---------------------------
* Wayne H. Noxchi
* PAC++ ex 2.17
* CS106B Programming Abstractions
* 07-Mar-2016 00:16
*/

/* Use the graphics library to draw a checkerboard at starting position.
 * 3 rows red checkers top, 3 black bottom. white and gray squares. 8x8
 */

#include "graphics.h"
using namespace std;

int main() {
    initGraphics(800, 800);
    // draw checkerboard
    setColor("GRAY");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 4; j++) {
            fillRect((10 * (i + 2 % 2)) + j*20, i*20, 10, 10);
        }
    }
    // draw red pieces
    setColor("RED");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            fillOval((10 * (i + 2 % 2)) + j*20, i*20, 10, 10);
        }
    // draw black pieces
    setColor("BLACK");
    for (int i = 5; i < 8; i++) {
        for (int j = 0; j < 4; j++) {
            fillOval((10 * (i + 2 % 2)) + j*20, i*10, 10, 10);
        }

    return 0;
}
