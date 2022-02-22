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
10.3 Threaded binary trees
  One-way threading
  Two-way threading
  10.3.1 Traversing a threaded binary tree (Program example 2)
10.4 AVL trees
  10.4.1 Operations on AVL trees
    Searching for a node in an AVL tree
    Inserting a new in an AVL tree
    LL rotation (Example 10.3)
    RR rotation
    LR and RL rotations (Example 10.4 ~ 10.6)
    Deleting a node from an AVL tree
    R0 rotation
    R1 rotation (Example 10.7 ~ 10.8)
    R1 rotation (Example 10.9 ~ 10.10) (Program example 3)
10.5 Red-black trees
  10.5.1 Properties of red-black trees
  10.5.2 Operations on red-black trees
    Inserting a node in a red-black tree
    Deleting a node from a red-black tree
  10.5.3 Applications of red-black trees
10.6. SPlay tree
  10.6.1 Operations on Splay trees
    Splaying (Example 10.11)
    Searching for a node in a Splay tree (Example 10.12 ~ 13)
    Deleting a node from a Splay tree
  10.6.2 Advantages and disadvantages of Splay trees
*/

/*
Programming Example
5. Write a program that shows insertion operation in an splay tree.
*/

/*
* Zig, Zig-Zig, Zig-Zag steps
  1) Zig step
    - P is root

      P           N
     / \         / \
    N*  c   =>  a   P
   / \             / \
  a   b           b   c

  2) Zig-zig step 
    - P is not root

         G               P              N
        / \             / \            / \
       P*  d   =>      N*  G    =>    a   P
      / \             / \ / \            / \
     N   c           a  b c  d          b   G
    / \                                    / \
   a   b                                  c   d

  3) Zig-zag step 
    - P is not root

         G              G                 N
        / \            / \               / \
       P   d   =>     N*  d    =>       P   G
      / \            / \               / \ / \
     a   N*         P   c             a  b c  d
        / \        / \
       b   c      a   b

* Inserting a node in a Splay Tree
  - inserting 81
         54                 54                  54                 54
       /    \             /    \              /    \             /    \
      39    63           39    63            39    63           39    63
     /  \     \         /  \      \         /  \      \        /  \     \
    9   45    90       9   45     90       9   45     90      9   45    81*
     \       /  \       \        /  \       \        /  \      \       /  \
     27     72  99      27      72  99      27      81* 99     27     72  90
     /                  /        \          /      /           /            \
    18                 18        81*       18     72          18            99
    (a)                (b) add 81 to tree  (c) Zig-Zag

           54                     63                    81*
         /    \                 /    \                /    \
        39    63               54    81*             63    90
       /  \     \             /     /  \            /  \     \
      9   45    81*          39    72  90          54  72    99
       \       /  \         /            \        /
       27     72  90       9             99      39
       /            \       \                   /
      18            99       27                 9
                            /                    \
                           18                    27
                                                /
                                               18
    (d) Zig-Zig

* Searching a node in a Splay Tree
  - searching for 81
          54                 54                      54
        /    \             /    \                  /    \
      39     63           39    63               39     72*
     /  \      \         / \      \            /  \     /  \
    9   45     90       9  45     72          9   45   63  90
              /  \                  \                        \
             72* 99                 90                       99
                                      \
                                      99
         Zig-Zag step

           54                           72
         /    \                       /    \
       39     72*                   54     90
     /  \     /  \                 /  \      \
    9   45   63  90              39   63     99
                   \             /
                   99           9
        Zig step

* Deleting a node in a Splay Tree
  http://lcm.csa.iisc.ernet.in/dsa/node94.html

             80                      80                  50
           /    \                  /    \              /    \
          60    90                60    90            20    60
        /  \      \              /  \     \          / \      \
       50  70     100           50* 70    100      10  40     80
      /                        /                    \         / \
     30*                      20                    15       70  90
    /  \                     /  \                                 \
  10   40                   10  40                                100
   \                         \
   20                        15
   /
  15
*/