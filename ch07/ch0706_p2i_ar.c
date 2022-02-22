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
notation. (array stack)

# Write down cases
    infix                     postfix
  3 * 4 + 5              ==>  3 4 * 5 +
  30.5*(4+5)             ==>  30.5 4 5 + *
  (3 * (4 + 5))          ==>  3 4 5 + *
  3 * 4 + 5              ==>  3 4 *5 +
  3.3   *(4.4   +   5.4) ==>  3.3 4.4 5.4 + *

# Analysis
  exp   stack
  -------------------------------
  3     3
  4     3,4
  *     (3 * 4)
  5     (3 * 4), 5
  +     (3 * 4) + 5
  -------------------------------
  30.5  30.5
  4     30.5, 4
  5     30.5, 4, 5
  +     30.5, (4 + 5)
  *     30.5 * (4 + 5)

# Generalized rules
  - number is separated by space(s) or tab(s)
  - stack stores strings
  - if exp[i] is operator,
    a. pop twice
    b. insert operator symbol
    c. add spaces properly
    d. push result to the stack
  - if null terminator, get a string from stack

# TODO: This is my verbose solution.
        Make this code more elegant, later.
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define R 3
#define C 10

int top = -1;
char stk[R][C];

/**********************************************************
 * prototypes
 **********************************************************/

int isop(char c);
void push(char stk[R][C], char *str);
char *pop(char (*stk)[C]);
void getexp(char *exp, char *temp, char stk[R][C]);

/**********************************************************
 * main function
 **********************************************************/

int main() {
  /* char exp[5][20] = {"3 4 * 5 +", "30.5 4 5 + *", "3 4 5 + *", "3 4 *5 +",
                     "3.3 4.4 5.4 + *"}; */
  char *exp = "33.3 44.4 + 55.5 *";
  char temp[C] = "";
  getexp(exp, temp, stk);
  printf("top: %d, inifx: %s\n", top, *stk);

  return 0;
}

/**********************************************************
 * isop, push, pop
 **********************************************************/

int isop(char c) {
  return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

void push(char stk[R][C], char *str) {
  if (top > R - 1) {
    printf("Stack full.\n");
    exit(EXIT_FAILURE);
  } else {
    ++top;
    strcpy(stk[top], str);
  }
}

char *pop(char (*stk)[C]) {
  if (top == -1) {
    printf("Empty stack.\n");
    exit(EXIT_FAILURE);
  } else {
    return stk[top--];
  }
}

/**********************************************************
 * getexp
 - Don't be confused with pointer arithmetics.
   Watch out where the pointer variables are pointing.
 **********************************************************/

void getexp(char *exp, char *temp, char stk[R][C]) {
  while (*exp) {
    char *ptr = temp;  // TODO: Where are they pointing at?
    /* spaces or tabs */
    if (*exp == ' ' || *exp == '\t') exp++;

    /* if alphnumerics */
    if (isdigit(*exp) || *exp == '.') {
      while (*exp != ' ' && *exp != '\t') {
        *ptr++ = *exp++;
      }
      *ptr = '\0';
      push(stk, temp);
      strcpy(temp, "");
    }

    /* if operator
      (a + b)
    */
    if (isop(*exp)) {
      strcpy(temp, "(");
      char numa[20], numb[20];
      strcpy(numb, pop(stk));
      strcpy(numa, pop(stk));
      char op[2] = {*exp, '\0'};
      strcat(strcat(strcat(strcat(strcat(strcat(temp, numa), " "), op), " "),
                    numb),
             ")");
      push(stk, temp);
    }
    exp++;
  }
}