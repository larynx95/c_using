/* Data Structures Using C, 2nd, Reema Thareja
Chapter 04. Strings

# Merge Sort
- (1) merging fx., (2) sorting fx.

# My Plan
  idx:            0  1  2  3  4  5  6
  elems:         38-27-43-03-09-82-10(3)  m = 7/2
                         /   \
             38-27-43-03(2)  09-82-10(1)          => divide
             /   \              /   \
      39-27(1)  43-03(1)  09-82(1)  10(0)         => divide
      /   \     /   \       /  \       \
  39(0) 27(0) 43(0) 03(0) 09(0) 82(0)  10(0)      => divide
    \   /        \   /      \   /       /         ** sorting and merging **
    27-39        03-43      09-82      10         => merge
        \        /            \       /           ** sorting and merging **
       03-27-39-43             09-19-82           => merge
              \                 /                 ** sorting and merging **
             03-09-19-27-39-43-82                 => merge
*/

#include <stdio.h>
#include <stdlib.h>

void print_arr(int, int *);

int main() {
  int arr[5] = {5, 2, 4, 3, 1};

  return 0;
}

void print_arr(int sz, int *arr) {
  printf("Your array: ");
  for (int i = 0; i < sz; i++) {
    printf("%d ", arr[i]);
  }
}
