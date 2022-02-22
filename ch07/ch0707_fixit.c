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

float read_float(char *);
double s2d(char *);

int main() {
  char *st = "-123.456";
  printf("%.5g", s2d(st));
  return 0;
}

/**********************************************************
 * read number from string expression
 * - fractional part
 * - floating point
 * - negative number
 * - separated by space
 * ex) -3.0 8.98 5 + *
 * - TODO: check the function in K & R book
 **********************************************************/

double getop(char *exp) {
  char c;

  /* start with space or tab */
  while ((exp[0] = c = getchar()) == ' ' || c == '\t')
    ;

  /* if c is operator */
  if (!isdigit(c) && c != '.') return c;

  return 0.0;
}

/**********************************************************
 * s2f: string to double (from K & R book)
 **********************************************************/

double s2d(char *str) {
  double val, power;
  int i, sign;

  /* skip white space */
  for (i = 0; isspace(str[i]); i++)
    ;

  /* signs of number */
  sign = (str[i] == '-') ? -1 : 1;
  if (str[i] == '+' || str[i] == '-') i++;

  /* string to double */
  for (val = 0.0; isdigit(str[i]); i++) {
    val = 10.0 * val + (str[i] - '0');
  }

  /* decimal point */
  if (str[i] == '.') i++;
  for (power = 1.0; isdigit(str[i]); i++) {
    val = 10.0 * val + (str[i] - '0');
    power *= 10.0;
  }

  return sign * val / power;
}
