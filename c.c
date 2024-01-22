#include "c.h"
#include "c1.h"
#include "c2.h"
int main(void)
{
  
  //an example of using memset():
  size_t arr_length = 10;
  int arr[arr_length];
  printf("%lu", arr_length);
  memset(arr,'1', arr_length );
  //the issue I was experiencing was due to the fact, that int is 4 bytes long, 
  //and I was trying to assign int each byte in memory.
  for(int i = 0; i < arr_length; ++i)
  {
    printf("The value after memset is: %c\n", arr[i]);
  }
  long int number = 0;
  assert(arr_length - number == 10);//
  printf("Terminating, value: %ld", number);
  return 0; 
}
// enum {LONG, SHORT};
// char *cpu_type(void);
// #define DEBUG printf("File %s, line %d",
//                                         
//                     __FILE__, __LINE__);
// //for example now we can choose the name of the file:
// #define FILENAME
// #define PRINT(format) printf("The format of the printing message is: " #format)
// // int main(int argc, char **argv)
// // {
// //   PRINT(45);
// //   fprintf(stdout, "Select the current file name:");
// //   char *str;
// //   fscanf(stdin, "%s", str);//file name must be of 1 word
// //   fprintf(stdout, "Previous file name: %s", __FILE__);



// //   #ifndef TYPE
// //     #ifndef FILENAME
// //       #error "The TYPE var is not defined"
// //     #endif /*End of the FILENAME checking clause*/
// //   #endif
// //   DEBUG;
// //   printf("\n");
// //   int res = doubleFunction(5);
// //   int (*fp)(int) = doubleFunction;
// //   int res_1 = fp(5);
// //   int res_2 = (*fp)(5);
// //   do_args(argc, argv, "ab+cd", do_arg, illegal_arg);
// //   printf("Result 1: %d, result 2: %d, result 3: %d\n", res, res_1, res_2);
// //   Node *nodes = createNodes(10);
// //   int value = 5;
// //   Node *correct_node = searchGeneral(nodes, &value, compare_ints);
// //   fprintf(stdout, "%d is the value in the node.", correct_node->value);
// //   //check the traverseList function:
// //   traverseList(nodes, traverseListHelp);
  

// //   free_nodes(nodes);
// //   //process the args that start with '-' followed by the letter:
// //   while(++*argv != NULL && **argv == '-')
// //   {
    
// //       // switch(**argv)
// //       // {
// //       //   case(LONG):;//...
// //       //   case(SHORT):;///.......
// //       // }
// //     while(*++*argv != '\0')
// //     {
// //       switch(**argv)
// //       {
// //         case(0):;
// //         case(1):;//...
// //       }
// //     }
    
// //   }

// //   readFunc();
// //   return 0;
// // }
// int main(void)
// {
//   printf("You current CPU is: %s", cpu_type());
//   //create the temporary file:
//   FILE *f_p = tmpfile();
//   // if(f_p == NULL)
//     // #error Unable to create a temp file

//   FILE *p = fopen("c.c", "r+");
//   if(p == NULL)
//   {
//     fprintf(stderr, "Sorry, unable to open the file.");
//     return 1;
//   }
//   //here let's work with the file_pointer:
//   printf("\n----%lu----\n", p->__pad5);
//   fseek(p,-40,SEEK_END);
//   printf("\n----%u----\n", p->_cur_column);
//   printf("\n----%lu----\n", p->_offset);
//   // printf("\n----%s----\n", p->_IO_buf_base);
//   printf("\n----%d----\n", p->_flags);
//   printf("\n----%s----\n", p->_IO_backup_base);
//   printf("\n----%d----\n", p->_mode);
//   printf("\n----%s----\n", p->_unused2);
//   #ifndef HAHA
//     system("ls -lFa");
//   #endif

  




//   char *file_name = tmpnam(NULL);
//   printf("New temp file name: %s",file_name);
//   fclose(f_p);
//   fclose(p);
//   return 0;
// }
// void print_ledger(int value)
// {
//   #ifdef OPTION_LONG 
//     // print_ledger_long();
//   #elif defined(OPTION_DETAILED) 
//     //print_ledger_detailed();
//   #else
//     // print_ledger_default();
//   #endif //OPTIONS
// }
// char *cpu_type(void)
// {
//   #ifdef VAX
//     return "CPU_VAX";
//   #elif defined(M6800)
//     return "CPU_68020";
//   #elif defined(K68020)
//     return "CPU_68020";
//   #elif defined(I80386)
//     return "CPU_80386";
//   #elif defined(X6809)
//     return "CPU_6809";
//   #elif defined(X6502)
//     return "CPU_6502";
//   #elif defined(U3B2)
//     return "CPU_3B2";  
//   #else 
//     return "CPU_UNKNOWN";
//   #endif
// }
