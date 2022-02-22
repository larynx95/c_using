/* Data Structures Using C, 2nd, Reema Thareja
Chapter 04. Strings
4.1 Introduction
  4.1.1 Reading Strings: scanf(), gets(), getchar(), getch(), getche()
  4.1.2 Writing strings
4.2 Operations on strings
  Finding length of a string (Program example 1)
  Converting characters of a string into upper/lower case (Program example 2)
*/

/*
Program Example 2.
Write a program to convert the lower case characters of a string
into upper case.

# Concepts
  character  ASCII
  'a'        97   == 'A' + 32
  'z'        122  == 'Z' + 32
  'A'        65   == 'a' - 32
  'Z'        90   == 'z' - 32

  upper = 'A' + ch - 'a'
        = ch + 'A' - 'a'
        = ch - 32

  lower = 'a' + ch - 'A"
        = ch + 'a' - 'A"
        = ch + 32

TODO: Why is the `gets` function so dangerous?
*/

#include <stdio.h>
#include <stdlib.h>

char chr_to_upper(char lower) { return 'A' + lower - 'a'; }

int main() {
  /* imperative solution */
  char str[100], upper_str[100];
  int i = 0;
  system("clear");

  printf("Enter the string :");
  gets(str);

  while (str[i] != '\0') {
    if (str[i] >= 'a' && str[i] <= 'z')
      upper_str[i] = str[i] - 32;
    else
      upper_str[i] = str[i];
    i++;
  }
  upper_str[i] = '\0';
  printf("The string converted into upper case is : ");

  puts(upper_str);

  return 0;
}