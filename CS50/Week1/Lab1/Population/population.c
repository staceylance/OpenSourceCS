#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Prompts User for starting population
    int pop_start = get_int("what is the beginning population? \n");
    //Checks for < 9
    while (pop_start < 9)
    {
        pop_start = get_int("Please input a number < 9 \n");
    }

    // Prompts User for ending population
    int pop_end = get_int("what is the end population \n");
    //Checks for > starting population
    while (pop_end < pop_start)
    {
        pop_end = get_int("Please input a number larger than, %d\n", pop_start);
    }

    //Establishes calculation for population
    int pop_current = pop_start;
    int years = 0;
    while (pop_current < pop_end)
    {
        int pop_growth = pop_current / 3;
        int pop_decline = pop_current / 4;
        pop_current = pop_current + (pop_growth - pop_decline);
        years ++;
    }

    printf("Start Size: %d \n", pop_start);
    printf("End Size: %d \n", pop_end);
    printf("Years: %d \n", years);

}
