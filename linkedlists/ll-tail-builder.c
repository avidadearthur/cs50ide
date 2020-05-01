#include <stdio.h>
#include <stdlib.h>

typedef struct node* Node;

struct node{
  int data;
  Node next;
};

int push(Node *headref, int data)
{
    Node newNode = malloc(sizeof(int));
    if (newNode == NULL)
    {
        return 1;
    }

    newNode->data = data;
    newNode->next = *headref;

    *headref = newNode;

    return 0;
}

int main(void)
{
    int i;
    Node head, tail, current, node;
    tail = NULL;
    head = NULL;
    current = NULL;

    push(&head, 1);
    tail = head;


    // build linked list from 1 tpo 9
    for (i = 2; i <= 9; i++)
    {
        push(&(tail->next), i); // pretend tail->next is a new head
        tail = tail->next; // set the tail pointer to poit to the latest element tail->next is pointing to
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