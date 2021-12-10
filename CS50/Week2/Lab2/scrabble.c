#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");
    // Score both words

    int score1 = compute_score(word1);
    int score2 = compute_score(word2);


    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
    return 0;
}

int compute_score(string word)
{
    int score_increment;
    int score_array_value;
    char upper_letter_value;
    int score = 0;
    // iterates through string. Strings are capable of array operations.
    // Cannot use sizeof with dynamically allocated array
    for (int i = 0; i < strlen(word); i++)
    {
        //converts lower case letters to upper case
        upper_letter_value = toupper(word[i]);
        //checks for actual letter (26 letters, A is ASCII #65)
        if ((upper_letter_value - 65) < 26)
        {
            score_array_value = upper_letter_value - 65;
            score_increment = POINTS[score_array_value];
        }
        else
        {
            score_increment = 0;
        }
        score = score + score_increment;

    }
    return score;
}
