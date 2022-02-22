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
11.5 trie
  Advantages relative to binary search tree
  Advantage relative to hash table
  Disadvantages
*/

/*
* trie
  https://www.cs.bu.edu/teaching/c/tree/trie/
           root
     /      |       \
     t      a        b
     |      |        |
     h      n        y
     |      |  \     |
     e      s  y     e
  /  |      |
  i  r      w
  |  |      |
  r  e      e
            |
            r
  
*/

#include <stdio.h>
#include <stdlib.h>
