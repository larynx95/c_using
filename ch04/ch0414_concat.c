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
Program Example 14.
Write a program to concatenate two strings.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
  char str1[100], str2[100], copy_str[200];
  char *pstr1, *pstr2, *pcopy_str;

  pstr1 = str1;
  pstr2 = str2;
  pcopy_str = copy_str;

  printf("Enter the first string : ");
  gets(str1);
  printf("Enter the second string : ");
  gets(str2);

  while (*pstr1 != '\0') {
    *pcopy_str = *pstr1;
    pcopy_str++, pstr1++;
  }
  while (*pstr2 != '\0') {
    *pcopy_str = *pstr2;
    pcopy_str++, pstr2++;
  }
  *pcopy_str = '\0';

  printf("The concatenated text is : ");
  while (*pcopy_str != '\0') {
    printf("%c", *pcopy_str);
    pcopy_str++;
  }
  return 0;
}
