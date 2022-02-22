/* Data Structures Using C, 2nd, Reema Thareja
Chapter 04. Strings

# Quick Sort (KNK) - split fx.
1. odd number of array (len == 5, part_elem == 5 == a[0])

  array       a[low]       a[high]      result
  ---------------------------------------------------------
  5 3 8 4 9   a[0]=5       a[4]=9 > 5   high--(4->3)
                           a[3]=4 < 5   a[0]=a[3], low++(0->1)
  4 3 8 4 9   a[1]=3       a[3]=4       fst while ends
              a[1]=3 < 5                low++(1->2)
              a[2]=8 > 5                a[3]=a[2], high--(3->2)
  4 3 8 8 9   a[2]=8       a[2]=8       2nd while, for ends
                                        a[2]=5
  4 3 5 8 9                             return 2(value of high)
      *                                 divided into two arrays
                                        with the same length

2. even number of array (len == 6, part_elem == 5 == a[0])

  array         a[low]       a[high]      result
  -----------------------------------------------------------
  5 3 8 4 9 2   a[0]=5       a[5]=2 < 5   a[0]=a[5], low++(0->1)
                                          fst while ends
  2 3 8 4 9 2   a[1]=3 < 5   a[5]=2       low++(1->2)
                a[2]=8 > 5                a[5]=a[2], high--(5->4)
                                          2nd while ends, fst end again
  2 3 8 4 9 8   a[2]=8       a[4]=9 > 5   high--(4->3)
                             a[3]=4 < 5   a[2]=a[3], low++(2->3)
  2 3 4 4 9 8   a[3]=4       a[3]=4       2nd while, for ends
                                          a[3]=5
  2 3 4 5 9 8                             return 3(value of high)
        *                                 divided into two arrays,
                                          one: length(orig arr)/2
                                          two: length(orig arr)/2 - 1

*/

#include <stdio.h>
#include <stdlib.h>
#define N 5

void quicksort(int a[], int low, int high);
int split(int a[], int low, int high);

int main() {
  int a[N], i;

  printf("Enter %d numbers to be sorted: ", N);
  for (i = 0; i < N; i++) scanf("%d", &a[i]);
  quicksort(a, 0, N - 1);

  printf("In sorted order: ");
  for (i = 0; i < N; i++) printf("%d ", a[i]);
  printf("\n");

  return 0;
}

void quicksort(int a[], int low, int high) {
  int middle;

  if (low >= high) return;
  middle = split(a, low, high);
  quicksort(a, low, middle - 1);
  quicksort(a, middle + 1, high);
}

/* divide array into two sub-arrays
   one: elements smaller than the first element of the original array
   two: elements larger than the first element of the original arraY
*/
int split(int a[], int low, int high) {
  int part_element = a[low];  // first element

  for (;;) {
    while (low < high && part_element <= a[high]) high--;
    if (low >= high) break;  // condition for exiting for-loop
    a[low++] = a[high];

    while (low < high && a[low] <= part_element) low++;
    if (low >= high) break;  // condition for exiting for-loop
    a[high--] = a[low];
  }

  a[high] = part_element;
  return high;
}