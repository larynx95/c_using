/* Data Structures Using C, 2nd, Reema Thareja
Chapter 01. Introduction to C

Program Exercise 17.
Write a program to read a character and print it.
Also print its ASCII value.
If the character is in lower case, print it in upper case and vice versa.
Repeat the process until a '*' is entered.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
  char chr;
  while (1) {
    printf("Enter a character: ");
    scanf(" %c", &chr);  // TODO: Notice space!!

    /* break condition */
    if (chr == '*') {
      printf("End");
      break;
    }

    printf("You've entered: %c, %d\n", chr, chr);

    /* upper and lower case conversion */
    if (chr >= 'a' && chr <= 'z') {
      printf("%c\n", 'A' + chr - 'a');
    } else if (chr >= 'A' && chr <= 'Z') {
      printf("%c\n", 'a' + chr - 'A');
    } else {
      printf("It's not a alphabet.");
      break;
    }
  }

  return 0;
}
