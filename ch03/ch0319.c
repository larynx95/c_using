/******************************************************************************
Data Structures Using C, 2nd, Reema Thareja
Chapter 03. Arrays
3.1 Introduction
3.2 Declaration of arrays
3.3 Accessing the elements of an array
  3.3.1 Calculating the address of array elements (Example 3.1)
  3.3.2 Calculating the length of an array (Example 3.2)
3.4 Storing values in arrays
  Initializing arrays during declaration
  Inputting values from the keyboard
  Assigning values to individual elements
3.5 Operations on arrays
  3.5.1 Traversing an array (Program example 1 ~ 6)
  3.5.2 Onserting an element in an array (Example 3.3)
    Algorithm to insert an elem in the middle of an arr (Program example 7 ~ 8)
  3.5.3 Deleting an element from an array (Example 3.4)
    Algorithm to delete an elem from the middle of an array
    (Program example 9 ~ 10)
  3.5.4 Merging two arrays (Program example 11 ~ 12)
3.6 Passing arrays to functions
  3.6.1 Passing individual elements
    Passing data values
    passing addresses
  3.6.2 Passing the entire array (Program example 13 ~ 14)
3.7 Pointers and arrays (Program example 15)
3.8 Arrays of pointers
3.9 Two-dimensional arrays
  3.9.1 Declaring two-dimensional arrays (Example 3.5)
  3.9.2 Initializing two-dimensional arrays
  3.9.3 Accessing the elements of two-dimensional arrays
       (Program example 16 ~ 19)
******************************************************************************/

/*
Prpgram Example 19.
Write a program to read a 2D array marks which stores the marks of five students
in three subjects. Write a program to display the highest marks in each subject.
*/

#include <stdio.h>
#include <stdlib.h>

#define NUM_STDENT 3
#define NUM_CLASS 2

int main() {
  system("clear");

  int marks[NUM_STDENT][NUM_CLASS], i, j, max_marks;
  for (i = 0; i < NUM_STDENT; i++) {
    printf("Enter the marks obtained by student %d\n", i + 1);
    for (j = 0; j < NUM_CLASS; j++) {
      printf("marks[%d][%d] = ", i, j);
      scanf("%d", &marks[i][j]);
    }
  }

  for (j = 0; j < NUM_CLASS; j++) {
    max_marks = -999;
    for (i = 0; i < NUM_STDENT; i++) {
      if (marks[i][j] > max_marks) max_marks = marks[i][j];
    }
    printf("The highest marks obtained in the subject %d = %d\n", j + 1,
           max_marks);
  }

  return 0;
}