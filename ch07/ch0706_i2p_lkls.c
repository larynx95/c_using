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
6. Write a program to convert an infix expression into its equivalent postfix
notation. (singly linked list version)

# possible expressions
- no space bw digits or operators: "3+4*5", "3*4+5"
- with spaces or tabs            : "  3+4*56 ", "  3 *4   +5"
- starts with '('                : " (3+5  )*  5 "
- repeating parenthesis          : "((3+  5) *   5)"
- alphanumeric                   : "(a +4) * 3b"
- floating numbers               : "  (33.3 - 20b) *32"
- cosecutive operators           : " 3+*  4"
- content within parenthesis     : "(3+ )* 4 "
- symbols other than parenthesis : "{4* (4 - 2) + 20.2} + [3.0 +4  ]"

# possible characters
(1) empty space: space or tab
(2) closing parentheses
(3) opening parentheses
(4) operators
(5) block of alphanumerics or points, empty spaces before and after it


# precondition for expression
- Infix expression should be surrounded by parenthesis. "(...)"
  That's all that required for this code.

# conditions for invalid expressions
- When the character in expression (*exp) is ')',
  but stack is empty (top == NULL).
- When *exp is operator symbol,
  but *(exp-1) or *(exp+1) is also operator.
- unpaired parenthesis

*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nd {
  char sym;
  struct Nd* next;
} Nd;

/**********************************************************
 * function prototypes
 **********************************************************/

Nd* push(Nd* top, char chr);
Nd* pop(Nd* top);
char peek(Nd* top);
int isop(char c);
int prior(char c);
void getexp(char* exp, Nd* top, char* pfix);

/**********************************************************
 * main function
 **********************************************************/

int main() {
  /* Preconditioning: Expression must be surrounded by parenthesis */
  char* exp = "((33.3 + 44.4) * 55.5)";  // 33.3 44.4 + 55.5 *

  /* Practicing conversion  */
  Nd* top = NULL;
  char pfix[20] = "";
  getexp(exp, top, pfix);

  /* Printing the result */
  printf("%s\n", pfix);

  return 0;
}

/**********************************************************
 * getexp
 **********************************************************/

void getexp(char* exp, Nd* top, char* pfix) {
  /* loop till the end of string, exp */
  while (*exp) {
    /* (1) space or tab */
    if (*exp == ' ' || *exp == '\t') exp++;
    /* (2) closing parentheses ')' */
    else if (*exp == ')') {
      /* invalid expression, stack (top) must have at least one '(' character */
      if (top == NULL) {
        printf("Empty stack.\n");
        exit(EXIT_FAILURE);
      }
      /* pop characters from top, and add it to postfix string (pfix) */
      else {
        while (peek(top) != '(') {
          *pfix++ = peek(top);
          *pfix++ = ' ';
          top = pop(top);
        }
      }
      exp++;
    }
    /* (3) opening parentheses */
    else if (*exp == '(') {
      top = push(top, *exp++);
    }
    /* (4) operator */
    else if (isop(*exp)) {
      /* TODO: Implement code for validity check */
      /* if op in exp has greater priority than the op in stack */
      if (prior(peek(top)) > prior(*exp)) {
        *pfix++ = peek(top);
        *pfix++ = ' ';
        top = pop(top);
      }
      top = push(top, *exp++);
    }
    /* (5) alphanumeric character */
    else if (isalnum(*exp) || *exp == '.') {
      /* TODO: Implement code for validity check */
      /* number is not only single digit, but also digits or float numbers */
      while (isalnum(*exp) || *exp == '.') {
        *pfix++ = *exp++;
      }
      *pfix++ = ' ';
    }
    /* (6) Is this required? */
    else {
      exp++;
    }
  }
}

/**********************************************************
 * helper functions: push, pop, isop, prior
 **********************************************************/

Nd* push(Nd* top, char chr) {
  Nd* new = malloc(sizeof(Nd));
  new->sym = chr;
  new->next = top;
  top = new;
  return top;
}

Nd* pop(Nd* top) {
  /* if stack is empty (We can't pop from empty stack.) */
  if (top == NULL) {
    printf("Empty.\n");
    exit(EXIT_FAILURE);
  }
  /* if not empty */
  else {
    Nd* ptr = top;
    top = top->next;
    printf("You have popped %d\n", ptr->sym);
    free(ptr);
  }
  return top;
}

char peek(Nd* top) { return top->sym; }

int isop(char c) {
  return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

int prior(char c) {
  if (c == '*' || c == '/' || c == '%')
    return 1;
  else
    return 0;
}
