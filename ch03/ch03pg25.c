/******************************************************************************
Data Structures Using C, 2nd, Reema Thareja
Chapter 03. Arrays

Programming exercises 25.
Write a program to read a floating point array.
Update the array to insert a new number at the specified location.
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main() {
  system("clear");
  int i, n, pos, arr[10];
  printf("Enter the number of elements in the array: ");
  scanf("%d", &n);

  /* add elements */
  for (i = 0; i < n; i++) {
    printf("arr[%d] = ", i);
    scanf("%d", &arr[i]);
  }

  /* the position of element to be deleted
  arr[0] = arr[1]
  arr[1] = arr[2]
  arr[2] = arr[3]
  arr[n-1] = arr[n]  // array[n] is garbage
  */
  printf("Enter the position from which the number has to be deleted: ");
  scanf("%d", &pos);

  for (i = pos; i < n - 1; i++) arr[i] = arr[i + 1];
  n--;

  // print result
  printf("The array after deletion is: \n");
  for (i = 0; i < n; i++) printf("arr[%d] = %d\n", i, arr[i]);

  return 0;
}