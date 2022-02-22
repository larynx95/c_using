/* Data Structures Using C, 2nd, Reema Thareja
Chapter 04. Strings

# Count Sort
https://www.geeksforgeeks.org/counting-sort/

index     0 1 2 3 4 5 6 7       ... N-1
array     1 4 1 2 7 5 2
count     0 0 0 0 0 0 0 0 0 0 0 ... N-1 N
count     0 2 2 0 1 1 0 1 0 0 0 ...   0 0
count     0 2 4 4 5 6 6 7 7 7 7 ...   7 7
output

*/

// C Program for counting sort
#include <stdio.h>
#include <string.h>
#define RANGE 255

// The main function that sort the given string arr[] in alphabatical order
void countSort(char arr[]) {
  // The output character array that will have sorted arr
  char output[strlen(arr)];

  // Create a count array to store count of inidividul
  // characters and initialize count array as 0
  int count[RANGE + 1], i;
  memset(count, 0, sizeof(count));

  // Store count of each character
  for (i = 0; arr[i]; ++i) ++count[arr[i]];

  // Change count[i] so that count[i] now contains actual
  // position of this character in output array
  for (i = 1; i <= RANGE; ++i) count[i] += count[i - 1];

  // Build the output character array
  for (i = 0; arr[i]; ++i) {
    output[count[arr[i]] - 1] = arr[i];
    --count[arr[i]];
  }

  // Copy the output array to arr, so that arr now
  // contains sorted characters
  for (i = 0; arr[i]; ++i) arr[i] = output[i];
}

// Driver program to test above function
int main() {
  // char arr[] = "geeksforgeeks";  //"applepp";
  char arr[] = "037821";
  countSort(arr);

  printf("Sorted character array is %s\n", arr);
  return 0;
}
