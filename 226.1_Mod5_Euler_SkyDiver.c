// 30-Mar-2016 13:06

#include <stdio.h>
#include <math.h>

int main(void)
{
    float deltaT;
    int trials;

    float vk = 0, tk = 0, mk;
    float vmax;

    printf("\nCalculating time to .95(VMax) for a skydiver (Euler):\n"
           " -> Differential Eqtn: m(dv/dt) = mg - kv^2\n"
           " -> Terminal Velocity: sqrt(mg/k)\n\n");

    vmax = sqrt(54 * 9.81 / 0.18);
    printf(" -> mass: 54kg. drag-coeff: 0.18kg/m. Vmax = %.4f m/s", vmax);
    printf("\n -> Init/Term Conditions: V(0) = 0 , V(Tx) = %.4f m/s\n", (0.95*vmax));

    printf("Time interval for calculation: дt = ");
    scanf("%f", &deltaT);

    do {
        mk = (9.81) - ((0.18)*powf(vk, 2.0))/54;
        vk = vk + mk * deltaT;
        tk += deltaT;
    }
    while (vk <= 0.95*vmax);

    printf("\nTime to .95(Vmax): %.2f seconds.\n\n", tk);

    return 0;
}
