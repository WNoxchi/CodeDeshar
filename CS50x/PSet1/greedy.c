#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int amount;
    int quart;
    int dime;
    int nick;
    int penn;
    int coins;
    
    printf("O hai! How much change is owed? ");
    amount = round(GetFloat() * 100);       //  can change to truncate partial
        // printf("%i\n", amount);
    while (amount < 0)
    {
        printf("How much change is owed? ");
        amount = round(GetFloat() * 100);
    }
    
    quart = amount / 25;
    amount -= quart * 25;
        // printf("%i\n", amount);
    
    dime = amount / 10;
    amount -= dime * 10;
        // printf("%i\n", amount);

    nick = amount / 5;
    amount -= nick * 5;
        // printf("%i\n", amount);

    penn = amount;
        // printf("%i\n", amount);

    // printf("Quarters: %i\nDimes: %i\nNickels: %i\nPennies: %i\n", quart, dime, nick, penn);
    coins = quart + dime + nick + penn;
    printf("%i\n", coins);
    
    return 0;
}