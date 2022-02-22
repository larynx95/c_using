/******************************************************************************
Data Structures Using C, 2nd, Reema Thareja
Chapter 02. Introduction to Data Structures and Algorithms
2.1 Basic terminology
  2.1.1 Elementary Data Structure Organization
2.2 Classification of data structures
  Primitive and Non-primitive data structures
  Linear and Non-linear structures
  Arrays, Linked Lists, Stacks, Queues, Trees, Graphs
2.3 Operations on data structures
  traversing, searching, inserting, deleting, sorting, merging
2.4 Abstract data type (ADT)
  data type, abstract
  Advantage of using ADTs
2.5 Algorithms
2.6 Different approachs to designing an algorithm
  Top-down, Bottom-up approach
2.7 Control structures used in algorithms
  Sequence, Decision, Repetition (Program example 1)
2.8 Time and space complexity
  2.8.1 Worst-case, Average-case, Best-case, and Amortized time complexity
    Worst-case/Average-case/Best-case/Amortized running time
  2.8.2 Time-space trade-off
  2.8.3 Expressing time and space complexity
  2.8.4 Algorithm efficiency
    Linear loops
    Logarithmic loops
    Nested loops
      Linear logarithmic loop
      quadratic loop
      dependent quadratic loop
2.9 Big O notation
  Categories of algorithms (Example 1 ~ 4)
  Limitations of Big O notation
2.10 Omega notation (Example 5 ~ 6)
2.11 Theta notation (Example 7)
2.12 Other useful notations
  Little O notation (Example 8)
  Little Omega Notation (Example 9)
******************************************************************************/

/*
* Number of operations for different functions of n
  n  O(1)  O(log n)  O(n)  O(n log n)  O(n^2)  O(n^3)
  --------------------------------------------------
  1   1        1      1        1          1        1
  2   1        1      2        2          4        8
  4   1        2      4        8         16       64
  8   1        3      8       24         64      512
  16  1        4     16       64        256     4096
*/

/*
Programming Example 2.
Write an algorithm to find the larger of two numbers.

Answer:
    Step 1: Input first number as A
    Step 2: Input second number as B
    Step 3: IF A>B
              PRINT A
            ELSE
              IF A<B
                PRINT B
            ELSE
              PRINT "The numbers are equal"
              [END OF IF]
            [END OF IF]
    Step 4: END
*/

#include <stdio.h>

void find_larger(int x, int y) {
  if (x == y) printf("The numbers are equal");
  (x > y) ? printf("%d", x) : printf("%d", y);  // ternary
}

int main() {
  find_larger(10, 20);

  return 0;
}