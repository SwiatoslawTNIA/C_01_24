#include "../headers/c.h"
void readFunc(void);
int traverseListHelp(Node *first_node);
void traverseList(Node *first_node, int(*pt_to_func)(Node *pt_to_cur_node));
char **do_args( int argc, char **argv, char *control,
void (*do_arg)( int ch, char * value ),
void (*illegal_arg)( int ch ));
void illegal_arg(int ch);
void do_arg(int ch, char *value);
// The change