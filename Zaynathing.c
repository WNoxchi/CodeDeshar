/**
This program will check whether or not the equation Z = (X*Y)/(X+Y) is equal to (X+Y)/(X*Y)
**/

#import <stdio.h>

float XYmul(float z, float x, float y);
float XYadd(float z, float x, float y);

int main(void){
    float z, x, y, W;
    printf("Check: Z = (XY)/(X+Y) vs. Z = (X+Y)/(XY)\n");
    printf("Please enter a value for z, x, y:\n");
    printf("Z = ");
    scanf("%f", &z);
    printf("\nX = ");
    scanf("%f", &x);
    printf("\nY = ");
    scanf("%f", &y);

    W = XYmul(z, x, y);
    printf("Z = (XY)/(X+Y)\n");
    printf("(%.2f*%.2f)/(%.2f+%.2f) = %.4f\n", x, y, x, y, W);
    if (W == XYadd(z, x, y)) {
        printf("(XY)/(X+Y) equal to (X+Y)/(XY) for values chosen.\n");
    }
    else {
        printf("(XY)/(X+Y) NOT equal to (X+Y)/(XY) for values chosen.\n");
    }
    if (z != W) {
        printf("Btw, %.4f doesn't equal %.4f dummy. <3\n", z, W);
    }
    else {
        printf("Oh, and the Z you picked, %.4f -- is correct. Good job <3\n", z);
    }
    return 0;
}

float XYmul(float z, float x, float y){
    float result;
    result = (x*y)/(x+y);
    return result;
}
float XYadd(float z, float x, float y){
    float result;
    result = (x+y)/(x*y);
    return result;
}
