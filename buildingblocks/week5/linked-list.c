#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

// over complicating on purpose
typedef struct node
{
    int data;
    struct node *next;
}
Node;

int main(void)
{
    Node *head = malloc(sizeof(Node));
    Node *second = malloc(sizeof(Node));
    Node *third = malloc(sizeof(Node));

    *head = (struct node) {1, second};
    *second = (struct node) {2, third};
    *third = (struct node) {3, NULL};

    //alternatively you could just add
    //head->data = 1;
    //head->next = second;
    //second->data = 2;
    //(...)

    //int count = 0; //
    Node *current = NULL;
    current = head;

    while (current != NULL)
    {
        //count++; // in case you whant to keep
        //track of the number of elements
        printf("%d\n", current->data);
        current = current->next;
    }

    //we'll have some memory leak here but who cares

    return 0;
}