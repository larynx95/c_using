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
Prpgram Example 16.
Write a program to print the elements of a 2D array.

TODO:
- 1D representation of 2D array
- difference bw Char and Int array in pointer arithmetics
  null terminator in Char array
*/

#include <stdio.h>

void print_2iarr1(int rows, int cols, int[rows][cols]);
void print_2iarr2(int rows, int cols, int[rows][cols]);

int main() {
  int arr[2][2] = {12, 34, 56, 32};

  print_2iarr2(2, 2, arr);

  return 0;
}

void print_2iarr1(int rows, int cols, int arr[rows][cols]) {
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++) printf("%d ", arr[i][j]);
}

void print_2iarr2(int rows, int cols, int arr[rows][cols]) {
  for (int *ptr = &arr[0][0]; ptr <= &arr[rows - 1][cols - 1]; ptr++)
    printf("%d ", *ptr);
}