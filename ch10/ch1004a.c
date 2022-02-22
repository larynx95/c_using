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
* TODO:
  - What is the red-black trees?
  - What is the rules of red-black trees?
  - Which action would be needed if I add or delete node?

* Programiz: https://www.programiz.com/dsa/red-black-tree
* GeeksforGeeks: Red-Black Tree | Set 1 (Introduction) O(log n)
  https://www.geeksforgeeks.org/red-black-tree-set-1-introduction-2/

* Rule of Red-Black Trees
  Red-Black Tree is a self-balancing Binary Search Tree (BST) where every node
  follows following rules. RedBlackTree
  1. The colour of a node is either red or black. (easy)
  2. The colour of the root node is always black. (easy)
  3. All leaf nodes are black. (easy)
  4. Every red node has both the children coloured in black. (easy)
  5. Every simple path from a given node to any of its leaf nodes has an equal
  number of black nodes. (TODO: ??)

  A chain of 3 nodes is nodes is not possible in Red-Black Trees.
  Following are NOT Red-Black Trees
          30             30               30
        / \            /  \             /  \
      20  NIL         20*  NIL         20*  NIL
      / \             / \              /  \
    10  NIL          10  NIL          10* NIL
  Violates          Violates        Violates
  Property 4.      Property 4       Property 3

  Following are different possible Red-Black Trees with above 3 keys
          20                           20
        /   \                        /   \
      10     30                    10*    30*
      /  \   /  \                 /  \    /  \
  NIL  NIL NIL NIL             NIL  NIL NIL NIL

* Insertion steps
  1. standard BST insertion and make the color of newly inserted nodes as RED.

  2. If x is root, change color of x as BLACK (Black height of complete tree
  increases by 1).

  3. Do following if color of x’s parent is not BLACK and x is not root.
  a) If x’s uncle is RED (Grand parent must have been black from property 4)
    (i) Change color of parent and uncle as BLACK.
    (ii) color of grand parent as RED.
    (iii) Change x = x’s grandparent, repeat steps 2 and 3 for new x.

               g               g* <-- new x
             /   \           /   \      i) change color of P and U
            p*   u*         p    u      ii) change color of GP as RED
           / \  / \        / \  / \     iii) change x = x's GP,
         x* T3 T4 T5     x* T3 T4 T5         repeat step 2, 3 for new x
        / \             / \
       T1 T2  T1 T2    T1 T2

  b) If x’s uncle is BLACK, then there can be four configurations for x, x’s
  parent (p) and x’s grandparent (g) (This is similar to AVL Tree)
    i) Left Left Case (p is left child of g and x is left child of p)

            g                    p       i) right rotate g
          /   \                /   \     ii) swap colors of GP and P
        p*     u             x*     g*
      /  \   /  \          /  \    /  \
     x* T3  T4  T5        T1  T2  T3  u
    / \                              / \
   T1 T2                           T4  T5

    ii) Left Right Case (p is left child of g and x is right child of p)
                    left rotate P         Left Left case
                 g                   g                   g
               /   \               /   \               /   \
             p*     u            x*     u             p*    g*
           /  \   /  \         /  \   /  \          /  \   /  \
         T1   x* T4  T5       p*  T3 T4  T5       T1   T2 T3  u
            /  \            /  \                             / \
          T1  T2          T1  T2                           T4  T5

    iii) Right Right Case (Mirror of case i)

                 g                   p       i) left rotate GP
               /   \               /   \     ii) swap colors of GP and P
             u     p*             g*    x*
           / \    / \           /  \   /  \
         T1  T2 T4  x*         u   T3 T4  T5
                   / \        / \
                  T1  T2    T1  T2

    iv) Right Left Case (Mirror of case ii)

                  right rotate P        right right case
                 g                  g                   x
               /  \               /  \                /  \
             u     p*           u    x*             g*    p*
           / \    / \         / \   / \           /  \   /  \
         T1  T2  x* T5       T1 T2 T3  p*       u   T3 T4   T5
                / \                   / \      / \
               T3 T4                T4  T5   T1  T2

* Deletion step: https://www.geeksforgeeks.org/red-black-tree-set-3-delete-2/

*/

// Implementing Red-Black Tree in C
// https://www.programiz.com/dsa/red-black-tree

#include <stdio.h>
#include <stdlib.h>

enum nodeColor { RED, BLACK };

struct rbNode {
  int data, color;
  struct rbNode *link[2];
};

struct rbNode *root = NULL;

struct rbNode *createNode(int data) {
  struct rbNode *newnode;
  newnode = (struct rbNode *)malloc(sizeof(struct rbNode));
  newnode->data = data;
  newnode->color = RED;
  newnode->link[0] = newnode->link[1] = NULL;
  return newnode;
}

void insertion(int data);
void deletion(int data);
void inorderTraversal(struct rbNode *node);

int main() {
  int ch, data;

  while (1) {
    printf("1. Insertion\t2. Deletion\n");
    printf("3. Traverse\t4. Exit");
    printf("\nEnter your choice:");
    scanf("%d", &ch);
    switch (ch) {
      case 1:
        printf("Enter the element to insert:");
        scanf("%d", &data);
        insertion(data);
        break;
      case 2:
        printf("Enter the element to delete:");
        scanf("%d", &data);
        deletion(data);
        break;
      case 3:
        inorderTraversal(root);
        printf("\n");
        break;
      case 4:
        exit(0);
      default:
        printf("Not available\n");
        break;
    }
    printf("\n");
  }
  return 0;
}

void insertion(int data) {
  struct rbNode *stack[98], *ptr, *newnode, *xPtr, *yPtr;
  int dir[98], ht = 0, index;
  ptr = root;
  if (!root) {
    root = createNode(data);
    return;
  }
  stack[ht] = root;
  dir[ht++] = 0;
  while (ptr != NULL) {
    if (ptr->data == data) {
      printf("Duplicates Not Allowed!!\n");
      return;
    }
    index = (data - ptr->data) > 0 ? 1 : 0;
    stack[ht] = ptr;
    ptr = ptr->link[index];
    dir[ht++] = index;
  }
  stack[ht - 1]->link[index] = newnode = createNode(data);
  while ((ht >= 3) && (stack[ht - 1]->color == RED)) {
    if (dir[ht - 2] == 0) {
      yPtr = stack[ht - 2]->link[1];
      if (yPtr != NULL && yPtr->color == RED) {
        stack[ht - 2]->color = RED;
        stack[ht - 1]->color = yPtr->color = BLACK;
        ht = ht - 2;
      } else {
        if (dir[ht - 1] == 0) {
          yPtr = stack[ht - 1];
        } else {
          xPtr = stack[ht - 1];
          yPtr = xPtr->link[1];
          xPtr->link[1] = yPtr->link[0];
          yPtr->link[0] = xPtr;
          stack[ht - 2]->link[0] = yPtr;
        }
        xPtr = stack[ht - 2];
        xPtr->color = RED;
        yPtr->color = BLACK;
        xPtr->link[0] = yPtr->link[1];
        yPtr->link[1] = xPtr;
        if (xPtr == root) {
          root = yPtr;
        } else {
          stack[ht - 3]->link[dir[ht - 3]] = yPtr;
        }
        break;
      }
    } else {
      yPtr = stack[ht - 2]->link[0];
      if ((yPtr != NULL) && (yPtr->color == RED)) {
        stack[ht - 2]->color = RED;
        stack[ht - 1]->color = yPtr->color = BLACK;
        ht = ht - 2;
      } else {
        if (dir[ht - 1] == 1) {
          yPtr = stack[ht - 1];
        } else {
          xPtr = stack[ht - 1];
          yPtr = xPtr->link[0];
          xPtr->link[0] = yPtr->link[1];
          yPtr->link[1] = xPtr;
          stack[ht - 2]->link[1] = yPtr;
        }
        xPtr = stack[ht - 2];
        yPtr->color = BLACK;
        xPtr->color = RED;
        xPtr->link[1] = yPtr->link[0];
        yPtr->link[0] = xPtr;
        if (xPtr == root) {
          root = yPtr;
        } else {
          stack[ht - 3]->link[dir[ht - 3]] = yPtr;
        }
        break;
      }
    }
  }
  root->color = BLACK;
}

void deletion(int data) {
  struct rbNode *stack[98], *ptr, *xPtr, *yPtr;
  struct rbNode *pPtr, *qPtr, *rPtr;
  int dir[98], ht = 0, diff, i;
  enum nodeColor color;
  if (!root) {
    printf("Tree not available\n");
    return;
  }
  ptr = root;
  while (ptr != NULL) {
    if ((data - ptr->data) == 0) break;
    diff = (data - ptr->data) > 0 ? 1 : 0;
    stack[ht] = ptr;
    dir[ht++] = diff;
    ptr = ptr->link[diff];
  }
  if (ptr->link[1] == NULL) {
    if ((ptr == root) && (ptr->link[0] == NULL)) {
      free(ptr);
      root = NULL;
    } else if (ptr == root) {
      root = ptr->link[0];
      free(ptr);
    } else {
      stack[ht - 1]->link[dir[ht - 1]] = ptr->link[0];
    }
  } else {
    xPtr = ptr->link[1];
    if (xPtr->link[0] == NULL) {
      xPtr->link[0] = ptr->link[0];
      color = xPtr->color;
      xPtr->color = ptr->color;
      ptr->color = color;
      if (ptr == root) {
        root = xPtr;
      } else {
        stack[ht - 1]->link[dir[ht - 1]] = xPtr;
      }
      dir[ht] = 1;
      stack[ht++] = xPtr;
    } else {
      i = ht++;
      while (1) {
        dir[ht] = 0;
        stack[ht++] = xPtr;
        yPtr = xPtr->link[0];
        if (!yPtr->link[0]) break;
        xPtr = yPtr;
      }
      dir[i] = 1;
      stack[i] = yPtr;
      if (i > 0) stack[i - 1]->link[dir[i - 1]] = yPtr;
      yPtr->link[0] = ptr->link[0];
      xPtr->link[0] = yPtr->link[1];
      yPtr->link[1] = ptr->link[1];
      if (ptr == root) {
        root = yPtr;
      }
      color = yPtr->color;
      yPtr->color = ptr->color;
      ptr->color = color;
    }
  }
  if (ht < 1) return;
  if (ptr->color == BLACK) {
    while (1) {
      pPtr = stack[ht - 1]->link[dir[ht - 1]];
      if (pPtr && pPtr->color == RED) {
        pPtr->color = BLACK;
        break;
      }
      if (ht < 2) break;
      if (dir[ht - 2] == 0) {
        rPtr = stack[ht - 1]->link[1];
        if (!rPtr) break;
        if (rPtr->color == RED) {
          stack[ht - 1]->color = RED;
          rPtr->color = BLACK;
          stack[ht - 1]->link[1] = rPtr->link[0];
          rPtr->link[0] = stack[ht - 1];
          if (stack[ht - 1] == root) {
            root = rPtr;
          } else {
            stack[ht - 2]->link[dir[ht - 2]] = rPtr;
          }
          dir[ht] = 0;
          stack[ht] = stack[ht - 1];
          stack[ht - 1] = rPtr;
          ht++;
          rPtr = stack[ht - 1]->link[1];
        }
        if ((!rPtr->link[0] || rPtr->link[0]->color == BLACK) &&
            (!rPtr->link[1] || rPtr->link[1]->color == BLACK)) {
          rPtr->color = RED;
        } else {
          if (!rPtr->link[1] || rPtr->link[1]->color == BLACK) {
            qPtr = rPtr->link[0];
            rPtr->color = RED;
            qPtr->color = BLACK;
            rPtr->link[0] = qPtr->link[1];
            qPtr->link[1] = rPtr;
            rPtr = stack[ht - 1]->link[1] = qPtr;
          }
          rPtr->color = stack[ht - 1]->color;
          stack[ht - 1]->color = BLACK;
          rPtr->link[1]->color = BLACK;
          stack[ht - 1]->link[1] = rPtr->link[0];
          rPtr->link[0] = stack[ht - 1];
          if (stack[ht - 1] == root) {
            root = rPtr;
          } else {
            stack[ht - 2]->link[dir[ht - 2]] = rPtr;
          }
          break;
        }
      } else {
        rPtr = stack[ht - 1]->link[0];
        if (!rPtr) break;
        if (rPtr->color == RED) {
          stack[ht - 1]->color = RED;
          rPtr->color = BLACK;
          stack[ht - 1]->link[0] = rPtr->link[1];
          rPtr->link[1] = stack[ht - 1];
          if (stack[ht - 1] == root) {
            root = rPtr;
          } else {
            stack[ht - 2]->link[dir[ht - 2]] = rPtr;
          }
          dir[ht] = 1;
          stack[ht] = stack[ht - 1];
          stack[ht - 1] = rPtr;
          ht++;
          rPtr = stack[ht - 1]->link[0];
        }
        if ((!rPtr->link[0] || rPtr->link[0]->color == BLACK) &&
            (!rPtr->link[1] || rPtr->link[1]->color == BLACK)) {
          rPtr->color = RED;
        } else {
          if (!rPtr->link[0] || rPtr->link[0]->color == BLACK) {
            qPtr = rPtr->link[1];
            rPtr->color = RED;
            qPtr->color = BLACK;
            rPtr->link[1] = qPtr->link[0];
            qPtr->link[0] = rPtr;
            rPtr = stack[ht - 1]->link[0] = qPtr;
          }
          rPtr->color = stack[ht - 1]->color;
          stack[ht - 1]->color = BLACK;
          rPtr->link[0]->color = BLACK;
          stack[ht - 1]->link[0] = rPtr->link[1];
          rPtr->link[1] = stack[ht - 1];
          if (stack[ht - 1] == root) {
            root = rPtr;
          } else {
            stack[ht - 2]->link[dir[ht - 2]] = rPtr;
          }
          break;
        }
      }
      ht--;
    }
  }
}

void inorderTraversal(struct rbNode *node) {
  if (node) {
    inorderTraversal(node->link[0]);
    printf("%d  ", node->data);
    inorderTraversal(node->link[1]);
  }
  return;
}