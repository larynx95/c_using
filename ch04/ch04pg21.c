/* Data Structures Using C, 2nd, Reema Thareja
Chapter 04. Strings

Programming exercises
21. Write a program to read a text, delete all the semicolons it has,
and finally replace all '.' with a ','.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
  char str[18] = "sample;;;...  ...";
  char *ptr = str;

  while (*ptr != '\0') {
    if (*ptr == ';')
      *ptr = ' ';
    else if (*ptr == '.')
      *ptr = ',';
    ptr++;
  }

  printf("%s\n", str);

  return 0;
}
