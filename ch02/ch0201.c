/******************************************************************************
Data Structures Using C, 2nd, Reema Thareja
Chapter 02. Introduction to Data Structures and Algorithms
2.1 Basic terminology
  2.1.1 Elementary Data Structure Organization
2.2 Classification of data structures
  Primitive and Non-primitive data structures
  Linear and Non-linear structures
  Arrays, Linked Lists, Stacks, Queues, Trees, Graphs
2.3 Operations on data structures
  traversing, searching, inserting, deleting, sorting, merging
2.4 Abstract data type (ADT)
  data type, abstract
  Advantage of using ADTs
2.5 Algorithms
2.6 Different approachs to designing an algorithm
  Top-down, Bottom-up approach
2.7 Control structures used in algorithms
  Sequence, Decision, Repetition (Program example 1 ~ 5)
2.8 Time and space complexity
  2.8.1 Worst-case, Average-case, Best-case, and Amortized time complexity
    Worst-case/Average-case/Best-case/Amortized running time
  2.8.2 Time-space trade-off
  2.8.3 Expressing time and space complexity
  2.8.4 Algorithm efficiency
    Linear loops
    Logarithmic loops
    Nested loops
      Linear logarithmic loop
      quadratic loop
      dependent quadratic loop
2.9 Big O notation
  Categories of algorithms (Example 1 ~ 4)
  Limitations of Big O notation
2.10 Omega notation (Example 5 ~ 6)
2.11 Theta notation (Example 7)
2.12 Other useful notations
  Little O notation (Example 8)
  Little Omega Notation (Example 9)
******************************************************************************/

/*
Programming Example 1.
Write an algorithm for swapping two values.

Answer:
  Step 1: Input first number as A
  Step 2: Input second number as B
  Step 3: SET TEMP = A
  Step 4: SET A = B
  Step 5: SET B = TEMP
  Step 6: PRINT A, B
  Step 7: END
*/

#include <stdio.h>
#include <stdlib.h>

void swap_ints(int *, int *);
void swap_ints1(int *, int *);
void swap_strings(char *, char *);
void swap_strings1(char **, char **);

int main() {
  /* swap two integers */
  int a, b;
  a = 10;
  b = 20;
  swap_ints(&a, &b);
  printf("a: %d, b: %d\n", a, b);  // a:10, b: 20
  swap_ints1(&a, &b);
  printf("a: %d, b: %d\n", a, b);  // a: 20, b: 10

  /* swap two strings */
  char *str1 = "geeks";
  char *str2 = "forgeeks";
  swap_strings(str1, str2);
  printf("str1: %s, str2: %s\n", str1, str2);  // not working
  swap_strings1(&str1, &str2);
  printf("str1: %s, str2: %s\n", str1, str2);

  return 0;
}

/* not working */
void swap_ints(int *a, int *b) {
  int *temp = b;
  b = a;
  a = temp;
}

void swap_ints1(int *a, int *b) {
  int temp = *b;
  *b = *a;
  *a = temp;
}

/* not working */
void swap_strings(char *st1, char *st2) {
  char *temp = st1;
  st1 = st2;
  st2 = temp;
}

void swap_strings1(char **sp1, char **sp2) {
  char *temp = *sp1;
  *sp1 = *sp2;
  *sp2 = temp;
}