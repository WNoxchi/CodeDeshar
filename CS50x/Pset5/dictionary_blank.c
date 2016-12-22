/**
 * dictionary.c     -   Wayne Nixalo - 19-Nov-2016 11:07
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>

#include "dictionary.h"

/* prototype */
short hashfunk(char c);

/* max length of a word */
const unsigned short LENGTH = 45;


/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // TODO
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{

}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return 0;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    return false;
}

short hashfunk(char c) {
    if (isalpha(c)) {
        if (islower(c)) {
            return c - 'a';
        } else {
            return c - 'A';
        }
    }
    return c - '\'';
}

/* ------------ ------------ junk n stuff ------------ ------------ */

// // old load:
// bool load(const char* dictionary)
// {
//     /* open file and check successful */
//     FILE* fptr = fopen(dictionary, "r");
//     if (fptr == NULL) {
//         printf("Could not open %s.\n", dictionary);
//         return false;
//     }
//
//     /* load words into hashtable until end of file */
//     node* new_node = malloc(sizeof(node));
//     while (fscanf(file, "%s", new_node->word) != NULL) {
//         /* run first char or word thru hashfuntion to get hashtable index */
//         short index = hashfunk(new_node->word[0]);
//         new_node->next = head[index];
//         head = new_node;
//     }
//
//     /* close file */
//     fclose(fptr);
//     return true;
// }
