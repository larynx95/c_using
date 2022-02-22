/* Data Structures Using C, 2nd, Reema Thareja
Chapter 12. Heaps

# https://www.geeksforgeeks.org/building-heap-from-array/

    Input: arr[] = {4, 10, 3, 5, 1}
    Output: Corresponding Max-Heap:
          10
        /   \
        5     3
      /  \
      4    1

    Input: arr[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17}
    Output: Corresponding Max-Heap:
                    17
                  /      \
                15         13
              /    \      /  \
            9      6    5   10
           / \   /  \
          4  8  3    1

          4
        /   \
        10    3
      /  \
      5    1

    Note:
    Root is at index 0 in array.
    Left child of i-th node is at (2*i + 1)th index.
    Right child of i-th node is at (2*i + 2)th index.
    Parent of i-th node is at (i-1)/2 index.

# https://www.youtube.com/watch?v=HqPJF2L5h9U (Don't miss this video.)
# Array representation of binary trees

         A                         A                        A
       / \                       / \                      / \
      B   C                     B  C                     B  C
     / \ / \                   / \                         / \
    D E  F G                  D  E                        D  E
    1234567                   1234567                  1234567
    ABCDEFG                   ABCDE--                  ABC--DE (missing elems)
    full/complete BT          complete BT              incomplete BT

  if a node is at index: i
  its Lt-child is at   : 2*i
  ist Rt-chid is at    : 2*i+1
  its parent is at     : i/2

# full/complete/incomplete binary tree
- full BT: in its height, it has maximum number of nodes: 2^(h+1) - 1
- complete BT: no missing element
- incomplete BT: has missing elements (third in above figure)

# max/min heap
            50  largest               10  smallest
           / \                       / \
         30  20                    30  20
        / \  / \                  / \  / \
      15 10 8 16                35 40 32 25

      50 30 20 15 10 8 16      10 30 20 35 40 32 25

# insertion
         add 60                             result
            50                                60
           / \                               / \
         30  20                            50  20
        / \  / \                          / \  / \
      15 10 8 16                        30 10 8 16
     /                                 /
    60                                15

    50 30 20 15 10  8 16 +60          60 50 20 30 10 8 16 15
idx: 1  2  3  4  5  6  7  8
              * arr[8/2]
        * arr[4/2]  <--
     * arr[2/2]  <--

# deletion (only root element)
        1) delete 50             2) move 16 (for complete tree rule)
            *                                 16
           / \                               / \
         30  20                            30--20  compare
        / \  / \                          / \  /
      15 10 8 16                        15 10 8

    * 30 20 15 10  8 16               16 50 20 30 10 8

    3) result
             30
            / \
          16  20
         / \  /
       15--10 8  compare(X)

       30 10 20 15 10  8 (50)  <--- sequential deletion do the heap-sort
    idx 1  2  3  4  5  6  7

# heap-sort: insert-deletion, two steps
1) insertion, nlogn
  id 1  2  3  4  5
    10 20 15 30 40

        10       20       20           30            40
                /        / \          / \           / \
              10        10 15       20  15        30  15
                                    /             / \
                                  10            10 20
  array 10    20-10     10-10-15  30-20-15-10   40-30-15-10-20 O(nlogn)
2) deletion, nlogn
        40*             20                30
       / \             / \               / \
     30  15          30  15            20  15
    / \             /                 /
  10  20          10                10
  40 30 15 10 20  20 30 15 10(40)  30 20 15 10(40)

        30*             10               20
       / \             / \              / \
     20  15          20  15           10  15
    /
  10
  30 20 15 10(40)  30 20 15(30)(40)   20 10 15(30)(40)

        20*              15
       / \              /
      10 15            10
  20 10 15(30)(40)    15 10 (20)(30)(40)

        15*                10
       /
      10
  15 10 (20)(30)(40)   10 (15)(20)(30)(40)

# heapify (look downward, topdown approach), O(n)
        10                     10
       / \                    / \
     20  15                 40  25   *
    / \  / \               / \  / \
  12 40 25 18 *          12 20 15 18

  10 20 15 12 40 25 18   10 40 25 12 20 15 18
  1  2  3  4  5  6  7

        40  *                  40
       / \                    / \
     10  25                 20  25
    / \  / \               / \  / \
  12 20 25 18            12 10 15 18
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
  //
  return 0;
}