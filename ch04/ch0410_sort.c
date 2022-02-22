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
Program Example 10.
Write a program to sort the names of students.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char names[5][10], temp[10];
  int i, n, j;
  printf("Enter the number of students: ");
  scanf("%d", &n);
  getchar();

  for (i = 0; i < n; i++) {
    printf("Enter the name of student %d: ", i + 1);
    gets(names[i]);
  }

  // TODO: inefficient sorting
  for (i = 0; i < n; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (strcmp(names[j], names[j + 1]) > 0) {
        strcpy(temp, names[j]);
        strcpy(names[j], names[j + 1]);
        strcpy(names[j + 1], temp);
      }
    }
  }

  printf("Names of the students in alphabetical order are : \n");
  for (i = 0; i < n; i++) puts(names[i]);

  return 0;
}

/*
* TODO: gets() after scanf()
  scanf() leaves the new line char in the buffer
  https://stackoverflow.com/questions/5240789/scanf-leaves-the-new-line-char-in-the-buffer

* TODO: sorting algorithms
*/