#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
// function declaration
struct results computation(string paragraph);
bool is_letter(int character);
bool is_punctuation(int character);

// Create struct to allow passage from computation function.
struct results {
    int letters;
    int words;
    int sentences;
} results;




// results array declared to allow passing of results from computation
int main(void)
{
    // Prompts for a paragraph for testing
    string paragraph = get_string("Please input your paragraph: ");

    computation(paragraph);
    float ratio = (float)100 / (float)results.words;
    float L = (results.letters * ratio);
    float S = (results.sentences * ratio);
    float reading_level = 0.0588 * L - 0.296 * S - 15.8;
    int index = round(reading_level);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 15+\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
    return 0;

}
// parses paragraph to find number of letters, sentences and words
struct results computation(string paragraph)
{
    //declare local variables
    int letters = 0;
    int sentences = 0;
    int words = 1;
    int length = strlen(paragraph);
    for (int i = 0; i < length; i++)
    {
        // converts character to uppercase if applicable
        int upper_character_value = toupper(paragraph[i]);
        //checks for actual letter (26 letters, A is ASCII #65)
        if (is_letter(upper_character_value))
        {
            letters ++;
        }
        if (is_punctuation(paragraph[i]))
        {
            sentences++;
        }
        //tests for space
        if (paragraph[i] == 32)
        {
            words++;
        }
    }
    results.letters = letters;
    results.words = words;
    results.sentences = sentences;

    return results;
}


bool is_letter(int character)
{
    if ((character > 64) && (character < 91))
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
    int punctuation_marks[3] = {33, 46, 63};

    for (int j =0; j < 3; j++)
    {
        if (punctuation_marks[j] == character)
        {
        return 1;
        }
    }
    return 0;
}