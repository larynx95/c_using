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
******************************************************************************/

/*
Prpgram Example 21.
Write a program to transpose a 3 * 3 matrix.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
  int i, j, mat[3][3], transposed_mat[3][3];
  system("clear");

  printf("Enter the elements of the matrix \n");
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      scanf("%d", &mat[i][j]);
    }
  }

  printf("The elements of the matrix are \n");
  for (i = 0; i < 3; i++) {
    printf("\n");
    for (j = 0; j < 3; j++) printf("\t %d", mat[i][j]);
  }
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) transposed_mat[i][j] = mat[j][i];
  }

  printf("The elements of the transposed matrix are \n");
  for (i = 0; i < 3; i++) {
    printf("\n");
    for (j = 0; j < 3; j++) printf("%d ", transposed_mat[i][j]);
  }

  return 0;
}