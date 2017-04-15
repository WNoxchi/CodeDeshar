// CS50x - Kirana 4 - WNixaloy - 13-Aug-2016 18:15 - 13-Aug-2016 18:21

// writing a summing (factorial) program using pointers

#include <stdio.h>
int sigma(int x) {
    if (x < 1)
        return 0;
    return x + sigma(x-1);
}
int main(void) {
    int x;
    int * xp = &x;
    printf("Terah: ");
    scanf("%i", &x);
    x = sigma(*xp);
    printf("%i\n", *xp);
}
