#include "c2.h"
//the improved code fragment:
/*
register Transaction *trans;
trans->product->orders += 1;
trans->product->quantity_on_hand -= trans->quantity;




*/
// controlȱcharactersȱ
// whitespaceȱcharactersȱ
// digitsȱ
// lowerȱcaseȱlettersȱ
// upperȱcaseȱlettersȱ
// punctuationȱcharactersȱ
// nonȬprintableȱcharactersȱ
void readFunc(void)
{
  printf("Please start typing:\n>  ");
  char c, prev_char;
  size_t control_chars = 0, whitespace_chars = 0, digits = 0,
   lowercase = 0, uppercase =0, punctuate = 0, nonprint = 0;
  while((c = getc(stdin)) != EOF && (c != '\n' && prev_char  != '\n'))
  {
    if(isdigit(c))
      digits++;
    if(iscntrl(c))
      control_chars++;
    if(isspace(c))
      whitespace_chars++;
    if(islower(c))
      lowercase++;
    if(isupper(c))
      uppercase++;
    if(ispunct(c))
      punctuate++;
    if(!isprint(c))
      nonprint++;
    prev_char = c;
  }
  printf("The result:\n " 
         "Control characters: %lu\n "
         "Whitespace characters: %lu\n "
         "Digits: %lu\n "
         "Lowercase characters: %lu\n "
         "Uppercase characters: %lu\n "
         "Punctuation characters: %lu\n "
         "Nonprintable characters: %lu\n "
          , control_chars, whitespace_chars, digits, lowercase, uppercase, punctuate, 
          nonprint);
}
int traverseListHelp(Node *first_node)
{
  if(first_node != NULL)
  {
    while(first_node->next != NULL)
    {
      first_node = first_node->next;
    }
    return 0;//We've made it to the end of the list.
  }
  else
  {
    return 1;//the pointer pointed to NULL 
  }
  return 0;
}
void traverseList(Node *first_node, int(*pt_to_func)(Node *pt_to_cur_node))
{
  int resp = 0;
  if((resp = pt_to_func(first_node)) == 1)
    fprintf(stderr,"Sorry, could not traverse the list");
  else
    fprintf(stdout, "Successfully traversed to the end of the list.");
  //an experiment:
  // Node *(*pt[4])(Node *list, Node *current);// = [func names];
}
void sort_copy(void *first_element, size_t arr_length, size_t element_size, 
int(*fp)(void *first_value, void *second_value))
{
  //insertion-sort algorithm:
  for(size_t j = 2; j < arr_length;++j)
  {
    void *key = malloc(element_size);//element size should be in bytes
    if(key == NULL)
    {
      fprintf(stderr, "Not enough memory.");
    }
    memcpy(key, (char *)first_element + j*element_size, element_size);//the size of the first_element is just 
    //the first element essentially, when we need the access to the whole object
    int i = j - 1;
    while( i >= 0 && fp((char *)first_element + j*element_size, key) > 0)//then the key is less than curr_el
    {
      memcpy((char *)first_element + (i + 1)*element_size,(char *)first_element + i*element_size, 
      element_size);
      i--;
    }//the key is less than the number:
    memcpy((char *)first_element + (i + 1)*element_size,key, element_size);
    free(key);
  }
}
char **do_args( int argc, char **argv, char *control,
void (*do_arg)( int ch, char * value ),
void (*illegal_arg)( int ch ))
{
  //skip past the file_name:
  

  if(*(argv + 1) != NULL)
  {
    argv++;
    while(*argv != NULL)
    {
      printf("%s", *argv);
      if(argv[0][0] == '-')//this arg is an option:
      {
        char *string = malloc(sizeof(char)*20);//allocate the space for the string.
        if(string == NULL)
        {
          fprintf(stderr, "Out of memory");
        }

        while(argv[0][0] != ' ')
        {//until the space is encountered
          //check for the arg in control:
          int i = 0;
          bool found = false, has_value = false;
          char value[40];//to record the value
          for(; i < strlen(control);++i)
          {
            if(control[i] == argv[0][0])
            {
              found = true;
              break;
            }
          }

          if(!found)
          {
            illegal_arg(control[i]);
            return argv;
          }//now the char was found:
          //check for subs. values:
          if(control[i + 1] == '+')
            has_value = true;
          if(has_value)
          {
            i++;
            if(!isspace(control[i + 1]))//if the next char is not space
            {
              //check for the length:
              if(strlen(&control[i + 1]) > 39)
              {
                fprintf(stderr, "Sorry, the value is too long!!!");
                return NULL;
              }
              strcpy(value, &control[i + 1]);
            }//now the next arg is space, so:
            argv++;//move to the next arg;
            char c;
            int counter = 0;
            bool length_exceeded = false;
            while((c = argv[0][0]) != ' ' && counter < 40 && !length_exceeded)//while the char is not space
            {
              if(counter == 39 && c != ' ')
              { 
                fprintf(stderr, "Sorry, the value is too long!!!");
              } 
              string[counter] = c;
              argv[0][0]++, counter++;
            }
            string[counter] = '\0';//terminate the string
          }
          argv[0][0]++;
        }
        free(string);
      }
      argv++;//point to the next arg
    }
  }
  else
  {
    fprintf(stderr,"No args");
  }
  
  return NULL;
}
void do_arg(int ch, char *value)
{

}
void illegal_arg(int ch)
{
  fprintf(stderr, "Error, this arg does not exist: %c", ch);
}