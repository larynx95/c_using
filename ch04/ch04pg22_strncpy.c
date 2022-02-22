/* Data Structures Using C, 2nd, Reema Thareja
Chapter 04. Strings

Programming exercises
22. Write a program to copy the last n characters of a character array in
another character array. Also, convert the lower case letters into upper case
letters while copying.

# My Plan
             012345
  string A: "abcdef"   sz = 6
                ***
                345    sz-n .. sz-1
  int n: 3
  substring to be copied: "def"
  target string: "target "
  result: "target def"

# strncpy
https://en.cppreference.com/w/c/string/byte/strncpy
*/

#include <stdio.h>
#include <stdlib.h>

void cpystr(int n, char *target, char *origin) {
  int sz = 0;
  char *ptr = origin;
  while (*ptr++ != '\0') sz++;
  ptr = origin;
  ptr = ptr + sz - n;

  char *qtr = target;
  while (*qtr != '\0') qtr++;

  while (*ptr != '\0') {
    *qtr++ = *ptr++;
  }
  *qtr = '\0';
}

int main() {
  char target[20] = "hello";
  char origin[6] = "12345";

  cpystr(3, target, origin);
  printf("%s\n", target);

  return 0;
}
