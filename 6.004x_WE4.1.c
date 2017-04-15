/*  6.004.1x - Computation Structures
 *  WE4.1 - CMOS Circuit to TT
 *  WNixalo - 29-Nov-2016 22:36
 */

#include <stdio.h>

short F(short A, short B, short C, short D) {
    if (!((A+B)*C+D)) {
        return 1;
    } else {
        return 0;
    }
}
int main(void){
    printf("F = !((A+B)•C+D)\n");
    short A = 0, B = 0, C = 0, D = 0;
    for (int a = 0; a <= 1; a++) {
        A = a;
        for (int b = 0; b <= 1; b++) {
            B = b;
            for (int c = 0; c <= 1; c++) {
                C = c;
                for (int d = 0; d <= 1; d++) {
                    D = d;
                    printf("%d%d%d%d|%d\n", A, B, C, D, F(A,B,C,D));
                }
            }
        }
    }
    return 0;
}

// F = !((A+B)•C+D)
// 0000|1
// 0001|0
// 0010|1
// 0011|0
// 0100|1
// 0101|0
// 0110|0
// 0111|0
// 1000|1
// 1001|0
// 1010|0
// 1011|0
// 1100|1
// 1101|0
// 1110|0
// 1111|0
