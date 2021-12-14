#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
// function declaration
int computation(string paragraph);
bool is_letter(int character);
bool is_punctuation(int character);
// results array declared to allow passing of results from computation
int results[3];
int main(void)
{
    // Prompts for a paragraph for testing
    string paragraph = get_string("Please input your paragraph: ");

    int sentences = compute_sentences(paragraph);
    int words = compute_words(paragraph);
    int letters = compute_letters(paragraph);

    int index = 0.0588 * L - 0.296 * S - 15.8;

    printf("Grade %d", index);

}
// parses paragraph to find number of letters, sentences and words
int computation(paragraph)
{
    //declare local variables
    int letters = 0;
    int sentences = 0;
    int words = 0;
    for (int i = 0; i < strlen(paragraph); i++)
    {
        // converts character to uppercase if applicable
        upper_character_value = toupper(paragraph[i]);
        //checks for actual letter (26 letters, A is ASCII #65)
        if (is_letter(paragraph[i]))
        {
            letters ++;
        }
        if (is_punctuation(paragraph[i]))
        {
            sentences++;
        }
        //tests for space, assuming the prior character isnt a punctuation mark 
        if ((paragraph[i] == 32) && (is__punctuation(paragraph[i-1]) == 0))
        {
            words++;
        }
    }
    results = [letters, words, sentences];
    return results;

}


bool is_letter(int character)
{
    if ((character > 64) && (character < 90))
    {
        return 1;   
    }    
    else 
    {
        return 0;   
    }    
}

bool is_punctuation (int character)
{
    int punctuation_marks[3] = [33, 46, 63];
    
    for (int j =0, j < 3, j++)
    (
        if (character == punctuation_marks[j])
        {
            return 1;
        }
    )
    return 0;
}    
}
