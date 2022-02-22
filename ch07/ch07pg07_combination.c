/* Data Structures Using C, 2nd, Reema Thareja
Chapter 07. Stack: LIFO (Last-In-First-Out) data structure

Programming Exercises
7. Write a program to compute F(n, r) where F(n,r) can be recursively defined
as: F(n, r) = F(n–1, r) + F(n–1, r–1)

TODO: This exercise needs some more specification.
      There's no base case.
      C(n,k) = {1, if k = 0 or n = k
      C(n-1, k) + C(n-1, k-1) if n>k>0

# Examples
F(2,2) = F(1,2) + F(1,1)
       = F(0,2) + F(0,1) + F(0,1) + F(0,0)
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int combination(int n, int r) {
  if (r == 0 || n == r) {
    return 1;
  } else {
    return combination(n - 1, r) + combination(n - 1, r - 1);
  }
}

int main() {
  printf("combination(3, 2): %d\n", combination(3, 2));
  return 0;
}
