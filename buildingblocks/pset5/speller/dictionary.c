// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 186019;

// Number of words added to the dictionary
int nWords = 0;

// Hash table
node *table[N];

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

// Turns word from the dictionary into node of linked list//
// Loads the node in the appropriate hash position //
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
bool load(const char *dictionary)
{
    // Open dictionary file //
    FILE* dicptr = fopen(dictionary, "r");
    if (dicptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", dictionary);
        return false;
    }

    int index;
    char *word = malloc((LENGTH + 1) * sizeof(char));
    // Read each line one at a time //
    while (fscanf(dicptr, "%s", word) != EOF)
    {
        // Get current word's index in the hash function
        index = hash(word);
        // Create a pointer for a new node for each word // //
        // Insert the new nodeptr to the hash table // // use a push function to set the node as the head of the ll //
        push(word, index);
        // Increment number of words added
        nWords++;
    }
    fclose(dicptr);
    free(word);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return nWords;
}

// Frees all the memory in a linked list //
void destroy(struct node* head)
{
    if (head == NULL) { return; }

    destroy(head->next);
    free(head);
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    int i;
    // Iterate over all buckets looking for non-NULL pointers //
    for (i = 0; i < 186020; i++)
    {
        struct node* head = table[i];
        destroy(head);
    }
    return true;
}
