#include <stdio.h>

int main(void) {
    
    int minutes, bottles;
    
    printf("minutes: ");
    scanf("%i", &minutes);
    
    bottles = minutes * 12;
    
    printf("bottles: %i\n", bottles);
}