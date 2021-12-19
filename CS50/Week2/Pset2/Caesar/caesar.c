#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>



bool is_letter(int character);
bool is_lower(int character);



int main(int argc, char *argv[])
{
    //checks for more than one argument or too few arguments.
    if ((argv[2] != NULL) || (argv[1] == NULL))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }


    //accepts numerical argument and calls it key
    char *endptr;
    long key = strtol(argv[1], &endptr, 10);

    //checks for non integer input

    if (*endptr != '\0')
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Gets plaintext for encryption
    string plaintext = get_string("Plaintext: ");

    char ciphertext[strlen(plaintext)];

    //loops through each character, looking for letters
    for (int i=0; i < strlen(plaintext); i++)
    {
        //creates characters for manipulation
        int old_character = 0;
        int new_character = 0;

        // verifies that character is a letter, if so conduct manipulation
        if (is_letter(plaintext[i]))
        {
            //goes to upper case for easier manipulation
            int uppercase_character = toupper(plaintext[i]);

            //drops to 0-26 scale for easier checking
            old_character = uppercase_character - 65;

            //adds movement for key and converts back to ascii
            new_character = (((old_character + (int)key) % 26) + 65);

            //if letter was lower case, converts back
            if (is_lower(plaintext[i]))
            {
                new_character = new_character + 32;
            }
        }
        // if not a letter, transfer it directly
        else
        {
            new_character = plaintext[i];
        }

        //puts new character at end of ciphertext array
        ciphertext[i] = (char)new_character;
    }

    printf("ciphertext: %s\n", (string)ciphertext);

}

bool is_letter(character)
{
    if ((character > 64 && character < 91))
    {
        return 1;
    }
    else if (character > 96 && character < 123)
    {
        return 1;
    }
    else
    {
        return 0;
    }


}

bool is_lower(character)
{
    if (character > 96 && character < 123)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
