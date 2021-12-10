#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{

    // Gets card number
    long card = get_long("Number: ");


    // Quick test to establish validity
    // Declaration of variables for this process
    int card_length = log10(card) + 1;
    int card_array[card_length];
    long card_math = card;
    //Logic for the same project
    if (card_length < 13)
    {
        printf("INVALID\n");
        return 0;
    }
    else
    {
        // Parse card into array
        for (int i = 0; i < card_length; i++)
        {
            card_array[i] = (card_math % 10);
            card_math = (card_math / 10);
        }
    }


    //Performs weighted calculation of summation
    int weighted_sum = 0;
    for (int j = 0; j < card_length; j++)
    {
        if ((j % 2 == 1))
        {
        //Tackles odd numbered entries, Adds individual digits for double digit numbers
            int odd_count_increment = (card_array[j]) * 2;
            while (odd_count_increment >= 10)
            {
                odd_count_increment = 1 + (odd_count_increment % 10);
            }
            weighted_sum = weighted_sum + odd_count_increment;
        }
        //Adds even numbers directly
        else
        {
            weighted_sum = weighted_sum + card_array[j];
        }
    }


    // Performs test using previous calculation and tests for card issuer

    if ((weighted_sum % 10) == 0)
    {
        //Switch case for card issuer
        switch ((card_array[card_length - 1]))
        {
            case 4:
                printf("VISA\n");
                break;
            case 5:
                if (((card_array[card_length - 2]) < 6) && ((card_array[card_length - 2]) > 0))
                {
                    printf("MASTERCARD\n");
                }
                else
                {
                    printf("INVALID\n");
                }
                break;
            case 3:
                if (((card_array[card_length - 2]) == 4) || ((card_array[card_length - 2]) == 7))
                {
                    printf("AMEX\n");
                }
                else
                {
                    printf("INVALID\n");
                }
                break;
            default:
                printf("INVALID\n");
        }
    /* Tests for start with 4 -> Visa (original)
        if ((card_array[card_length - 1]) == 4)
        {
            printf("VISA\n");
        }
        else if ((card_array[card_length - 1] == 5) && ((card_array[card_length - 2]) < 6) && ((card_array[card_length - 2]) > 0))
        {
            printf("MASTERCARD\n");
        }
        else if (card_array[card_length-1]==3)
        {
            if (((card_array[card_length - 2]) == 4) || ((card_array[card_length - 2]) == 7))
            {
            printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    */
    }
    else if ((weighted_sum % 10) != 0)
    {
        printf("INVALID\n");
    }


}