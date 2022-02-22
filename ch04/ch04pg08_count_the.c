/* Data Structures Using C, 2nd, Reema Thareja
Chapter 04. Strings

Programming exercises
8. Write a program to accept a text.
Count and display the number of times the word 'the' appears in the text.

# My Plan
1. 'character' approach
- check each character in the string
- if current character is 't' or 'T',
  check the following two characters. ('h' or 'H', then 'e' or 'E')
2. 'word' approach
- trim, split string and store every word into an array
- count 'the' word in the array
*/

#include <stdio.h>
#include <stdlib.h>

int cnt_the(char *);

int main() {
  char str[50];
  printf("Enter a string: ");
  gets(str);

  printf("%d\n", cnt_the(str));

  return 0;
}

int cnt_the(char *str) {
  int total = 0;
  while (*str != '\0') {
    if ((*(str + 0) == 't' || *(str + 0) == 'T') &&
        (*(str + 1) == 'h' || *(str + 1) == 'H') &&
        (*(str + 2) == 'e' || *(str + 2) == 'E')) {
      total++;
      str = str + 2;
    } else {
      str++;
    }
  }
  return total;
}
