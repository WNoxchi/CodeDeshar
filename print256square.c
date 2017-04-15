// 11-Nov-2016 18:18 - Wayne Nixalo
#include <stdio.h>
#include <stdlib.h>

// program prints a square 256 x 256 brackets - to help visualize a 256 cube
void printsquare(int n) {
    for (short i = 0; i < n; i++) {
        if ( rand() % 2 == 0) {
            printf("[O]");
        } else {
            printf("[I]");
        }
    }
}
int main(void) {
    int n = 256;
    for (unsigned short i = 0; i < n; i++) {
        printsquare(n);
        printf("\n");
    }
    return 0;
}
