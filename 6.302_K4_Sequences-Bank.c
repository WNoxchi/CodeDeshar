// 6.302_K4_Sequences-Bank.c
// WNoxchi - 03-Aug-2016 12:13

#include <stdio.h>

float interest(int month, float balance, float rate);
int main(void) {
    int years;
    float balance, rate;
    printf("Banking Interest: y[n] = y[n-1] + 0.12y[n-1]    compounded monthly\n");
    while (years != 0) {
        printf ("years: ");
        scanf("%i", &years);
        printf ("balance: ");
        scanf("%f", &balance);
        printf ("interest rate (monthly; 1%% = '0.01'): ");
        scanf("%f", &rate);
        printf ("New balance after %i years: %.2f\n", \
                                                years, interest(years*12, balance, rate));
    }
    return 0;
}

float interest( int m, float balance, float rate ) {
    float iRate = 1.0 + rate;
    if (m == 0) return balance;
    else {
        return (iRate * interest(m-1, balance, rate));
    }
}
