#include "c.h"
int doubleFunction(int arg);
Node *searchNode(Node *first_node, int search_value);
Node *searchGeneral(Node *first_node, int *search_value, int (*compare)(void const * , void const *));
int compare_ints(void const *a, void const *b);
void free_nodes(Node *first_node);
Node *createNodes(int count);