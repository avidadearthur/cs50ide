#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node* next;
};

int copy_ll(struct node *noderef, struct node **copyref)
{
    struct node* current = noderef;
    struct node* newList = NULL;
    struct node* tail = NULL;

    while (current != NULL)
    {
        if (newList == NULL)
        { // special case for the first new node
            newList = malloc(sizeof(struct node));
            newList->data = current->data;
            newList->next = NULL;
            tail = newList;
        }
        else
        {
            tail->next = malloc(sizeof(struct node));
            tail = tail->next;
            tail->data = current->data;
            tail->next = NULL;
        }

        current = current->next;
    }

    *copyref = newList;
    return 0;
}



int push(struct node **noderef, int data)
{
    struct node* newNode = malloc(sizeof(int));
    if (newNode == NULL)
    {
    return 1;
    }

    newNode->data = data;
    newNode->next = *noderef;

    *noderef = newNode;

    return 0;
}

int main(void)
{
    struct node* head;
    struct node* tail;
    struct node* current;
    struct node* copyHead;
    copyHead = NULL;
    tail = NULL;
    head = NULL;
    current = NULL;

    push(&head, 1);
    tail = head;



    int i;
    // build linked list from 1 tpo 9
    for (i = 2; i <= 9; i++)
    {
        push(&(tail->next), i);
        tail = tail->next;
    }


    copy_ll(head, &copyHead);

    current = copyHead;
    while (current != NULL)
    {
        printf("%d\n", current->data);
        current = current->next;

    }

    free(head);
    return 0;
}