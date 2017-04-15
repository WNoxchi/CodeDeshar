// int prime(int n)
// {
//     if (n % 2 == 0) return 0;
//     for (int i = 3; i < n; i += 2)
//     {
//         if (n % i == 0) return 0;
//     }
//     return 1;
// }

#include <stdio.h>

int     gNumber;
int     gIndex = 3;
int     gPrime = 0;

void isPrime(void)
{
    printf("Number to check prime: ");
    scanf("%i", &gNumber);

    for (gIndex = 3; gIndex < gNumber; gIndex += 2) {
        if (gNumber % gIndex == 0) {
            gPrime = 0;
        }
        else {
            gPrime = 1;
        }
    }
}

void displayPrime(void)
{
    if (gPrime == 0) {
        printf("Not Prime");
    }
    else {
        printf("Prime");
    }
}

int main(void)
{
    void isPrime (void);
    void displayPrime (void);

    isPrime();
    displayPrime();
}
