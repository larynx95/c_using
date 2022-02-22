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
  - https://en.cppreference.com/w/c/io/fscanf
  - A beginners' guide away from scanf()
    http://sekrit.de/webdocs/c/beginners-guide-away-from-scanf.html
  - Problem with scanf() when there is fgets()/gets()/scanf() after it
    https://bit.ly/3h5sDb1
*/

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  /*
  For the sake of completeness, if you really really want to get a line of input
  using scanf(), of course this can be done safely as well:
  */

  char name[40];
  printf("What's your name? ");
  if (scanf("%39[^\n]%*c", name) == 1) {
    printf("Hello %s!\n", name);  // We expect exactly 1 conversion
  }

  /*
  Note that this final example of course leaves input unread, even from the same
  line, if there were more than 39 characters until the newline. If this is a
  concern, you'd have to find another way -- or just use fgets(), making the
  check easier, because it gives you the newline if there was one.
  */

  return 0;
}
