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
Program Example 11.
Write a program to read multiple lines of text and
then count the number of characters, words, and lines in the text.
*/

#include <stdio.h>

int main() {
  char str[1000];
  int i = 0, word_count = 1, line_count = 1, char_count = 1;
  printf("\n Enter a '*' to end");
  printf("\n **************");
  printf("\n Enter the text : ");
  scanf("%c", &str[i]);
  while (str[i] != '*') {
    i++;
    scanf("%c", &str[i]);
  }
  str[i] = '\0';
  i = 0;
  while (str[i] != '\0') {
    if (str[i] == '\n' || i == 79) line_count++;
    if (str[i] == ' ' && str[i + 1] != ' ') word_count++;
    char_count++;
    i++;
  }
  printf("\n The total count of words is : %d", word_count);
  printf("\n The total count of lines is : %d", line_count);
  printf("\n The total count of characters is : %d", char_count);
  return 0;
}
