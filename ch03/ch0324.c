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
/******************************************************************************/

/*
Prpgram Example 24.
Write a program to fill a square matrix with value zero on the diagonals, 1 on
the upper right triangle, and -1 on the lower left triangle.
*/

#include <stdio.h>

void read_matrix(int mat[5][5], int);
void display_matrix(int mat[5][5], int);

int main() {
  int row;
  int mat1[5][5];

  printf("Enter the number of rows and columns of the matrix:");
  scanf("%d", &row);
  read_matrix(mat1, row);
  display_matrix(mat1, row);

  return 0;
}

void read_matrix(int mat[5][5], int r) {
  int i, j;
  for (i = 0; i < r; i++) {
    for (j = 0; j < r; j++) {
      if (i == j)
        mat[i][j] = 0;
      else if (i > j)
        mat[i][j] = -1;
      else
        mat[i][j] = 1;
    }
  }
}

void display_matrix(int mat[5][5], int r) {
  int i, j;
  for (i = 0; i < r; i++) {
    printf("\n");
    for (j = 0; j < r; j++) printf("\t %d", mat[i][j]);
  }
}