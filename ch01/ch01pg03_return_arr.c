/* Data Structures Using C, 2nd, Reema Thareja
Chapter 01. Introduction to C

Program Exercise 3.
Write a program to count the number of vowels in a text.

TODO: How many ways does a function return an array?
https://www.geeksforgeeks.org/taking-string-input-space-c-3-different-methods/
https://www.youtube.com/watch?v=EDy8BmAW3uo
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* this doesn't work
char* return_string() {
  char buffer[] = "This is a local char buffer";
  return buffer;
}
*/

/* this doesn't work
int* return_int_arr() {
  int int_arr[] = {9, 1, 3};
  return int_arr;
}
*/

/**********************************************************
 * 1. returning string literal
 this works ok
 a. simplest solution, but...
 b. only works for string literals
 c. can't be used for string manipulation
 d. string literal is stored in read only memeory sector
 *********************************************************/
char* return_string_literal() { return "Returned string"; }

/**********************************************************
 * 2. using globally declared array variable
 a. contents can be calculated
 b. anyone can modify the global array
 c. overwritten on next call to the function
    (caller needs to copy return value)
 d. large buffers can be wasteful
 **********************************************************/
char global_arr[100];
char* using_global_var() {
  global_arr[0] = 'a';
  return global_arr;
}

/**********************************************************
 * 3. using a static array
 a. only those with pointer will be able to modify static array
 b. overwritten on next call to the function
 c. large buffers can be wasteful
 **********************************************************/
char* using_static_array() {
  static char static_arr[100];
  static_arr[0] = 'a';
  return static_arr;
}

/**********************************************************
 * 4. explicitly allocated memory to hold the return value
 a. every invocation creates a new buffer
 b. memory managemnent issues
  - momory freed while still in use
  - memory leaks
 **********************************************************/
char* using_malloc() {
  char* buffer = malloc(100);
  *buffer = 'a';
  return buffer;
}

/**********************************************************
 * 5. caller allocates memory to hold return value
 a. for saftey, provide a count of the size of the buffer
 b. simplified momory management
 c. return from the function can be used for status code
 **********************************************************/
void caller_allocate(char* result, int size) {
  strncpy(result, "returned string", size);
}

/**********************************************************
 * 6. wrap with struct
 a. no memory management
 b. fixed-size array only
 c. costly for large arrays
 **********************************************************/

struct Data {
  char buffer[100];
};
struct Data using_struct() {
  struct Data d;
  strncpy(d.buffer, "Returned string", 100);
  return d;
}

int main() {
  // char* sptr = return_string();
  // int* iptr = return_int_arr();
  return_string_literal();

  // 6. caller allocate & free memeory
  int size = 100;
  char* buffer = malloc(size);
  caller_allocate(buffer, size);
  *buffer = 'a';
  free(buffer);

  // solution for this exercise
  char text[20] = "this is a string";
  char* ptr = text;

  int cnt;
  for (; *ptr++;) {
    if (*ptr == 'a' || *ptr == 'e' || *ptr == 'i' || *ptr == 'o' || *ptr == 'u')
      cnt++;
  }
  printf("The number of vewels is %d\n", cnt);

  return 0;
}
