// 30-Mar-2016 13:06

#include <stdio.h>
#include <math.h>

int main(void)
{
    float step, T;
    int trials;

    float mk, yk, tk;
    
    printf("\nEuler: dy/dt = (3 - w)(w + 1)\n");

    printf("\nStep size (x.xx): ");
    scanf("%f", &step);

    printf("From T = 0 to T = ?: ");
    scanf("%f", &T);

    trials = T / step;
    printf("Number Trials = %i\n", trials);

    printf("Y(0) = ?: ");
    scanf("%f", &yk);

    tk = 0;

    for (int i = 0; i < trials; i++) {
        mk = (3 - yk) * (yk + 1);
        tk += step;
        yk = yk + mk * step;
    }

    printf("\nY(%.0f) = %.4f\n", T, yk);

    return 0;
}

// ESET 5.5:
// printf("\nEuler: dy/dt = sqrt(y)\n");
// mk = sqrtf(yk);

// ESET 5.6:
// printf("\nEuler: dy/dt = 2 - y\n");
// mk = 2 - yk;

// ESET 5.7:
// printf("\nEuler: dy/dt = (3 - w)(w + 1)\n");
// mk = (3 - yk) * (yk + 1);
