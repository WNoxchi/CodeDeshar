/*  6.004.1x - Computation Structures
 *  T4.3 - Tutorial : Minimal Sum Of Products
 *  WNixalo - 30-Nov-2016 13:03
 */
#include <stdio.h>
int MUX(int x, int y, int w) {
    if (w)
        return y;
    return x;
}
int AND(int x, int y) {
    return x && y;
}
int XOR(int x, int y) {
    return !(x == y);
}
int NOT(int x) {
    return !x;
}
int main(void) {
    int A, B, C, F;
    for (int a = 0; a <= 1; a++) {
        A = a;
        for (int b = 0; b <= 1; b++) {
            B = b;
            for (int c = 0; c <= 1; c++) {
                C = c;
                F = MUX(AND(B,NOT(C)),XOR(B,C),A);
                printf("%d%d%d|%d\n", A,B,C,F);
            }
        }
    }
    return 0;
}
