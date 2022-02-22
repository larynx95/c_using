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

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  /*
  atoi() is good enough in many cases, but if you want better error checking,
  there's an alternative: strtol():

    long int strtol(const char *nptr, char **endptr, int base);

  This looks complicated. But it isn't:
  - endptr is set to point at the first character that couldn't be converted. So
    you have a way to check whether the whole string was converted.
  - base allows you to specify any base you expect a number in. Most of the
    time, this will be 10, but you could give 16 here for parsing hexadecimal or
    2 for parsing binary.
  - strtol() even sets errno, so you can check whether a number was too small or
    too big for conversion.
  */

  long a;
  char buf[1024];  // use 1KiB just to be sure
  int success;     // flag for successful conversion

  do {
    printf("enter a number: ");
    if (!fgets(buf, 1024, stdin)) {
      // reading input failed:
      return 1;
    }

    // have some input, convert it to integer:
    char *endptr;

    errno = 0;  // reset error number
    a = strtol(buf, &endptr, 10);
    if (errno == ERANGE) {
      printf("Sorry, this number is too small or too large.\n");
      success = 0;
    } else if (endptr == buf) {
      // no character was read
      success = 0;
    } else if (*endptr && *endptr != '\n') {
      // *endptr is neither end of string nor newline,
      // so we didn't convert the *whole* input
      success = 0;
    } else {
      success = 1;
    }
  } while (!success);  // repeat until we got a valid number

  printf("You entered %ld.\n", a);

  /*
  $ ./example10
  enter a number: 565672475687456576574
  Sorry, this number is too small or too large.
  enter a number: ggggg
  enter a number: 15x
  enter a number: 0
  You entered 0.
  */

  return 0;
}
