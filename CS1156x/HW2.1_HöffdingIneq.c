/*  Wayne H Nixalo - CS1156x Learning from Data - HW2.1 Höffding Inequality
    Port of Python code into C for speed    -   20-Oct-2016 14:00       */

#include <stdio.h>
#include <stdlib.h>

// int randomize();
int ITER = 100000;

// randint fn
int randint(int x) {
    return rand()%x;
}

int main(void) {
    struct Result {
        double C1V1;
        double CRVR;
        double CMRM;
    };
    struct Result Result;
    Result.C1V1 = 0.0;
    Result.CRVR = 0.0;
    Result.CMRM = 0.0;

    for (int n = 0; n < ITER; n++) {
        // generate 1000x10 flips
        int Coins[1000][10];
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 1000; j++) {
                int flip = randint(2);
                Coins[j][i] = flip;
            }
        }
        // find minimum ratio
        double Vmin = 2;
        for (int i = 0; i < 1000; i++) {
            int sumflip = 0;
            for (int j = 0; j < 10; j++) {
                sumflip += Coins[i][j];
            }
            if (Vmin > (double)sumflip/10) {
                Vmin = (double)sumflip/10;
            }
        }
        Result.CMRM += Vmin;
        // printf("%.5f\n", Result.CMRM);
        // find other ratios
        int C1 = 0, CR = 0, indexR = randint(1000);
        for (int i = 0; i < 10; i++) {
            C1 += Coins[0][i];
            CR += Coins[indexR][i];
        }
        Result.C1V1 += (double)C1/10;
        Result.CRVR += (double)CR/10;

        if (n % 1500 == 0) {
            printf("%.1f%% complete\n", (double)n/1000);
        }
    }
    // average results:
    Result.C1V1 /= ITER;
    Result.CRVR /= ITER;
    Result.CMRM /= ITER;

    printf("C1V1: %.4f; CRVR: %.4f; CMRM: %.4f\n", Result.C1V1, Result.CRVR, Result.CMRM);

    return 0;
}
