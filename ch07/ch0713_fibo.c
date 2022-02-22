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
    Greatest common divisor (Program example 11)
    Find exponents (Program example 12)
    The fibonacci series (Program exampe 13)
    Types of recursion
      Direct recursion
      Indirect recursion
      Tail recursion
      Converting recursive functions to tail recursive
        Linear and tree recursion
    Tower of Hanoi
    Recursion vs. iteration
*/

/*
Programming Example
13. Write a program to print the Fibonacci series using recursion.

# Types of recursion
1. direct or indirect
   ; whether the function calls itself directly or indirectly

   ```c
   // direct recursion
   int Func (int n) {
     if (n == 0) return n;
     else return (Func (n-1));
   }

   // indirect recursion
   int Func1 (int n) {
     if(n == 0) return n;
     else return Func2(n);
   }

   int Func2 (int x) {
     return Func1(x-1);
   }
   ```
2. tail or not
   ; whether any operation is pending at each recursive call

   ```c
   // not tail recursion
   int Fact(int n) {
     if(n == 1) return 1;
     else return (n * Fact (n-1));
   }

   // tail recursion
   int Fact(n) {
     return Fact1(n, 1);
   }

   int Fact1(int n, int res) {
     if(n == 1) return res;
     else return Fact1(n-1, n*res);
   }
   ```
3. linear or tree-recursion
   ; the structure of the calling pattern

*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Fibonacci(int);

int main() {
  int n, i = 0, res;
  printf("Enter the number of terms\n");
  scanf("%d", &n);
  printf("Fibonacci series\n");
  for (i = 0; i < n; i++) {
    res = Fibonacci(i);
    printf("%d\t", res);
  }
  return 0;
}

int Fibonacci(int n) {
  if (n == 0)
    return 0;
  else if (n == 1)
    return 1;
  else
    return (Fibonacci(n - 1) + Fibonacci(n - 2));
}