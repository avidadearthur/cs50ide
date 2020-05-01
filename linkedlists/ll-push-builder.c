#include <stdio.h>
#include <stdlib.h>

typedef struct node* Node;

struct node{
  int data;
  Node next;
};

// pushes the new head
int push(Node *headref, int data)
{
    Node newNode = malloc(sizeof(Node));
    if (newNode == NULL)
    {
        return 1;
    }
    // for the first it will be NULL, the first in
    // becomes the last in the end
    newNode->next = *headref;
    newNode->data = data;

    *headref = newNode;

    return 0;
}



int main(void)
{
    int i;
    Node head, current;
    head = NULL;

    current = NULL;

    // build linked list from 1 tpo 9
    for (i = 1; i <= 9; i++)
    {
        push(&head, i);
    }

    // check if it works
    current = head;
    while (current != NULL)
    {
        printf("%d\n", current->data);
        current = current->next;
    }

    return 0;
}