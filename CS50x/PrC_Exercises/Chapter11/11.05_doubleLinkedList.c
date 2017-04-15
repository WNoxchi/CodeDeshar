/*  CS50x - Intro to Computer Science
 *  Programming in C
 *-----------------------------------------------------<>
 *  11.05_doubleLinkedList.c
 *-----------------------------------------------------<>
 *  WNixaloy - 06-Aug-2016 16:45
 */

/*
A doubly linked list is a list in which each entry contains a pointer to the
preceding entry in the list as well as a pointer to the next entry in the list.
Define the appropriate structure definition for a doubly linked list entry and
then write a small program that implements a small doubly linked list and
prints out the elements of the list.
*/

#include <stdio.h>

struct entry
{
    int value;
    struct entry *prev;
    struct entry *next;
};

int main (void) {
    struct entry n1, n2, n3;

    n1.value = 100, n2.value = 200, n3.value = 300;

    n1.next = &n2;
    n2.next = &n3;
    n3.next = (struct entry *) 0;

    n1.prev = (struct entry *) 0;
    n2.prev = &n1;
    n3.prev = &n2;

    struct entry *linkPointer = &n1;
    while (linkPointer->next != (struct entry *) 0) {
        printf("%i\n", linkPointer->value);
        linkPointer = linkPointer->next;
    }
    while (linkPointer->prev != (struct entry *) 0) {
        printf("%i\n", linkPointer->value);
        linkPointer = linkPointer->prev;
    }
    printf("%i\n", linkPointer->value);

    return 0;
}

// Terminal:
// Waynes-MBP:Chapter11 WayNoxchi$ ./11.05_doubleLinkedList
// 100
// 200
// 300
// 200
// 100


// Solution by author:
// -----------------------------------
//
// 11-5
// ------
// struct dentry
// {
//     int            value;
//     struct dentry  *next;
//     struct dentry  *prev;
// };
//
// int main (void)
// {
//     struct dentry  n1, n2, n3, *lptr;
//     int            i;
//
//     n1.value = 100;
//     n2.value = 200;
//     n3.value = 300;
//
//     n1.next = &n2;
//     n2.next = &n3;
//     n3.next = (struct dentry *) 0;
//
//     n1.prev = (struct dentry *) 0;
//     n2.prev = &n1;
//     n3.prev = &n2;
//
//     // forward search through list
//
//     lptr = &n1;
//
//     while ( lptr != 0 ) {
//
//        printf ("%i ", lptr->value);
//        lptr = lptr->next;
//     }
//
//     printf ("\n");
//
//     // backward search through list
//
//     lptr = &n3;
//
//     while ( lptr != 0 ) {
//        printf ("%i ", lptr->value);
//        lptr = lptr->prev;
//     }
//
//     printf ("\n");
//     return 0;
}
//
// -----------------------------------



// below from: https://github.com/ivanbrennan/programming-in-c/blob/master/ex.11.5.c
/*
#include <stdio.h>

struct entry
{
    int           value;
    struct entry  *prev;
    struct entry  *next;
};

void roundTrip (const struct entry *ptr) {
    while (ptr->next != (struct entry *) 0) {
        printf("%i\n", ptr->value);
        ptr = ptr->next;
    }
    while (ptr->prev != (struct entry *) 0) {
        printf("%i\n", ptr->value);
        ptr = ptr->prev;
    }
    printf("%i\n", ptr->value);
}

int main (void) {

    struct entry n1 = { .value = 10, .prev = (struct entry *) 0 };
    struct entry n2 = { .value = 20, .prev = &n1 };
    struct entry n3 = { .value = 30, .prev = &n2 };

    n1.next = &n2;
    n2.next = &n3;
    n3.next = (struct entry *) 0;

    roundTrip(&n1);

    return 0;
}
*/
