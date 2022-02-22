/* Data Structures Using C, 2nd, Reema Thareja
Chapter 04. Strings

Programming exercises
10. Write a program to find the last instance (index?) of occurrence of a
sub-string within a string.
*/

#include <stdio.h>
#include <stdlib.h>

/*
sub:    "abc"
string: "abc  ab  cd  abcd  "
idx:     0123456789012345678
fst:     0    5       3
lst    -10            3
*/
int lst_idx(char *sub, char *str) {
  int idx = 0;
  int fst = 0;
  int lst = -1;
  while (*str != '\0') {
    if (*sub == *str) {
      char *ptr = sub;
      fst = idx;
      while (*ptr != '\0') {
        if (*ptr != *str) break;
        *ptr++;
        str++;
        idx++;
      }
      if (*ptr == '\0') {
        lst = fst;
      }
    } else {
      str++;
      idx++;
    }
  }

  return lst;
}

int main() {
  printf("%d\n", lst_idx("abc", "abc cd ef ab f abc "));  // 15
  printf("%d\n", lst_idx("abc", "abc cd ef ab f a "));    // 0
  printf("%d\n", lst_idx("abc", "abc cd abcd ab f "));    // 7

  return 0;
}
