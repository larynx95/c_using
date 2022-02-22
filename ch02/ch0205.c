/******************************************************************************
Data Structures Using C, 2nd, Reema Thareja
Chapter 02. Introduction to Data Structures and Algorithms

Programming Example 5.
Write an algorithm to find the sum of first N natural numbers.

Answer:
    Step 1: Input N
    Step 2: SET I = 1, SUM = 0
    Step 3: Repeat Step 4 while I <= N
    Step 4:        SET SUM = SUM + I
                   SET I = I + 1
            [END OF LOOP]
    Step 5: PRINT SUM
    Step 6: END
******************************************************************************/

#include <stdio.h>

int sum(size_t, int *, int);

int main() {
  int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  printf("total=%d\n", sum(10, arr, 5));

  return 0;
}

int sum(size_t sz, int *iarr, int N) {
  int total = 0;
  for (int i = 0; i < N; i++) total += iarr[i];
  return total;
}