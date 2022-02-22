/* Data Structures Using C, 2nd, Reema Thareja
Chapter 04. Strings

Programming exercises
3. Write a program in C that compares first n characters of one string
with first n characters of another string.

<string.h> strcomp fx.
-1: s2 is greater ASCII code than s1
0: s1 and s2 have the same ASCII code
1: s1 is greater ASCII code than s2
*/

#include <stdio.h>
#include <stdlib.h>

int comp_strs(int, char*, char*);

int main() {
  printf("%d \n", comp_strs(2, "abcd", "abcd"));
  printf("%d \n", comp_strs(2, "abcd", "aacd"));
  printf("%d \n", comp_strs(2, "abcd", "accd"));

  return 0;
}

int comp_strs(int num, char* atr, char* btr) {
  int idx;
  for (int i = 0; i < num; i++) {
    if (*(atr + i) != *(btr + i)) {
      idx = i;
      break;
    }
  }
  return *(atr + idx) - *(btr + idx);
}