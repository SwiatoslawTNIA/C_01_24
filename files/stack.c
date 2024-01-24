#include "stack.h"

STACK_TYPE array[STACK_SIZE];
void push(STACK_TYPE element)
{
  assert(!is_full());
  array[++top_element] = element;
}
STACK_TYPE pop(void)
{
  assert(!is_empty());
  return array[top_element--];
}
STACK_TYPE top(void)
{
  assert(!is_empty());
  return array[top_element];
}
int is_full(void)
{
  return top_element = STACK_SIZE - 1;
}
int is_empty(void)
{
  return top_element == -1;
}
