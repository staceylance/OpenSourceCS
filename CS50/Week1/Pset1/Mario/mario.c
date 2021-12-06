#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int rows = get_int("Height: ");
    // Double condition for negative, 0 and > 8
    while (rows <= 0 || rows >8)
        {
        rows = get_int("Height: ");
        };
    // Establishes total number of columns
    for (int i=1; i <= rows; i++)
        {

        // Establishes white space to right justify pyramid
        for (int k=1; k <= (rows - i); k++)
            {
            printf(" ");
            };
        //Establishes # for each level
        for (int j=1; j<=i; j++)
            {
            printf("#");
            };
        printf("  ");
        //Establishes # for other half level
        for (int j=1; j<=i; j++)
            {
            printf("#");
            };
        printf("\n");
        };
};