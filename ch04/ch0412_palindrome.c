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
*/

/*
Program Example 12.
Write a program to find whether a string is a palindrome or not.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
  char str[100];
  int i = 0, j, length = 0;

  printf("Enter the string: ");
  gets(str);

  while (str[i] != '\0') {
    length++;
    i++;
  }
  i = 0;
  j = length - 1;

  while (i <= length / 2) {  // as in reverse() fx.
    if (str[i] == str[j]) {
      i++;
      j--;
    } else
      break;
  }
  if (i >= j)
    printf("PALINDROME");
  else
    printf("NOT A PALINDROME");

  return 0;
}