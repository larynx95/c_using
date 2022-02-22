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
  7.7.4 Recursion (Program example 10)
*/

/*
Programming Example
10. Write a program to calculate the factorial of a given number.

# reference
- What is tail recursion?
  https://stackoverflow.com/questions/33923/what-is-tail-recursion
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Fact(int);  // function declaration
int Fact_tail(int n, int fact);

int main() {
  int num, val;
  printf("Enter the number: ");
  scanf("%d", &num);
  val = Fact_tail(num, 1);
  printf("Factorial of %d = %d\n", num, val);
  return 0;
}

/*
f(3) = 3 * f(2)
     = 3 * 2 * f(1)
     = 3 * 2 * 1
     = 6
*/
int Fact(int n) {
  if (n == 1)
    return 1;
  else
    return (n * Fact(n - 1));
}

/*
f(3, 1) = f(2, 3 * 1)
        = f(1, 2 * 3 * 1)
        = 6
*/
int Fact_tail(int n, int fact) {
  if (n == 1)
    return fact;
  else
    Fact_tail(n - 1, n * fact);
}