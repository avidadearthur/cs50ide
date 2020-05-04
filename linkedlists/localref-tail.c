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
  struct node* head;  // head here is a local pointer, that will be passed by reference.
                      // with dummy what was being passed by reference was a pointer the
                      // .next poiter it has.
  struct node** localref = &head;

  int i;
  // build linked list from 1 tpo 9
  for (i = 1; i <= 9; i++)
  {
      push(localref, i);
      localref = &((*localref)->next);  // here we must dereference localref, which leads us to head
  }                                     // take the head.next pointer address and pass it by reference on
                                        // the next loop

  struct node* current;
  current = head;     // after the first struct node*is set, the tail pointer
  while (current != NULL)   // stops pointing to dummy and dummy.next equivalent to tail->next
  {                         // in the first round, is left pointing to the first element of the ll
    printf("%d\n", current->data);
    current = current->next;

  }

  free(head);
  return 0;
}