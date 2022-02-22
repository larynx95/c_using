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
  Pattern matching
  Deleting a substring from the main string (Program example 8)
  Replacing a pattern with another pattern in a string (Program example 9)
4.3 Arrays of strings (Program example 10 ~ 12)
4.4 Pointers and strings (Program example 13 ~ 14)
*/

/*
Program Example 13.
Write a program to copy a string into another string.
*/

#include <stdio.h>
#include <stdlib.h>

void cpy_str(const char *, char *);

int main() {
  const char *astr = "abcdef";
  int sz = sizeof(astr) / sizeof(char);
  char bstr[sz];
  cpy_str(astr, bstr);
  printf("copied string is %s\n", bstr);

  return 0;
}

void cpy_str(const char *orig, char *copied) {
  while (*orig) *copied++ = *orig++;
}