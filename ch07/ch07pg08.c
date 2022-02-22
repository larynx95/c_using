/* Data Structures Using C, 2nd, Reema Thareja
Chapter 07. Stack: LIFO (Last-In-First-Out) data structure

Programming Exercises
8. Write a program to compute Lambda(n) for all positive values of n where
Lambda(n) can be recursively defined as:
  Lambda(n) = Lambda(n/2) + 1 if n > 1
  Lambda(n) = 0 if n = 1

TODO: What does this mean?
  The On-Line Encyclopedia of Integer Sequences® (OEIS®)
  https://oeis.org/
  a(n) = floor(log_2(n))

  0   0
  2   1 1
  4   2 2 2 2
  8   3 3 3 3 3 3 3 3
  16  4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4
    ...
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Lambda(int n) {
  if (n == 1) {
    return 0;
  } else {
    return Lambda(n / 2) + 1;
  }
}

int main() {
  for (int i = 1; i < 100; i++) {
    printf("%d,", Lambda(i));
  }
  return 0;
}
