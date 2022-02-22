/* Data Structures Using C, 2nd, Reema Thareja
Chapter 09. Trees
9.1 Introduction
9.2 Types of trees
9.3 Creating a binary tree from a general tree
9.4 Traversing a binary tree
*/

/*
* Tree traversal
                   4
                  / \
                 2   6
                /\   /\
               1  3 5  7
  (a) Inorder (Left, Root, Right) : 1 2 3 4 5 6 7
  (b) Preorder (Root, Left, Right) : 4 2 1 3 6 5 7
  (c) Postorder (Left, Right, Root) : 1 3 2 5 7 6 4
  (d) Level-order (breadth-first traversal algorithm) : 4 2 6 1 3 5 7

* Traversing Example 9.6 ~ 9.8
  - pre-order traversal:
    (a) A, B, D, G, H, L, E, C, F, I, J, K
    (b) A, B, D, C, D, E, F, G, H, I
  - in-order traversal:
    (a) G, D, H, L, B, E, A, C, I, F, K, J
    (b) B, D, A, E, H, G, I, F, C
  - post-order traversal:
    (a) G, L, H, D, E, B, I, K, J, F, C, A
    (b) D, B, H, I, G, F, E, C, A
  - level-order traversal:
    (a) A, B, C, D, E, F, G, H, I, J, L, K
    (b) A, B, C, D, E, F, G, H, I

          (a)               (b)
           A                 A
          / \               / \
         B   C             B   C
        / \   \            \   /
       D   E   F            D E
      / \     / \              \
     G   H   I   J              F
          \     /              /
           L   K              G
                             / \
                            H   I

* Constructing a binary tree from traversal results
  - We need to know at least two traversal results.
    in-order + (pre-order or post-order)
*/

#include <stdio.h>
#include <stdlib.h>

/**********************************************************
 * Structure for node
 **********************************************************/

typedef struct Nd {
  int data;
  struct Nd* Lt;
  struct Nd* Rt;
} Nd;

/**********************************************************
 * Function prototypes
 **********************************************************/

Nd* insert_btree(Nd*, int);
void preorderTraversal(Nd*);
void inorderTraversal(Nd*);
void postorderTraversal(Nd*);

int height(Nd*);
void print_lvl(Nd*, int);
void lvlorderTraversal(Nd*);

void free_nodes(Nd*);
void del_tree(Nd*);

/**********************************************************
 * Main function
 **********************************************************/

int main() {
  Nd* root = NULL;
  root = insert_btree(root, 4);
  root = insert_btree(root, 2);
  root = insert_btree(root, 6);
  root = insert_btree(root, 1);
  root = insert_btree(root, 3);
  root = insert_btree(root, 5);
  root = insert_btree(root, 7);

  printf("Preorder Traversal: ");
  preorderTraversal(root);
  printf("\n");

  printf("Inorder Traversal: ");
  inorderTraversal(root);
  printf("\n");

  printf("Postorder Traversal: ");
  postorderTraversal(root);
  printf("\n");

  printf("Levelorder Traversal: ");
  lvlorderTraversal(root);
  printf("\n");

  del_tree(root);

  return 0;
}

/**********************************************************
 * Function definitions
 **********************************************************/

Nd* insert_btree(Nd* root, int val) {
  Nd *parent, *cur;
  Nd* new = malloc(sizeof(Nd));
  new->data = val;
  new->Lt = NULL;
  new->Rt = NULL;

  if (root == NULL) {
    root = new;
  } else {
    cur = root;
    while (cur != NULL) {
      parent = cur;
      if (cur->data > val) {
        cur = cur->Lt;
      } else {
        cur = cur->Rt;
      }
    }
    if (parent->data > val) {
      parent->Lt = new;
    } else {
      parent->Rt = new;
    }
  }
  return root;
}

/**********************************************************
 * PreorderTraversal: Root -> Lt -> Rt
 **********************************************************/

void preorderTraversal(Nd* tree) {
  if (tree != NULL) {
    printf("%d ", tree->data);
    preorderTraversal(tree->Lt);
    preorderTraversal(tree->Rt);
  }
}

/**********************************************************
 * InorderTraversal: Lt -> Root -> Rt
 **********************************************************/

void inorderTraversal(Nd* tree) {
  if (tree != NULL) {
    inorderTraversal(tree->Lt);
    printf("%d ", tree->data);
    inorderTraversal(tree->Rt);
  }
}

/**********************************************************
 * PostorderTraversal: Lt -> Rt -> Root
 **********************************************************/

void postorderTraversal(Nd* tree) {
  if (tree != NULL) {
    postorderTraversal(tree->Lt);
    postorderTraversal(tree->Rt);
    printf("%d ", tree->data);
  }
}

/**********************************************************
 * TODO: Levelorder Traversal
 * https://www.geeksforgeeks.org/level-order-tree-traversal/
 **********************************************************/

int height(Nd* nd) {
  if (nd == NULL)
    return 0;
  else {
    /* compute the height of each subtree */
    int lheight = height(nd->Lt);
    int rheight = height(nd->Rt);

    /* use the larger one */
    if (lheight > rheight)
      return (lheight + 1);
    else
      return (rheight + 1);
  }
}

void print_lvl(Nd* root, int lvl) {
  if (root == NULL) return;
  if (lvl == 1)
    printf("%d ", root->data);
  else if (lvl > 1) {
    print_lvl(root->Lt, lvl - 1);
    print_lvl(root->Rt, lvl - 1);
  }
}

void lvlorderTraversal(Nd* root) {
  int h = height(root);
  int i;
  for (i = 1; i <= h; i++) print_lvl(root, i);
}

/**********************************************************
Delete whole tree
**********************************************************/

void del_tree(Nd* root) {
  if (root != NULL) {
    del_tree(root->Lt);
    del_tree(root->Rt);
    free(root);
  }
}