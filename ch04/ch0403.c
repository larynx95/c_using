/* Data Structures Using C, 2nd, Reema Thareja
Chapter 04. Strings
4.1 Introduction
  4.1.1 Reading Strings: scanf(), gets(), getchar(), getch(), getche()
  4.1.2 Writing strings
4.2 Operations on strings
  Finding length of a string (Program example 1)
  Converting characters of a string into upper/lower case (Program example 2)
  Appending a string to another string (Program example 3)
*/

/*
Program Example 3.
Write a program to append a string to another string..

*/

#include <stdio.h>
#include <stdlib.h>

int main() {
  char str[100];
  const char added[50];  // constness, not modified
  int i = 0, j = 0;
  system("clear");

  printf("Enter the a original string: ");
  gets(str);

  printf("Enter the a string which will be appended: ");
  gets(added);

  while (str[i] != '\0') i++;
  while (added[j] != '\0') {
    str[i] = added[j];
    i++;
    j++;
  }
  str[i] = '\0';

  printf("After appending, the result string is : ");
  puts(str);

  return 0;
}