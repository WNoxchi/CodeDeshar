/**     6.002x_sanityCheck.c     **/
/** 09-May-2016 14:58 - WHNoxchi **/

#include <stdio.h>

float calcZf(int Zc, int Zl, int ZR2);
float calcZfv2(int Zc, int Zl, int ZR2);

int main(void){
    printf("Zf = (ZcZl+ZcZR2)/(Zc+Zl+ZR2)\n");
    printf("Can Zc be cancelled out?\n");
    int Zc = 2, Zl = 3, ZR2 = 5;
    float Zf, Zf2;
    Zf = calcZf(Zc, Zl, ZR2);
    printf("%.4f\n", Zf);
    Zf2 = calcZfv2(Zc, Zl, ZR2);
    printf("%.4f\n", Zf2);
    if (Zf != Zf2) printf("False\n");
    else printf("True\n");

    return 0;
}

float calcZf(int Zc, int Zl, int ZR2){
    return (Zc*Zl + Zc*ZR2)/ (float)(Zc + Zl + ZR2);
}

float calcZfv2(int Zc, int Zl, int ZR2){
    return (Zl + ZR2)/ (float)(Zl + ZR2);
}

// 09-May-2016 15:18 - complete
