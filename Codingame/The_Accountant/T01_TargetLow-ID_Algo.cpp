/*  Wayne H Nixalo - 12-Oct-2016 16:45
    Codingame: The Accountant
    Test01 Target Lowest ID Algorithm   */

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

        /* preload first enemy info into Target ID */
        int enemyId;
        int enemyX;
        int enemyY;
        int enemyLife;
        cin >> enemyId >> enemyX >> enemyY >> enemyLife; cin.ignore();
        int TargetID = enemyId;

        for (int i = 0; i < enemyCount - 1; i++) {
            int enemyId;
            int enemyX;
            int enemyY;
            int enemyLife;
            cin >> enemyId >> enemyX >> enemyY >> enemyLife; cin.ignore();
            if (TargetID > enemyId) {
                TargetID = enemyId;
            }
        }

        /* Output Command */
        cout << "SHOOT " << TargetID << endl; // MOVE x y or SHOOT id
    }
}

// -------------------DEVDUMP---------------------------------------------------
// int enemyCount;
// /* building our own struct to have a list of enemies */
// typedef struct enemy {
//     int ID[enemyCount];
//     int x[enemyCount];
//     int y[enemyCount];
//     int life[enemyCount];
// }
// cin >> enemyCount; cin.ignore();
// for (int i = 0; i < enemyCount; i++) {
//     int enemyId;
//     int enemyX;
//     int enemyY;
//     int enemyLife;
//     cin >> enemyId >> enemyX >> enemyY >> enemyLife; cin.ignore();
//     /* load enemy data into struct */
//     enemy.ID[i] = enemyId;
//     enemy.x[i] = enemyX;
//     enemy.y[i] = enemyY;
//     enemy.life[i] = enemyLife;
// }
// /* target lowest id enemy */
// int TargetID = enemy.ID[0];
// for (int i = 0; i < enemyCount; i++) {
//     if (enemy.ID[i] < TargetID) {
//         TargetID = enemy.ID[i]
//     }
// }
