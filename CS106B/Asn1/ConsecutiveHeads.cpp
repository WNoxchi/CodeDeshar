/*
 * File: ConsecutiveHeads.cpp
 * --------------------------
 * Name: Wayne H. Noxchi
 * UbuntuMATE - terminal
 * 04-Jun-2016 21:49 - 04-Jun-2016 21:59
 * --------------------------
 * Assignment 1.1 - ConsecutiveHeads
 */

#include <iostream>
#include <string>
#include "console.h"
#include "random.h"
using namespace std;

int main() {
   int heads = 0, count = 0, flip;
   while (heads < 3) {
       flip = randomInteger(0, 1);
       count++;
       if (flip == 1) {
           heads++;
           cout << count << ": Körtash" << endl;
       } else {
           heads = 0;
           cout << count << ": Küygash" << endl;
       }
   }
   cout << count << " flips to get 3 küygash in a row." << endl;
   return 0;
}
