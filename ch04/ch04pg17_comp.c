/* Data Structures Using C, 2nd, Reema Thareja
Chapter 04. Strings

Programming exercises
17. Write a program to check whether the two given strings "Good Morning" and
"GOOD MORNING" are same.
*/

#include <stdio.h>
#include <stdlib.h>

char char_lower(char);
char *str_lower(char *);
int str_compare(char *, char *);

int main() {
  char astr[13] = "Good Morning";
  char bstr[13] = "GOOD MORNING";

  printf("%d\n", str_compare(astr, bstr));

  return 0;
}

char chr_lower(char ch) {
  if (ch >= 'A' && ch <= 'Z') {
    ch = 'a' + ch - 'A';
  }
  return ch;
}

char *str_lower(char *str) {
  char *ptr = str;
  while (*ptr != '\0') {
    if (*ptr >= 'A' && *ptr <= 'Z') {
      *ptr = 'a' + *ptr - 'A';
    }
    ptr++;
  }
  return str;
}

int str_compare(char *astr, char *bstr) {
  while (*astr != '\0' && chr_lower(*astr) == chr_lower(*bstr)) {
    astr++;
    bstr++;
  }

  if (chr_lower(*astr) == chr_lower(*bstr))
    return 0;
  else if (chr_lower(*astr) > chr_lower(*bstr))
    return 1;
  return -1;
}
