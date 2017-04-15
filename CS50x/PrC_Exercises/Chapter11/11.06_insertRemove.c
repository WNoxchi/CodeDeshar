/*  CS50x - Intro to Computer Science
 *  Programming in C
 *-----------------------------------------------------<>
 *  11.06_insertRemove.c
 *-----------------------------------------------------<>
 *  WNixaloy - 06-Aug-2016 18:34
 */

/*
Develop insertEntry and removeEntry functions for a doubly linked list that are
similar in function to those developed in previous exercises for a singly
linked list. Why can your removeEntry function now take as its argument a
direct pointer to the entry to be removed from the list?
*/
#include <stdio.h>

struct entry
{
    int value;
    struct entry *next;
    struct entry *prev;
};

void insertEntry (struct entry *W, struct entry *X) {
    X->next->prev = W;   // X -[W]- Y -- point Y to W
    W->next = X->next;      // W points to what X pointed to
    X->next = W;
    W->prev = X;
}

void removeEntry (struct entry *X) {
    X->prev->next = X->next;
    X->next->prev = X->prev;
}

void printEntries (struct entry linkItem) {
    struct entry *pointer = &linkItem; // another way
    // struct entry *pointer = linkItem.next;
    while (pointer->next != (struct entry *) 0) {
        printf("%i\n", pointer->value);
        pointer = pointer->next;
    }
    while (pointer->prev != (struct entry *) 0) {
        printf("%i\n", pointer->value);
        pointer = pointer->prev;
    }
    printf("%i\n", pointer->value);
}

int main (void) {
    struct entry n1, n2, n3, n99;
    n1.value = 100, n2.value = 200, n3.value = 300, n99.value = 9001;
    n1.next = &n2, n2.next = &n3, n3.next = (struct entry *) 0;
    n1.prev = (struct entry *) 0, n2.prev = &n1, n3.prev = &n2;

    printEntries(n1);
    printf("---\n");
    insertEntry(&n99, &n1);
    printEntries(n1);
    printf("---\n");
    removeEntry(&n99);
    printEntries(n1);

    // n1.value = 100, n2.value = 200, n3.value = 300, n99.value = 9001;

}

// Terminal:
// Waynes-MBP:Chapter11 WayNoxchi$ make 11.06_insertRemove
// cc     11.06_insertRemove.c   -o 11.06_insertRemove
// Waynes-MBP:Chapter11 WayNoxchi$ ./11.06_insertRemove
// 100
// 200
// 300
// 200
// 100
// ---
// 100
// 9001
// 200
// 300
// 200
// 9001
// 100
// ---
// 100
// 200
// 300
// 200
// 100
