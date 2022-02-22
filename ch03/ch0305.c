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
******************************************************************************/

/*
Prpgram Example 5.
Write a program to enter n number of digits.
Form a number using these digits.
*/

#include <math.h>
#include <stdio.h>

int main() {
  int number = 0, digit[10], numofdigits, i;

  // user input
  printf("Enter the number of digits : ");
  scanf("%d", &numofdigits);
  for (i = 0; i < numofdigits; i++) {
    printf("Enter the digit at position %d: ", i + 1);
    scanf("%d", &digit[i]);
  }

  // create a number from integers (important)
  i = 0;
  while (i < numofdigits) {
    number = number + digit[i] * pow(10, i);
    i++;
  }

  // print result
  printf("The number is : %d", number);

  return 0;
}

// TODO: Implement functions: decimal to binary, binary to decimal ...
