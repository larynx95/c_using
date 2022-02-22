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
*/

/*
Program Example 6.
Write a program to extract a substring from the middle of a given string.

TODO: Use pointer arithmetic
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void substr_void(int, int, char *, char *);
void substr_void1(int, int, char *, char *);
void substr_void2(int, int, char *, char *);

int main() {
  char str[10] = "abcdef";
  char substr[10];
  int start = 1;
  int len = 2;

  substr_void2(start, len, str, substr);

  return 0;
}

void substr_void(int start, int len, char *str, char *sub) {
  int i = 0, j = 0;

  i = start;
  while (str[i] != '\0' && len > 0) {
    sub[j] = str[i];
    i++;
    j++;
    len--;
  }
  sub[j] = '\0';

  printf("The substring is: ");
  printf("%s", sub);
}

void substr_void1(int start, int len, char *str, char *sub) {
  char *ptr = str + start;
  for (int i = 0; i < len; i++) {
    printf("%c", *ptr++);
  }
  *ptr = '\0';
}

void substr_void2(int start, int len, char *str, char *sub) {
  char *ptr = str + start;
  while (*ptr && len > 0) {
    printf("%c", *ptr++);
    len--;
  }
  *ptr = '\0';
}