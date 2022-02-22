/* Data Structures Using C, 2nd, Reema Thareja
Chapter 04. Strings

Programming exercises
4. Write a program in C that removes leading and trailing spaces from a string.

# Concepts
  1. Leading space(s): simple
    - leading space(s):     "  abc", "  a bc"

  2. Trailing space(s): not so simple
    - single word:          "abc  ", " abc  "
    - space-separated text: "  abc ", "  a b c  "
*/

#include <stdio.h>
#include <stdlib.h>

void rem_lspc(char *, char *);
int allspc(char *str);
int idx_lst_char(char *);
void rem_tspc(char *, char *);

int main() {
  /* test for rem_lspc fx. */
  char astr[5] = "  ab";
  char aout[5];
  rem_lspc(astr, aout);
  printf("%s\n", aout);

  /* test for idx_lst_char fx. */
  printf("%d\n", idx_lst_char("  "));      // -1
  printf("%d\n", idx_lst_char("a  "));     // 0
  printf("%d\n", idx_lst_char("abc  "));   // 2
  printf("%d\n", idx_lst_char("ab c  "));  // 3

  /* test for rem_tspc fx. */
  char bstr[6] = "ab c ";
  char bout[6];
  rem_tspc(bstr, bout);
  printf("%s", bout);
  printf("|");

  return 0;
}

/* remove leading space(s) */
void rem_lspc(char *str, char *out) {
  while (*str == ' ') str++;
  while (*str != '\0') *out++ = *str++;
}

/* check if the string consists of only space(s) */
int allspc(char *str) {
  while (*str != '\0') {
    if (*str != ' ') return 0;
    str++;
  }
  return 1;
}

/* find the index of the last non-space character
      "abc d  "
  idx  0122444
  cur  0123456
*/
int idx_lst_char(char *str) {
  int idx = 0;
  int cur = 0;

  /* find the index of last non-space character */
  while (*str != '\0') {
    if (*str != ' ') {
      cur++;
      idx = cur;
    } else {
      cur++;
    }
    str++;
  }
  return idx - 1;
}

/* remove trailing space(s) */
void rem_tspc(char *str, char *out) {
  int lst = idx_lst_char(str);
  for (int i = 0; i < lst + 1; i++) {
    *(out + i) = *(str + i);
  }
}

// TODO: Find more elegant code!