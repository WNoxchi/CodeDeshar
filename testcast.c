// type cast test - WNixaloy - 13-Aug-2016 23:42
#include <stdio.h>
int main(void) {
    float x = (float) 65 / 66;
    float y = ((float) 65) / 66;
    printf("\nX = %.4f", x);
    printf("\nY = %.4f\n", y);
    return 0;
}
