// CS1156x - Learning from Data - HW 4.8
// Wayne H Nixalo - 04-Nov-2016 20:46

#include <stdio.h>
#include <math.h>
// calculate binomial coefficient
int biCof(int N, int q) {
    if (N < q) {
        return 0;
    } else if (q == 0 || q == N || q <= 0) {
        return 1;
    } else {
        return (biCof(N-1, q-1) + biCof(N-1, q));
    }
}

// calculate growth function
int mH(int N, int q) {
    if (N == 1) {
        return 2;
    }
    return (2 * mH(N-1, q) - biCof(N-1, q));
}

int main(void){
    printf("mH(N+1) = 2mH(N) - {N, q}; where {N, q} is a Binomial Coefficient\n");
    printf("----------  ----------\n");
    for (int N = 1; N < 6; N++) {
        printf("N = %i, q = 1...5:\n", N);
        for (int q = 1; q < 6; q++) {
            printf("[N,q]:[%i,%i] = %i\n", N, q, mH(N+1,q));
        }
        printf("----------  ----------\n");
    }

    // calculating (N+1)^k
    for (int N = 1; N < 6; N++) {
        printf("N = %i, dvc = 1...5:\n", N);
        for (int dvc = 1; dvc < 6; dvc++) {
            printf("(N+1)^dvc: (%i+1)^%i = %i\n", N, dvc, (int)pow(N+1, dvc));
        }
        printf("----------  ----------\n");
    }
}
