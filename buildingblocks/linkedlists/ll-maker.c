#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <cs50.h>

typedef struct node* Node;

struct node {
    int data;
    Node next;
};

// #define build_list(...) \
//     _build_list((sizeof((int []){ __VA_ARGS__ }))/(sizeof(int)), \
//     (int []){ __VA_ARGS__ })

// // Builds arbitrary linked list given a number of arguments

// struct node * _build_list(size_t count, int values[count])
// {
//     struct node * next = NULL;

//     for(size_t i = count; i--; )
//     {
//         struct node * current = malloc(sizeof *current);

//         *current = (struct node){ values[i], next };
//         next = current;
//     }

//     return next;
// }

// Alternative for the builder above
Node build_list(int len, int arr[])
{
    Node next = NULL;

    for (int i = len-1; i >= 0; i--)
    {
        Node current = malloc(sizeof(Node));
        *current = (struct node) {arr[i], next};
        next = current;
    }

    return next;
}

// Pushes a new head in a linked list
Node push(Node *head, int data)
{
    Node newNode = malloc(sizeof(Node));
    newNode->next = *head;
    newNode->data = data;

    *head = newNode;

    return *head;
}

int main(void)
{
    Node head, current;
    int arr[] = {1, 2, 3, 4, 5};
    head = build_list(5, arr);

    // notice the ampersand here, and the * inside push()
    // doing so it passes a pointer to the head pointer
    push(&head, 6);
    push(&head, 7);
    push(&head, 8);
    current = head;

    int count = 0;

    while (current != NULL)
    {
        count++;
        printf("%d\n", current->data);
        current = current->next;
    }

    printf("lenght: %i\n", count);
    return 0;
}