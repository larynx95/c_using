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
  char c;
  printf("......Enter q to quit......\n");
  do {
    printf("Enter a character\n");
    scanf("%c", &c);
    printf("%c\n", c);
  } while (c != 'q');

  /*
  ......Enter q to quit......
  Enter a character
  a
  a
  Enter a character


  Enter a character
  b
  b
  Enter a character


  Enter a character
  q
  q
  */

  /*
  We can notice that above program prints an extra “Enter a character” followed
  by an extra new line. This happens because every scanf() leaves a newline
  character in buffer that is read by next scanf.

  How to solve above problem?
  - We can make scanf() to read a new line by using an extra “\n”, i.e.,
    scanf(“%d\n”, &x).
    In fact scanf(“%d “, &x) also works (Note extra space).
  - We can add a getchar() after scanf() to read an extra newline.
  */

  return 0;
}
