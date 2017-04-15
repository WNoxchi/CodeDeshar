/*  6.004.1x - Computation Structures
 *  WE4.1 - Gates & Boolean Logic
 *  WNixalo - 29-Nov-2016 23:54
 */

#include <stdio.h>

int INV(int X) {
    return !X;
}
int OR(int X, int Y) {
    return X || Y;
}
int NOR(int X, int Y) {
    return !OR(X,Y);
}
int AND(int X, int Y) {
    return X && Y;
}
int NAND(int X, int Y) {
    return !AND(X,Y);
}
int H(int A, int B) {
    return NAND(NOR(NOR(A,INV(B)), AND(A,B)),OR(A,B));
}

int main(void) {
    int A, B;
    for (int a = 0; a <= 1; a++) {
        A = a;
        for (int b = 0; b <= 1; b++) {
            B = b;
            printf("%d%d|%d\n", A, B, H(A,B));
        }
    }
    return 0;
}

// Circuit Pseudo:
// INV1 = INV(B)
// AND1 = AND(A, B)
// NOR1 = NOR(A, INV1)
// NOR2 = NOR(NOR1, AND1)
// OR = OR(A, B)
// H = NAND(NAND2, OR1)
