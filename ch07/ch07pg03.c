/* Data Structures Using C, 2nd, Reema Thareja
Chapter 07. Stack: LIFO (Last-In-First-Out) data structure

Programming Exercises
3. Write a program to convert the expression "a+b" into "+ab".
   infix -> prefix

*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
char st[MAX];
int top = -1;
char infix[100], postfix[100], temp[100];

/**********************************************************
 * Function prototypes
 **********************************************************/

void reverse(char str[]);
void push(char st[], char);
char pop(char st[]);
void rev2postfix(char source[], char target[]);
int getPriority(char);

/**********************************************************
 * Main function
 **********************************************************/

int main() {
  system("clear");
  /* Enter infix notation */
  printf("Enter any infix expression: ");
  gets(infix);

  /* Get posfix notation */
  reverse(infix);
  strcpy(postfix, "");
  rev2postfix(temp, postfix);
  printf("The corresponding postfix expression is: ");
  // TODO: This is not correct representation of postfix conversion
  // 2*(3-4)  ==>  43-2*  (incorrect), 34-2*  (correct)
  puts(postfix);

  /* Get prefix notation */
  strcpy(temp, "");
  reverse(postfix);
  printf("The prefix expression is: ");
  puts(temp);

  return 0;
}

/**********************************************************
 * reverse function
 * - param: character array (arithmetic expression)
 * - modifying globally declared array stack, 'temp'
 *
 * TODO: Implement this using stack operation, pop and push.
 *       Implement this using point arithmetics.
 *       Implement this using recursion.
 **********************************************************/

void reverse(char str[]) {
  int len, i = 0, j = 0;
  len = strlen(str);
  j = len - 1;
  while (j >= 0) {
    if (str[j] == '(')
      temp[i] = ')';
    else if (str[j] == ')')
      temp[i] = '(';
    else
      temp[i] = str[j];
    i++, j--;
  }
  temp[i] = '\0';
}

/**********************************************************
 * rev2postfix function
 * - param source: array stack, reversed equation
 * - param target: array stack for postfix
 **********************************************************/

void rev2postfix(char source[], char target[]) {
  int i = 0, j = 0;
  char temp;
  strcpy(target, "");

  while (source[i] != '\0') {
    /* if char is '(', then push it to array stack, 'st' */
    if (source[i] == '(') {
      push(st, source[i]);
      i++;
    }
    /* if char is ')', then pop chars from 'st' and store them to 'target' */
    else if (source[i] == ')') {
      while ((top != -1) && (st[top] != '(')) {
        target[j] = pop(st);
        j++;
      }
      if (top == -1) {
        printf("INCORRECT EXPRESSION");
        exit(1);
      }
      temp = pop(st);  // remove left parentheses
      i++;
    }
    /* if char is digit, ... */
    else if (isdigit(source[i]) || isalpha(source[i])) {
      target[j] = source[i];
      j++;
      i++;
    }
    /* if char is operator, ... */
    else if (source[i] == '+' || source[i] == '-' || source[i] == '*' ||
             source[i] == '/' || source[i] == '%') {
      while ((top != -1) && (st[top] != '(') &&
             (getPriority(st[top]) > getPriority(source[i]))) {
        target[j] = pop(st);
        j++;
      }
      push(st, source[i]);
      i++;
    }
    /* if error condition */
    else {
      printf("INCORRECT ELEMENT IN EXPRESSION");
      exit(1);
    }
  }

  /* if closing paren is not the end of expression */
  while ((top != -1) && (st[top] != '(')) {
    target[j] = pop(st);
    j++;
  }

  target[j] = '\0';
}

/**********************************************************
 * getPriority function
 **********************************************************/

int getPriority(char op) {
  if (op == '/' || op == '*' || op == '%')
    return 1;
  else if (op == '+' || op == '-')
    return 0;
}

/**********************************************************
 * push function
 **********************************************************/

void push(char st[], char val) {
  if (top == MAX - 1)
    printf("STACK OVERFLOW");
  else {
    top++;
    st[top] = val;
  }
}

/**********************************************************
 * pop function
 **********************************************************/

char pop(char st[]) {
  char val = ' ';
  if (top == -1)
    printf("STACK UNDERFLOW");
  else {
    val = st[top];
    top--;
  }
  return val;
}
