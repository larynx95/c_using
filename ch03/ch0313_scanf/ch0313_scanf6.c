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
  /* One way around this is to tell scanf() to skip whitespace: If the format
   * string contains any whitespace, it matches any number of whitespace
   * characters in the input, including no whitespace at all. Let's use this to
   * skip whitespace the user might enter before entering his name: */

  char name[40];
  printf("What's your name? ");
  scanf(" %39[^\n]", name);
  //     ^ note the space here, matching any whitespace
  printf("Hello %s!\n", name);

  /*
  Yes, this program works and doesn't have any undefined behavior*), but I guess
  you don't like very much that nothing at all happens when you just press
  enter, because scanf() is skipping it and continues to wait for input that can
  be matched.

  *) actually, this isn't even entirely true. This program still has undefined
  behavior for empty input. You could force this on a Linux console hitting
  Ctrl+D for example. So, it's again an example for code you should not write.
  */

  return 0;
}
