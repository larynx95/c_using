/* Data Structures Using C, 2nd, Reema Thareja
Chapter 04. Strings

Programming exercises
12. Write a program to append a given string in the following format.
"GOOD MORNING MORNING GOOD"
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rev_str(char* str);
void rev_subs(int fst, int lst, char* str);
void rev_seq(char* str);
void rev_append(char* str);

int main() {
  char out[27];
  char str[13] = "GOOD MORNING";
  strcpy(out, str);
  rev_seq(str);
  strcat(out, " ");
  strcat(out, str);
  printf("%s\n", out);

  return 0;
}

/* reverse whole string */
void rev_str(char* str) {
  int sz = 0;
  char* ptr = str;
  while (*ptr++ != '\0') sz++;

  for (int i = 0; i < sz / 2; i++) {
    char temp = str[i];
    str[i] = str[sz - i - 1];
    str[sz - i - 1] = temp;
  }
}

/* reverse str[fst:lst] */
void rev_subs(int fst, int lst, char* str) {
  for (int i = 0; i < (lst - fst) / 2; i++) {
    char temp = str[fst + i];
    str[fst + i] = str[lst - i - 1];
    str[lst - i - 1] = temp;
  }
}

/* reverse order of words */
void rev_seq(char* str) {
  int sz = 0;
  char* ptr = str;
  while (*ptr++ != '\0') sz++;

  rev_str(str);
  ptr = str;
  int idx = 0;  // index of string
  int fst = 0;  // index of the first character of a word
  int lst = 0;  // index of the last character of a word

  while (*ptr != '\0') {
    if (*ptr == ' ') {
      ptr++;
      idx++;
    } else {
      fst = idx;
      while (*ptr != '\0' && *ptr != ' ') {
        idx++;
        ptr++;
      }
      lst = idx;
      rev_subs(fst, lst, str);
    }
  }
}

void rev_append(char* str) {}
