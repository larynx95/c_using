/* Data Structures Using C, 2nd, Reema Thareja
Chapter 12. Heaps

http://programmingearth.com/post.php?pageid=80&title=C%20program%20to%20implement%20Max%20heap.
*/

#include <math.h>
#include <stdio.h>

int parent(int i);
int left(int i);
int right(int i);
void maxheapify(int arr[], int n, int i);

int main() {
  int arr[20];
  int i = 0, n;
  system("clear");

  printf("Enter the number the of element in array: ");
  scanf("%d", &n);
  printf("Enter the elements: ");
  for (i = 0; i < n; i++) scanf("%d", &arr[i]);

  printf("Array before max heap ");
  for (i = 0; i < n; i++) printf("%d ", arr[i]);
  printf("\n");

  for (i = (n - 1) / 2; i >= 0; i--) maxheapify(arr, n, i);

  printf("Array after Maxheap ");
  for (i = 0; i < n; i++) printf("%d ", arr[i]);
  printf("\n");

  return 0;
}

int parent(int i) { return (i - 1) / 2; }
int left(int i) { return 2 * i + 1; }
int right(int i) { return 2 * i + 2; }

void maxheapify(int arr[], int n, int i) {
  int l, r, largest, temp;
  l = left(i);
  r = right(i);
  if (l < n && arr[l] > arr[i])
    largest = l;
  else
    largest = i;
  if (r < n && arr[r] > arr[largest]) largest = r;
  // printf("i=%d  l=%d  r=%d largest=%d",i,l,r,largest);
  if (largest != i) {
    temp = arr[i];
    arr[i] = arr[largest];
    arr[largest] = temp;
    maxheapify(arr, n, largest);
  }
}