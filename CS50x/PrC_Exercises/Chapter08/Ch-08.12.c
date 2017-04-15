// CS50x - Intro to Computer Science
// Programming in C - Exercise 8.12
// WH Noxchi - 24-Mar-2016 20:00  -  Finish: 24-Mar-2016 22:41

// Write a function that takes an arg a 4x5 Mat & a 5x4 Mat. Transpose 4x5 Mat
// & store result in 5x4 Mat.

// Use variable-length arrays, rewrite function to take number of rows & cols as
// args & transpose.

#include <stdio.h>

void copyright();
void transMat(int rows, int cols, int MatA[rows][cols]);
void displayMat(int rows, int cols, int matrix[rows][cols]);

int main(void)
{
    copyright();
    int MatA[][5] =
    {
        {  1,  2,  3,  4,  5 },
        {  6,  7,  8,  9, 10 },
        { 11, 12, 13, 14, 15 },
        { 16, 17, 18, 19, 20 }
    };
    printf("Original Matrix: \n");
    displayMat(4, 5, MatA);
    printf("\nTranspose Matrix: \n");
    transMat(4, 5, MatA);

}

void transMat(int rows, int cols, int MatA[rows][cols])
{
    int MatAt[cols][rows];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            MatAt[j][i] = MatA[i][j];
        }
    }
    // cols & rows reversed bc transpMat
    displayMat(cols, rows, MatAt);
}

void displayMat(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%5i", matrix[i][j]);
        }
        printf("\n");
    }
}

void copyright()
{
    printf("\n       Copyright WNoxchi 2016, Daymoxk\n");
    printf("---------------------------------------------\n");
    printf("      Matrix A[i][j]  =  Matrix At[j][i]\n");
    printf("---------------------------------------------\n");
}

/*  // EX 8.12A:
#include <stdio.h>

void copyright();
void transMat(int testMatA[][5], int testMatAt[][4], int row, int col);
void displayMatrix(int matrix[5][4]);
void displayMatrix2(int matrix[4][5]);

int main(void)
{
    copyright();
    int testMatA[4][5] =
        {
            {  1,  2,  3,  4,  5 },
            {  6,  7,  8,  9, 10 },
            { 11, 12, 13, 14, 15 },
            { 16, 17, 18, 19, 20 }
        };
    // int testMatAt[5][4];
    int testMatAt[5][4] =
        {
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 }
        };

    // testMatAt = transMat(testMatA, testMatAt, 4, 5);
    // displayMatrix(testMatAt);
    transMat(testMatA, testMatAt, 4, 5);
    printf("\n MatA:\n");
    displayMatrix2(testMatA);
    return 0;
}

void transMat(int testMatA[][5], int testMatAt[][4], int row, int col)
{
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            testMatAt[j][i] = testMatA[i][j];
        }
    }
    // return testMatAt;
    displayMatrix(testMatAt);
}

void displayMatrix(int matrix[5][4])
{
    int row, col;
    for (row = 0; row < 5; row++) {
        for (col = 0; col < 4; col++) {
            printf("%5i", matrix[row][col]);
        }
        printf("\n");
    }
}

void displayMatrix2(int matrix[4][5])
{
    int row, col;
    for (row = 0; row < 4; row++) {
        for (col = 0; col < 5; col++) {
            printf("%4i", matrix[row][col]);
        }
        printf("\n");
    }
}

void copyright()
{
    printf("\n       Copyright WNoxchi 2016, Daymoxk\n");
    printf("---------------------------------------------\n");
    printf("      Matrix A[i][j]  =  Matrix At[j][i]\n");
    printf("---------------------------------------------\n");
}
 */
