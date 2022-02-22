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
  /* Rule 3: Although scanf() format strings can look quite similar to printf()
   * format strings, they often have slightly different semantics. (Make sure to
   * read the fine manual) */

  char name[40];
  printf("What's your name? ");
  scanf("%39s", name);
  printf("Hello %s!\n", name);

  /*
  $ ./example4
  What's your name? Martin Brown
  Hello Martin!

  Well, that's ... outspoken.
  What happens here? Reading some scanf() manual,
  we would find that %s parses a word, not a string,
  for example I found the following wording:

  s: Matches a sequence of non-white-space characters
  A white-space in C is one of space, tab (\t) or newline (\n).
  */

  /*
  The general problem with parsing "a string" from an input stream is:
  Where does this string end? With %s, the answer is at the next white-space.
  If you want something different, you can use %[:

  %[a-z]: parse as long as the input characters are in the range a - z.
  %[ny]: parse as long as the input characters are y or n.
  %[^.]: The ^ negates the list, so this means parse as long as there is no . in
  the input.
  */

  return 0;
}
