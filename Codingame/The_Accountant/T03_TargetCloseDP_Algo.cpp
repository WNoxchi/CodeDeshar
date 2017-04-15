/*  Wayne H Nixalo - 12-Oct-2016 17:48 - 18:39
    Codingame: The Accountant
    Test03 Target Closest Enemy to DP Algorithm   */

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

            /* consolidated struct to hold Enemy & DP data */
            struct TargetData {
                vector <int> dx;  // DP x
                vector <int> dy;  // DP y
                int xe;             // enemy x
                int ye;             // enemy y
                int id;             // enemy ID
                double Drange;      // range of nearest enemy to a DP
                double range;       //  range of enemy to player
            };
            TargetData TD;
            TD.dx.resize(dataCount);
            TD.dy.resize(dataCount);

            for (int i = 0; i < dataCount; i++) {
                int dataId;
                int dataX;
                int dataY;
                cin >> dataId >> dataX >> dataY; cin.ignore();
                /* load DP coord info into TD */
                TD.dx[i] = dataX;
                TD.dy[i] = dataY;
            }
            int enemyCount;
            cin >> enemyCount; cin.ignore();

            /* preload first enemy info into Target Data */
            int enemyId;
            int enemyX;
            int enemyY;
            int enemyLife;
            cin >> enemyId >> enemyX >> enemyY >> enemyLife; cin.ignore();
            TD.xe = enemyX;
            TD.ye = enemyY;
            TD.id = enemyId;
            TD.range = sqrt((x - TD.xe)*(x - TD.xe)+(y - TD.ye)*(y - TD.ye));
            /* find closest range to DP for enemy */
            TD.Drange = sqrt((TD.dx[0] - TD.xe)*(TD.dx[0] - TD.xe)+(TD.dy[0] - TD.ye)*(TD.dy[0] - TD.ye));
            for (int i = 0; i < dataCount; i++) {
                if (TD.Drange > sqrt((TD.dx[i] - TD.xe)*(TD.dx[i] - TD.xe)+(TD.dy[i] - TD.ye)*(TD.dy[i] - TD.ye))) {
                    TD.Drange = sqrt((TD.dx[i] - TD.xe)*(TD.dx[i] - TD.xe)+(TD.dy[i] - TD.ye)*(TD.dy[i] - TD.ye));
                }
            }

            for (int i = 0; i < enemyCount - 1; i++) {
                int enemyId;
                int enemyX;
                int enemyY;
                int enemyLife;
                cin >> enemyId >> enemyX >> enemyY >> enemyLife; cin.ignore();
                /* find enemy closest to a DP */
                for (int j = 0; j < dataCount; j++) {
                    if (TD.Drange > sqrt((TD.dx[j] - enemyX)*(TD.dx[j] - enemyX)+(TD.dy[j] - enemyY)*(TD.dy[j] - enemyY))) {
                        TD.xe = enemyX;
                        TD.ye = enemyY;
                        TD.id = enemyId;
                        TD.range = sqrt((x - enemyX)*(x - enemyX)+(y - enemyY)*(y - enemyY));   // unnec fur Test03
                        TD.Drange = sqrt((TD.dx[j] - enemyX)*(TD.dx[j] - enemyX)+(TD.dy[j] - enemyY)*(TD.dy[j] - enemyY));
                    }
                }
            }

            /* load Targetting Data */
            int TargetID = TD.id;

            /* Output Command */
            cout << "SHOOT " << TargetID << endl; // MOVE x y or SHOOT id
        }
    }

// ----------------------DEVDUMP------------------------------------------------

    /* select enemy with shortest range */
    // if (sqrt((x - enemyX)*(x - enemyX)+(y - enemyY)*(y - enemyY)) < TD.range) {
    //     TD.xe = enemyX;
    //     TD.ye = enemyY;
    //     TD.id = enemyId;
    //     TD.range = sqrt((x - enemyX)*(x - enemyX)+(y - enemyY)*(y - enemyY));
    // }
