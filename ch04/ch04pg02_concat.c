/* Data Structures Using C, 2nd, Reema Thareja
Chapter 04. Strings

Programming exercises
2. Write a program in C to concatenate first n characters of a string with
another string.
*/

#include <stdio.h>
#include <stdlib.h>

void conc_str(int, char *, char *);

int main() {
  char astr[9] = ", world!";
  char bstr[20] = "Hello";
  conc_str(7, astr, bstr);
  printf("%s\n", bstr);

  return 0;
}

void conc_str(int n, char *from, char *target) {
  char *ptr = target;
  while (*ptr != '\0') ptr++;
  for (int i = 0; i < n; i++) {
    *ptr++ = *from++;
  }
  *ptr = '\0';
}