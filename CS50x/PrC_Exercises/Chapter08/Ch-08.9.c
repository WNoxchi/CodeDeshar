// CS50x - Intro to Computer Science
// Programming in C - Exercise 8.9
// WH Noxchi - 24-Mar-2016 19:31

// Write a function lcm() that takes 2 ints and returns their least common multiple.
// Call gcd function from Program 8.6
// identity:   lcm (u, v) = uv / gcd (u, v)    |   u, v >= 0

#include <stdio.h>
int gcd(int u, int v);
void copyright();

int main(void)
{
    int u, v, gc, lcm;
    copyright();
    printf("Enter u: ");
    scanf("%i", &u);
    printf("\nEnter v: ");
    scanf("%i", &v);
    printf("\n");

    gc = gcd (u, v);
    lcm = (u * v) / gc;
    printf("LCM(%i, %i) = %i\n", u, v, lcm);

}

/* Function to find the greatest common divisor of two
    nonnegative integer values and to return the result.    */
int gcd (int u, int v)
{
    int temp;

    while (v != 0) {
        temp = u % v;
        u = v;
        v = temp;
    }

    return u;
}

void copyright()
{
    printf("\n      Copyright WNoxchi 2016, Daymoxk\n");
    printf("---------------------------------------------\n");
    printf("lcm (u, v) = uv / gcd (u, v)    |   u, v >= 0\n");
    printf("---------------------------------------------\n");
}
