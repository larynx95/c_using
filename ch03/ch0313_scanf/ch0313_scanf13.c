/* Data Structures Using C, 2nd, Reema Thareja
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
*/

/*
* scanf() problems
  - Problem with scanf() when there is fgets()/gets()/scanf() after it
    https://bit.ly/3h5sDb1
*/

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  int x;
  char str[100];
  printf("Enter a number: ");
  scanf("%d", &x);
  fgets(str, 100, stdin);
  printf("x = %d, str = %s", x, str);

  /*
  $ Enter a number: 10
    x = 10, str =
  */

  /*
  The problem with above code is scanf() reads an integer and leaves a newline
  character in buffer. So fgets() only reads newline and the string “test” is
  ignored by the program.
  */

  /*
  soultion: https://ide.geeksforgeeks.org/nnfP2h
  */
  int y;
  char btr[100];
  scanf("%d\n", &y);
  fgets(btr, 100, stdin);
  printf("y = %d, btr = %s", y, btr);

  return 0;
}
