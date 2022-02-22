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
******************************************************************************/

/*
Prpgram Example 3.
Write a program to print the position of the smallest number of n numbers using
arrays.
*/

#include <stdio.h>

int f_min(int, int *);
void swap(int *, int *);
int f_min1(int, int a[]);

int main() {
  system("clear");

  /* 1. example code in the book */
  // user input for the number of the array
  int i, n, arr[20], small, pos;
  printf("Enter the number of elements in the array: ");
  scanf(" %d", &n);

  // array elements
  for (i = 0; i < n; i++) {
    printf("Enter the elements: ");
    scanf(" %d", &arr[i]);
  }

  // find the smallest number and its index
  small = arr[0];
  pos = 0;
  for (i = 1; i < n; i++) {
    if (arr[i] < small) {
      small = arr[i];
      pos = i;
    }
  }

  // print
  printf("The smallest element is : %d\n", small);
  printf("The position of the smallest element in the array is : %d\n", pos);

  /* 2. recursive function */
  printf("Recursive min: %d\n", f_min(n, arr));
  printf("Recursive min1: %d\n", f_min1(n, arr));

  /* 3. bitwise operation
     Bit Twiddling Hacks
     https://graphics.stanford.edu/~seander/bithacks.html
  */
  int x = 5;
  int y = 8;
  int CHAR_BIT = 8;
  printf("min(%d, %d): %d\n", x, y, y ^ ((x ^ y) & -(x < y)));
  printf("min(%d, %d): %d\n", x, y,
         y + ((x - y) & ((x - y) >> (sizeof(int) * CHAR_BIT - 1))));

  return 0;
}

void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

int f_min(int sz, int *arr) {
  if (sz == 0)
    return 0;
  else if (sz == 1)
    return arr[0];
  else {
    if (arr[0] < arr[1]) {
      swap(&arr[0], &arr[1]);
      return f_min(sz - 1, arr + 1);
    } else {
      return f_min(sz - 1, arr + 1);
    }
  }
}
