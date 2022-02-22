/* Data Structures Using C, 2nd, Reema Thareja
Chapter 01. Introduction to C

Program Exercise 4.
Write a program to read the address of a user.
Display the result by breaking it in multiple lines.

TODO: address or HTTP?
  https://www.google.com/
  Menlo Park, California, United States

# algorithms
- get a line of string, split it, and print words

*/

#include <stdio.h>
#include <stdlib.h>

#define LEN 10  // max numbers of a word
#define NWS 10  // max numbers of words in a array

int getwds(char *, char out[NWS][LEN]);
int getwds1(char *, char (*)[LEN]);
int getWords(char *base, char target[NWS][LEN]);

int main() {
  /* practice for case 0 ~ 3 */
  char crr[NWS][LEN];
  char *str = "abc def";
  int n = getwds(str, crr);
  printf("%s\n", crr[0]);
  printf("%s\n", crr[1]);

  /* practice for pointer to array of character(s)
     ptr --> "abc"
  */
  char(*ptr)[LEN];
  int m = getwds(str, ptr);
  printf("%s\n", ptr + 1);

  return 0;
}

/* Case 0: 2-D array param */
int getwds(char *str, char out[NWS][LEN]) {
  int n, i, j;
  i = j = n = 0;

  // skip the empty spaces
  while (*str == ' ') str++;

  while (*str != '\0') {
    if (*str != ' ') {
      out[i][j++] = *str;
    } else {
      out[i++][j] = '\0';
      n++;
      j = 0;
    }
    str++;
  }
  return n;
}

/* Case 1: pointer to array param - same as above */
int getwds1(char *str, char (*out)[LEN]) {
  int n, i, j;
  i = j = n = 0;

  // skip the empty spaces
  while (*str == ' ') str++;

  while (*str != '\0') {
    if (*str != ' ') {
      out[i][j++] = *str;
    } else {
      out[i++][j] = '\0';
      n++;
      j = 0;
    }
    str++;
  }
  return n;
}

/* Case 2: other programmer's code
https://www.includehelp.com/code-snippets/c-program-to-split-string-into-the-words-separated-by-spaces.aspx
*/
int getwds2(char *base, char target[NWS][LEN]) {
  int n = 0, i, j = 0;

  while (1) {
    if (base[i] != ' ') {
      target[n][j++] = base[i];
    } else {
      target[n][j++] = '\0';
      n++;
      j = 0;
    }
    if (base[i] == '\0') break;
    i++;
  }
  return n;
}
