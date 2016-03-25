// CS50x - Intro to Computer Science
// Programming in C - Exercise 8.13
// WH Noxchi - 24-Mar-2016 23:30

// Modify sort func of prg8.12 to take a 3rd arg indicatng sort: asc or desc


// Program to sort an array of integers into ascending order

#include <stdio.h>

void sort (int a[], int n, int order);
void copyright();

int main (void)
{
    copyright();
    int order;
    int array[16] = { 34, -5, 6, 0, 12, 100, 56, 22,
                      44, -3, -9, 12, 17, 22, 6, 11 };

    printf ("The array before the sort:\n{ ");

    for (int i = 0; i < 16; ++i)
        printf ("%3i ", array[i]);

    printf(" }\n\nEnter 1 to sort in ascending order, 0 for descending:");
    scanf("%i", &order);
    sort (array, 16, order);

    printf ("\nThe array after the sort:\n");

    for (int i = 0; i < 16; ++i)
        printf ("%i ", array[i]);

    printf ("\n");

    return 0;
}

void sort (int a[], int n, int order)
{
    int i, j, temp;
    if (order == 0) {
        for (i = 0; i < n - 1; ++i)
            for (j = i + 1; j < n; ++j)
                if (a[i] < a[j]) {
                    temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
    }
    else {
        for (i = 0; i < n - 1; ++i)
            for (j = i + 1; j < n; ++j)
                if (a[i] > a[j]) {
                    temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
    }
}

void copyright()
{
    printf("\n       Copyright WNoxchi 2016, Daymoxk\n");
    printf("---------------------------------------------\n");
    printf("    Sorting an Array: Ascending/Descending\n");
    printf("---------------------------------------------\n");
}

/* TERMINAL:

       Copyright WNoxchi 2016, Daymoxk
---------------------------------------------
    Sorting an Array: Ascending/Descending
---------------------------------------------
The array before the sort:
{  34  -5   6   0  12 100  56  22  44  -3  -9  12  17  22   6  11  }

Enter 1 to sort in ascending order, 0 for descending:0

The array after the sort:
100 56 44 34 22 22 17 12 12 11 6 6 0 -3 -5 -9
Waynes-MBP:Chapter08 WayNoxchi$ ./Ch-08.13

       Copyright WNoxchi 2016, Daymoxk
---------------------------------------------
    Sorting an Array: Ascending/Descending
---------------------------------------------
The array before the sort:
{  34  -5   6   0  12 100  56  22  44  -3  -9  12  17  22   6  11  }

Enter 1 to sort in ascending order, 0 for descending:1

The array after the sort:
-9 -5 -3 0 6 6 11 12 12 17 22 22 34 44 56 100

 */
