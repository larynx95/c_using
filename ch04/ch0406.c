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
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_substring();

int main() {
  /* get_substring fx. */
  get_substring();

  return 0;
}

void get_substring() {
  char str[100], substr[100];
  int i = 0, j = 0, n, m;

  printf("Enter the main string: ");
  gets(str);
  printf("Enter the position from which to start the substring: ");
  scanf("%d", &m);
  printf("Enter the length of the substring: ");
  scanf("%d", &n);

  i = m;
  while (str[i] != '\0' && n > 0) {
    substr[j] = str[i];
    i++;
    j++;
    n--;
  }
  substr[j] = '\0';

  printf("The substring is: ");
  puts(substr);
}
