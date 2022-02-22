/* Data Structures Using C, 2nd, Reema Thareja
Chapter 04. Strings

Programming exercises
25. Write a program to read a line until a newline is entered.

# My Plan
- special character `\n`
- regular expression: `%[^\n]s`
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
  char str[100];
  printf("Enter a string: ");
  gets(str);
  printf("string: %s\n", str);

  return 0;
}
