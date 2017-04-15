// CS50x - Intro to Computer Science
// Programming in C - Exercise 8.11
// WH Noxchi - 24-Mar-2016 22:51  |F: 23:06

// Write a function arraySum that takes an int array & number elements in array
// Returns sum of Эs in array

#include <stdio.h>

// prototype
int arraySum(int elements, int array[elements]);
void copyright();

int main(void)
{
    copyright();
    int arr[7] = {1, 2, 3, 4, 5, 6, 7};
    int sum = arraySum(7, arr);
    printf("The array A has 7 elements (Э):\n{ 1, 2, 3, 4, 5, 6, 7 }\n");
    printf("\nΣ( A(Э) ) = %i\n", sum);
}

// definition
int arraySum(int elements, int array[elements])
{
    int sum = 0;
    for (int i = 0; i < elements; i++) {
        sum += array[i];
    }
    return sum;
}

void copyright()
{
    printf("\n       Copyright WNoxchi 2016, Daymoxk\n");
    printf("---------------------------------------------\n");
    printf("             Σ of Э's in an array\n");
    printf("---------------------------------------------\n");
}

/* TERMINAL:

Waynes-MBP:Chapter08 WayNoxchi$ ./Ch-08.11

       Copyright WNoxchi 2016, Daymoxk
---------------------------------------------
             Σ of Э's in an array
---------------------------------------------
The array A has 7 elements (Э):
{ 1, 2, 3, 4, 5, 6, 7 }

Σ( A(Э) ) = 28
Waynes-MBP:Chapter08 WayNoxchi$

 */
