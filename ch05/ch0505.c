/* Data Structures Using C, 2nd, Reema Thareja
Chapter 05. Structure and Unions
5.1 Introduction
  5.1.1 Structure declaration
  5.1.2 `typedef` declarations
  5.1.3 Initialization of structures
  5.1.4 Accessing the members of a structure
  5.1.5 Copying and comparing structures (Program example 1 ~ 2)
5.2 Nested structures (Program example 3)
5.3 Arrays of structures (Program example 4)
5.4 Structures and fucntions
  5.4.1 Passing individual members
  5.4.2 Passing the entire structure (Program example 5)
*/

/*
Programming Example
5. Write a program to read, display, add, and subtract two distances. Distance
must be defined using kms and meters.

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct distance {
  int kms;
  int meters;
} DISTANCE;

DISTANCE add_distance(DISTANCE, DISTANCE);
DISTANCE subtract_distance(DISTANCE, DISTANCE);
DISTANCE d1, d2, d3, d4;

int main() {
  int option;
  clrscr();
  do {
    printf("\n ******** MAIN MENU *********");
    printf("\n 1. Read the distances ");
    printf("\n 2. Display the distances");
    printf("\n 3. Add the distances");
    printf("\n 4. Subtract the distances");
    printf("\n 5. EXIT");
    printf("\n Enter your option : ");
    scanf("%d", &option);
    switch (option) {
      case 1:
        printf("\n Enter the first distance in kms and meters: ");
        scanf("%d %d", &d1.kms, &d1.meters);
        printf("\n Enter the second distance in kms and meters: ");
        scanf("%d %d", &d2.kms, &d2.meters);
        break;
      case 2:
        printf("\n The first distance is : %d kms %d meters", d1.kms,
               d1.meters);
        printf("\n The second distance is : %d kms %d meters", d2.kms,
               d2.meters);
        break;

      case 3:
        d3 = add_distance(d1, d2);
        printf("\n The sum of two distances is : %d kms %d meters", d3.kms,
               d3.meters);
        break;
      case 4:
        d4 = subtract_distance(d1, d2);
        printf("\n The difference between two distances is : %d kms %d meters",
               d4.kms, d4.meters);
        break;
    }
  } while (option != 5);

  return 0;
}

DISTANCE add_distance(DISTANCE d1, DISTANCE d2) {
  DISTANCE sum;
  sum.meters = d1.meters + d2.meters;
  sum.kms = d1.kms + d2.kms;
  while (sum.meters >= 1000) {
    sum.meters = sum.meters % 1000;
    sum.kms += 1;
  }
  return sum;
}

DISTANCE subtract_distance(DISTANCE d1, DISTANCE d2) {
  DISTANCE sub;
  if (d1.kms > d2.kms) {
    sub.meters = d1.meters - d2.meters;
    sub.kms = d1.kms - d2.kms;
  } else {
    sub.meters = d2.meters - d1.meters;
    sub.kms = d2.kms - d1.kms;
  }
  // TODO: What is this?
  //       10 km 20 meters, 20 km 10 meters
  if (sub.meters < 0) {
    sub.kms = sub.kms - 1;
    sub.meters = sub.meters + 1000;
  }
  return sub;
}