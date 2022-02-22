/******************************************************************************
Data Structures Using C, 2nd, Reema Thareja
Chapter 02. Introduction to Data Structures and Algorithms

Programming Example 4.
Write an algorithm to print the grade obtained by a
student using the following rules.

Answer:
    Step 1: Enter the Marks obtained as M
    Step 2: IF M>75 PRINT O
    Step 3: IF M>=60 AND M<75
              PRINT A
    Step 4: IF M>=50 AND M<60
              PRINT B
    Step 5: IF M>=40 AND M<50
              PRINT C
            ELSE
              PRINT D
            [END OF IF]
    Step 6: END
******************************************************************************/

#include <stdio.h>

int main() {
  printf("Enter your score: ");
  int M;
  scanf(" %d", &M);

  if (M > 75)
    printf("O");
  else if (M >= 60)
    printf("A");
  else if (M >= 50)
    printf("B");
  else if (M >= 40)
    printf("C");
  else
    printf("D");

  return 0;
}