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
*/

/*
Programming Example
3. Write a program that shows insertion operation in an AVL tree.
*/

/*
* AVL tree
  - G.M. (A)delson-(V)elsky and E.M. (L)andis in 1962
  - self-balancing binary search tree
  - AVL visualization
    https://www.cs.usfca.edu/~galles/visualization/AVLtree.html

* why AVL tree?
  https://www.geeksforgeeks.org/avl-tree-set-1-insertion/
- Even with the same data, height of binary tree can be different.
  Height is efficiency of tree data structure.
        30-20-10    20-30-10   10-30-20
              30      20         10
             /       / \          \
           20      10  30         30
          /                       /
        10                       20
    Ht: (3)         (2)          (3)

* Balance factor = Height (left sub-tree) – Height (right sub-tree)
  - |BF| <= 1
  - if |BF| is > 1, it is imbalanced.

           45                45                45
       (3-2=1)           (2-3=-1)          (2-2=0)
         / \               / \               / \
       36  63            36  63            36  63
      (1)  (0)          (0)  (-1)         (0)  (0)
      / \  / \          / \  / \          / \  / \
    27 39 54 72       27 39 54 72       27 39 54 72
  (1) (0)(0) (0)    (0) (0)(0) (1)    (0) (0)(0) (0)
  /                           /
  18                         70
  (0)                        (0)

* Rotation
  - https://www.youtube.com/watch?v=jDM6_TnYIqE
  - TODO: the direction of rotation?

  1) LR-imbalance (LR-rotation: two steps)
      initial    add 20      L-rotation  R-rotation
      30        30 (2)          30         20
      /         / L             /          / \
    10        10 (-1)         20         10  30
              \ R           /
              20 (0)      10

 2) RR-imbalance (RR-rotation: one step)
    initial   add 30          L-rotation
    10         10 (-2)           20
     \          \ R             / \
     20         20 (-1)       10  30
                 \ R
                 30 (0)

  3) RL-imbalance (RL-rotation)
    initial  add 20    R-rotation   L-rotation
    10       10 (-2)       10         20
     \        \ R           \        / \
     30       30 (1)        20     10  30
             / L             \
           20 (0)            30

  4) LL-imbalance (LL-rotation)
    initial  add 10
       30       30 (2)
      /        /
    20       20 (1)
            /
          10 (0)

* Inserting a New Node in an AVL Tree
  - critical node (CN): balance factor is >= |2|
  - balance factor = height(Lt subtree) - height(Rt subtree)
  - LL, RR, LR, RL rotations
    - LL rotation: new node is inserted in the Lt of Lt subtree of the CN
    - RR rotation: new node is inserted in the Rt of Rt subtree of the CN
    - LR rotation: new node is inserted in the Rt of Lt subtree of the CN
    - RL rotation: new node is inserted in the Lt of Rt subtree of the CN
  - single/double rotation
    - LL,RR: single rotation
    - LR,RL: double rotation
  - calculate only two rotation even if there are more

         20(-2)
         /    \          R   This is RL, not RLL
      10(0)  30(1)
            /   \        L
         25(1) 40(0)
         /               L
      22(0) <--- new node

  T1, T2 and T3 are subtrees of the tree
  rooted with y (on the left side) or x (on the right side)
        y                               x
       / \     Right Rotation          /  \
     x   T3   - - - - - - - >        T1   y
    / \       < - - - - - - -            / \
  T1  T2     Left Rotation            T2  T3
  Keys in both of the above trees follow the
  following order: keys(T1) < key(x) < keys(T2) < key(y) < keys(T3)
  So BST property is not violated anywhere.

* LL roation
         A(1)                A(2)                 B(0)
       /     \             /     \              /     \
      B(0)   [T3]         B(1)   [T3]         [T1]    A(0)
     / \                 / \                  /       / \
  [T1] [T2]           [T1] [T2]              C     [T2] [T3]
                       /
                      C
    AVL tree (LL)         add C to tree        after rotation

        45(1)              45(2)            36(0)
        /   \              /L  \            /   \
     36(0)  63(0)       36(1)  63(0)     27(1)  45(0)
     /  \               /L \             /     /  \
  27(0) 39(0)        27(1) 39(0)      18(0)  39(0) 63(0)
                     /
                   18(0)
                          step 1.             step 2.

* RR rotation
         A(-1)              A(-2)                 B(0)
       /     \             /     \              /     \
      [T1]   B(0)        [T1]   B(-1)         A(0)   [T3]
             / \                 / \          / \       \
          [T2] [T3]           [T2] [T3]    [T2] [T3]     C
                                     \
                                      C
    AVL tree (RR)         add C to tree        after rotation

         45(-1)            45(-2)                  63(0)
         /    \            /    \R                /    \
      36(0)  63(0)      36(0)  63(-1)         45(0)    72(-1)
             /  \              /  \R           /  \       \
          53(0) 72(0)       53(0) 72(-1)   36(0) 54(0)   89(0)
                                    \
                                   89(0)
                            step 1.            step 2.

* LR rotation
         A(1)               A(2)                 C(0)
       /     \             /    \               /    \
     B(0)   [T4]        B(-1)   [T4]         B(0)   A(-1)
    /  \                /  \                 /  \    /  \
  [T1] C(0)          [T1]  C(1)           [T1] [T2] [T3] [T4]
       /  \                /  \                /
    [T2]  [T3]           [T2] [T3]            C
                         /
                        C
    AVL tree (LR)         add C to tree        after rotation

         45(1)              45(2)               39(0)
        /    \             /L   \              /    \
     36(0)  63(0)      36(-1)  63(0)       36(0)    45(-1)
     /   \              /   \R            /   \       \
  27(0) 39(0)        27(0) 39(1)       27(0) 37(0)   63(0)
                            /
                          37(0)
                        step 1.              step 2.

* RL rotation
        A(-1)               A(-2)                C(0)
       /     \             /    \               /    \
    [T1]     B(0)        [T1]   B(1)         A(0)   B(-1)
            /  \                /  \         /  \    /  \
          C(0) [T4]           C(1) [T4]   [T1] [T2] [T3] [T4]
         /  \                /  \               /
      [T2]  [T3]           [T2] [T3]           C
                          /
                         C
    AVL tree (RL)         add C to tree        after rotation

         45(-1)            45(-2)               47(0)
        /    \            /    \R              /    \
     36(0)  63(0)      36(0)  63(0)         45(0)  63(0)
           /   \             /L  \          /  \      \
         47(0) 88(0)       47(0) 88(0)   36(0) 46(0)  88(0)
                            /
                        46(0)
                        step 1.              step 2.
*/

#include <stdio.h>
#include <stdlib.h>

typedef enum { FALSE, TRUE } bool;

struct node {
  int val;
  int balance;  // store balance factor
  struct node *left_child;
  struct node *right_child;
};

struct node *search(struct node *ptr, int data);
struct node *insert(int data, struct node *ptr, bool *ht_inc);
void display(struct node *ptr, int level);
void inorder(struct node *ptr);

int main() {
  bool ht_inc;
  int data;
  int option;
  struct node *root = (struct node *)malloc(sizeof(struct node));
  root = NULL;

  while (1) {
    printf("1.Insert\n");
    printf("2.Display\n");
    printf("3.Quit\n");

    printf("Enter your option: ");
    scanf("%d", &option);

    switch (option) {
      case 1:
        printf("Enter the value to be inserted : ");
        scanf("%d", &data);
        /* if not already exists */
        if (search(root, data) == NULL) root = insert(data, root, &ht_inc);
        /* if already exists */
        else
          printf("Duplicate value ignored\n");
        break;
      case 2:
        /* if empty tree */
        if (root == NULL) {
          printf("Tree is empty\n");
          continue;
        }
        printf("Tree is:\n");
        display(root, 1);
        printf("\n\n");
        printf("Inorder Traversal is: ");
        inorder(root);
        printf("\n");
        break;
      case 3:
        exit(1);
      default:
        printf("Wrong option\n");
    }
  }
}

struct node *search(struct node *ptr, int data) {
  if (ptr != NULL)
    if (data < ptr->val)
      ptr = search(ptr->left_child, data);
    else if (data > ptr->val)
      ptr = search(ptr->right_child, data);
  return (ptr);
}

struct node *insert(int data, struct node *ptr, bool *ht_inc) {
  struct node *aptr;
  struct node *bptr;
  if (ptr == NULL) {
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->val = data;
    ptr->left_child = NULL;
    ptr->right_child = NULL;
    ptr->balance = 0;
    *ht_inc = TRUE;
    return (ptr);
  }
  if (data < ptr->val) {
    ptr->left_child = insert(data, ptr->left_child, ht_inc);
    if (*ht_inc == TRUE) {
      switch (ptr->balance) {
        case -1: /* Right heavy */
          ptr->balance = 0;
          *ht_inc = FALSE;
          break;
        case 0: /* Balanced */
          ptr->balance = 1;
          break;
        case 1: /* Left heavy */
          aptr = ptr->left_child;
          if (aptr->balance == 1) {
            printf("Left to Left Rotation\n");
            ptr->left_child = aptr->right_child;
            aptr->right_child = ptr;
            ptr->balance = 0;
            aptr->balance = 0;
            ptr = aptr;
          } else {
            printf("Left to right rotation\n");
            bptr = aptr->right_child;
            aptr->right_child = bptr->left_child;
            bptr->left_child = aptr;
            ptr->left_child = bptr->right_child;
            bptr->right_child = ptr;
            if (bptr->balance == 1)
              ptr->balance = -1;
            else
              ptr->balance = 0;
            if (bptr->balance == -1)
              aptr->balance = 1;
            else
              aptr->balance = 0;
            bptr->balance = 0;
            ptr = bptr;
          }
          *ht_inc = FALSE;
      }
    }
  }
  if (data > ptr->val) {
    ptr->right_child = insert(data, ptr->right_child, ht_inc);
    if (*ht_inc == TRUE) {
      switch (ptr->balance) {
        case 1: /* Left heavy */
          ptr->balance = 0;
          *ht_inc = FALSE;
          break;
        case 0: /* Balanced */
          ptr->balance = -1;
          break;
        case -1: /* Right heavy */
          aptr = ptr->right_child;
          if (aptr->balance == -1) {
            printf("Right to Right Rotation\n");
            ptr->right_child = aptr->left_child;
            aptr->left_child = ptr;
            ptr->balance = 0;
            aptr->balance = 0;
            ptr = aptr;
          } else {
            printf("Right to Left Rotation\n");
            bptr = aptr->left_child;
            aptr->left_child = bptr->right_child;
            bptr->right_child = aptr;
            ptr->right_child = bptr->left_child;
            bptr->left_child = ptr;
            if (bptr->balance == -1)
              ptr->balance = 1;
            else
              ptr->balance = 0;
            if (bptr->balance == 1)
              aptr->balance = -1;
            else
              aptr->balance = 0;
            bptr->balance = 0;
            ptr = bptr;
          } /*End of else*/
          *ht_inc = FALSE;
      }
    }
  }
  return (ptr);
}

void display(struct node *ptr, int level) {
  int i;
  if (ptr != NULL) {
    display(ptr->right_child, level + 1);
    printf("\n");
    for (i = 0; i < level; i++) printf(" ");
    printf("%d", ptr->val);
    display(ptr->left_child, level + 1);
  }
}

void inorder(struct node *ptr) {
  if (ptr != NULL) {
    inorder(ptr->left_child);
    printf("%d ", ptr->val);
    inorder(ptr->right_child);
  }
}