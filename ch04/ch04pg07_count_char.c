/* Data Structures Using C, 2nd, Reema Thareja
Chapter 04. Strings

Programming exercises
7. Write a program to count the total number of
occurrences of a given character in the string.
*/

#include <stdio.h>
#include <stdlib.h>

int cnt_char(char ch, char *);

int main() {
  char str[50];
  printf("Enter a string: ");
  gets(str);

  printf("%d\n", cnt_char('a', str));

  return 0;
}

int cnt_char(char ch, char *str) {
  int total = 0;
  while (*str != '\0') {
    if (*str == ch) total++;
    str++;
  }
  return total;
}