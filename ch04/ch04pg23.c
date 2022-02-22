/* Data Structures Using C, 2nd, Reema Thareja
Chapter 04. Strings

Programming exercises
23. Write a program to rewrite the string "Good Morning" to "Good Evening"
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
  char target[] = "Good Morning";
  char eve[] = "Evening";

  for (int i = 5, j = 0; i < sizeof(target) / sizeof(char); i++, j++) {
    target[i] = eve[j];
  }

  printf("%s\n", target);

  return 0;
}
