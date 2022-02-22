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
* scanf() problems
  - https://en.cppreference.com/w/c/io/fscanf
  - A beginners' guide away from scanf()
    http://sekrit.de/webdocs/c/beginners-guide-away-from-scanf.html
  - Problem with scanf() when there is fgets()/gets()/scanf() after it
    https://bit.ly/3h5sDb1
*/

#include <conio.h>
#include <stdio.h>

int main() {
  /* Rule 0: Don't use scanf(). (Unless, you know exactly what you do.) */
  int a;
  printf("enter a number: ");
  scanf("%d", &a);
  printf("You entered %d.\n", a);

  /*
  ```
  $ ./example1
  enter a number: 42
  You entered 42.

  $ ./example1
  enter a number: abcdefgh
  You entered 38.
  ```

  Oops. Where does the value 38 come from?
  The answer is: This could be any value, or the program could just crash.
  A crashing program in just two lines of code is quite easy to create in C.
  scanf() is asked to convert a number, and the input doesn't contain any
  numbers, so scanf() converts nothing. As a consequence, the variable a is
  never written to and using the value of an uninitialized variable in C is
  undefined behavior.
  */

  return 0;
}
