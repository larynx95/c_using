/* Data Structures Using C, 2nd, Reema Thareja
Chapter 05. Structure and Unions

Programming Exercises
8. Write a program to add and subtract height 6'2" and 5'4".

- 1 feet == 12 inches

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int feets, inches;
} LENGTH;

int main() {
  LENGTH arr[2];
  for (int i = 0; i < 2; i++) {
    printf("Enter feets and inches: ");
    scanf("%d %d", &arr[i].feets, &arr[i].inches);
  }

  /* subtract */
  int fts, ichs;
  if (arr[0].feets > arr[1].feets) {
    if (arr[0].inches > arr[1].inches) {
      fts = arr[0].feets - arr[1].feets;
      ichs = arr[0].inches - arr[1].inches;
    } else {
      fts = arr[0].feets - arr[1].feets - 1;
      ichs = 12 + arr[0].inches - arr[1].inches;
    }
  } else {
    if (arr[0].inches < arr[1].inches) {
      fts = arr[1].feets - arr[0].feets;
      ichs = arr[1].inches - arr[0].inches;
    } else {
      fts = arr[1].feets - arr[0].feets - 1;
      ichs = 12 + arr[1].inches - arr[0].inches;
    }
  }

  printf("Subtract two lengths is %d feets %d inches\n", fts, ichs);

  /* add */
  fts = arr[0].feets + arr[1].feets;
  if (arr[0].inches + arr[1].inches >= 12) {
    ichs = (arr[0].inches + arr[1].inches) % 12;
    fts++;
  } else {
    ichs = arr[0].inches + arr[1].inches;
  }

  printf("Subtract two lengths is %d feets %d inches\n", fts, ichs);

  return 0;
}