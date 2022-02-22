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
  /* Rule 4: scanf() is a very powerful function. (and with great power comes
   * great responsibility ...) */

  int a;
  int rc;
  printf("enter a number: ");
  while ((rc = scanf("%d", &a)) == 0)  // Neither success (1) nor EOF
  {
    // clear what is left, the * means only match and discard:
    scanf("%*[^\n]");
    // input was not a number, ask again:
    printf("enter a number: ");
  }
  if (rc == EOF) {
    printf("Nothing more to read - and no number found\n");
  } else {
    printf("You entered %d.\n", a);
  }

  /*
  It's not as nice as the version using strtol() above, because there is no way
  to tell scanf() not to skip whitespace for %d -- so if you just hit Enter, it
  will still wait for your input -- but it works and it's a really short
  program.
  */

  return 0;
}
