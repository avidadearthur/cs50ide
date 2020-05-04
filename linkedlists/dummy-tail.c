#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node* next;
};

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
  struct node dummy; // dummy here is a local variable, not a pointer to a struct.
  struct node* tail = &dummy;

  int i;
  dummy.next = NULL;
  // build linked list from 1 tpo 9
  for (i = 2; i <= 9; i++)
  {
      push(&(tail->next), i); // pretend tail->next is a new head
      tail = tail->next; // set the tail pointer to poit to the latest element tail->next is pointing to
  }

  struct node* current;
  current = dummy.next;     // after the first struct node*is set, the tail pointer
  while (current != NULL)   // stops pointing to dummy and dummy.next equivalent to tail->next
  {                         // in the first round, is left pointing to the first element of the ll
    printf("%d\n", current->data);
    current = current->next;

  }
  return 0;
}