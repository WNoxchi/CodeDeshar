/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
//  binary search
bool search(int value, int values[], int n)
{
    int mid, int max = n, int min = 0;  // max = n YA max = n - 1 ?
    while (max > min) {
        mid = (max + min) / 2
        if (value == values[mid]) return true;
        else if (value > values[mid]) {
            min = mid;
        }
        else if (value < values[mid]) {
            max = mid;
        }
    }
    return false;
}

/* binary search pseudocode:

while length of list > 0
    look at middle of list
    if number found, return true;
    else if number higher, search left
    else if number lower, search right
return false

*/

// // recursive search helper function
// bool reesarch(int & value, int values[], int & max, int & min) {
//     mid = (max - min) / 2;
//     if (value == values[mid]) return true;
//     if 
// }

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    int mindex = 0, temp;
    // sorting algorithm (selsort)
    for (int i = 0; i < n; i++) {
        for (int k = 1; k <= n; k++) {
            // find index of min val
            if (values[k] < values[mindex]) mindex = k;
        }
        // swap array[min] and array[i]
        temp = values[i];
        values[i] = values[mindex];
        values[mindex] = temp;
        
    }
    return values[];
}
/****
halxara sort algo:

    int temp;
    // sorting algorithm
    for (int i = 0; i < n; i++) {
        for (int l = 0; l < n; l++) {
            if (values[i] < values[l]) {
                   temp = values[i];
                   values[i] = values[l];
                   values[l] = temp;
            }
        }
    }
****/

/***
//  linear search
bool search(int value, int values[], int n)
{
    for (int i = 0; i < n; i++) {
        if (values[i] == value) {
            return true;
        }
    }
    return false;
}
***/