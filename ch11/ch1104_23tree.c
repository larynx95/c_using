/* Data Structures Using C, 2nd, Reema Thareja
Chapter 11. Multi-way Search Trees
11.1 Introduction
11.2 B tree
  11.2.1 Searching for an element in a B tree
  11.2.2 Inserting a new element in a B tree
  11.2.3 Deleting an element from a B tree
  11.2.4 Applications of B trees
11.3 B* trees
  11.3.1 Inserting a new element in a B+ tree
  11.3.2 Deleting an element from a B+ tree
11.4 2-3 trees
  11.4.1 Searching fro an element in a 2-3 tree
  11.4.2 Inserting a new element in a 2-3 tree
  11.4.3 Deleting an element from a 2-3 tree
*/

/*
# 2-3 tree Rules
- each non-leaf can have 2 or 3 children
- each node can have 1 or 2 keys (respectively)
- each leaf will be at the same level of the tree

# 2-3 tree insertion (bottom-up, not top-down)
  https://www.youtube.com/watch?v=bhKixY-cZHE
  50 60 70 40 30 20 10 80 90 100

  50-60    60        60       40-60        40-60
          / \       / \      /  \  \       / \  \
        50  70  40-50 70   30  50  70  20-30 50 70

         40          40             40             40
       /   \       /   \          /   \          /   \
     20    60     20    60      20    60-80    20    60-80
    / \   / \    / \   / \     / \   / \ \    / \   / \  \
  10  30 50 70  10 30 50 70  10 30 50 70 90  10 30 50 70 90-100



*/

#include <stdio.h>
#include <stdlib.h>
