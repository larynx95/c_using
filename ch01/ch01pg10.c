/* Data Structures Using C, 2nd, Reema Thareja
Chapter 01. Introduction to C

Program Exercise 10.
Write a C program using printf statement to print
BYE in the following format:

        BBB       Y    Y     EEEE
        B   B      Y   Y     E
        BBB          Y       EEEE
        B   B        Y

TODO: What is the meaning of this exercise? too easy or too difficult...
- printing multiple lines of string?
- convert a string value to Neon-sign-like char-based graphics?
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
  printf(
      "        BBB       Y    Y     EEEE\n"
      "        B   B      Y   Y     E\n"
      "        BBB          Y       EEEE\n"
      "        B   B        Y\n");
  return 0;
}
