/* Data Structures Using C, 2nd, Reema Thareja
Chapter 07. Stack: LIFO (Last-In-First-Out) data structure

Programming Exercises
9. Write a program to compute F(M, N) where F(M,N) can be recursively defined
as:
F(M,N) = 1 if M=0 or M≥N≥1 and
F(M,N) = F(M–1,N) + F(M–1, N–1) , otherwise

TODO: What does this code mean?
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int F(int m, int n) {
  if (m == 0 || (m >= n && n >= 1)) {
    return 1;
  } else {
    return F(m - 1, n) + F(m - 1, n - 1);
  }
}

int main() {
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
      printf("m: %d, n: %d, F(m,n): %d\n", i, j, F(i, j));
    }
    printf("\n");
  }
  return 0;
}
