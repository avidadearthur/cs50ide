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
    // TODO
    // If name does not match the name of any of the candidates in the election,
    // no vote totals should change, and the vote function should return false
    // to indicate an invalid ballot.
    bool exists = false;
    int candIndex;

    for (int i = 0; i < candidate_count; i++)
    {
        // the input name is among the candidates array
        if (strcmp(candidates[i].name, name) == 0)
        {
            exists = true;
            candIndex = i;
        }
    }

    // If name matches one of the names of the candidates in the election,
    // then update that candidate’s vote total to account for the new vote.
    // The vote function in this case should return true to indicate a successful ballot.
    if (exists)
    {
        candidates[candIndex].votes++;
    }

    return exists;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO
    int i;

    for (i = 0; i < candidate_count; i++)
    {
        candidate winner = candidates[i];
        int j = i + 1;

        // Move elements of arr[0..i-1], that are
        // greater than winner, to one position ahead
        // of their current position
        while (j > 0 && candidates[j].votes > winner.votes)
        {
            candidates[j - 1] = candidates[j];
            j -= 1;
        }
        candidates[j - 1] = winner;
    }

    // /*sort elements in Ascending Order*/
    // for(i=1; i<(limit); i++)
    // {
    //     j=i;
    //     while(j>0 && arr[j]<arr[j-1])
    //     {
    //         temp=arr[j];
    //         arr[j]=arr[j-1];
    //         arr[j-1]=temp;

    //         j--;
    //     }
    // }

    // After sorting
    // The function should print out the name of the candidate
    // who received the most votes in the election, and then print a newline.

    // It is possible that the election could end in a tie
    // if multiple candidates each have the maximum number of votes.
    // In that case, you should output the names of each of the winning candidates,
    // each on a separate line.
    printf("%s\n", candidates[0].name);

    for (int n = 1; n < candidate_count; n++)
    {
        if (candidates[n].votes == candidates[0].votes)
        {
            printf("%s\n", candidates[n].name) ;
        }
    }
}

