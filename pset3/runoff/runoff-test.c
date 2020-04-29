#include <cs50.h>
#include <stdio.h>
#include <string.h>

// preferences array
// simulation with 7 voters
// {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}

// candidates array
// simulation with 3 candidates
// {{name = 0x0, votes = 0, eliminated = false}, {name = 0x0, votes = 0, eliminated = false},
// {name = 0x0, votes = 0, eliminated = false}, {name = 0x0, votes = 0, eliminated = false},
// {name = 0x0, votes = 0, eliminated = false}, {name = 0x0, votes = 0, eliminated = false},
// {name = 0x0, votes = 0, eliminated = false}, {name = 0x0, votes = 0, eliminated = false}, {name = 0x0, votes = 0, eliminated = false}}

// Max voters and candidates
#define MAX_VOTERS 7
#define MAX_CANDIDATES 3

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;


// Numbers of voters and candidates
int voter_count = 7;
int candidate_count = 3;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];


int main(void)
{

    // Array of candidates
    candidates[0].name = "Alice";
    candidates[0].votes = 0;
    candidates[0].eliminated = false;
    candidates[1].name = "Bob";
    candidates[1].votes = 0;
    candidates[1].eliminated = false;
    candidates[2].name = "Charlie";
    candidates[2].votes = 0;
    candidates[2].eliminated = false;

    // preferences[i][j] is jth preference for voter i
    preferences[0][0] = 0;
    preferences[0][1] = 1;
    preferences[0][2] = 2;

    preferences[1][0] = 0;
    preferences[1][1] = 1;
    preferences[1][2] = 2;

    preferences[2][0] = 0;
    preferences[2][1] = 2;
    preferences[2][2] = 1;


    preferences[3][0] = 1;
    preferences[3][1] = 0;
    preferences[3][2] = 2;

    preferences[4][0] = 1;
    preferences[4][1] = 2;
    preferences[4][2] = 0;

    preferences[5][0] = 1;
    preferences[5][1] = 0;
    preferences[5][2] = 2;

    preferences[6][0] = 2;
    preferences[6][1] = 0;
    preferences[6][2] = 1;

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// int preferences[i][j] is jth preference for voter i
// this int is the index of the candidate that is the jth choice
// of the ith voter!

// Record preference if vote is valid

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // TODO
    // The function should update the number of votes each candidate has at this stage in the runoff.
    // Recall that at each stage in the runoff, every voter effectively votes for their top-preferred
    // candidate who has not already been eliminated

    // let's loop over the preferences and assign the number of times a candidate appears as TOP-PREFERRED
    // as the current number of votes his or hers candidates.votes has.
    int j = 0;
    for (int i = 0; i < voter_count; i++)
    {
        while (j < candidate_count && candidates[preferences[i][j]].eliminated == true)
        {
            j++;
        }
        // Index of the 1st preferrence candidate preferences[i][0];
        // check if the candidate has been eliminated
        candidates[preferences[i][j]].votes++;

        j = 0;
    }
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // TODO
    int candIndex;
    // majority (more than 50%)
    // candidates[i].votes/voter_count > 50%
    int majority = (voter_count / 2);
    // If any candidate has a majority (more than 50%) of the first preference votes,
    // that candidate is declared the winner of the election.
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > majority)
        {
            printf("%s\n",candidates[i].name);
            return true;
        }
    }
    // If no candidate has more than 50% of the vote, then an “instant runoff” occurrs.
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // TODO
    // The candidate who received the fewest number of votes is eliminated from the election,
    // and anyone who originally chose that candidate as their first preference
    // now has their second preference considered.

    // We dont need to sort the candidates, we just need to
    // loop over the current array and find the not-eliminated candidate(s) with the fewest votes

    // linear search for the lowest number of votes
    candidate looser = candidates[0];
    for (int i = 1; i <= candidate_count; i++)
    {

        if (looser.votes > candidates[i].votes)
        {
            looser = candidates[i];
        }
    }

    int min = looser.votes;

    return min;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // TODO
    bool tie = true;
    // if no candidates have a number of votes different from the min
    // there is a tie
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes != min)
        {
            tie = false;
        }
    }

    return tie;
}

// Eliminate the candidate (or candidiates) in last place
void eliminate(int min)
{
    // TODO
    // the min votes is the number of  votes of looser candidate
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
}
