// Wayne H. Noxchi  - MATH226.1x - Intro to Differential Equations
// 05-Apr-2016 20:10

#include <stdio.h>

void Euler(int step, float delta) {
    float t = 0, Yk = 2, Vk = 4, dV, dY;

    for (int i = 0; i < step; i++) {
        t += delta;
        dY = Vk;
        dV = -Vk*(Yk*Yk - 2) - 3*Yk;
        Yk = Yk + Vk*delta;
        // Vk = Vk + dY*delta;  << incorrect update methd
        Vk = Vk + dV*delta;
    }
    printf("\nT(%i) = %.2f", step, t);
    printf("\nY(%i) = %.2f", step, Yk);
    printf("\nV(%i) = %.2f\n", step, Vk);
}

int main(void){
    int step;
    float delta;

    printf("Number of steps: ");
    scanf("%i", &step);
    printf("delta T = ");
    scanf("%f", &delta);

    Euler(step, delta);
}
