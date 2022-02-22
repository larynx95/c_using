/* Data Structures Using C, 2nd, Reema Thareja
Chapter 04. Strings

Programming exercises
29. Write a program to insert a new name in the string array STUD[][],
assuming that names are sorted alphabetically.

# My Plan
1. Create a 2D character array
2. Sorting algorithms
  1)
    index: 0 1 2 3 4 5
    elem:  4 2 3 7 0 8
    find:  0 -> 2 -> 3 -> 4 -> 7 -> 8
  2) quick sort
  3) binary tree
              4
             / \
            2   7
           / \   \
          0  3    8
TODO:
  - 2D character array with pointer
  - binary tree sort
  - function pointer
  - queue, heap sort
*/

#include <stdio.h>
#include <stdlib.h>

#define ROWS 2
#define COLS 10

void print_names(char std[ROWS][COLS]);
int comp_strs(char *atr, char *btr);
void sort_names(char std[ROWS][COLS]);

int main() {
  char std[2][10];  // two names, the length of name less than 9 characters
  for (int i = 0; i < 2; i++) {
    printf("Enter student's name: ");
    scanf("%s", std[i]);
  }

  print_names(std);
  printf("%d\n", comp_strs(std[0], std[1]));

  return 0;
}

/* print names */
void print_names(char std[ROWS][COLS]) {
  for (int i = 0; i < ROWS; i++) {
    printf("Student %d. - %s\n", i, std[i]);
  }
}

/* compare strings */
int comp_strs(char *atr, char *btr) {
  /* get size of each string */
  int sz_a = 0, sz_b = 0;
  char *ptr = atr;
  while (*ptr++ != '\0') sz_a++;
  ptr = btr;
  while (*ptr++ != '\0') sz_b++;

  /* compare */
  if (sz_a <= sz_b) {
    while (*btr != '\0') {
      if (*btr != *atr) return *btr++ - *atr++;
    }
  } else {
    while (*atr != '\0') {
      if (*btr != *atr) return *btr++ - *atr++;
    }
  }
}

/* TODO: sort names */
void sort_names(char std[ROWS][COLS]) {
  for (int i = 0; i < ROWS; i++) {
    // ...
  }
}