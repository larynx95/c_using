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
*/

/*
Programming Example
4. Write a program that shows insertion operation in an red black tree.
*/

/*
* Is RB tree is binary tree? Yes.

* Properties of Red-black tree
  1. The colour of a node is either red or black.
  2. The colour of the root node is always black.
  3. All leaf nodes are black.
  4. Every red node has both the children coloured in black.
  5. Every simple path from a given node to any of its leaf nodes
     has an equal number of black nodes.

               16b             root is black (ok)
            /      \
           9r       27r
         /  \       /  \
        7b   11b   21b  45b    children of red nodes are all blcak (ok)
       / \   / \   / \  / \
      X 11r  X X   X X  X X    the number of black nodes
         / \                   from root to leaves is ONE
         X X                   all leaves are black (ok)

* Black Height (BH)
  - the number of black nodes on any simple path from a node x
    (not including it) to a leaf
  - Example
                                     symbol
                     B?*             0 : leaf, black
                 /       \           B : black node
               R?*        R2         R : red node
             /   \       /   \       number: BH
            R1*   B1    B1    B1
           / \   / \   / \   / \     This example breaks 4 & 5th rule.
          0  R1 0  0  0  0  R1  R1
            / \            / \ / \
            0 0            0 0 0 0

* New node is always red-colored.

* Rotation
  - Left-rotation
       p         p                  P          P
       |         |                  |          |
       X         X             X    Y          Y
      / \       / \           / \    \        / \
     a   Y     a   b   Y     a   b    c      X   c
        / \             \                   / \
       b   c             c                 a   b
      (a)         (b)            (c)          (d)

  - Right-rotation
         p              p         p
         |              |         |
         Y              Y         X
        / \            / \       / \
       X   a       X  b   a     c   Y
      / \         /                / \
     c   b       c                b   a
      (a)          (b)            (c)

  - Left-Right rotation
         p             p           p
         |             |           |
         Z             Z*          Y
        / \           / \         / \
       X*  d         Y*  d       X   Z
      / \           / \         / \ / \
     a   Y*        X   c        a b c d
        / \       / \
       b   c     a   b

  - Right-Left rotation
         p              p              p
         |              |              |
         Z              Z*             Y
        / \            / \            / \
       d   X*         d   Y*         Z   X
          / \            / \        / \ / \
         Y*  a          c   X       d c b a
        / \                / \
       c   b              b   a

* Inserting a new node (N) in a Red-Black Tree

          Nr
         / \
        X   X      new node and it's two black leaves

  Case 1. N is root
    - violate property-2 (Root black)
    - recolor Nr -> Nb
          Nb
         / \
        X   X

  Case 2. Black P
    - no violation
                Rb
              /   \
            Gr     r
           / \    / \
          Pb  b  b   b
         / \    / \ / \
        Nr  X  X  X X  X
       / \
      X   X

  Case 3. Red P & U (-> color flip)
    1) P's Lt
      - violate property-4
      -> color-flip: repaint P&U to black, G to red
      -> violate property-2, 4
      -> recursive Case 1.

            Gb               Gr*              Gb*
          /    \           /    \           /    \
         Pr    Ur         Pb*   Ub*        Pb    Ub
       /  \   /  \       /  \  /  \       /  \  /  \
      x   x x    x     Nr  x  x   x     Nr  x  x   x
     / \               / \              / \
    x   x             x   x            x   x
      repaint: Gb->Gr, Pr/Ur->Pb/Ub     Gr is root, Gr->Gb

    2) P's Rt
          Gb               Gr*              Gb*
        /    \           /    \           /    \
       Ur    Pr         Ub    Pb*        Ub    Pb
     /  \   /  \       /  \  /  \       /  \  /  \
    x    x x    Nr    x   x  x   Nr    x   x  x   Nr
               / \              / \              / \
              x   x            x   x            x   x


  Case 4. Red P, Black U
    1) LL case
      - violate property-4
        -> Right rotation
        -> violate property-2, 4, 5
        -> repaint: Pr->Pb, Gb -> Gr
              Gb                Pr*                Pb
            /    \            /    \             /    \
           Pr*    Ub        Nr      Gb*        Nr      Gr
         /  \    /  \      /  \    /  \       /  \    /  \
        Nr*  c  d    e    a    b  c   Ub     a    b  c   Ub
       / \                            / \                / \
      a   b                          d   e              d   e
      Rt-rotate G         swap colors of G & P

    2) RR case
              Gb                  Pr*                Pb*
            /    \              /    \             /    \
           Ub     Pr*         Gb*     Nr         Gr      Nr
         /  \    /  \        /  \    /  \       /  \    /  \
        a    b  c    Nr*    Ub   c  d    e     Ub   c  d    e
                    / \    / \                / \
                   d   e  a   b              a   b
      Lt-rotate G           swap colors of G & P

    3) LR case
            Gb                 Gb               Nb
          /    \             /    \           /    \
         Pr*    Ub          Nr     Ub       Pr     Gr
       /  \    /  \       /  \    /  \     /  \    /  \
      a   Nr* d    e     Pr   c  d    e   a    b  c   Ub
          / \           / \                           / \
         b   c         a   b                         d   e
      Lt-rotate P      apply LL case

    4) RL case

            Gb                 Gb                  Nb
          /    \             /    \              /    \
         Ub     Pr*         Ub     Nr           Gr    pr
       /  \    /  \       /  \    /  \        /  \    /  \
      a    b  Nr*  e     a    b  c   Pr      Ub  c   d    e
             / \                     / \    / \
            c   d                   d   e  a   b
    Rt-rotate P          apply RR case

*/
