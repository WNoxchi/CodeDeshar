// CS50x - Intro to Computer Science
// Programming in C - Exercise 8.14
// WH Noxchi - Start: 24-Mar-2016 23:33 - 00:25
                 //   25-Mar-2016 02:18 - 03:06

// rewrite the last 4 exercises to use global variables instead of args
/*
 *  8.10 - 8.11 - 8.12 - 8.13
 */
// -----------------------------------------------------------------------------
/* Ex 8.10 - prime() */
// int prime(int n)
// {
//     if (n % 2 == 0) return 0;
//     for (int i = 3; i < n; i += 2)
//     {
//         if (n % i == 0) return 0;
//     }
//     return 1;
// }
// --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- -
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
        printf("\nNot Prime\n");
    }
    else {
        printf("\nPrime\n");
    }
}

int main(void)
{
    void isPrime (void);
    void displayPrime (void);

    isPrime();
    displayPrime();
}
// ----------------------------------------------------------------------------
/* Ex 8.11 - sumArray() */
#include <stdio.h>
int     gArrLen = 7;
int     gArray[7] = {1, 2, 3, 4, 5, 6, 7};
int     gArrSum;
int     gIndex;

void sumArray(void) {
    for (gIndex = 0; gIndex < gArrLen; gIndex++) {
        gArrSum += gArray[gIndex];
    }
}
void printSum(void) {
    printf("\nΣ of Array = %i\n", gArrSum);
}

int main(void)
{
    void sumArray(void), printSum(void);

    sumArray();
    printSum();
}
/* TERMINAL:

Waynes-MBP:Chapter08 WayNoxchi$ ./Ch-08.14

Σ of Array = 28

 */
// --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- -
// /* Ex 8.11 - arraySum() */
// #include <stdio.h>
//
// // prototype
// int arraySum(int elements, int array[elements]);
// void copyright();
//
// int main(void)
// {
//     copyright();
//     int arr[7] = {1, 2, 3, 4, 5, 6, 7};
//     int sum = arraySum(7, arr);
//     printf("The array A has 7 elements (Э):\n{ 1, 2, 3, 4, 5, 6, 7 }\n");
//     printf("\nΣ( A(Э) ) = %i\n", sum);
// }
//
// // definition
// int arraySum(int elements, int array[elements])
// {
//     int sum = 0;
//     for (int i = 0; i < elements; i++) {
//         sum += array[i];
//     }
//     return sum;
// }
//
// void copyright()
// {
//     printf("\n       Copyright WNoxchi 2016, Daymoxk\n");
//     printf("---------------------------------------------\n");
//     printf("             Σ of Э's in an array\n");
//     printf("---------------------------------------------\n");
// }
// -----------------------------------------------------------------------------
/* Ex 8.12 transMat() */
#include <stdio.h>

int     gRows = 4;
int     gCols = 5;
int     gMatAt[5][4];
int     gMatA[4][5] =
    {
        {  1,  2,  3,  4,  5 },
        {  6,  7,  8,  9, 10 },
        { 11, 12, 13, 14, 15 },
        { 16, 17, 18, 19, 20 }
    };

void transMat(void) {
    for (int i = 0; i < gRows; i++) {
        for (int j = 0; j < gCols; j++) {
            gMatAt[j][i] = gMatA[i][j];
        }
    }
}
void displayMat(void) {
    printf("Transposed Matrix:\n");
    for (int i = 0; i < gCols; i++) {
        for (int j = 0; j < gRows; j++) {
            printf("%5i", gMatAt[i][j]);
        }
        printf("\n");
    }
}

int main(void)
{
    void transMat(void), displayMat(void);
    transMat();
    displayMat();
}
/* TERMINAL:

Waynes-MBP:Chapter08 WayNoxchi$ ./Ch-08.14
Transposed Matrix:
    1    6   11   16
    2    7   12   17
    3    8   13   18
    4    9   14   19
    5   10   15   20

 */
// --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- -
/* Ex 8.12 transMat() */
// #include <stdio.h>
//
// void copyright();
// void transMat(int rows, int cols, int MatA[rows][cols]);
// void displayMat(int rows, int cols, int matrix[rows][cols]);
//
// int main(void)
// {
//     copyright();
//     int MatA[][5] =
//     {
//         {  1,  2,  3,  4,  5 },
//         {  6,  7,  8,  9, 10 },
//         { 11, 12, 13, 14, 15 },
//         { 16, 17, 18, 19, 20 }
//     };
//     printf("Original Matrix: \n");
//     displayMat(4, 5, MatA);
//     printf("\nTranspose Matrix: \n");
//     transMat(4, 5, MatA);
//
// }
//
// void transMat(int rows, int cols, int MatA[rows][cols])
// {
//     int MatAt[cols][rows];
//     for (int i = 0; i < rows; i++) {
//         for (int j = 0; j < cols; j++) {
//             MatAt[j][i] = MatA[i][j];
//         }
//     }
//     // cols & rows reversed bc transpMat
//     displayMat(cols, rows, MatAt);
// }
//
// void displayMat(int rows, int cols, int matrix[rows][cols]) {
//     for (int i = 0; i < rows; i++) {
//         for (int j = 0; j < cols; j++) {
//             printf("%5i", matrix[i][j]);
//         }
//         printf("\n");
//     }
// }

// void copyright()
// {
//     printf("\n       Copyright WNoxchi 2016, Daymoxk\n");
//     printf("---------------------------------------------\n");
//     printf("      Matrix A[i][j]  =  Matrix At[j][i]\n");
//     printf("---------------------------------------------\n");
// }
// -----------------------------------------------------------------------------
/* Ex 8.13 sortArray */
#include <stdio.h>

int     gOrder;
int     array[7] = { 1, 2, 3, 4, 5, 6, 7 };
int     ArrLen = 7;
int     i;
int     j;
int     temp;

void upDown(void){
    printf(" }\n\nEnter 1 to sort in ascending order, 0 for descending:");
    scanf("%i", &gOrder);
}
void sort(void){
    if (gOrder == 0) {
        for (i = 0; i < ArrLen - 1; ++i)
            for (j = i + 1; j < ArrLen; ++j)
                if (array[i] < array[j]) {
                    temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                }
    }
    else {
        for (i = 0; i < ArrLen - 1; ++i)
            for (j = i + 1; j < ArrLen; ++j)
                if (array[i] > array[j]) {
                    temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                }
    }
}
void show(void){
    for (i = 0; i < ArrLen; i++){
        printf("%3i", array[i]);
    }
    printf("\n");
}

int main(void)
{
    void upDown(void), sort(void), show(void);

    upDown();
    sort();
    show();
}
// --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- -
/* Ex 8.13 sortArray() */
// #include <stdio.h>
//
// void sort (int a[], int n, int order);
// void copyright();
//
// int main (void)
// {
//     copyright();
//     int order;
//     int array[16] = { 34, -5, 6, 0, 12, 100, 56, 22,
//                       44, -3, -9, 12, 17, 22, 6, 11 };
//
//     printf ("The array before the sort:\n{ ");
//
//     for (int i = 0; i < 16; ++i)
//         printf ("%3i ", array[i]);
//
//     printf(" }\n\nEnter 1 to sort in ascending order, 0 for descending:");
//     scanf("%i", &order);
//     sort (array, 16, order);
//
//     printf ("\nThe array after the sort:\n");
//
//     for (int i = 0; i < 16; ++i)
//         printf ("%i ", array[i]);
//
//     printf ("\n");
//
//     return 0;
// }
//
// void sort (int a[], int n, int order)
// {
//     int i, j, temp;
//     if (order == 0) {
//         for (i = 0; i < n - 1; ++i)
//             for (j = i + 1; j < n; ++j)
//                 if (a[i] < a[j]) {
//                     temp = a[i];
//                     a[i] = a[j];
//                     a[j] = temp;
//                 }
//     }
//     else {
//         for (i = 0; i < n - 1; ++i)
//             for (j = i + 1; j < n; ++j)
//                 if (a[i] > a[j]) {
//                     temp = a[i];
//                     a[i] = a[j];
//                     a[j] = temp;
//                 }
//     }
// }
//
// void copyright()
// {
//     printf("\n       Copyright WNoxchi 2016, Daymoxk\n");
//     printf("---------------------------------------------\n");
//     printf("    Sorting an Array: Ascending/Descending\n");
//     printf("---------------------------------------------\n");
// }
