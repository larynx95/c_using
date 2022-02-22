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
  int a;
  char buf[1024];  // use 1KiB just to be sure

  do {
    printf("enter a number: ");
    if (!fgets(buf, 1024, stdin)) {
      // reading input failed, give up:
      return 1;
    }

    // have some input, convert it to integer:
    a = atoi(buf);
  } while (a == 0);  // repeat until we got a valid number

  printf("You entered %d.\n", a);

  /*
  $ ./example9
  enter a number: foo
  enter a number: bar
  enter a number: 15x
  You entered 15.
  */

  /*
  Well, not bad so far. But what if we want to allow an actual 0 to be entered?
  We can't tell whether atoi() returns 0 because it cannot convert anything or
  because there was an actual 0 in the string. Also, ignoring the extra x when
  we input 15x may not be what we want.
  */

  return 0;
}
