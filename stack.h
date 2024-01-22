#include "c.h"
//the simplest stack implementation, using static array:
#define STACK_SIZE 100
#define STACK_TYPE int
int is_full(void);
int is_empty(void);
void push(STACK_TYPE element);
STACK_TYPE top(void);
STACK_TYPE pop(void);
static int top_element = -1;
