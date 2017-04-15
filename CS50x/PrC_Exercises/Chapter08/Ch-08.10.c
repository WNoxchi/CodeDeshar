// CS50x - Intro to Computer Science
// Programming in C - Exercise 8.10
// WH Noxchi - 24-Mar-2016 19:54

// Write a function that returns 1 if arg is prime, 0 otherwise
int prime(int n)
{
    if (n % 2 == 0) return 0;
    for (int i = 3; i < n; i += 2)
    {
        if (n % i == 0) return 0;
    }
    return 1;
}
