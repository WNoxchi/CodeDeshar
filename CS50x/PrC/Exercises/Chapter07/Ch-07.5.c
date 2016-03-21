// CS50x - Introduction to Computer Science
// Programming in C - Exercise 7.5
// WH Noxchi - 18-Mar-2016 16:21

#include <stdio.h>

int main(void)
{
    int numbers[10] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int i, j;

    for (j = 0; j < 10; ++j)
        for (i = 0; i < j; ++i)
            numbers[j] += numbers[i];
            // printf("n[I]: %i -- n[J]: %i\n", numbers[i], numbers[j]);
            // printf("  I:  %i   --   J:  %i\n", i, j);
            // printf("numbers[9] = %i\n\n", numbers[9]);

            for (int i = 0; i < 10; i++) {
                // printf("numbers[%i] = %i\n", i, numbers[i]);
            }

    for (j = 0; j < 10; ++j)
        printf("%i\n", numbers[i]);

    printf("\n");

    return 0;
}

/* Okay I understand this now. It's [i] iterating inside of [j], they're just
 * indexes: j from 0 to 10, i from 0 to j on each run of j. That means the j'th
 * element of numbers[] gets more added to it because it's cycling and adding
 * all the previous values as i goes from 0 to j. simple.
 */
