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
  deleting a substring from the main string (Program example 8)
*/

/*
Program Example 8.
Write a program to delete a substring from a text.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char text[200], str[20], new_str[200];
  int i = 0, j = 0, found = 0, k, n = 0, copy_loop = 0;
  system("clear");

  printf("Enter the main text: ");
  gets(text);
  printf("Enter the string to be deleted: ");
  gets(str);

  while (text[i] != '\0') {
    j = 0, found = 0, k = i;
    while (text[k] == str[j] && str[j] != '\0') {
      k++;
      j++;
    }
    if (str[j] == '\0') copy_loop = k;
    new_str[n] = text[copy_loop];
    i++;
    copy_loop++;
    n++;
  }
  new_str[n] = '\0';

  printf("The new string is: ");
  puts(new_str);

  return 0;
}