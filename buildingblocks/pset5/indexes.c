#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#define LENGTH 45

// Number of buckets in hash table
const unsigned int N = 186019;

typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Hash table
node *table[N];


// Hashes word to a number
unsigned int hash(const char *word)
{
    int i, ascii;
    int hash = 0;
    for (i = 0; word[i] != '\0'; i++)
    {
        ascii =  tolower(word[i]);
        hash = ascii + (31 * hash);    // Horner's method to hash string of length L: L multiplies/adds// // not very efficient
    }
    return hash%N;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // Get current word's index in the hash function
    int index = hash(word);

    struct node* trav = table[index];
    if (trav == NULL){ return false; } // The bucket is empty //

    else
    {
        while (trav != NULL)
        {
            if (strcasecmp(trav->word, word) == 0){ return true; } // Word found //
            trav = trav->next;
        }
    }
    return false; // The word is not in the linked list //
}

unsigned int push(const char *word, const int hashindex)
{
    struct node* newNode = malloc(sizeof(struct node));
    if (newNode == NULL){ return 1; }

    strcpy(newNode->word, word); // here you can't assign newNod->word to word directly //
    newNode->next = table[hashindex];
    table[hashindex] = newNode;
    return 0;
}

// Loads dictionary into memory, returning true if successful else false
int main (void)
{
    // naming file
    char *dictionary = "large";

    // Open dictionary file //
    FILE *dicptr = fopen(dictionary, "r");
    if (dicptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", dictionary);
        return 1;
    }

    int index;
    // Read each line one at a time //
    char *word = malloc(LENGTH * sizeof(char));
    while (fscanf(dicptr, "%s", word) != EOF)
    {
        // Get current word's index in the hash function
        index = hash(word);
        // Create a pointer for a new node for each word // //
        // Insert the new nodeptr to the hash table // // use a push function to set the node as the head of the ll //
        push(word, index);
    }
    // int counter = 0;
    // for (int j = 0; j < 186020; j++)
    // {
    //     if (table[j] == NULL) { counter++; }
    // }

    printf("The word exists: %i\n", check("afghsnistan's"));
    free(word);

    return 0;
}