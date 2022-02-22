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
*/

/*
Programming Example
7. Write a program to evaluate a postfix expression.

# Algorithm
  Step 1. Add a ")" at the end of the postfix expression
  Step 2. Scan every character of the postfix expression and repeat
          Step 3 and 4 until ")" encountered
  Step 3. If an operand is encountered,
          push it on the stack
          If an operator X is encountered, then
          a. Pop the top elements from the stack as A and B as A and B
          b. Evaluate B X A, where A is the topmost element and
            B is the element below A.
          c. Push the result of evaluation on the stack
          [END of IF]
  Step 4. Set result equal to the topmost element of the stack
  Step 5. Exit

  character stack       explanation
  --------------------------------
  9         9           digit -> push
  3         9, 3        digit -> push
  4         9, 3, 4     digit -> push
  *         9, 12       op    -> pop <op> pop
  8         9, 12, 8    digit -> push
  +         9, 20       op    -> pop <op> pop
  4         9, 20, 4    digit -> push
  /         9, 5        op    -> pop2 <op> pop1
  -         4           op    -> pop2 <op> pop1
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
float st[MAX];
int top = -1;

/**********************************************************
 * function prototypes
 **********************************************************/

void push(float st[], float val);
float pop(float st[]);
float evaluatePostfixExp(char exp[]);

/**********************************************************
 * main functions
 **********************************************************/

int main() {
  float val;
  char exp[100];  // TODO: Is this correct?
  system("clear");

  printf("Enter any postfix expression: ");
  gets(exp);
  // TODO: array exp is string, character array
  //       it can contain space, tab ...

  val = evaluatePostfixExp(exp);
  printf("Value of the postfix expression = %.2f", val);

  return 0;
}

/**********************************************************
 * evaluatePostfixExp
 * 1. digit vs. operator
 * 2. simpler than notation conversion
 * TODO: This function has many limitations
 *  - It does not allow space.
 *  - It does not allow a number greater than 9
 *  - It does not allow floating point number
 *  - It does not allow negative number
 * ex) 45+    ==> 9.00
 *     4 5 +  ==> error
 **********************************************************/

float evaluatePostfixExp(char exp[]) {
  int i = 0;
  float op1, op2, value;

  while (exp[i] != '\0') {
    /* if integer number */
    if (isdigit(exp[i])) {
      push(st, (float)(exp[i] - '0'));
    } else {
      op2 = pop(st);
      op1 = pop(st);
      switch (exp[i]) {
        case '+':
          value = op1 + op2;
          break;
        case '-':
          value = op1 - op2;
          break;
        case '/':
          value = op1 / op2;
          break;
        case '*':
          value = op1 * op2;
          break;
        case '%':
          value = (int)op1 % (int)op2;
          break;
      }
      push(st, value);
    }
    i++;
  }
  return (pop(st));
}

/**********************************************************
 * push
 **********************************************************/

void push(float st[], float val) {
  if (top == MAX - 1)
    printf("STACK OVERFLOW");
  else {
    top++;
    st[top] = val;
  }
}

/**********************************************************
 * pop
 **********************************************************/

float pop(float st[]) {
  float val = -1;
  if (top == -1)
    printf("STACK UNDERFLOW");
  else {
    val = st[top];
    top--;
  }
  return val;
}