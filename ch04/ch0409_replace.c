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
*/

/*
Program Example 9.
Write a program to replace a pattern with another pattern in the text.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char str[200], pat[20], new_str[200], rep_pat[100];
  int i = 0, j = 0, k, n = 0, copy_loop = 0, rep_index = 0;
  system("clear");

  printf("Enter the string: ");
  gets(str);
  printf("Enter the pattern to be replaced: ");
  gets(pat);
  printf("Enter the replacing pattern: ");
  gets(rep_pat);

  while (str[i] != '\0') {
    j = 0, k = i;
    while (str[k] == pat[j] && pat[j] != '\0') {
      k++;
      j++;
    }
    if (pat[j] == '\0') {
      copy_loop = k;
      while (rep_pat[rep_index] != '\0') {
        new_str[n] = rep_pat[rep_index];
        rep_index++;
        n++;
      }
    }
    new_str[n] = str[copy_loop];
    i++;
    copy_loop++;
    n++;
  }
  new_str[n] = '\0';

  printf("The new string is: ");
  puts(new_str);

  return 0;
}