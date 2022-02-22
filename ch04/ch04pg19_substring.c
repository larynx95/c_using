/* Data Structures Using C, 2nd, Reema Thareja
Chapter 04. Strings

Programming exercises
19. Write a program to extract the string "od Mo"
from the given string "Good Morning"
*/

#include <stdio.h>
#include <stdlib.h>

void subs(int from, int to, char *str, char *sub);

int main() {
  char str[13] = "Good Morning";
  char sub[13];

  subs(2, 7, str, sub);
  printf("%s\n", sub);

  return 0;
}

void subs(int from, int to, char *str, char *sub) {
  for (int i = from; i < to; i++) {
    *sub++ = *(str + i);
  }
  *sub = '\0';
}