/* Data Structures Using C, 2nd, Reema Thareja
Chapter 04. Strings
4.1 Introduction
  4.1.1 Reading Strings: scanf(), gets(), getchar(), getch(), getche()
  4.1.2 Writing strings
4.2 Operations on strings
  Finding length of a string (Program example 1)
  Converting characters of a string into upper/lower case (Program example 2)
  Appending a string to another string (Program example 3)
  Comparing two strings (Program example 4)
  Reversing a string (Program example 5)
  Extracting a substring from a string (Program example 6)
  Inserting a string in the main string (Program example 7)
*/

/*
Program Example 7.
Write a program to insert a string in the main text.

TODO: Be careful not to insert null character between valid characters.

    char str[4] = "abc";
    char txt[4] = "def";
    char res[7];

    prepend:
    index   0   1   2   3   4   5   6
          'a' 'b' 'c' '\0'
                      'd' 'e' 'f' '\0'

    append:
    index   0   1   2   3   4   5   6
          'd' 'e' 'f' '\0'
                      'a' 'b' 'c' '\0'

    insert:     *
    index   0   1   2   3   4   5   6
          'd'             'e' 'f' '\0'
              'a' 'b' 'c' '\0'

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN_STR 10
#define LEN_TXT 10

char* read_str(int sz, char* str);
void prepend(char*, char*, char*);
void append(char*, char*, char*);
void insert(int, int, int, char*, char*, char*);

int main() {
  char astr[4] = "abc";
  char bstr[4] = "def";

  /* char cstr[7];
  prepend(astr, bstr, cstr);
  printf("prepened: %s\n", cstr); */

  /* char dstr[7];
  append(astr, bstr, dstr);
  printf("appended: %s\n", dstr); */

  char estr[7];
  insert(1, 4, 4, astr, bstr, estr);
  printf("inserted: %s\n", estr);

  return 0;
}

/* get empty char array, and return string as a result */
char* read_str(int sz, char* str) {
  char c;
  int i = 0;
  printf("Enter a string (not more than %d characters): ", sz);
  while ((c = getchar()) != EOF && c != '\0' && c != '\n') {
    if (sz <= 0) {
      printf("You've entered more than %d characters. EXIT_FAILURE.", sz);
      exit(EXIT_FAILURE);
    }
    *str++ = c;
    sz--;
    i++;
  }
  printf("You have entered this string: %s (%d characters)\n", str - i, i);
  return str - i;
}

void prepend(char* str, char* txt, char* res) {
  while (*str) *res++ = *str++;
  while (*txt) *res++ = *txt++;
}

void append(char* str, char* txt, char* res) {
  while (*txt) *res++ = *txt++;
  while (*str) *res++ = *str++;
}

void insert(int pos, int slen, int tlen, char* str, char* txt, char* res) {
  if (pos == 0)
    prepend(str, txt, res);
  else if (pos == tlen - 1)
    append(str, txt, res);
  else {
    int i, j, k;
    i = j = k = 0;
    while (k < pos) res[k++] = txt[i++];
    while (k < pos + slen - 1) res[k++] = str[j++];
    while (k < slen + tlen - 1) res[k++] = txt[i++];
  }
}

// TODO: use pointer arithmetic