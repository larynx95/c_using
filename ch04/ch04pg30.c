/* Data Structures Using C, 2nd, Reema Thareja
Chapter 04. Strings

Programming exercises
30. Write a program to delete a name in the string array STUD[][],
assuming that names are sorted alphabetically.

*/

#include <stdio.h>
#include <string.h>

void print_2d_arr(int rows, char arr[][5]);

int main() {
  char arr[][5] = {"ARM", "BOMB", "IBM", "TOM", "BOMB"};
  char enemy[5] = "BOMB";

  int sz_arr = sizeof(arr) / 5;
  int sz_new = sz_arr;

  for (int i = 0; i < sz_arr; i++) {
    if (strcmp(arr[i], enemy) == 0) {
      sz_new--;
    }
  }

  printf("sz_new: %d\n", sz_new);

  char new_arr[3][5];
  int i = 0, j = 0;
  while (j < sz_new) {
    int comp = strcmp(arr[i], enemy);
    if (comp != 0) {
      strcpy(new_arr[j], arr[i]);
      i++, j++;
    } else {
      i++;
    }
  }

  print_2d_arr(sz_new, new_arr);

  return 0;
}

void print_2d_arr(int rows, char arr[][5]) {
  for (int i = 0; i < rows; i++) {
    printf("%s\n", arr[i]);
  }
}