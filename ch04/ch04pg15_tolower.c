/* Data Structures Using C, 2nd, Reema Thareja
Chapter 04. Strings

Programming exercises
15. Write a program to convert the given string "GOOD
MORNING" to "good morning"
*/

#include <stdio.h>

void mytolower(char *);

int main() {
  char str[13] = "GOOD MORNING";
  mytolower(str);
  printf("%s\n", str);
  return 0;
}

void mytolower(char *str) {
  while (*str != '\0') {
    if (*str >= 'A' && *str <= 'Z') {
      *str = 'a' + *str - 'A';
    }
    str++;
  }
}
