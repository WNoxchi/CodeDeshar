/*  CS50x - Intro to Computer Science
 *  Programming in C
 *-----------------------------------------------------<>
 *  11.08_sort3.c
 *-----------------------------------------------------<>
 *  WNixaloy - 06-Aug-2016 21:53
 */

/*  Write a function called sort3 to sort three integers into ascending order.
    (This function is not to be implemented with arrays.)   */

#include <stdio.h>

void sort3(int *n1, int *n2, int *n3) {
    int temp;
    if (*n3 < *n2) {
        temp = *n2;
        *n2 = *n3;
        *n3 = temp;
    }
    if (*n2 < *n1) {
        temp = *n1;
        *n1 = *n2;
        *n2 = temp;
    }
}

int main (void) {
    int n1 = 10, n2 = 9, n3 = 15;
    printf("unsorted: %i, %i, %i\n\n", n1, n2, n3);
    sort3(&n1, &n2, &n3);
    printf("sorted: %i, %i, %i\n\n", n1, n2, n3);

    return 0;
}

// Terminal:
// Waynes-MBP:Chapter11 WayNoxchi$ ./11.08_sort3
// unsorted: 10, 9, 15
//
// sorted: 9, 10, 15
