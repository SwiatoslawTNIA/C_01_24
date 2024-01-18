#include "c.h"
#include "c1.h"
#include "c2.h"
enum {LONG, SHORT};
int main(int argc, char **argv)
{
  int res = doubleFunction(5);
  int (*fp)(int) = doubleFunction;
  int res_1 = fp(5);
  int res_2 = (*fp)(5);
  do_args(argc, argv, "ab+cd", do_arg, illegal_arg);
  printf("Result 1: %d, result 2: %d, result 3: %d\n", res, res_1, res_2);
  Node *nodes = createNodes(10);
  int value = 5;
  Node *correct_node = searchGeneral(nodes, &value, compare_ints);
  fprintf(stdout, "%d is the value in the node.", correct_node->value);
  //check the traverseList function:
  traverseList(nodes, traverseListHelp);
  

  free_nodes(nodes);
  //process the args that start with '-' followed by the letter:
  while(++*argv != NULL && **argv == '-')
  {
    
      // switch(**argv)
      // {
      //   case(LONG):;//...
      //   case(SHORT):;///.......
      // }
    while(*++*argv != '\0')
    {
      switch(**argv)
      {
        case(0):;
        case(1):;//...
      }
    }
    
  }

  readFunc();
  return 0;
}