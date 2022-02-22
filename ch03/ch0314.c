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
******************************************************************************/

/*
Prpgram Example 14.
Write a program to interchange the largest and the smallest number in an array.

# array vs. pointer
- array name is not a lvalue
                not a pointer variable
                converted to local pointer variable
                          only when it passed to a function as a arg
- pointer is varialbe storing the address
- When passed to a function as a parameter,
  array is converted to a local pointer variable
  pointing to the address of the first element of the array
- multidimensional array is not expressed as double pointer
- inc/decrement value is all the same in different types of pointer arithmetic
  Int : ptr + sizeof(int)    // wrong
  Int : ptr + 1              // ok
  Char: ptr + sizeof(char)   // ok, but unnecessary
  Char: ptr + 1              // ok, same as int
*/

#include <stdio.h>
#include <stdlib.h>

void read_array(int, int *);
void display_array(int, int *);
void interchange(int, int *);
int find_biggest_pos(int, int *);
int find_smallest_pos(int, int *);

int main() {
  int arr[10], n;
  system("clear");
  printf("Enter the size of the array: ");
  scanf("%d", &n);

  read_array(n, arr);
  interchange(n, arr);
  printf("The new array is: \n");
  display_array(n, arr);

  return 0;
}

void read_array(int n, int *my_array) {
  int i;
  for (i = 0; i < n; i++) {
    printf("arr[%d] = ", i);
    scanf("%d", &my_array[i]);
  }
}

void display_array(int n, int *my_array) {
  int i;
  for (i = 0; i < n; i++) printf("arr[%d] = %d\n", i, my_array[i]);
}

void interchange(int n, int *my_array) {
  int temp, big_pos, small_pos;
  big_pos = find_biggest_pos(n, my_array);
  small_pos = find_smallest_pos(n, my_array);
  temp = my_array[big_pos];
  my_array[big_pos] = my_array[small_pos];
  my_array[small_pos] = temp;
}

int find_biggest_pos(int n, int *my_array) {
  int i, large = my_array[0], pos = 0;
  for (i = 1; i < n; i++) {
    if (my_array[i] > large) {
      large = my_array[i];
      pos = i;
    }
  }
  return pos;
}

int find_smallest_pos(int n, int my_array[10]) {
  int i, small = my_array[0], pos = 0;
  for (i = 1; i < n; i++) {
    if (my_array[i] < small) {
      small = my_array[i];
      pos = i;
    }
  }
  return pos;
}