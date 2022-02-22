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
*/

/*
* B tree vs. B+ tree
  b Tree
  1. Search keys are not repeated
  2. Data is stored in internal or leaf nodes
  3. Searching takes more time as data may be found in a leaf or non-leaf node
  4. Deletion of non-leaf nodes is very complicated
  5. Leaf nodes cannot be stored using linked lists
  6. The structure and operations are complicated

  b+ Tree
  1. Stores redundant search key
  2. Data is stored only in leaf nodes
  3. Searching data is very easy as the data can be found in leaf nodes only
  4. Deletion is very simple because data will be in the leaf node
  5. Leaf node data are ordered using sequential linked lists
  6. The structure and operations are simple

* Properties of B+ tree (order of m)
  - All leaves are at the same level.
  - The root has at least two children.
  - Each node except root can have a maximum of [m] children 
                                 and at least [m/2] children.
  - Each node can contain a maximum of [m - 1] keys 
                      and a minimum of ⌈m/2⌉ - 1 keys.

                            B+ tree, order of 3
                               [*13*]  
                   /                            \       
            [*4*7*]                              [*17*20*]
        /      |       \                    /        |       \
  [*1*3*] -> [*5*6*] -> [*8*11*] -> [*14*16*] -> [*18*19*] -> [23*24*]                    

* Inserting a New Element in a B+ Tree
  Step 1:  Insert the new node as the leaf node. 
  Step 2:  If the leaf node overflows, 
           split the node and copy the middle element to next index node. 
  Step 3:  If the index node overflows, 
           split that node and move the middle element to next index page.

* Example of insertion (order 4)

              10-20-30
           /   /   \   \ 
  [3-6-9]->[15]->[27]->[32-34-48]

  [*10*20*30*] ┌ [*3*6*9*]
               ├ [*15*]
               ├ [*27*]
               └ [*32*34*48*]

  [*10*20*30*] ┌ [*3*6*9*]
               ├ [*15*]
               ├ [*27*]
               └ [*32*(33)*34*48*]   // insert 33

  [*10*20*30*] ┌ [*3*6*9*]
               ├ [*15*]
               ├ [*27*]
               ├ [*32*33*]           // split leaf
               └ [*34*48*]

  [*20*] ┌ [*10*] ┌ [*3*6*9*]
         │        └ [*15*]
         │
         └ [*30*34*] ┌ [*27*]
                     ├ [*32*33*]
                     └ [*34*48*]

* Deleting an Element in a B+ Tree    
  Step 1: Delete the key and data from the leaves. 
  Step 2: If the leaf node underflows, 
          merge that node with the sibling and delete the key in between them. 
  Step 3: If the index node underflows, 
          merge that node with the sibling and move down the key in between them.

* Example of deletion

                   [*20*]
              /             \
         [*15*]              [*30*34*]
          /  \            /      |     \
  [*3*6*9*]->[*15*]->[*27*]->[*32*33*]->[*34*48*]

                   [*20*]
              /             \
         [*15*]              [*30*34*]
          /  \            /      |     \
  [*3*6*9*]->  (X)  ->[*27*]->[*32*33*]->[*34*48*]

                   [*20*]
              /             \
           (X)              [*30*34*]
          /  \            /      |     \
  [*3*6*9*]->[*27*]->[*32*33*]->[*34*48*]

               [*20*30*34*]
          /                     \
  [*3*6*9*]->[*27*]->[*32*33*]->[*34*48*]
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
  printf("B plus tree");
  return 0;
}