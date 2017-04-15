#include <stdio.h>

int main(void){
    int d = 5;
    short s = d;
    char ch = *(char *) &d;

    printf("int d is:   %i\n", d);
    printf("short s is: %d\n", s);
    printf("char ch is: %c\n", ch);

    d = 2*2*2*2*2*2*2*2*2*2*2*2*3 + 1;
    ch = *(char*) &d;
    printf("int d is:   %i\n", d);
    printf("char ch is: %c\n", ch);


    return 0;
}
