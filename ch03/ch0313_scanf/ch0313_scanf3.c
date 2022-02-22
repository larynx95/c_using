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
  /* Rule 2: scanf() can be dangerous when used carelessly.
     Always use field widths with conversions that parse to a string (like %s).
  */

  char name[12];
  printf("What's your name? ");
  scanf("%s", name);
  printf("Hello %s!\n", name);

  /*
  $ ./example3
  What's your name? Paul
  Hello Paul!

  $ ./example3
  What's your name? Christopher-Joseph-Montgomery
  Segmentation fault
  */

  /*
  Explanation:
  Well, now we have a buffer overflow. You might get Segmentation fault on a
  Linux system, any other kind of crash, maybe even a "correctly" working
  program, because, once again, the program has undefined behavior.

  The problem here is: %s matches any string, of any length, and scanf() has no
  idea when to stop reading. It reads as long as it can parse the input
  according to the format string, so it writes a lot more data to our name
  variable than the 12 characters we declared for it.
  */

  return 0;
}
