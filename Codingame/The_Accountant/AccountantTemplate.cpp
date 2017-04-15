#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Shoot enemies before they collect all the incriminating data!
 * The closer you are to an enemy, the more damage you do but don't get too close or you'll get killed.
 **/
int main()
{

    // game loop
    while (1) {
        int x;
        int y;
        cin >> x >> y; cin.ignore();
        int dataCount;
        cin >> dataCount; cin.ignore();
        for (int i = 0; i < dataCount; i++) {
            int dataId;
            int dataX;
            int dataY;
            cin >> dataId >> dataX >> dataY; cin.ignore();
        }
        int enemyCount;
        cin >> enemyCount; cin.ignore();
        for (int i = 0; i < enemyCount; i++) {
            int enemyId;
            int enemyX;
            int enemyY;
            int enemyLife;
            cin >> enemyId >> enemyX >> enemyY >> enemyLife; cin.ignore();
        }

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        cout << "MOVE 8000 4500" << endl; // MOVE x y or SHOOT id
    }
}
