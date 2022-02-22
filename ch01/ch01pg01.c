/* Data Structures Using C, 2nd, Reema Thareja
Chapter 01. Introduction to C

Program Exercise 1.
Write a program to read 10 integers.
Display these numbers by printing three numbers in a line separated by commas.
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>  // exit(EXIT_FAILURE)

void three_pairs1();
void three_pairs2();
void three_pairs3();
void three_pairs4();
void three_pairs5();
void three_pairs6();

int main() {
  three_pairs1();

  return 0;
}

/**********************************************************
 * void
 * 1-D array
 *    version 1.
 *    version 2. improved for printing
 **********************************************************/

void three_pairs1() {
  int arr[10];

  // enter ten elements of the array
  printf("Enter ten integer values: ");
  for (int i = 0; i < 10; i++) {
    int temp;
    scanf("%d", &temp);
    arr[i] = temp;
  }

  // print array
  printf("This is the result: \n");
  for (int i = 0; i < 10; i++) {
    if (i % 3 == 0) printf("\n");
    printf("%d ", arr[i]);
  }
}

void three_pairs2() {
  int arr[10];

  // enter ten elements of the array
  printf("Enter ten integer values: ");
  for (int i = 0; i < 10; i++) {
    int temp;
    scanf("%d", &temp);
    arr[i] = temp;
  }

  // print array
  // solving first line nreak problem in ver 1.
  printf("This is the result: \n");
  printf("%d ", arr[0]);
  for (int i = 1; i < 10; i++) {
    if (i % 3 == 0) printf("\n");
    printf("%d ", arr[i]);
  }
}

/**********************************************************
 * void
 * pointer to 1-D array
 *    version 3.
 *    version 4. improved for printing
 **********************************************************/

void three_pairs3() {
  int arr[10];
  int *ptr = arr;

  for (; ptr <= arr + 9; ptr++) {
    int temp;
    scanf("%d", &temp);
    *ptr = temp;
  }

  int i = 0;
  for (ptr = arr; ptr <= arr + 9; ptr++) {
    if (i % 3 == 0) printf("\n");
    printf("%d ", *ptr);
    i++;
  }
}

void three_pairs4() {
  int arr[10];
  int *ptr = arr;

  printf("Enter ten integers: ");
  for (; ptr <= arr + 9; ptr++) {
    int temp;
    scanf("%d", &temp);
    *ptr = temp;
  }

  int i = 1;
  ptr = arr;
  printf("This is the result: \n");
  printf("%d ", *ptr);
  for (ptr = arr + 1; ptr <= arr + 9; ptr++) {
    if (i % 3 == 0) printf("\n");
    printf("%d ", *ptr);
    i++;
  }
}

/**********************************************************
 * void
 * 2-D array
 *    version 5.
 **********************************************************/

void three_pairs5() {
  int arr[4][3];
  printf("Enter ten integer values: ");
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
      int temp;
      scanf("%d", &temp);
      if (!isdigit(temp)) {  // TODO: Improve this part.
        arr[i][j] = temp;
      }
    }
  }

  printf("This is the result: \n");
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
}

/**********************************************************
 * void
 * pointer to 2-D array
 *    version 6. pointer to array
 **********************************************************/

// TODO: How can I use pointer to 2D array?