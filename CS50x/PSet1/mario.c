#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    int count = 0;

    printf("height: ");
    // scanf("%i", &height);
    height = GetInt();

    while(height < 0 || height > 23)
    {
        printf("height: ");
        height = GetInt();
    }

    while(count < height)
    {
        for(int i = 1; i < height - count; i++)
        {
            printf(" ");
        }
        printf("##");
        for(int j = count; j > 0; j--)
        {
        printf("#");
        }
  
        printf("\n");
        count += 1;
    }
    
    return 0;
}

// Makes an awesome thing:
    // while(height > 0)
    // {
    //     for(int i = 0; i < height; i++)
    //     {
    //         printf(" ");
    //     }
    //     for(int j = height; j > 0; j--)
    //     {
    //         printf("#");
    //     }
    //     printf("\n");
    //     height -= 1;
    // }
