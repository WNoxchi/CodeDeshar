// CS50x - Intro to Computer Science
// Problem Set 2 - initials.c
// Wayne H. Noxchi - 28-May-2016 00:19

#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

int main(void){
    string name;
    name = GetString();
    printf("%c", toupper(name[0]));
    for (int i = 1; i < strlen(name); i++){
        if (toupper(name[i-1]) == ' ')
            printf("%c", toupper(name[i]));
    }
    printf("\n");
}
