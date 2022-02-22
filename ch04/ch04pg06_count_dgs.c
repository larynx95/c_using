/* Data Structures Using C, 2nd, Reema Thareja
Chapter 04. Strings

Programming exercises
6. Write a program to count the number of digits,
upper case characters, lower case characters, and
special characters in a given string.
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  int dgs, ups, lws, sps;
  dgs = ups = lws = sps = 0;
  char arr[10];
  char *str = &arr[0];
  printf("Enter string: ");
  gets(str);

  while (*str != '\0') {
    if (isdigit(*str)) {
      dgs++;
    } else if (*str >= 'a' && *str <= 'z') {
      lws++;
    } else if (*str >= 'A' && *str <= 'Z') {
      ups++;
    } else {
      sps++;
    }
    str++;
  }

  printf("digits: %d\nupper: %d\nlower: %d\nspec: %d\n", dgs, ups, lws, sps);

  return 0;
}
