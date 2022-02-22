/* Data Structures Using C, 2nd, Reema Thareja
Chapter 10. Efficient Binary Trees
10.1 Binary search trees (Example 10.1 ~ 10.2)
10.2 Operations on binary search trees
  10.2.1 Searching for a node in a binary search tree
  10.2. Inserting a new node in a binary search tree
  10.2.3 Deleting a node from a binary search tree
    Case 1: Deleting a node that has no children
    Case 2: Deleting a node with one child
    Case 3: Deleting a node with two children
  10.2.4 Determining the height of a binary search tree
  10.2.5 Determining the number of nodes
    Determining the number of internal nodes
    Determining the number of external nodes
  10.2.6 Finding the mirror image of a binary search tree
  10.2.7 Deleting a binary search tree
  10.2.8 Finding the smallest node in a binary search tree
  10.2.9 Finding the largest node in a binary search tree
         (Program example 1)
*/

/*
Programming Example
1. Write a program to create a binary search tree and perform all the operations
discussed in the preceding sections. (TODO: array version)

TODO: array version of binary tree structure
min/max heap (array or binary tree)
https://www.youtube.com/watch?v=HqPJF2L5h9U

* Array version of max-heap (breadth-first order)
             8
           /  \
          4    6
         / \  / \
        1  2  3  5

  index    : 0 1 2 3 4 5 6
  max-heap : 8 4 6 1 2 3 5

  value of node      : 4    2    6    1     general
  ------------------------------------------------
  idx of current node: 1    4    2    3     i
  idx of Lt. child   : 3(1) -    5(3) -     2*i + 1
  idx of Rt. child   : 4(2) -    6(5) -     2*i + 2
  idx of parent      : 0(8) 1(4) 0(8) 1(4)  (i-1) / 2

  TODO: Why array version of heap should be constructed
        by breadth-first order?

* Aray version of min-heap (breadth-first order)

                      0
                   /    \
                 1        3
               / \        / \
             2    5      4   6
            / \  / \    / \  / \
           7 11 12 14  8  9 10 13

  index: 0  1  2  3  4  5  6  7  8  9 10 11 12 13 14
  heap : 0  1  3  2  5  4  6  7 11 12 14  8  9 10 13

  value of node      :  1      5      4      9   general
  -----------------------------------------------------
  idx of current node:  1      4      5     12   i
  idx of Lt. child   :  3(2)   9(12) 11(8)   -   2*i + 1
  idx of Rt. child   :  4(5)  10(14) 12(9)   -   2*i + 2
  idx of parent      :  0(0)   1(1)   2(3) 5(4)  (i-1) / 2

* Array version of max-heap (in-order traversal)
             8
           /  \
          4    6
         / \  / \
        1  2  3  5

  index    : 0 1 2 3 4 5 6
  max-heap : 1 4 2 8 3 6 5

  value of node      : 8    4    6    2    general
  ------------------------------------------------
  idx of current node: 3    1    5    2    TODO: no general rule!
  idx of Lt. child   : 1(4) 0(1) 4(3) -
  idx of Rt. child   : 5(6) 2(2) 6(5) -
  idx of parent      : -    3(8) 3(8) 1(4)

  Finding general rule
  i   Lt.         i   Rt.          i   Root
  -----------------------------------------
  3 -> 1          3 -> 5           1 -> 3
  1 -> 0          1 -> 2           5 -> 3
  5 -> 4          5 -> 6           2 -> 1

  ax + b = y... There's no general rule.

* Array version of max-heap (pre-order traversal)
             8
           /  \
          4    6
         / \  / \
        1  2  3  5

  index    : 0 1 2 3 4 5 6
  max-heap : 8 4 1 2 6 3 5

  value of node      : 8    4    6    2    general
  ------------------------------------------------
  idx of current node: 0    1    4    3    TODO: no general rule!
  idx of Lt. child   : 1(4) 2(1) 5(3) -
  idx of Rt. child   : 4(6) 3(2) 6(5) -
  idx of parent      : -    0(8) 0(8) 1(4)

* Array version of max-heap (post-order traversal)
             8
           /  \
          4    6
         / \  / \
        1  2  3  5

  index    : 0 1 2 3 4 5 6
  max-heap : 1 2 4 3 5 6 8

  value of node      : 8    4    6    2    general
  ------------------------------------------------
  idx of current node: 6    2    5    1    TODO: no general rule!
  idx of Lt. child   : 2(4) 0(1) 3(3) -
  idx of Rt. child   : 5(6) 1(2) 4(5) -
  idx of parent      : -    6(8) 6(8) 2(4)

* initilaize tree
- ML: predefined maximum length of tree (array)
- initialize array with unused value (e.g. negative number -1)

* insert node (or value) to tree
  a. if array[0] is -1, then tree array is empty.
  b. if array[0] is not -1, then tree array is not emepty.
    a) if value is less than array[0], then check left subtree.
    b) if value is greater than array[0], then check right subtree.

* delete node (or value) from tree


*/

#include <stdio.h>
#include <stdlib.h>

#define ML 10  // max length of array

void init_tree(int *);
void ins_val(int *);
void del_val(int *, int);
int height(int *);
void print_tree(int *);

int main() {
  // initialize array
  int tree[ML];
  init_tree(tree);

  return 0;
}

void init_tree(int *tree) {
  for (int i = 0; i < ML; i++) tree[i] = -1;
}

void ins_val(int *tree) {}

void del_val(int *tree, int val) {}

void print_tree(int *tree) {}

int height(int *tree) {}