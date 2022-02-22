/* Data Structures Using C, 2nd, Reema Thareja
Chapter 04. Strings

Programming exercises
28. Write a program to check whether a pattern exists in a text.
If it does, delete the pattern and display it.

# My Plan
- regular expression
- substring
*/

#include <stdio.h>
#include <stdlib.h>

void test1();
void print_arr(int sz, int arr[]);
int contains(int num, int sz, int arr[]);

int main() {
  test1();
  return 0;
}

/*
pattern bc           size = 3
index   0 1 2 3 4 5
chars   a b c d e f  size = 7
        ---           0
          ---         1
            ---       2
              ---     3
                ---   4, 0 ~ 4 (0 ~ sz_text - sz_pattern)
*/
void test1() {
  /* find indices where the pattern matches */
  char text[] = "aaa\nbbb\nccc\nddd";
  const char pattern[] = "bbb";
  int sz_t = sizeof(text) / sizeof(char);
  int sz_p = sizeof(pattern) / sizeof(char);

  int indices[5];
  int idx = 0;
  int max_idx = 0;
  for (int i = 0; i < sz_t - sz_p; i++) {
    int flag = 1;
    for (int j = 0; j < sz_p - 1; j++) {
      if (text[i + j] != pattern[j]) {
        flag = 0;
      }
    }
    if (flag == 1) {
      indices[idx++] = i;
      max_idx++;
    }
  }

  print_arr(max_idx, indices);

  /* print result
  text:     aaa\nbbb\nccc\nbbb\0  (size 15)
  pattern:  bbb\0                 (size 4)
  indices:  [4, 12]
  print:    a a a \n . . . \n c c c \n . . . \0
                     4 5 6  7         12     15
  */
  int i = 0;
  while (text[i] != '\0') {
    for (int j = 0; j <= max_idx; j++) {
      if (i == indices[j]) {
        i += (sz_p - 1);
        j++;
      } else {
        printf("%c", text[i++]);
      }
    }
  }
}

void print_arr(int sz, int arr[]) {
  for (int i = 0; i < sz; i++) {
    printf("%i ", arr[i]);
  }
  printf("\n");
}

int contains(int num, int sz, int arr[]) {
  for (int i = 0; i < sz; i++) {
    if (num == arr[i]) return 1;
  }
  return 0;
}