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
Prpgram Example 15.
Write a program to display an array of given numbers.
*/

#include <stdio.h>
#include <stdlib.h>

void print_iarr0(int, int *);
void print_iarr1(int, int *);
void print_iarr2(int, int *);
void print_iarr3(int, int *);
void print_carr0(int, char *);
void print_carr1(int, char *);

int main() {
  int iarr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  char carr[] = "abcd";

  print_iarr0(sizeof(iarr) / sizeof(iarr[0]), iarr);
  print_carr0(sizeof(carr) / sizeof(carr[0]), carr);

  return 0;
}

void print_iarr0(int n, int *arr) {
  int *ptr1, *ptr2;
  ptr1 = arr;
  ptr2 = &arr[8];
  while (ptr1 <= ptr2) {
    printf("%d ", *ptr1);
    ptr1++;
  }
}

void print_iarr1(int n, int *arr) {
  for (int i; i < n; i++) printf("%d ", arr[i]);
}

void print_iarr2(int n, int *arr) {
  int *ptr;
  for (ptr = arr; ptr < arr + n; ptr++) printf("%d ", *ptr);
}

void print_iarr3(int n, int *arr) {
  for (int *ptr = arr; ptr < arr + n; ptr++) printf("%d ", *ptr);
}

void print_carr0(int n, char *arr) {
  while (*arr) printf("%c ", *(arr++));
}

void print_carr1(int n, char *arr) {
  for (; *(arr);) printf("%c ", *(arr++));
}
