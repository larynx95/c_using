/******************************************************************************
Data Structures Using C, 2nd, Reema Thareja
Chapter 02. Introduction to Data Structures and Algorithms

Programming Example 3.
Write an algorithm to find whether a number is even or odd.

Answer:
    Step 1: Input number as A
    Step 2: IF A%2 =0
              PRINT "EVEN"
            ELSE
              PRINT "ODD"
            [END OF IF]
    Step 3: END
******************************************************************************/

#include <stdio.h>

void is_even(int n) { (n % 2 == 0) ? printf("EVEN") : printf("ODD"); }

int main() {
  is_even(10);

  return 0;
}