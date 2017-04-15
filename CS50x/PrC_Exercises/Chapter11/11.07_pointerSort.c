/*  CS50x - Intro to Computer Science
 *  Programming in C
 *-----------------------------------------------------<>
 *  11.07_pointerSort.c
 *-----------------------------------------------------<>
 *  WNixaloy - 06-Aug-2016 21:29
 */

/*
Write a pointer version of the sort function from Chapter 8, “Working with
Functions.” Be certain that pointers are exclusively used by the function,
including index variables in the loops.
*/

#include <stdio.h>

void sort (int *array, int n) {
    int *arrPtr1, *arrPtr2, temp;
    for (arrPtr1 = array; arrPtr1 < array + n - 1; arrPtr1++)
        for (arrPtr2 = arrPtr1 + 1; arrPtr2 < array + n; arrPtr2++)
            if (*arrPtr1 > *arrPtr2) {
                temp = *arrPtr1;
                *arrPtr1 = *arrPtr2;
                *arrPtr2 = temp;
            }
}

int main (void) {
    int array[16] = { 13, 33, 52, -85, -10, -99, 43, 17,
                      67, 55, 99, -98, 710, -15, 19, 77 };
    printf("Array pre-sort:\n\n");
    for (int i = 0; i < 16; i++)
        printf("%i  ", array[i]);
    printf("\n\n");

    sort(array, 16);

    printf("Array post-sort:\n\n");
    for (int i = 0; i < 16; i++)
        printf("%i  ", array[i]);
    printf("\n\n");

    return 0;
}

// from Chapter 8:
// void sort (int a[], int n) {
//     int i, j, temp;
//     for (i = 0; i < n - 1; ++i) {
//         for (j = i + 1; j < n; ++j) {
//             if (a[i] > a[j]) {
//                 temp = a[i];
//                 a[i] = a[j];
//                 a[j] = temp;
//             }
//         }
//     }
// }

// Solution by Author
// ---------------------------------------
//
// 11-7
// ------
// /* Sort an array of integers into ascending order
//    (pointer version )  */
//
// void sort (int  *a, int  n)
// {
//    int  *aptr1, *aptr2, temp;
//
//    for ( aptr1 = a;  aptr1 < a + n - 1;  ++aptr1 )
//        for ( aptr2 = aptr1 + 1;  aptr2 < a + n;  ++aptr2 )
//            if ( *aptr1 > *aptr2 ) {
//               temp = *aptr1;
//               *aptr1 = *aptr2;
//               *aptr2 = temp;
//            }
// }
//
// ---------------------------------------

// Crap and tries:

// #include <stdio.h>
// #include <stdlib.h>

// // void sort (int *arr, int *last, int *order) {
// //     int temp;
// //     int *i, *j;
// //     for (i = arr, i < last - 1, ++i) {
// //         for (j = i + 1; j < last; ++j) {
// //             if ( (*order && *i > *j) || (!*order && *i < *j) ) {
// //                 temp = *i;
// //                 *i = *j;
// //                 *j = temp;
// //             }
// //         }
// //     }
// // }

// void sort (int *a, int *last, int *order) {
//     int *i, *j;
//     int temp;
//
//     for (i = a; i < last - 1; ++i) {
//         for (j = i + 1; j < last; ++j) {
//             if ( (*order && *i > *j) || (!*order && *i < *j) ) {
//                 temp = *i;
//                 *i = *j;
//                 *j = temp;
//             }
//         }
//     }
// }
//
// int main (void) {
//     int array[16] = { 13, 33, 52, -85, -10, -99, 43, 17,
//                       67, 55, 99, -98, 710, -15, 19, 77 };
//     int order, *i;
//
//     void sort(int *arr, int *last, int *order);
//
//     printf("Array:\n");
//     for (i = array; i < array + 16; i++)
//         printf("%i ", *i);
//     printf("\n\n");
//
//     order = 1;
//     sort(array, &array[16], &order);
//
//     printf("Array sorted ascending:\n");
//     for (i = array; i < array+ 16; i++)
//         printf("%i ", *i);
//     printf("\n\n");
//
//     order = 0;
//     sort(array, &array[16], &order);
//
//     printf("Array sorted ascending:\n");
//     for (i = array; i < array + 16; i++)
//         printf("%i ", *i);
//     printf("\n\n");
// }

// help from: https://github.com/ivanbrennan/programming-in-c/blob/master/ex.11.7.c
