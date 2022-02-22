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
notation.

# postfix to infix
  ex) 3 4 +       ==> 3 + 4
  ex) 3 4 5 + *   ==> 3 * (4 + 5)
  ex) 3 4 * 5 +   ==> 3 * 4 + 5

  pfix  stack          explanation (@ is space)
  ---------------------------------------------
  3     3
  4     3 4
  5     3 4 5
  +     3 (4@+@5)      if exp[i] is op, do some action
  *     (3@*@(4@+@5))  if exp[i] is op, do some action
  'some action'

*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 20
#define N 20

char stk[M][N];  // array of string
int top = -1;

void push(char (*)[N], char *);
char *pop(char (*)[N]);
void getexp(char *);
int isop(char);

/**********************************************************
 *
 **********************************************************/

int main() {
  char *exp = "abc+*";
  getexp(exp);
  printf("%s ", stk[0]);
  return 0;
}

/**********************************************************
 *
 **********************************************************/

void getexp(char *exp) {
  while (*exp != '\0') {
    /* if space or tab */
    if (*exp == ' ' || *exp == '\t') exp++;
    /* if digit or point */
    else if (isdigit(*exp) || *exp == '.') {
      char digits[20];
      int i = 0;
      while (*exp != ' ' && *exp != '\0' && isop(*exp)) {
        digits[i++] = *exp++;
      }
      digits[i] = '\0';
      push(stk, digits);
    }
    /* if operator */
    else if (isop(*exp)) {
      char bwparens[20], pop1[20], pop2[20], temp[4];
      strcpy(pop2, pop(stk));
      strcpy(pop1, pop(stk));
      temp[0] = ' ';
      temp[1] = *exp;
      temp[2] = ' ';
      temp[3] = '\0';
      bwparens[0] = '(';
      strcat(strcat(strcat(bwparens, pop1), temp), ")\0");
      push(stk, bwparens);
      exp++;
    }
  }
}

/**********************************************************
 *
 **********************************************************/

int isop(char chr) {
  return (chr == '+' || chr == '-' || chr == '*' || chr == '/' || chr == '%');
}

void push(char stk[M][N], char *exp) {
  if (top == -1) {
    printf("Stack is full");
    exit(EXIT_FAILURE);
  } else
    strcpy(stk[++top], exp);
}

char *pop(char stk[M][N]) {
  if (top == -1) {
    printf("Stack is empty.\n");
    exit(EXIT_FAILURE);
  } else {
    return stk[top--];
  }
}