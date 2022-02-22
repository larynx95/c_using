/* Data Structures Using C, 2nd, Reema Thareja
Chapter 11. Multi-way Search Trees
11.1 Introduction
11.2 B tree
  11.2.1 Searching for an element in a B tree
  11.2.2 Inserting a new element in a B tree
  11.2.3 Deleting an element from a B tree
  11.2.4 Applications of B trees
*/

/*
* B tree (Rudolf Bayer and Ed McCreight in 1970)
  - specialized M-way tree

* properties of B tree
  1. Every node in the B tree has at most (maximum) [m] children.
  2. Every node in the B tree except the root node and leaf nodes
     has at least (minimum) [m/2] children.
     This condition helps to keep the tree bushy
     so that the path from the root node to the leaf is very short,
     even in a tree that stores a lot of data.
  3. The root node has at least two children
     if it is not a terminal (leaf) node.
  4. All leaf nodes are at the same level.

  https://www.geeksforgeeks.org/introduction-of-b-tree-2/
  - All leaves are at the same level.
  - A B Tree is defined by the term minimum degree ‘t'. The value of t depends
    upon disk block size.
  - Every node except root must contain at least t-1 keys. The root may contain
    minimum 1 key.
  - All nodes (including root) may contain at most 2t – 1 keys.
  - Number of children of a node is equal to the number of keys in it plus 1.
  - All keys of a node are sorted in increasing order. The child between two
    keys k1 and k2 contains all keys in the range from k1 and k2.
  - B Tree grows and shrinks from the root which is unlike Binary Search Tree.
    Binary Search Trees grow downward and also shrink from downward.
  - Like other balanced Binary Search Trees, time complexity to search, insert
    and delete is O(log n).

* Example
  - column style
                              [*45*]
                      /                     \
              [*29*32*]                       [*49*63*]
            /     |    \                   /     |      \
    [*18*27*] [*30*31*] [*36*39*] [*46*47*] [*54*59*61*] [*67*72*]

  - row style
    [*45*] ┌ [*29*32*] ┌ [*18*27*]
           │           ├ [*30*31*]
           │           └ [*36*39*]
           │
           └ [*49*63*] ┌ [*46*47*]
                       ├ [*54*59*61*]
                       └ [*67*72*]

* Inserting a New Element in a B Tree (m = 4, degree = 5)
  - cases
    1. search the B tree to find the leaf node
       where the new key value should be inserted.
    2. if the leaf node is not full
    3. if the leaf node is full
      - insert the new value in order into the existing set of keys
      - split the node at its median into two nodes
      - push the median element up to its parent's node

* Example of inserting
  - if leaf node is not full
    [*18*45*72*] ┌ [*7*71]            // B tree of order 4
                 ├ [*21*27*36*42]
                 ├ [*54*63*]
                 └ [*81*89*90*]

    [*18*45*72*] ┌ [*7*(8)*71]        // insert 8
                 ├ [*21*27*36*42]
                 ├ [*54*63*]
                 └ [*81*89*90*]

    [*18*45*72*] ┌ [*7*8*(9)*71]      // insert 9
                 ├ [*21*27*36*42]
                 ├ [*54*63*]
                 └ [*81*89*90*]

  - if leaf node is full
    [*18*45*72*] ┌ [*7*8*9*71]
                 ├ [*21*27*36*39*42]  // insert 39, 5 > m !!
                 ├ [*54*63*]
                 └ [*81*89*90*]

    [*18*36*45*72*] ┌ [*7*8*9*71]
                    ├ [*21*27*]   // split, median (36) to parent
                    ├ [*39*42*]
                    ├ [*54*63*]
                    └ [*81*89*90*]

  - if parent node is full
    [*18*36*45*72*] ┌ [*3*7*8*9*71]
                    ├ [*21*27*]
                    ├ [*39*42*]
                    ├ [*54*63*]
                    └ [*81*89*90*]

* Deleting an element from a b Tree (m = 4)
  1. Deleting leaf node (LN)
    1) Locate the LN which has to be deleted, and delete it.
    2) If the LN contains more than m/2 elements -> OK 
    3) Else if the leaf node does not contain m/2 elements -> NOT OK
      (1) If Lt or Rt sibling has more than m/2 elements,
        A. If Lt sibling has more than m/2 elements, 
           push its largest key into its parent's node
           and pull down the intervening element from the parent node
           to the leaf node where the key is deleted
        B. If Rt sibling has more than m/2 elements,
           push its largest key into its parent's node
           and pull down the intervening element from the parent node
           to the leaf node where the key is deleted
      (2) If both Lt and Rt siblings have only m/2 elements,
    4) If both Lt and Rt siblings contain only the min number of elements, 
      combining the two leaf nodes & the intervening element of the parent node 
      (ensuring that the number of elements does not exceed 
      the maximum number of elements a node can have, that is, m). 
      If pulling the intervening element from the parent node leaves it 
      with less than the minimum number of keys in the node, 
      then propagate the process upwards, 
      thereby reducing the height of the B tree.
  2. Deleting internal node

* Example of deleting (m = 4)
  - delete 93
    [*108*] ┌ [*63*81*] ┌ [*36*45*]
            │           ├ [*72*79*]
            │           └ [*90*(93)*101*]
            │
            └ [*117*201*] ┌ [*111*114*]
                          ├ [*151*180*]
                          └ [*243*256*333*450*]

  - delete 201, 2 !> m/2
    [*108*] ┌ [*63*81*] ┌ [*36*45*]
            │           ├ [*72*79*]
            │           └ [*90*101*]
            │
            └ [*117*(201)*] ┌ [*111*114*]
                            ├ [*151*180*]
                            └ [*243*256*333*450*]

  - delete 180
    [*108*] ┌ [*63*81*] ┌ [*36*45*]
            │           ├ [*72*79*]
            │           └ [*90*101*]
            │
            └ [*117*243*] ┌ [*111*114*]
                          ├ [*151*(180)*]
                          └ [*256*333*450*]

    [*108*] ┌ [*63*81*] ┌ [*36*45*]
            │           ├ [*72*79*]
            │           └ [*90*101*]
            │
            └ [*117*243*] ┌ [*111*114*]
                          ├ [*151*]
                          └ [*256*333*450*]

    [*108*] ┌ [*63*81*] ┌ [*36*45*]
            │           ├ [*72*79*]
            │           └ [*90*101*]
            │
            └ [*117*256*] ┌ [*111*114*]
                          ├ [*151*243*]
                          └ [*333*450*]

  - delete 72
    [*108*] ┌ [*63*81*] ┌ [*36*45*]
            │           ├ [*(72)*79*]
            │           └ [*90*101*]
            │
            └ [*117*256*] ┌ [*111*114*]
                          ├ [*151*243*]
                          └ [*333*450*]

    [*108*] ┌ [*63*81*] ┌ [*36*45*]
            │           ├ [*79*]
            │           └ [*90*101*]
            │
            └ [*117*256*] ┌ [*111*114*]
                          ├ [*151*243*]
                          └ [*333*450*]

    [*108*] ┌ [*63*81*] ┌ [*36*45*]
            │           ├ [*79*]
            │           └ [*90*101*]
            │
            └ [*117*256*] ┌ [*111*114*]
                          ├ [*151*243*]
                          └ [*333*450*]

* B tree
- http://www.cs.yale.edu/homes/aspnes/pinewiki/BTrees.html
- https://stuff.mit.edu/afs/sipb/user/gamadrid/nscript/btree.c
*/

#include <stdio.h>
#include <stdlib.h>
