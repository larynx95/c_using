/* Data Structures Using C, 2nd, Reema Thareja
Chapter 04. Strings

Programming exercises
1. Write a program in which a string is passed as an argument to a function.

TODO: Array vs. Pointer
- When pass as an argument to a function,
  array is converted to a local pointer variable.
  (without any info of its length!)
*/

#include <stdio.h>
#include <stdlib.h>

int count(char *);
int count_rec(char *);

int main() {
  char *astr = "abc";
  printf("count: %d\n", count(astr));
  printf("count: %d\n", count_rec(astr));

  return 0;
}

int count(char *str) {
  int nc = 0;
  while (*str++) nc++;
  return nc;
}

int count_rec(char *str) {
  if (*str == '\0') return 0;
  return 1 + count_rec(str + 1);
}