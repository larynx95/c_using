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
/******************************************************************************/

/*
Prpgram Example 23.
Write a program to multiply two m * n matrices.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
  int i, j, k;
  int rows1, cols1, rows2, cols2, res_rows, res_cols;
  int mat1[5][5], mat2[5][5], res[5][5];

  printf("\n Enter the number of rows in the first matrix : ");
  scanf("%d", &rows1);
  printf("\n Enter the number of columns in the first matrix : ");
  scanf("%d", &cols1);
  printf("\n Enter the number of rows in the second matrix : ");
  scanf("%d", &rows2);
  printf("\n Enter the number of columns in the second matrix : ");
  scanf("%d", &cols2);
  if (cols1 != rows2) {
    printf(
        "\n The number of columns in the first matrix must be equal\
to the number of rows in the second matrix");
    exit(EXIT_FAILURE);
  }
  res_rows = rows1;
  res_cols = cols2;
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
  for (i = 0; i < res_rows; i++) {
    for (j = 0; j < res_cols; j++) {
      res[i][j] = 0;
      for (k = 0; k < res_cols; k++) res[i][j] += mat1[i][k] * mat2[k][j];
    }
  }
  printf("\n The elements of the product matrix are ");
  for (i = 0; i < res_rows; i++) {
    printf("\n");
    for (j = 0; j < res_cols; j++) printf("\t %d", res[i][j]);
  }
  return 0;
}