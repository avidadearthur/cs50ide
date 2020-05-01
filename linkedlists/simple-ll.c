#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

typedef struct node* Node;

struct node {
  int data;
  Node next;
};

// A function that creates a one two three
// linked list.

Node build_ll(void)
{
    // An alternative sintax to (struct->atribute
    // here is struct->atribute = (...)
    Node head = malloc(sizeof(Node));
    Node second = malloc(sizeof(Node));
    Node third = malloc(sizeof(Node));

    head->data = 1;
    head->next = second;
    // A shorter option is set the the
    // structure node values like
    // *head = (struct node){ 1, second }; and so forth ...

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    // At this point, the linked list referenced by "head"
    // matches the list in the drawing.
    return head;
}

int main(void)
{
    Node head, current;
    head = build_ll();
    current = head;
    int count = 0;
    // instead of :
    // printf("%d\n", head->data);
    // printf("%d\n", head->next->data);
    // printf("%d\n", head->next->next->data);
    // we can do :
    while (current != NULL)
    {
        count++;
        printf("%d\n", current->data);
        current = current->next;
    }

    printf("lenght: %i\n", count);

    return 0;
}