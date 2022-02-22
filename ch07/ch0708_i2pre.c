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
    Evaluation of a postfix expression (Program example 7)
    Conversion of an infix expression into a prefix expression
    (Program example 8)
*/

/*
Programming Example
8. Write a program to convert an infix expression to a prefix expression.

  # algorithm to convert an infix expression into prefix expression
  Step 1: Scan each character in the infix expression. For this,
          repeat steps 2-8 until the end of infix expression
  Step 2: Push the operator into the operator stack,
          operand into the operand stack,
          and ignore all the left parentheses
          until a right parenthesis is encountered
  Step 3: pop operand 2 from operand stack
  Step 4: Pop operand 1 from operand stack
  Step 5: Pop operator from operator stack
  Step 6: Concatenate operator and operand 1
  Step 7: Concatenate result with operand 2
  Step 8: Push result into the operand stack
  Step 9: END

  # algorithm to convert an infix expression into prefix expression
  Step 1: Reverse the infix string.
          Note that while reversing the string you must interchange
          left and right parenthesis.
  Step 2: Obtain the postfix expression of the infix expression
          obtained in Step 1.
  Step 3: reverse the postfix expression to get the prefix expression.

  # Visualization: (A+B^C)*D+E^5
  Step 1. Reverse the infix expression.
          5^E+D*)C^B+A(
  Step 2. Make Every '(' as ')' and every ')' as '('
          5^E+D*(C^B+A)
  Step 3. Convert expression to postfix form.
          Expression      Stack   Output      Comment
          5^E+D*(C^B+A)   Empty   -           Initial
          ^E+D*(C^B+A)    Empty   5           Print
          E+D*(C^B+A)     ^       5           Push
          +D*(C^B+A)      ^       5E          Push
          D*(C^B+A)       +       5E^         Pop And Push
          *(C^B+A)        +       5E^D        Print
          (C^B+A)         +*      5E^D        Push
          C^B+A)          +*(     5E^D        Push
          ^B+A)           +*(     5E^DC       Print
          B+A)            +*(^    5E^DC       Push
          +A)             +*(^    5E^DCB      Print
          A)              +*(+    5E^DCB^     Pop And Push
          )               +*(+    5E^DCB^A    Print
          End             +*      5E^DCB^A+   Pop Until '('
          End             Empty   5E^DCB^A+*+ Pop Every element
  Step 4. Reverse the expression.
          +*+A^BCD^E5

TODO: There're some flaws in this code. Fix these.
- 2 + (3 - 4)        error
- 2.2 + (3.3 - 4.4)  error
- 2.2+(3.3-4.4)      error
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