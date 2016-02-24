#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float amount = 1.89 * 100;
    printf("%.2f \n", amount);
    
    int newamount = round(amount);
    printf("newamount: %i \n", newamount);
    
    int quarters = newamount % 25;
    printf("quarters: %i \n", quarters);
}