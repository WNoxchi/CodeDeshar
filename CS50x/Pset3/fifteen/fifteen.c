/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE* file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{
    int counter = d*d - 1;
    bool odd = d % 2;
    for (int i = 0; i < d; i++) {
        for (int k = 0; k < d; k++) {
            board[i][k] = counter;
            counter--;
        }
    }
    // swap 1 and 2 if board dim even
    if (!odd) {
        board[d - 1][d - 2] = 2;
        board[d - 1][d - 3] = 1;
    }
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    for (int i = 0; i < d; i++) {
        for (int k = 0; k < d; k++) {
            if (board[i][k] == 0)
                printf("_");
            else
                printf("%i", board[i][k]);
            // proper spacing
            for (int j = 0; j < 2 - (board[i][k] > 9); j++)
                printf(" ");
        }
        printf("\n\n");
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    // tile coordinates
    int x,y;
    // find tile
    for (int i = 0; i < d; i++) {
        for (int k = 0; k < d; k++) {
            if (board[i][k] == tile) {
                x = i;
                y = k;
            }
        }
    }
    // check space verticle
    for (int i = -1; i < 2; i+=2) {
        if (y + i >= 0 && y + i < d) {
            if (board[x][y+i] == 0) {
                board[x][y+i] = board[x][y];
                board[x][y] = 0;
                return true;
            }
        }
    }
    // check space horizontal
    for (int i = -1; i < 2; i+=2) {
        if (x + i >= 0 && x + i < d) {
            if (board[x+i][y] == 0) {
                board[x+i][y] = board[x][y];
                board[x][y] = 0;
                return true;
            }   
        }
    }
    return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    for (int i = 0; i < d; i++) {
        // check rows in order
        if (i > 0 && board[i][0] < board[i-1][d-1])
            return false;
        for (int k = 0; k < d; k++) {
            // check cols in order, skip zero
            if (k > 0 && board[i][k] < board[i][k-1] && board[i][k] != 0) {
               return false;
            }
        }
    }
    // check zero placement
    if (board[d-1][d-1] != 0)
        return false;
    return true;
}

/*** Original space checking code - handled diagonals as true:
    // check space
    for (int i = x - 1; i <= x + 1; i++) {
        // bounds checking (row)
        if (i >= 0 && i < d) {
            for (int k = y - 1; k <= y + 1; k++) {
                // bounds checking (col)
                if (k >= 0 && k < d) {
                    // printf("\n%i\n", board[i][k]);
                    if (board[i][k] == 0) {
                        board[i][k] = board[x][y];
                        board[x][y] = 0;
                        return true;
                    }
                }
            }
        }
    }
***/

/*** Original bool function code:
bool move(int tile)
{
    // find tile
    for (int i = 0; i < d; i++) {
        for (int k = 0; k < d; k++) {
            if (board[i][k] == tile) {
                // check space
                for (int j = -1; j <= 1; j++) {
                    for (int l = 1; l >= -1; l--) {
                        if (board[i+j][k+l] == 0) {
                            board[i+j][k+l] = tile;
                            board[i][k] = 0;
                            return true;
                        }   
                    }   
                }
            }
        }
    }
    return false;
    // draw();
}
***/