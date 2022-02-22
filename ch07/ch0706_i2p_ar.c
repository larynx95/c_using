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
Programming Example (array version in this book)
6. Write a program to convert an infix expression into its equivalent postfix
notation.

TODO: Textbook's answer for this example is not fully functional.
  For example,
  30.3 * (40.4 - 20.2)   ==> error
  30.3*(40.4+20.2)       ==> error
  3 * (4 + 5)            ==> error

# key concepts for conversion
- signal for "store character!": opening paren '('
  but if expression is not starting with '('?
- signal for "execute some action!": closing paren ')'
- operator priority checking
- separating numbers, especially float or double numbers
- the number of array stacks: how many?
  SOURCE[]: char array for expression
  SYMBOLS[]: stack,
  OUTPUT[]: char array for postfix expression

# example 7.1
Convert the following infix expressions into postfix expressions.
Solution
  (a) (A-B) * (C+D)
      [AB-] * [CD+]
      AB-CD+*
  (b) (A + B) / (C + D) - (D * E)
      [AB+] / [CD+] - [DE*]
      [AB+CD+/] - [DE*]
      AB+CD+/DE*-

# example 7.2
Convert the following infix expressions into prefix expressions.
Solution
  (a) (A + B) * C
      (+AB)*C
      *+ABC
  (b) (A-B) * (C+D)
      [-AB] * [+CD]
      *-AB+CD
  (c) (A + B) / ( C + D) - ( D * E)
      [+AB] / [+CD] - [*DE]
      [/+AB+CD] - [*DE]
      -/+AB+CD*DE

# Visualization: A * B + C * D
https://runestone.academy/runestone/books/published/pythonds/BasicDS/InfixPrefixandPostfixExpressions.html#tbl-example3
Higher priority * , / , %
Lower priority + , –

equaton     A   *   B   +       C   *   D
                                    *   *   *
                *   *   *   +   +   +   +   +   +
stack       _   _   _   _   _   _   _   _   _   _

postfix     A       B       *   C       D       *   +


# Algorithm to convert an infix notation to postfix notation
Step 1: Add ")" to the end of the infix expression
        ")" has special meaning (execute or clear!)
Step 2: Push "(" on to the stack
Step 3: Repeat until each character in the infix notation is scanned
        IF a "(" is encountered, push it on the stack
        IF an operand (whether a digit or a character) is encountered,
            add it postfix expression.
        IF a ")" is encountered, then
          a. Repeatedly pop from stack and
              add it to the postfix expression until a "(" is encountered.
          b. Discard the "(" .
              That is, remove the "(" from stack and
              do not add it to the postfix expression
        IF an operator X is encountered, then
          a. Repeatedly pop from stack and add each operator
            (popped from the stack) to postfix expression
            which has the same precedence or a higher precedence than X
          b. Push the operator X to the stack
        [END OF IF]
Step 4: Repeatedly pop from the stack and
        add it to the postfix expression until the stack is empty
Step 5: EXIT

# example 7.3
  Convert the following infix expression into postfix expression using the
  algorithm given in Fig. 7.22.
  (a) A – (B / C + (D % E * F) / G)* H
  (b) A – (B / C + (D % E * F) / G)* H)

  Infix Stack           Postfix
  -------------------------------------------------
        (                                First, add this opening paren
  A     (               A                push
  –     ( –             A                push
  (     ( – (           A                push
  B     ( – (           A B              push
  /     ( – ( /         A B              push
  C     ( – ( /         A B C            push
  +     ( – ( +         A B C /          higher precedence op popped up
  (     ( – ( + (       A B C /
  D     ( – ( + (       A B C / D
  %     ( – ( + ( %     A B C / D
  E     ( – ( + ( %     A B C / D E
  *     ( – ( + ( % *   A B C / D E
  F     ( – ( + ( % *   A B C / D E F
  )     ( – ( +         A B C / D E F * %
  /     ( – ( + /       A B C / D E F * %
  G     ( – ( + /       A B C / D E F * % G
  )     ( –             A B C / D E F * % G / +
  *     ( – *           A B C / D E F * % G / +
  H     ( – *           A B C / D E F * % G / + H
  )                     A B C / D E F * % G / + H * –

*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
char stack[MAX]; /* array stack for symbols */
int top = -1;

/**********************************************************
 * function prototypes
 **********************************************************/

void push(char stack[], char);
char pop(char stack[]);
void ifix2pfix(char source[], char target[]);
int getPriority(char);

/**********************************************************
 * main
 **********************************************************/

int main() {
  char infix[100], postfix[100];
  system("clear");

  /* get infix notation and store it into [char] from stdin */
  printf("Enter any infix expression: ");
  gets(infix);

  // strcpy(postfix, "");  // obsolete line, commented out by me

  ifix2pfix(infix, postfix);
  printf("The corresponding postfix expression is: ");
  puts(postfix);

  return 0;
}

/**********************************************************
 * ifix2pfix
 **********************************************************/

void ifix2pfix(char source[], char target[]) {
  int i = 0, j = 0;
  char temp;

  while (source[i] != '\0') {
    /* meets opening paren */
    if (source[i] == '(') {
      push(stack, source[i]);
      i++;
    }
    /* meets closing paren, do something */
    else if (source[i] == ')') {
      /* pop all things within parenthesis */
      while ((top != -1) && (stack[top] != '(')) {
        target[j] = pop(stack);
        j++;
      }
      /* meets bottom of the stack unexpectedly */
      if (top == -1) {
        printf("incorrect expression");
        exit(1);
      }
      /* pop left paren */
      temp = pop(stack);
      i++;
    }
    /* meets alphanumeric character */
    else if (isdigit(source[i]) || isalpha(source[i])) {
      target[j] = source[i];
      j++;
      i++;
    }
    /* meets operator, check priority */
    else if (source[i] == '+' || source[i] == '-' || source[i] == '*' ||
             source[i] == '/' || source[i] == '%') {
      while ((top != -1) && (stack[top] != '(') &&
             (getPriority(stack[top]) > getPriority(source[i]))) {
        target[j] = pop(stack);
        j++;
      }
      push(stack, source[i]);
      i++;
    }
    /* error condition */
    else {
      printf("incorrect element in expression");
      exit(1);
    }
  }

  /* expression not ended with closing paren */
  while ((top != -1) && (stack[top] != '(')) {
    target[j] = pop(stack);
    j++;
  }

  target[j] = '\0';
}

/**********************************************************
 * getPriority
 **********************************************************/

int getPriority(char op) {
  if (op == '/' || op == '*' || op == '%')
    return 1;
  else if (op == '+' || op == '-')
    return 0;
}

void push(char stack[], char val) {
  if (top == MAX - 1)
    printf("stack overflow");
  else {
    top++;
    stack[top] = val;
  }
}

/**********************************************************
 * pop
 **********************************************************/

char pop(char stack[]) {
  char val = ' ';
  if (top == -1)
    printf("stack underflow");
  else {
    val = stack[top];
    top--;
  }
  return val;
}