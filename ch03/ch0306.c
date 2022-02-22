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
Prpgram Example 6.
Write a program to find whether the array of integers contains a duplicate
number.

TODO: Is there better algorithm for check duplication?
      sort first, then find duplication?

Quicksort — The Best Sorting Algorithm?
https://medium.com/human-in-a-machine-world/quicksort-the-best-sorting-algorithm-6ab461b5a9d0

Which sorting algorithm is best and why?
https://www.quora.com/Which-sorting-algorithm-is-best-and-why

Timsort — the fastest sorting algorithm you’ve never heard of
https://hackernoon.com/timsort-the-fastest-sorting-algorithm-youve-never-heard-of-36b28417f399

nandajavarma/Timsort
https://gist.github.com/nandajavarma/a3a6b62f34e74ec4c31674934327bbd3

*/

#include <stdio.h>
#include <stdlib.h>

int main() {
  system("clear");
  int array[10], i, n, j, flag = 0;

  // the number of elements in the array
  printf("Enter the size of the array : ");
  scanf("%d", &n);

  // get elements from user input
  for (i = 0; i < n; i++) {
    printf("array[%d] = ", i);
    scanf("%d", &array[i]);
  }

  // check duplication
  // TODO: Is there better algorithm?
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      if (array[i] == array[j] && i != j) {
        flag = 1;
        printf("Duplicate numbers found at locations %d and %d", i, j);
      }
    }
  }
  if (flag == 0) printf("No Duplicates Found");

  return 0;
}