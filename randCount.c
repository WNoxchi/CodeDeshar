// 22-Jun-2016 04:35 - WNoxchi

#include <stdio.h>

const int TER = 1000000;

int main(void) {
    int X = 0, count = 0;
    while (X > -1) {
        for (int i = 0; i < TER; i++) {
            count++;
            printf("%i + %i Million\n", count, X);
        }
        count = 0;
        X++;
    }
    return 0;
}
