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
******************************************************************************/

/*
Prpgram Example 13.
Write a program to read an array of n numbers and then find the smallest number.
*/

#include <conio.h>
#include <stdio.h>

void read_array(int arr[], int n);
int find_small(int arr[], int n);

int main() {
  int num[10], n, smallest;
  printf("Enter the size of the array: ");
  scanf("%d", &n);
  read_array(num, n);
  smallest = find_small(num, n);
  printf("The smallest number in the array is = %d", smallest);
  getch();

  return 0;
}

void read_array(int arr[10], int n) {
  int i;
  for (i = 0; i < n; i++) {
    printf("arr[%d] = ", i);
    scanf("%d", &arr[i]);
  }
}

int find_small(int arr[10], int n) {
  int i = 0, small = arr[0];
  for (i = 1; i < n; i++) {
    if (arr[i] < small) small = arr[i];
    return small;
  }
}