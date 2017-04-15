// 6.302_K4_Sequences.c
// 03-Aug-2016 11:48

#include <stdio.h>
#include <math.h>

void Yab(int n);
int main(void) {
    int n;
    printf("ya[n] = -4/3*ya[n-1]  ;  yb[n] = -3/4*yb[n-1]    ; yb[0] = 1 = ya[0]\n");
    while (n != 0) {
        printf("n: ");
        scanf("%i", &n);
        Yab(n);
        printf("\n");
    }
    return 0;
}

void Yab(int n) {
    float ya, yb;
    ya = pow(-1.333333, n) * 1;
    yb = pow(-0.75, n) * 1;
    printf("ya[%i] = %.4f", n, ya);
    printf("  ;  ya[%i] = %.4f", n, yb);
}
