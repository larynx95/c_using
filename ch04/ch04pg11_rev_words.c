/* Data Structures Using C, 2nd, Reema Thareja
Chapter 04. Strings

Programming exercises
11. Write a program to input an array of strings.
Then, reverse the string in the format shown below.
"HAPPY BIRTHDAY TO YOU" should be displayed as "YOU TO BIRTHDAY HAPPY"

# Helpful Sites
https://www.tutorialgateway.org/c-program-to-reverse-order-of-words-in-a-string/
https://codeforwin.org/2016/10/c-program-to-reverse-order-of-words-in-string.html

# My Plan
1. left to right
  sz: 22 (not inlcuding null terminator)
  string:   "HAPPY BIRTHDAY TO   YOU"  start  end
  index:     01234567890123456789012
  idx_word:  01234 01234567 01   012
            "                  HAPPY"  18     22
            "         BIRTHDAY HAPPY"   9     16
            "      TO BIRTHDAY HAPPY"   6      7
            "YOU   TO BIRTHDAY HAPPY"   0      2
2. right to left
  reverse:  "UOY   OT YADHTRIB YPPAH"
  reverse each word
*/

#include <stdio.h>
#include <string.h>

/* function for reversing a word (for warming up) */
void rev_str(char* str, char* out) {
  /* get the length of string, not including null terminator */
  int sz = 0;
  char* ptr = str;
  /* New pointer variable is required for tracing properly. */
  /* If you don't use the new pointer variable, your code will be messed up. */
  while (*ptr++ != '\0') sz++;
  /* reverse a word */
  for (int i = sz - 1; i >= 0; i--) out[sz - 1 - i] = str[i];
  /* add null terminator at the end of output word */
  out[sz] = '\0';
}

/* reverse whole string */
void rev_str2(char* str) {
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

  rev_str2(str);
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

int main() {
  char str[24] = "HAPPY BIRTHDAY TO   YOU";
  rev_seq(str);
  printf("%s\n", str);

  return 0;
}