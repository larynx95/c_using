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
    Evaluation of a prefix expression (Program example 9)
*/

/*
Programming Example
9. Write a program to evaluate a prefix expression.

# algorithms
    Step 1. Accept the prefix expression
    Step 2. Repeat until all the characters
            in the prefix expression have been scanned
      (a) Scan the prefix expression from right,
          one character at a time.
      (b) If the scanned character is an operand,
          push it on the operand stack.
      (c) If the scanned character is an operator, then
        (i) Pop two values from the operand stack
        (ii) Apply the operator on the popped operands
        (iii) Push the result on the operand stack
    Step 3. End

# Example: + - 9 2 7 * 8 / 4 12
    scanned  stack
    12       12
    4        12, 4
    /        3
    8        3, 8
    *        24
    7        24, 7
    2        24, 7, 2
    -        24, 5
    +        29

*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
