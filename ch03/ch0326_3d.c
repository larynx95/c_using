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
3.10 Operations on two-dimensional arrays
  Transpose, Sum, Difference, Product (Program example 20 ~ 23)
3.11 Passing two-dimensional arrays to functions
  Passing a row
  Passing the entire 2D array (Program example 24)
3.12 Pointers and two-dimensional arrays (Program example 25)
3.13 Multi-dimensional arrays (Example 3.6, Program example 26)
******************************************************************************/

/*
Prpgram Example 26.
Write a program to read and display a 2 * 2 * 2 array.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
  int array[2][2][2], i, j, k;

  for (i = 0; i < 2; i++) {
    for (j = 0; j < 2; j++) {
      for (k = 0; k < 2; k++) {
        printf("Enter the elements of the matrix (2*2*2): ");
        scanf("%d", &array[i][j][k]);
      }
    }
  }

  printf("The matrix is : \n");
  for (i = 0; i < 2; i++) {
    for (j = 0; j < 2; j++) {
      for (k = 0; k < 2; k++)
        printf("\narray[%d][%d][%d] = %d\n", i, j, k, array[i][j][k]);
    }
  }

  return 0;
}