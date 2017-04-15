/*  CS50x - Intro to Computer Science
 *  Programming in C
 *-----------------------------------------------------<>
 *  11.03_insertEntryVer2.c
 *-----------------------------------------------------<>
 *  Wayne Nixaloy - 05-Aug-2016 19:05
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
    struct entry n1, n2, n3, insert, n0;
    // struct entry *listPointer = &n0;     << this causes looking out of bounds

    n1.value = 100;
    n1.next = &n2;

    n2.value = 200;
    n2.next = &n3;

    n3.value = 300;
    n3.next = (struct entry *) 0;

    n0.next = &n1;

    insert.value = 9001;

    insertEntry (&insert, &n0);

    struct entry *listPointer = n0.next;    // this has to be declared here after inserEntry

    while (listPointer != (struct entry *) 0) {
        printf("%i\n", listPointer->value);
        listPointer = listPointer->next;
    }

    return 0;
}

// Solution by author:
// -----------------------------------
//
// 11-3
// ------
// You can solve this problem by setting up a "dummy" structure variable called listHead,
// for example:
//                 struct entry  listHead;
//
// and you can then set it pointing to the head of the list by assigning the next member of
// listHead to point to the actual first entry of the list:
//
//                 listHead.next = &entry1;
//
// Now to insert a new entry called newEntry at the front of the list, you can write:
//
//                 insertEntry (&new_entry, &list_head);
//
// -----------------------------------

// Another way by https://github.com/ivanbrennan/programming-in-c/blob/master/ex.11.3.c

/**

void printEntries (struct entry head)
{
	struct entry *ptr = head.next;

	while ( ptr != (struct entry *) 0 ) {
		printf ("%i\n", ptr->value);
		ptr = ptr->next;
	}
}

int main (void)
{
	struct entry n3 = { .value = 3, .next = (struct entry *) 0 };
	struct entry n2 = { .value = 2, .next = &n3 };
	struct entry n1 = { .value = 1, .next = &n2 };

	struct entry n0 = { .next = &n1 };
	struct entry n9  = { .value = 9 };

	printEntries (n0);
	insertEntry (&n9, &n0);
	printEntries (n0);

	return 0;
}

**/
