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
  /* Rule 1: scanf() is not for reading input, it's for parsing input. */
  int a;
  printf("enter a number: ");
  while (scanf("%d", &a) != 1) {
    // input was not a number, ask again:
    printf("enter a number: ");
  }
  printf("You entered %d.\n", a);

  /*
  $ ./example2
  enter a number: abc
  enter a number: enter a number: enter a number: enter a number: enter a
  number: enter a number: enter a number: enter a number: enter a number:
  enter a number: enter a number: enter a number: enter a number: enter a
  number: enter a number: enter a number: ^C
  */

  /*
  The first argument to scanf() is a format string,
  describing what scanf() should parse.

  The important thing is: scanf() never reads anything it cannot parse.
  In our example, we tell scanf() to parse a number, using the %d conversion.
  Sure enough, abc is not a number, and as a consequence, abc is not even read.
  The next call to scanf() will again find our unread input and, again, can't
  parse it.

  Chances are you find some examples saying "let's just flush the input before
  the next call to scanf()":

  fflush(stdin); // <- never do that!
  Forget about this idea immediately, please.

  You'd expect this to clear all unread input, and indeed, some systems will do
  just that. But according to C, flushing an input stream is undefined behavior,
  and this should now ring a bell. And yes, there are a lot of systems that
  won't clear the input when you attempt to flush stdin.

  So, the only way to clear unread input is by reading it. Of course, we can
  make scanf() read it, using a format string that parses any string. Sounds
  easy.
  */

  return 0;
}
