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
Prpgram Example 18.
In a small company there are five salesmen.
Each salesman is supposed to sell three products.
Write a program using a 2D array to print
(i) the total sales by each salesman and
(ii) total sales of each item.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
  system("clear");
  int sales[5][3], i, j, total_sales = 0;

  // INPUT DATA
  printf("ENTER THE DATA\n");
  printf("*****************\n");
  for (i = 0; i < 5; i++) {
    printf("Enter the sales of items %d sold by salesman: ", i + 1);
    for (j = 0; j < 3; j++) scanf(" %d", &sales[i][j]);
    fflush(stdin);
  }

  // print total sales by each salesman
  for (i = 0; i < 5; i++) {
    total_sales = 0;
    for (j = 0; j < 3; j++) total_sales += sales[i][j];
    printf("\nTotal Sales By Salesman %d = %d", i + 1, total_sales);
  }

  // total sales of each item
  for (i = 0; i < 3; i++)  // for each item
  {
    total_sales = 0;
    for (j = 0; j < 5; j++)  // for each salesman
      total_sales += sales[j][i];
    printf("\nTotal sales of item %d = %d", i + 1, total_sales);
  }

  return 0;
}