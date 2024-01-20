#ifndef DEFINED
#define DEFINED
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct NODE {
  struct NODE *next;
  int value;
} Node;
enum OPERAND {ADD, SUBTRACT, MULTIPLY, DIVIDE};

#endif
