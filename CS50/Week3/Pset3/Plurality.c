#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }

    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{

    for(int j =0; j<candidate_count; j++)
    {
        if(strcmp(candidates[j].name, name)==0)
        {
            candidates[j].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO
    //creates array to store which candidates win
    string winners_array[candidate_count];
    // creates array number for winners_array
    int M = 0;
    // creates variable to store winning vote count
    int winner_votes = candidates[0].votes;
    //Compares all existing votes to find largest vote count
    for (int k=1; k<candidate_count; k++)
    {
        if (winner_votes < candidates[k].votes)
        {
            winner_votes = candidates[k].votes;
        }
    }
    // finds candidates with vote count matching winning votes
    for (int L=0; L<candidate_count; L++)
    {
        if (winner_votes == candidates[L].votes)
        {
            winners_array[M] = candidates[L].name;
            M++;
        }
    }


    // Handles printing of winning names.
    for (int n=0; n<M; n++)
        {
            printf("%s\n", winners_array[n]);
        }


    return;
}
