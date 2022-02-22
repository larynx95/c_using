/* Data Structures Using C, 2nd, Reema Thareja
Chapter 04. Strings

Programming exercises
5. Write a program in C that replaces a given character with another character
in a string.
*/

#include <stdio.h>
#include <stdlib.h>

void replace_char(char, char, char *, char *);

int main() {
  char str[10], out[10];
  printf("Enter the string: ");
  gets(str);

  replace_char('a', 'z', str, out);
  printf("%s\n", out);

  return 0;
}

void replace_char(char tg, char ch, char *str, char *out) {
  while (*str != '\0') {
    if (*str == tg) {
      *out = ch;
    } else {
      *out = *str;
    }
    str++;
    out++;
  }
  *out = '\0';
}