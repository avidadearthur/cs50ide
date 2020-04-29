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
bool check_cycle(int start, int end);
void print_winner(void);
bool is_locked(int cand_index);

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
    // Lock all pairs
    for (int i = 0; i < pair_count; i++)
    {
        // lock path A --> B if B --> A does not exist
        if (!check_cycle(pairs[i].loser, pairs[i].winner))
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
}

// A --> B forms a cycle if a path B --> A already exist
// check_cycle: checks if path 'from' --> 'to' exist or not
bool check_cycle(int from, int to)
{
    // Base Case 1: if path exist
    if (from == to)
    {
        return true;    // it forms a cycle
    }
    else
    {
        int i;
        for (i = 0; i < candidate_count; i++)
        {
            // next node is found
            if (locked[from][i])   
            {
                return check_cycle(i, to);
            }
        }
        // it does not form cycle
        return false; 
    }
}

// Print the winner of the election
// the candidate who has no locked[i][j] = true
// is the winner
void print_winner(void)
{
    // TODO
    int i;

    for (i = 0; i < candidate_count; i++)
    {
        if (!is_locked(i))
        {
            printf("%s\n", candidates[i]);
        }
    }
}

// returns false for source candidate index
bool is_locked(int c_index)
{
    int i;

    for (i = 0; i < candidate_count; i++)
    {
        if (locked[i][c_index])
        {
            return true;
        }
    }
    return false;
}