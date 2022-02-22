/* Data Structures Using C, 2nd, Reema Thareja
Chapter 07. Stack: LIFO (Last-In-First-Out) data structure
7.1 Introduction
7.2 Array refresentation of stacks
7.3 Operations on a stack
  7.3.1 Push operation
  7.3.2 pop operation
  7.3.3 Peek operation (Program example 1)
7.4 Linked representation of stacks
7.5 Operations ona linked stack
  7.5.1 Push operation
  7.5.2 Pop operation (Program example 2)
7.6 Multiple stacks (Program example 3)
7.7 Applications of stacks
  7.7.1 Reversing a list (Program example 4)
  7.7.2 Implementing parentheses checker (Program example 5)
  7.7.3 Evaluation of arithmetic expressions
    Polish notations
    Conversion of an infix expression into a postfix expression (Example 7.3)
    (Program example 6)
*/

/*
Programming Example (optional)
6. Write a program to convert an post expression into its equivalent infix
notation. (linked stack)

# algorithm for lkls push and pop for stack
i. NULL         NULL
ii. One node    top --> Node --> NULL (or)
                NULL <-- Node <-- top
iii. more       top --> Node --> ... --> NULL (or)
                NULL <-- ... <-- Node <-- top

# string as a field of a structure
  How to work with string fields in a C struct?
  https://stackoverflow.com/questions/10162152/how-to-work-with-string-fields-in-a-c-struct

# Visualization code
  http://pythontutor.com/

*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ML 15

typedef struct Nd {
  char* data;
  struct Nd* next;
} Nd;

/**********************************************************
 * prototypes
 **********************************************************/

Nd* push(Nd* top, char* subs);
Nd* pop(Nd* top);
Nd* getexp(char* exp, Nd* top);
int isop(char c);

/**********************************************************
 * main function
 **********************************************************/

int main() {
  char* exp = "3 4 5 + *";
  Nd* top = NULL;  // initialize stack with NULL
  top = getexp(exp, top);
  printf("infix: %s\n", top->data);

  /* freeing memory spaces */
  free(top->data);
  free(top);

  return 0;
}

/**********************************************************
 * getexp
 **********************************************************/

Nd* getexp(char* exp, Nd* top) {
  while (*exp) {
    /* if spaces or tabs */
    if (*exp == ' ' || *exp == '\t') exp++;

    /* if alphnumeric or point */
    if (isalnum(*exp) || *exp == '.') {
      char temp[ML];  // TODO: check scope
      char* ptr = temp;
      while (*exp != ' ' && *exp != '\t') {
        *ptr++ = *exp++;
      }
      *ptr = '\0';
      top = push(top, temp);
    }

    /* if operator */
    if (isop(*exp)) {
      char temp[ML] = "(";
      char op[2] = {*exp, '\0'};
      strcat(strcat(strcat(strcat(temp, top->data), " "), op), " ");
      top = pop(top);
      strcat(strcat(temp, top->data), ")");
      top = pop(top);
      top = push(top, temp);
    }
    exp++;
  }
  return top;
}

/**********************************************************
 * push, pop, isop
 **********************************************************/

Nd* push(Nd* top, char* subs) {
  /* create a new node */
  Nd* new = malloc(sizeof(Nd));
  new->data = strdup(subs);
  // new->next = NULL;

  /* link new node to top */
  new->next = top;
  top = new;

  return top;
}

Nd* pop(Nd* top) {
  if (top == NULL) {
    printf("Empty stack.\n");
    exit(EXIT_FAILURE);
  } else {
    Nd* ptr = top;
    top = top->next;
    free(ptr->data);
    free(ptr);
  }
  return top;
}

int isop(char c) {
  return (c == '*' || c == '/' || c == '-' || c == '+' || c == '%');
}