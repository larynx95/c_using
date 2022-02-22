/* Data Structures Using C, 2nd, Reema Thareja
Chapter 01. Introduction to C

Program Exercise 3.
Write a program to count the number of vowels in a text.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char text[20] = "this is a string";
  char* ptr = text;

  int cnt = 0;
  for (; *ptr++;) {
    if (*ptr == 'a' || *ptr == 'e' || *ptr == 'i' || *ptr == 'o' || *ptr == 'u')
      cnt++;
  }
  printf("The number of vewels are %d.\n", cnt);

  return 0;
}
