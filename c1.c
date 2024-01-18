#include "c1.h"
int doubleFunction(int arg)
{
  return arg * 2;
}
//The problem with the search_node function is that it only works for a single linked list, 
//and values that are integers;
Node *searchNode(Node *first_node, int search_value)
{
  if(first_node != NULL)
  {
    while(first_node != NULL)
    {
      if(first_node->value == search_value)
        return first_node;
      else
        first_node = first_node->next;
    }
  }
  return first_node;
}
//This is a general function for comparison:
Node *searchGeneral(Node *first_node, int *search_value, int (*compare)(void const * , void const *))
{
  //the function above takes the same two functions, and as the third arg it accepts a function
  //of type int that is going to compare two nodes, that we pass by address:
  //we need to pass to the comparison function a pointer, because we also want to compare the strings, etc.
  while(first_node != NULL)
  {
    if(compare(&(first_node->value), search_value) == 0)//if the compare type function returns true, a.k.a 0
      return first_node;
    first_node = first_node->next;
  }
  return NULL;
}
//the prototype for a comparison function:
int compare_ints(void const *a, void const *b)
{//in these pointers are the integers
  if(*(int *)a == *(int *)b)//cast the pointers into the proper type.
    return 0;
  return 1;
}
void manage(void const * num1, void const * num2, enum OPERAND operand1)
{
  //An example of a pocket calculator:
  //the reason for the void pointer is that we may want to choose different number types.
  switch(operand1)
  {
    case(ADD):; //add function;
    case(SUBTRACT):; //subtract function
    case(MULTIPLY):;
    case(DIVIDE):;
  }
}
Node *createNodes(int count)
{
  int index = 0;
  Node *previous = NULL, *first_node;
  if(count > 0)
  {
    while(index < count)
    {
      Node *new_node = malloc(sizeof(Node));
      if(new_node == NULL)
      {
        fprintf(stderr, "Exiting, Out of memory.");
        free_nodes(first_node);
        return NULL;
      }
      new_node->value = index + 1;
      new_node->next = NULL;
      if(index == 0)//it is the first node
      {
        first_node = new_node;
        previous = new_node;
      }
      else
      {
        previous->next = new_node;
        previous = new_node;
      }
      ++index;
    }

  }
  else
    return NULL;
  return first_node;
}



void free_nodes(Node *first_node)
{
  while(first_node != NULL)
  {
    Node *next = first_node->next;
    free(first_node);
    first_node = next;
  }
}