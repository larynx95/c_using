/* Data Structures Using C, 2nd, Reema Thareja
Chapter 04. Strings

# Bubble Sort
https://www.geeksforgeeks.org/bubble-sort/
https://www.youtube.com/watch?v=lyZQPjUT5B4
  First Pass:
  ( 5* 1* 4 2 8 ) –> ( 1* 5* 4 2 8 ),
  Here, algorithm compares the first two elements, and swaps since 5 > 1.
  ( 1 5* 4* 2 8 ) –>  ( 1 4* 5* 2 8 ),
  Swap since 5 > 4
  ( 1 4 5* 2* 8 ) –>  ( 1 4 2* 5* 8 ),
  Swap since 5 > 2
  ( 1 4 2 5* 8* ) –> ( 1 4 2 5* 8* ),
  Now, since these elements are already in order (8 > 5),
  algorithm does not swap them.

  Second Pass:
  ( 1* 4* 2 5 8 ) –> ( 1* 4* 2 5 8 )
  ( 1 4* 2* 5 8 ) –> ( 1 2* 4* 5 8 ), Swap since 4 > 2
  ( 1 2 4* 5* 8 ) –> ( 1 2 4* 5* 8 )
  ( 1 2 4 5* 8* ) –>  ( 1 2 4 5* 8* )
  Now, the array is already sorted,
  but our algorithm does not know if it is completed.
  The algorithm needs one whole pass without any swap to know it is sorted.

  Third Pass:
  ( 1* 2* 4 5 8 ) –> ( 1* 2* 4 5 8 )
  ( 1 2* 4* 5 8 ) –> ( 1 2* 4* 5 8 )
  ( 1 2 4* 5* 8 ) –> ( 1 2 4* 5* 8 )
  ( 1 2 4 5* 8* ) –> ( 1 2 4 5* 8* )

# My Plan
1. nested loop
  i j  arr            output
  0 0  5* 2* 4 3 1 -> 2 5 4 3 1
    1  2 5* 4* 3 1 -> 2 4 5 3 1
    2  2 4 5* 3* 1 -> 2 4 3 5 1
    3  2 4 3 5* 1* -> 2 4 3 1 5
  1 0  2* 4* 3 1 5 -> 2 4 3 1 5
    1  2 4* 3* 1 5 -> 2 3 4 1 5
    2  2 3 4* 1* 5 -> 2 3 1 4 5
  2 0  2* 3* 1 4 5 -> 2 3 1 4 5
    1  2 3* 1* 4 5 -> 2 1 3 4 5
  3 0  2* 1* 3 4 5 -> 1 2 3 4 5

2. use `unordered variable`, true or false
- If the number of swap is zero, it ends.
- i = [0..n-2], if (arr[i] > arr[i+1]) then swap else pass
*/

#include <stdio.h>
#include <stdlib.h>

void print_arr(int, int *);
void sort_bub(int sz, int *);

int main() {
  int arr[5] = {5, 2, 4, 3, 1};

  sort_bub(5, arr);
  print_arr(5, arr);

  return 0;
}

void print_arr(int sz, int *arr) {
  printf("Your array: ");
  for (int i = 0; i < sz; i++) {
    printf("%d ", arr[i]);
  }
}

void sort_bub(int sz, int *arr) {
  for (int i = 0; i < sz - 1; i++) {
    for (int j = 0; j < sz - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}