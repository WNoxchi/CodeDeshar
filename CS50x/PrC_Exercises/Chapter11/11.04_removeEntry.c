/*  CS50x - Intro to Computer Science
 *  Programming in C
 *-----------------------------------------------------<>
 *  11.04_removeEntry.c
 *-----------------------------------------------------<>
 *  05-Aug-2016 19:53
 */

/*
Write a function called remove Entry to remove an entry from a linked list.
The sole argument to the procedure should be a pointer to the list. Have the
function remove the entry after the one pointed to by the argument. (Why can’t
you remove the entry pointed to by the argument?)You need to use the special
structure you set up in exercise 3 to handle the special case of removing the
first element from the list.
*/

#include <stdio.h>

struct entry
{
    int             value;
    struct entry    *next;
};

void removeEntry(struct entry *listTarget) {
    // remove linked item by linking to next item
    if (listTarget->next != (struct entry *) 0)
        listTarget->next = listTarget->next->next;
}

void printEntries (struct entry linkedItem) {
    struct entry *listPointer = linkedItem.next;

    while (listPointer->next != (struct entry *) 0) {
        printf("%i\n", listPointer->value);
        listPointer = listPointer->next;
    }
}

int main(void) {
    struct entry n9 = { .value = 9001, .next = (struct entry *) 0 };
    struct entry n3 = { .value = 300, .next = &n9 };
    struct entry n2 = { .value = 200, .next = &n3 };
    struct entry n1 = { .value = 100, .next = &n2 };
    struct entry n0 = {               .next = &n1 };    // for removing 1st entry (n1)

    removeEntry(&n0);
    printEntries(n1);

}
