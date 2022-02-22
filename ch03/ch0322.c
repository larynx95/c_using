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
Prpgram Example 22.
Write a program to input two m * n matrices and then calculate the sum of their
corresponding elements and store it in a third m * n matrix.

TODO:
- Is there any library for matrix operation in C lang?
*/

#include <stdio.h>

int main() {
  int i, j;
  int rows1, cols1, rows2, cols2, rows_sum, cols_sum;
  int mat1[5][5], mat2[5][5], sum[5][5];

  printf("\n Enter the number of rows in the first matrix : ");
  scanf("%d", &rows1);
  printf("\n Enter the number of columns in the first matrix : ");
  scanf("%d", &cols1);

  printf("\n Enter the number of rows in the second matrix : ");
  scanf("%d", &rows2);
  printf("\n Enter the number of columns in the second matrix : ");
  scanf("%d", &cols2);

  if (rows1 != rows2 || cols1 != cols2) {
    printf("\n Number of rows and columns of both matrices must be equal");
    exit();
  }

  rows_sum = rows1;
  cols_sum = cols1;
  printf("\n Enter the elements of the first matrix ");
  for (i = 0; i < rows1; i++) {
    for (j = 0; j < cols1; j++) {
      scanf("%d", &mat1[i][j]);
    }
  }

  printf("\n Enter the elements of the second matrix ");
  for (i = 0; i < rows2; i++) {
    for (j = 0; j < cols2; j++) {
      scanf("%d", &mat2[i][j]);
    }
  }

  for (i = 0; i < rows_sum; i++) {
    for (j = 0; j < cols_sum; j++) sum[i][j] = mat1[i][j] + mat2[i][j];
  }

  printf("\n The elements of the resultant matrix are ");
  for (i = 0; i < rows_sum; i++) {
    printf("\n");
    for (j = 0; j < cols_sum; j++) printf("\t %d", sum[i][j]);
  }
  return 0;
}