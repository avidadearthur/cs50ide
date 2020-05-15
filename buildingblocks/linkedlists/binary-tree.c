#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node* right;
  struct node* left;
};

int make_node(struct node** node, int data)
{
  struct node* newNode = malloc(sizeof(struct node));
  if (newNode == NULL){ return 1; }

  newNode->data = data;
  newNode->left = newNode->right = NULL;

  *node = newNode;

  return 0;
}

int insert_node(struct node** rootref, int data)
{
  // make a local pointer to the actual pointer will make things easier
  struct node* localnodeptr = *rootref;

  if (localnodeptr == NULL) // there is no node in the called position yet
  {
    return make_node(rootref, data);
  }

  if (data >= localnodeptr->data) // dta input goes to the right
  {
    insert_node(&localnodeptr->right, data);
  }

  if (data < localnodeptr->data) // data input goes to the left
  {
    insert_node(&localnodeptr->left, data);
  }

  return 0;
}

int main(void)
{
  struct node* root = NULL;

  // int i;
  // for (i = 0; i <= 6 ; i++)
  // {
  //   insert_node(&root, i);
  // }
  insert_node(&root, 4);
  insert_node(&root, 2);
  insert_node(&root, 3);
  insert_node(&root, 5);
  insert_node(&root, 6);

  return 0;
}