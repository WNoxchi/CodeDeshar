/*  Wayne H Nixalo - 16-Oct-2016 03:50
    Codingame: The Accountant
    Test07 Evasion II Algorithm   */

    #include <iostream>
    #include <string>
    #include <vector>
    #include <algorithm>

    using namespace std;

    /**
     * Shoot enemies before they collect all the incriminating data!
     * The closer you are to an enemy, the more damage you do but don't get too close or you'll get killed.
     **/

    /* consolidated struct to hold Enemy & DP data */
    struct TargetData {
        vector <int> dx;  // DP x
        vector <int> dy;  // DP y
        vector <int> xe;  // enemy x
        vector <int> ye;  // enemy y
        vector <int> id;  // enemy ID
        double Drange;    // range of nearest enemy to a DP
        double Erange;    // range of nearest enemy to player
        int targetID;     // id of enemy to shoot
        int targetX;      // X coord to move towards
        int targetY;      // Y coord to move towards
    };

    /* prototypes */
    void calcDrange(struct TargetData &TD, int dataCount, int enemyCount);    // calculates closest range of enemy to data point
    void calcErange(struct TargetData &TD, int enemyCount, int x, int y);    // calculates closest range of enemy to player

    int main()
    {

        TargetData TD;

        // game loop
        while (1) {

            int ShootMove;  // Decision to SHOOT(1) or MOVE(0)
            int EVADE;      // EVASION State, 1 = evade, 0 = attach
            string Cmd;     // Output Command ("SHOOT" + "id", or "MOVE" + "x y")

            int x;
            int y;
            cin >> x >> y; cin.ignore();
            int dataCount;
            cin >> dataCount; cin.ignore();
            /* TD DP coord vectors of correct size */
            TD.dx.resize(dataCount);
            TD.dy.resize(dataCount);

            for (int i = 0; i < dataCount; i++) {
                int dataId;
                int dataX;
                int dataY;
                cin >> dataId >> dataX >> dataY; cin.ignore();
                /* enter DP data into TD */
                TD.dx[i] = dataX;
                TD.dy[i] = dataY;
            }
            int enemyCount;
            cin >> enemyCount; cin.ignore();
            /* TD Enemy vectors of correct size */
            TD.xe.resize(enemyCount);
            TD.ye.resize(enemyCount);
            TD.id.resize(enemyCount);

            for (int i = 0; i < enemyCount; i++) {
                int enemyId;
                int enemyX;
                int enemyY;
                int enemyLife;
                cin >> enemyId >> enemyX >> enemyY >> enemyLife; cin.ignore();
                /* enter Enemy data into TD */
                TD.xe[i] = enemyX;
                TD.ye[i] = enemyY;
                TD.id[i] = enemyId;
            }

            /* Calculate D & E ranges */
            calcDrange(TD, dataCount, enemyCount);
            calcErange(TD, enemyCount, x, y);

            /* check if enemy too close */
            if (TD.Erange < 2500) {
                EVADE = 1;
            }
            if (TD.Erange >= 2500) {
                EVADE = 0;
            }

            if (!EVADE) {
                /* move towards closest enemy & shoot when in range */
                if (TD.Erange > 6000) {
                    ShootMove = 0;
                }
                if (TD.Erange <= 6000) {
                    ShootMove = 1;
                }
                if (ShootMove) {
                    Cmd = "SHOOT ";
                    Cmd += to_string(TD.targetID);
                }
                if (!ShootMove) {
                    Cmd = "MOVE ";
                    Cmd += to_string(TD.targetX);
                    Cmd += ' ';
                    Cmd += to_string(TD.targetY);
                    string s = " MOVE: ";
                    s += to_string(TD.targetX);
                    s += ' ';
                    s += to_string(TD.targetY);
                    Cmd += s;
                }
            }
            if (EVADE) {
                if (EVADE) {
                    Cmd = "MOVE ";
                    Cmd += to_string(2*x - TD.targetX);
                    Cmd += ' ';
                    Cmd += to_string(2*y - TD.targetY);
                    string s = " EVADE: ";
                    s += to_string(2*x - TD.targetX);
                    s += ' ';
                    s += to_string(2*y - TD.targetY);
                    Cmd += s;
                }
            }


            // Write an action using cout. DON'T FORGET THE "<< endl"
            // To debug: cerr << "Debug messages..." << endl;

            cout << Cmd << endl; // MOVE x y or SHOOT id
        }
    }

    void calcDrange(struct TargetData &TD, int dataCount, int enemyCount) {
        /* load first range */
        TD.Drange = sqrt((TD.dx[0] - TD.xe[0])*(TD.dx[0] - TD.xe[0])+(TD.dy[0] - TD.ye[0])*(TD.dy[0] - TD.ye[0]));
        TD.targetX = TD.xe[0];
        TD.targetY = TD.ye[0];
        TD.targetID = TD.id[0];
        /* scan through ranges of every enemy to every data point */
        for (int i = 0; i < dataCount; i++) {
            for (int k = 0; k < enemyCount; k++) {
                if (TD.Drange > sqrt((TD.dx[i] - TD.xe[k])*(TD.dx[i] - TD.xe[k])+(TD.dy[i] - TD.ye[k])*(TD.dy[i] - TD.ye[k]))) {
                    TD.Drange = sqrt((TD.dx[i] - TD.xe[k])*(TD.dx[i] - TD.xe[k])+(TD.dy[i] - TD.ye[k])*(TD.dy[i] - TD.ye[k]));
                    TD.targetID = TD.id[k];
                    TD.targetX = TD.xe[k];
                    TD.targetY = TD.ye[k];
                }
            }
        }
    }

    void calcErange(struct TargetData &TD, int enemyCount, int x, int y) {
        /* load first range */
        TD.Erange = sqrt((x - TD.xe[0])*(x - TD.xe[0])+(y - TD.ye[0])*(y - TD.ye[0]));
        TD.targetX = TD.xe[0];
        TD.targetY = TD.ye[0];
        TD.targetID = TD.id[0];
        /* scan through ranges of each enemy to player */
        for (int i = 0; i < enemyCount; i++) {
            if (TD.Erange > sqrt((x - TD.xe[i])*(x - TD.xe[i])+(y - TD.ye[i])*(y - TD.ye[i]))) {
                TD.Erange = sqrt((x - TD.xe[i])*(x - TD.xe[i])+(y - TD.ye[i])*(y - TD.ye[i]));
                TD.targetID = TD.id[i];
                TD.targetX = TD.xe[i];
                TD.targetY = TD.ye[i];
            }
        }
    }
