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
*/

/*
Program Example 4.
Write a program to compare two strings.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char str1[50], str2[50];
  int i = 0, len1 = 0, len2 = 0, same = 0;
  system("clear");

  printf("Enter the first string: ");
  gets(str1);
  printf("Enter the second string: ");
  gets(str2);

  /* string compare by index */
  len1 = strlen(str1);
  len2 = strlen(str2);
  if (len1 == len2) {
    while (i < len1) {
      if (str1[i] == str2[i])
        i++;
      else
        break;
    }
    if (i == len1) {
      same = 1;
      printf("The two strings are equal\n");
    }
  }

  if (len1 != len2) printf("The two strings are not equal\n");
  if (same == 0) {
    if (str1[i] > str2[i])
      printf("String 1 is greater than string 2\n");
    else if (str1[i] < str2[i])
      printf("String 2 is greater than string 1\n");
  }

  /* string compare by strcmp() fx.
  < 0 : the first mismatching character of str1 is lower than str2
  0   : same string
  > 0 : the first mismatching character of str1 is greater than str2
  */
  printf("Compare result: %d\n", strcmp(str1, str2));

  return 0;
}