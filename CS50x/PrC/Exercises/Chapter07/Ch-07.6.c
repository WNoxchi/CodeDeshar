// CS50x - Introduction to Computer Science
// Programming in C - Exercise 7.6
// WH Noxchi - 19-Mar-2016 02:06

// Rewrite Program 7.3 st arrays arent used. Display each Fib # as its generated.
// Use 3 variables

#include <stdio.h>

int main(void)
{
    int count = 15;
    int f1 = 1;
    int f2 = 0;
    int tot;

    for (int i = 0; i < count; i++) {
        tot = f2 + f1;
        printf("Fib Series [%i] = %i\n", i, tot);
        f1 = f2;
        f2 = tot;
    }

}
// F[i] = F[i-2] + F[i-1]
// tot  =   F1   +   F2

// #include <stdio.h>
//
// int main (void)
// {
//     int Fibonacci[15], i;
//
//     Fibonacci[0] = 0;   // by definition
//     Fibonacci[1] = 1;   // ditto
//
//     for ( i = 2; i < 15; ++i )
//          Fibonacci[i] = Fibonacci[i-2] + Fibonacci[i-1];
//
//     for ( i = 0; i < 15; ++i )
//          printf ("%i\n", Fibonacci[i]);
//
//     return 0;
// }
