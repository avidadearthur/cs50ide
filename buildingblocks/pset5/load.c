#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#define LENGTH 45

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Turns wor from the dictionary into node of linked list, returns a pointer to a node
struct node* make_node(const char *word)
{
    struct node* newNode = malloc(sizeof(struct node));
    if (newNode == NULL){ return NULL; }

    strcpy(newNode->word, word); // here you can't assign newNod->word to wordcopy directly
    newNode->next = NULL;

    return newNode;
}

// Loads dictionary into memory, returning true if successful else false
int main (void)
{
    // naming file
    char *dictionary = "small";

    // Open dictionary file //
    FILE *dicptr = fopen(dictionary, "r");
    if (dicptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", dictionary);
        return 1;
    }

    // Read each line one at a time //

    char *word = malloc(LENGTH * sizeof(char));
    while (fscanf(dicptr, "%s", word) != EOF)
    {
        // Create a pointer for a new node for each word // // use a make_node function
        struct node* wordNode = make_node(word);
        if (wordNode == NULL) { return false; }

        // Insert the new nodeptr to the hash table // // use a push function to set the node as the head of the ll //

    }
    return 0;
}