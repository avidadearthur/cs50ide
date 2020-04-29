#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
// on this problem candidate is not a struct
bool vote(int rank, string name, int ranks[])
{
    // TODO
    bool exists = false;
    int candidate_index;
    // loop over the andidates name array and check
    // the candidate name user input
    for (int i = 0; i < candidate_count; i++)
    {
        // the input name is among the candidates array
        if (strcmp(candidates[i], name) == 0)
        {
            exists = true;
            candidate_index = i;
        }
    }

    // if it exists, then record the vote
    if (exists)
    {
        ranks[rank] = candidate_index;
    }

    return exists;
}

// Given one voter's ranks, it updates the preferences
// ranks[candidate_count] = {first_ranked_candidate_index,
// second_ranked_candidate_index, ... nth_ranked_candidate_index}
void record_preferences(int ranks[])
{
    // TODO
    // update the global preferences array to add the current voter’s preferences.
    // Recall that preferences[i][j] should represent the number of voters
    // who prefer candidate i over candidate j.
    int i;
    int j;

    for (i = 0; i < candidate_count; i++)
    {
        j = i + 1;
        // the ith candidate is preferred over the i+n candidate
        // meanwhile the i+n candidate is preferred over the i+n+1 anf so forth.
        while (j < candidate_count)
        {
            preferences[ranks[i]][ranks[j]]++;
            j++;
        }
    }
}

// Record pairs of candidates where one is preferred over the other
// here we will compare the preferences[i][j] score with the preferences[j][i]
// matrix for 3 candidates and five voters
// preferences array
void add_pairs(void)
{
    // TODO
    // if preferences[i][j] > preferences[j][i]
    // candidate of i index wins the pair and vice-versa
    int i;
    int j;
    int pair_index = 0;

    for (i = 0; i < candidate_count; i++)
    {
        j = i + 1;
        while (j < candidate_count)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_index].winner = i;
                pairs[pair_index].loser = j;
                pair_index ++;
                pair_count++;

            }

            else if (preferences[i][j] < preferences[j][i])
            {
                pairs[pair_index].winner = j;
                pairs[pair_index].loser = i;
                pair_index ++;
                pair_count++;
            }
            // in case of equal preference over the candidates of
            // index i and candidates of index j, no pair is added
            j++;
        }
    }
}

// Sort pairs in decreasing order by strength of victory
// here we will keep track of how many times a candidate index
// appears as winner over another another candidate
// and also how expressive is his win over anothe candidate
void sort_pairs(void)
{
    // TODO
    // strenght = preferences[pairs[i].winner][pairs[i].loser] - preferences[pairs[i].loser][pairs[i].winner]
    int i = 0;
    int j = 0;

    int strenght_current;
    int strenght_next;

    // compare the strenght of the pairs and sorting
    for (i = 0; i < pair_count; i++)
    {
        j = i + 1;
        while (j + 1 <= pair_count)
        {
            strenght_current = preferences[pairs[i].winner][pairs[i].loser] - preferences[pairs[i].loser][pairs[i].winner];

            if (j < pair_count)
            {
                strenght_next = preferences[pairs[j].winner][pairs[j].loser] - preferences[pairs[j].loser][pairs[j].winner];
            }

            if (j == pair_count)
            {
                j = 0;
                strenght_current = preferences[pairs[i].winner][pairs[i].loser] - preferences[pairs[i].loser][pairs[i].winner];
            }

            // pair[i].winner is the index of the pair that
            // wins pair[j].loser index
            if (strenght_next > strenght_current)
            {
                // swap pairs
                pair temp = pairs[i];
                pairs[i] = pairs[j];
                pairs[j] = temp;
            }
            j++;
        }
    }
}

// Lock pairs into the candidate graph in order, without creating cycles
// the are being properly sorted
void lock_pairs(void)
{
    // TODO
    int i;
    bool all_false;
    // channge the bool array for each pair if it doesn't create a cycle
    for (i = 0; i < pair_count; i++)
    {
       // (candidate a index) pairs[i].winner --> (candidate b index) pairs[i].loser (locked) true
       // locked[candidate a index][candidate b index] = true;
       // however, from now on, locked[candidate b index][candidate a index] cannot happen!
       
       // lock_pairs locks all pairs when no cycles
       if (!locked[pairs[i].winner][pairs[i].loser] && !locked[pairs[i].loser][pairs[i].winner])
       {
            // lock_pairs skips middle pair if it creates a cycle// if not the last pair

            // lock_pairs skips final pair if it creates cycle
            if (i == pair_count - 1)
            {
                all_false = true;
                for (int m = 0; m < pair_count; m++)
                {
                    // lock_pairs skips final pair if it creates cycle
                    if (locked[pairs[m].winner][pairs[i].loser] == true)
                    {
                       all_false = false;
                    }
                }
                // if the last lock is not done under 
                // a colunm filled only by false elements, then allow lock
                if (!all_false)
                {
                    locked[pairs[i].winner][pairs[i].loser] = true; 
                }
            }
            
            else
            {
                locked[pairs[i].winner][pairs[i].loser] = true; 
            }
        }
    }
}

// Print the winner of the election
// the candidate who has no locked[i][j] = true
// is the winner
void print_winner(void)
{
    // TODO
    int i;
    int j;
    int n;
    int winner_index;
    
    for (i = 0; i < pair_count; i++)
    {
        n = 0;
        for (j = 0; j < candidate_count; j++)
        {
            if (locked[i][j] == false)
            {
                n++;
            }
        }
        // if all the candidate's elements in the
        // locks array are false the ith candidate is the source
        if (n == j)
        {
            winner_index = i;
        }
    }
    printf("%s\n", candidates[winner_index]);
}
