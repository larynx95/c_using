/* Data Structures Using C, 2nd, Reema Thareja
Chapter 04. Strings

# Count Sort
https://www.programiz.com/dsa/counting-sort
https://github.com/trekhleb/javascript-algorithms/tree/master/src/algorithms/sorting/counting-sort

# Concepts
Step 1. index: 0 1 2 3 4 5 6 7 8 9
        array: 3 4 2 1 0 0 4 3 4 2

Step 2. index: 0 1 2 3 4
        count: 2 1 2 2 3

Step 3. index: 0 1 2 3 4
        count: 2 3 5 7 10 (accumulative)

Step 4. index: 0 1 2 3 4 5 6 7 8 9
        array: 3 4 2 1 0 0 4 3 4 2
        count: 2 3 5 7 10

  1)  index: 0 1 2 3 4 5 6 7 8 9 10    2)  index: 0 1 2 3 4 5 6 7 8 9 10
      array: 3* 4 2 1 0 0 4 3 4 2          array: 3 4* 2 1 0 0 4 3 4 2
      count: 2 3 5 7-- 10                  count: 2 3 5 6 10--
      out:   . . . . . . . 3 . . .         out:   . . . . . . . 3 . . 4

  3)  index: 0 1 2 3 4 5 6 7 8 9 10    4)  index: 0 1 2 3 4 5 6 7 8 9 10
      array: 3 4 2* 1 0 0 4 3 4 2          array: 3 4 2 1* 0 0 4 3 4 2
      count: 2 3 5-- 6 9                   count: 2 3-- 4 6 9
      out:   . . . . . 2 . 3 . . 4         out:   . . . 1 . 2 . 3 . . 4

  5)  index: 0 1 2 3 4 5 6 7 8 9 10    6)  index: 0 1 2 3 4 5 6 7 8 9 10
      array: 3 4 2 1 0* 0 4 3 4 2          array: 3 4 2 1 0 0* 4 3 4 2
      count: 2-- 2 4 6 9                   count: 1-- 2 4 6 9
      out:   . . 0 1 . 2 . 3 . . 4         out:   . 0 0 1 . 2 . 3 . . 4

  7)  index: 0 1 2 3 4 5 6 7 8 9 10    8)  index: 0 1 2 3 4 5 6 7 8 9 10
      array: 3 4 2 1 0 0 4* 3 4 2          array: 3 4 2 1 0 0 4 3* 4 2
      count: 0 2 4 6 9--                   count: 0 2 4 6-- 8
      out:   . 0 0 1 . 2 . 3 . 4 4         out:   . 0 0 1 . 2 3 3 . 4 4

  9)  index: 0 1 2 3 4 5 6 7 8 9 10   10) index: 0 1 2 3 4 5 6 7 8 9 10
      array: 3 4 2 1 0 0 4 3 4* 2         array: 3 4 2 1 0 0 4 3 4 2*
      count: 0 2 4 5 8--                  count: 0 2 4-- 5 7
      out:   . 0 0 1 . 2 3 3 4 4 4        out:   . 0 0 1 2 2 3 3 4 4 4

 11)  index: 0 1 2 3 4 5 6 7 8 9 10
      out:   0 0 1 2 2 3 3 4 4 4  <-- (index-1)
*/
#include <stdio.h>

void countingSort(int array[], int size) {
  int output[10];

  int max = array[0];
  for (int i = 1; i < size; i++) {
    if (array[i] > max) max = array[i];
  }

  int count[10];
  for (int i = 0; i <= max; ++i) {
    count[i] = 0;
  }

  for (int i = 0; i < size; i++) {
    count[array[i]]++;
  }

  for (int i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }

  for (int i = size - 1; i >= 0; i--) {
    output[count[array[i]] - 1] = array[i];
    count[array[i]]--;
  }

  for (int i = 0; i < size; i++) {
    array[i] = output[i];
  }
}

void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

int main() {
  int array[] = {4, 2, 2, 8, 3, 3, 1, 0, 0};
  int n = sizeof(array) / sizeof(array[0]);
  countingSort(array, n);
  printArray(array, n);
}
