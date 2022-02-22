/* Data Structures Using C, 2nd, Reema Thareja
Chapter 07. Stack: LIFO (Last-In-First-Out) data structure

Programming Exercises
2. Write a program to convert the expression "a+b" into "ab+".
   infix -> postfix

*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

char stk[MAX];
int top = -1;

/**********************************************************
 * prototypes
 **********************************************************/

int ispoint(char);
int isoperator(char);
int priority(char);

void push(char *, char);
char pop(char *);
void topostfix(char *, char *);

/**********************************************************
 * main function
 **********************************************************/

int main() {
  /* get expression */
  char exp[4][50] = {"30.5*(4+5)", "(3 * (4 + 5))", "((33.3 + 44.4) * 55.5)",
                     "  3.3   *(4.4   +   5.4)   "};

  char postfix[4][50];

  /* convert infix to postfix */
  for (int i = 0; i < 4; i++) {
    topostfix(*(exp + i), *(postfix + i));
  }

  for (int i = 0; i < 4; i++) {
    printf("%s: ==> %s\n", *(exp + i), *(postfix + i));
  }

  return 0;
}

/**********************************************************
 * topostfix
 **********************************************************/

void topostfix(char *exp, char *postfix) {
  int i = 0;
  while (*exp != '\0') {
    /* 1. if spaces or tabs */
    if (*exp == ' ' || *exp == '\t') {
      *exp++;
    }
    /* 2. if digit or decimal point */
    else if (isdigit(*exp) || ispoint(*exp)) {
      postfix[i++] = *exp++;
    }
    /* 3. if open paren*/
    else if (*exp == '(')
      push(stk, *exp++);
    /* 4. if closing paren */
    else if (*exp == ')') {
      /* stk is empty */
      if (top == -1) {
        printf("incorrect expression");
        exit(1);
      }
      postfix[i++] = ' ';  // SPACE: if char of exp is ')'
      /* if stk is empty or stk[top] is '(' */
      if (top != -1 && stk[top] != '(') {
        postfix[i++] = pop(stk);
      }
      /* pop '(' from stk */
      top--;
      exp++;
    }
    /* 5. if operator */
    else if (isoperator(*exp)) {
      postfix[i++] = ' ';  // SPACE: if character of exp is operator
      while ((top != -1) && (stk[top] != '(') &&
             (priority(stk[top]) > priority(*exp))) {
        postfix[i++] = pop(stk);
      }
      push(stk, *exp++);
    }
    /* 6. other case */
    else {
      printf("incorrect element in expression");
      exit(1);
    }
  }

  while ((top != -1) && (stk[top] != '(')) {
    if (postfix[i] != ' ') {
    }
    postfix[i++] = ' ';  // SPACE: when emptying stack
    postfix[i++] = pop(stk);
  }

  postfix[i] = '\0';
}

/**********************************************************
 * helper functions
 **********************************************************/

int isoperator(char chr) {
  return (chr == '+' || chr == '-' || chr == '*' || chr == '/' || chr == '%');
}

int ispoint(char chr) { return chr == '.'; }

int priority(char chr) {
  if (chr == '/' || chr == '*' || chr == '%')
    return 1;
  else if (chr == '+' || chr == '-')
    return 0;
}

void push(char *stk, char chr) {
  if (top >= MAX - 1)
    printf("Stack is full!\n");
  else
    stk[++top] = chr;
}

char pop(char *stk) {
  if (top == -1)
    printf("Stack is empty!\n");
  else
    return stk[top--];
}
