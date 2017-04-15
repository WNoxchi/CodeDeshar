/*  Wayne H Nixalo - 15-Oct-2016 23:00
    Codingame: The Accountant
    Test04 Move Towards Closest Enemy Algorithm   */

    #include <iostream>
    #include <string>
    #include <vector>
    #include <algorithm>

    #include <cmath>    //  used for sqrt() fn

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

            /* create struct to hold enemy targetting data */   // looks like more complex than needed but we'll see
            struct enemy {
                int x;
                int y;
                int id;
                double range;
            };
            enemy enemy;

            /* preload first enemy info into Target Data */
            int enemyId;
            int enemyX;
            int enemyY;
            int enemyLife;
            cin >> enemyId >> enemyX >> enemyY >> enemyLife; cin.ignore();
            enemy.x = enemyX;
            enemy.y = enemyY;
            enemy.id = enemyId;
            enemy.range = sqrt((x - enemy.x)*(x - enemy.x)+(y - enemy.y)*(y - enemy.y));

            for (int i = 0; i < enemyCount - 1; i++) {
                int enemyId;
                int enemyX;
                int enemyY;
                int enemyLife;
                cin >> enemyId >> enemyX >> enemyY >> enemyLife; cin.ignore();
                /* select enemy with shortest range */
                if (sqrt((x - enemyX)*(x - enemyX)+(y - enemyY)*(y - enemyY)) < enemy.range) {
                    enemy.x = enemyX;
                    enemy.y = enemyY;
                    enemy.id = enemyId;
                    enemy.range = sqrt((x - enemyX)*(x - enemyX)+(y - enemyY)*(y - enemyY));
                }
            }

            /* load Targetting Data */
            // int TargetID = enemy.id;

            /* 0 -> Move, 1 -> Shoot */
            int ShootMove = 0;
            if (!ShootMove) {
                string Cmd = "MOVE ";
                Cmd += to_string(enemy.x);
                Cmd += ' ';
                Cmd += to_string(enemy.y);
                cout << Cmd << endl;
            }

        //     /* Output Command */
        //     cout << "MOVE " << enemy.x << enemy.y << endl; // MOVE x y or SHOOT id
        }
    }
