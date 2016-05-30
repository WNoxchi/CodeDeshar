// CS106B - Programming Abstractions
// Programming Abstractions in C++ (2008)
// Exercise 3.03 Slots.cpp
// --------------------------------------
// Wayne H. Noxchi - 29-May-2016 17:44 - 29-May-2016 20:00
// --------------------------------------

#include <iostream>
#include <string>
#include <sstream>
#include "random.h"
using namespace std;

bool newGame(int & money);
void askInstruct();
void pullLever(int & tsa, int & shi, int & kxo);
void displaySlots(int tsa, int shi, int kxo, int & money);
string getName(int x);

int main(){
    int money = 50, tsa, shi, kxo;
    bool cont = 1;
    cout << "       Slots.cpp -- Wayne H. Noxchi -- 29-May-2016 18:03\n";
    for (int i = 0; i < 80; i++){
        cout << "-";
    }
    askInstruct();
    cont = newGame(money);
    while(cont != 0){
        pullLever(tsa, shi, kxo);
        displaySlots(tsa, shi, kxo, money);
        cont = newGame(money);
    }
}

void askInstruct(){
// stub
}

bool newGame(int & money){
    string play;
    bool cont;
    cout << " You have $" << money << ". Would you like to play? (yes/no): ";
    cin >> play;
    cin.ignore();
    if (play == "yes" || play == "Yes" || play == "YES" || play == "y"){
        if (money > 0){
            cont = 1;
            money -= 1;
            return cont;
        }
        else {
            cout << "Sorry brah, you outta cash." << endl;
        }
    }
    else {
        cont = 0;
        return cont;
    }
}

void pullLever(int & tsa, int & shi, int & kxo){
    tsa = randomInteger(1,6);
    shi = randomInteger(1,6);
    kxo = randomInteger(1,6);
    // tsa = 1, shi = 1, kxo = 1;
}

void displaySlots(int tsa, int shi, int kxo, int & money){
    int winnings = 0;
    // string a = getName(tsa);
    // string b = getName(shi);
    // string c = getName(kxo);
    cout << getName(tsa) << "  " << getName(shi) << "  " << getName(kxo) << "  --  ";
    // $250
    if (tsa == 1 && shi == 1 && kxo == 1){
        winnings = 250;
        money += winnings;
    }
    // 20
    if ( (tsa == 2 && shi == 2 && (kxo == 1 || kxo == 2)) \
        || (tsa == 2 && (shi == 1 || shi == 2)&& kxo == 2) \
            || ((tsa == 1 || tsa == 2) && shi == 2 && kxo == 2) ){
        winnings = 20;
        money += winnings;
    }
    // 14
    if ( (tsa == 3 && shi == 3 && (kxo == 1 || kxo == 3)) \
        || (tsa == 3 && (shi == 1 || shi == 3)&& kxo == 3) \
            || ((tsa == 1 || tsa == 3) && shi == 3 && kxo == 3) ){
        winnings = 14;
        money += winnings;
    }
    // 10
    if ( (tsa == 4 && shi == 4 && (kxo == 1 || kxo == 4)) \
        || (tsa == 4 && (shi == 1 || shi == 4)&& kxo == 4) \
            || ((tsa == 1 || tsa == 4) && shi == 4 && kxo == 4) ){
        winnings = 10;
        money += winnings;
    }
    // 7
    if ( tsa == 5 && shi == 5 && kxo == 5){
        winnings = 7;
        money += winnings;
    }
    // 5
    if ( (tsa == 5 && shi == 5 && kxo != 6) \
        || (tsa == 5 && shi != 6 && kxo == 5) \
            || (tsa != 6 && shi == 5 && kxo == 5) ){
        winnings = 5;
        money += winnings;
    }
    // 2
    if ( (tsa == 5 && shi != 6 && kxo != 6) \
        || (tsa != 6 && shi == 5 && kxo != 6) \
            || (tsa != 6 && shi != 6 && kxo == 5 ) ){
        winnings = 2;
        money += winnings;
    }
    if (winnings == 0){
        cout << "You Lose" << endl;
    }
    else {
        cout << "You Win $" << winnings << endl;
    }
}

string getName(int x){
    if (x == 1)
        return "BAR";
    if (x == 2)
        return "BELL";
    if (x == 3)
        return "PLUM";
    if (x == 4)
        return "ORANGE";
    if (x == 5)
        return "CHERRY";
    if (x == 6)
        return "LEMON";
}
