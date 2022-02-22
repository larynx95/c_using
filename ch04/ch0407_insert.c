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
*/

/*
Program Example 7.
Write a program to insert a string in the main text.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ins_str();

int main() {
  /* ins_str fx. */
  ins_str();

  return 0;
}

void ins_str() {
  char text[100], str[20], ins_text[100];
  int i = 0, j = 0, k = 0, pos;
  system("clear");

  printf("Enter the main text: ");
  gets(text);
  printf("Enter the string to be inserted: ");
  gets(str);
  printf("Enter the position at which the string has to be inserted: ");
  scanf("%d", &pos);

  while (text[i] != '\0') {
    if (i == pos) {
      while (str[k] != '\0') {
        ins_text[j] = str[k];
        j++;
        k++;
      }
    } else {
      ins_text[j] = text[i];
      j++;
    }
    i++;
  }
  ins_text[j] = '\0';

  printf("The new string is: ");
  puts(ins_text);
}