/*  CS50x - Intro to Computer Science
 *  Programming in C
 *-----------------------------------------------------<>
 *  11.02_insertEntry.c
 *-----------------------------------------------------<>
 *  Wayne Nixaloy - 05-Aug-2016 12:40 - 05-Aug-2016 13:32
 */

/*
 Write a function called insertEntry to insert a new entry into a linked list.
 Have the procedure take as arguments a pointer to the list entry to be
 inserted (of type struct entry as defined in this chapter), and a pointer to
 an element in the list after which the new entry is to be inserted.
 */

#include <stdio.h>

struct entry
{
    int            value;
    struct entry   *next;
};

void insertEntry (struct entry *listPtrInsert, struct entry *listPtrPos) {
    // (*listPtrInsert).next = (*listPtrPos).next;
    listPtrInsert->next = listPtrPos->next;
    // (*listPtrPos).next = listPtrInsert;
    listPtrPos->next = listPtrInsert;

}

int main (void) {
    struct entry n1, n2, n3, insert;
    struct entry *listPointer = &n1;

    n1.value = 100;
    n1.next = &n2;

    n2.value = 200;
    n2.next = &n3;

    n3.value = 300;
    n3.next = (struct entry *) 0;

    insert.value = 250;

    insertEntry (&insert, &n3);

    while (listPointer != (struct entry *) 0) {
        printf("%i\n", listPointer->value);
        listPointer = listPointer->next;
    }

    return 0;
}

// help from: https://github.com/peterforgacs/programming-in-c-book/blob/master/chapter11/ex2_insertingToLinkedList.c
