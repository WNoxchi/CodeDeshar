/**
 * dictionary.c     -   Wayne Nixalo - 19-Nov-2016 11:07 -> 19-Nov-2016 22:54
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "dictionary.h"

/* prototype djb2 algo */
unsigned long hash_djb2(char* word);

/* size of hashtable -- using max size 16 bit unsigned number */
#define HASHSIZE 65536

/* word counter */
unsigned int wordcount = 0;

/* word node struct */
typedef struct node
{
    char word[LENGTH + 1];
    struct node* next;
}
node;

node* hashtable[HASHSIZE];

/** 19-Nov-2016 20:55
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    /* copy & format word */    // could this be done by direct = ? or by strcopy()?
    int len = strlen(word);     // is adding '\0' null terminator char necessary?
    char dosh[len + 1];         // error checking if dosh == null?
    for (int i = 0; i < len; i++) {
        dosh[i] = tolower(word[i]);
    }
    dosh[len] = '\0';

    /* hash the word */
    int index = hash_djb2(dosh) % HASHSIZE;

    /* cursor */
    node* cursor = hashtable[index];

    /* search hashtable for word */
    while (cursor != NULL) {
        if (strcmp(cursor->word, dosh) == 0) {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

/** 19-Nov-2016 20:52
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    /* open file and check successful */
    FILE* fptr = fopen(dictionary, "r");
    if (fptr == NULL) {
        printf("Could not open %s.\n", dictionary);
        return false;
    }

    /* buffer to hold word + its null terminator */
    char BUFFER[LENGTH + 1];

    while (fscanf(fptr, "%s", BUFFER) == 1) {       // fixed this, was fatal error <-- must eql 1, not != 0 --> else infin.loop
        /* allocate space for creation of new word */
        node* kerlo_dosh = malloc(sizeof(node));        // error checking later?
        /* copy word in buffer to new word ndoe */
        strcpy(kerlo_dosh->word, BUFFER);
        /* hash the new word for index */
        int index = hash_djb2(kerlo_dosh->word) % HASHSIZE;
        /* link new node into hashtable linked list */
        kerlo_dosh->next = hashtable[index];
        /* reset head of linked list to point to new first word */
        hashtable[index] = kerlo_dosh;
        /* update word count */
        wordcount++;
    }
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return wordcount;
}

/** 19-Nov-2016 20:56 -> 19-Nov-2016 21:02
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    /* goes through each bucket in hashtable & runs freeing op using cursor */
    for (int i = 0; i < HASHSIZE; i++) {
        node* cursor = hashtable[i];
        while (cursor != NULL) {
            node* temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
    return true;
}

/* the djb2 algo by Dan Bernstein - http://www.cse.yorku.ca/~oz/hash.html */
unsigned long hash_djb2(char* word) {
    unsigned long hash = 5381;
    int c;
    while ((c = *word++))
        hash = ((hash << 5) + hash) + c;    // hash * 33 + c
    return hash;
}

// short hashfunk(char c) {
//     if (isalpha(c)) {
//         if (islower(c)) {
//             return c - 'a';
//         } else {
//             return c - 'A';
//         }
//     }
    // return c - '\'';
// }

// memchecking:
// valgrind -v --leak-check=full ./speller ~cs50/pset5/texts/austinpowers.txt
// code checked/compared against: Lee-Loi Chieng on GitHub
