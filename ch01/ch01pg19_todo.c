/* Data Structures Using C, 2nd, Reema Thareja
Chapter 01. Introduction to C

Program Exercise 19.
Write a program to take input from the user
and then check whether it is a number or a character.
If it is a character,
determine whether it is in upper case or lower case.
Also print its ASCII value.
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Enter a character or a number: ");
  int input = getchar();
  printf("%c %d\n", input, input);

  if (isalpha(input)) {
    if (input >= 'a' && input <= 'z') {
      printf("Lower case character. ASCII: %c\n", input);
    } else {
      printf("Upper case character.ASCII: %c\n", input);
    }
  } else {
    printf("Not alphabet. ASCII: %d\n", input);
  }

  return 0;
}

/*
TODO:
- Distinguishing if int or char / string from user input
  https://stackoverflow.com/questions/31977398/distinguishing-if-int-or-char-string-from-user-input
*/