/* Data Structures Using C, 2nd, Reema Thareja
Chapter 09. Trees
9.1 Introduction
9.2 Types of trees
9.3 Creating a binary tree from a general tree
  1) Sequential representation
  2) Linked representation
*/

/*
* Example 9.5
  Convert the given general tree into a binary tree.

                 A
             /   |   \
           B     C     D
          /    / | \   / \
         E    F  G  H  I  J
                         /
                        K
          general tree

    A       A       A         A         A         A
   /       /       /         /         /         /
  B       B       B         B         B         B
         / \     / \       / \       / \       / \
        E   C   E   C     E   C     E   C     E   C
                   / \       / \       / \       / \
                  F   D     F   D     F   D     F   D
                               /         /         /
                              I         I         I
                                         \         \
                                          J         J
                                                   /
                                                  K

*/

#include <stdio.h>
#include <stdlib.h>

/**********************************************************
structure for node
**********************************************************/

typedef struct Nd {
  int data;
  struct Nd* Lt;
  struct Nd* Rt;
} Nd;

/**********************************************************
function prototypes
**********************************************************/

Nd* insert_btree(Nd* root, int val);
void preorderTraversal(Nd* root);
void free_nodes(Nd* root);

/**********************************************************
main function
**********************************************************/

int main() {
  Nd* root = NULL;
  root = insert_btree(root, 10);
  root = insert_btree(root, 20);
  root = insert_btree(root, 30);
  root = insert_btree(root, 40);

  preorderTraversal(root);

  del_tree(root);

  return 0;
}

/**********************************************************
function definitions
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

void preorderTraversal(Nd* root) {
  if (root != NULL) {
    printf("%d ", root->data);
    preorderTraversal(root->Lt);
    preorderTraversal(root->Rt);
  }
}

// TODO: free memory space
void del_tree(Nd* root) {
  if (root != NULL) {
    del_tree(root->Lt);
    del_tree(root->Rt);
    free(root);
  }
}