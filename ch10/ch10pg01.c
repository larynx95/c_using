/* Data Structures Using C, 2nd, Reema Thareja
Chapter 10. Efficient Binary Trees

Programming Exercises
1. Write a program to insert and delete values from a binary search tree.

*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ND {
  int data;
  struct ND* rt;
  struct ND* lt;
} ND;

ND* ins_node(ND* root, int val);
ND* del_node(ND* root, int val);
void preorderTraversal(ND*);
void inorderTraversal(ND*);
void postorderTraversal(ND*);

int main() {
  ND* root = NULL;

  root = ins_node(root, 10);
  root = ins_node(root, 20);
  root = ins_node(root, 30);
  root = ins_node(root, 40);

  inorderTraversal(root);

  return 0;
}

ND* ins_node(ND* root, int val) {
  // create a new node
  ND* new = malloc(sizeof(ND));
  new->rt = NULL;
  new->lt = NULL;
  new->data = val;

  // if tree is empty
  if (root == NULL) {
    root = new;
    return root;
  }

  // traverse
  ND *cur, *parent;
  cur = root;
  while (cur != NULL) {
    parent = cur;
    if (val < cur->data) {
      cur = cur->lt;
    } else {
      cur = cur->rt;
    }
  }

  // link each node
  cur = new;
  if (val < parent->data) {
    parent->lt = cur;
  } else {
    parent->rt = cur;
  }

  return root;
}

ND* del_node(ND* root, int val) {
  // if tree is empty
  if (root == NULL) {
    printf("Tree is empty.\n");
    return root;
  }

  // find node whose data is val
  ND *cur, *lt, *rt, *parent;
  parent = root;
  cur = parent->lt;
  while (cur != NULL && val != cur->data) {
    parent = cur;
    cur = (val < cur->data) ? cur->lt : cur->rt;
  }

  // if val does not exist (cur == NULL)
  if (cur == NULL) {
    printf("The value to be deleted is not present in the root\n");
    return root;
  }

  // if val does exist (val == cur->data)
  // case 1. if no child
  if (cur->lt == NULL && cur->rt == NULL) {
    free(cur);
  }
  // case 2-1. one left child
  else if (cur->rt == NULL) {
  }
  // case 2-2. one right child
  else if (cur->lt == NULL) {
  }
  // case 3. both
  else {
  }

  return root;
}

void preorderTraversal(ND* tree) {
  if (tree != NULL) {
    printf("%d ", tree->data);  // anything, any job
    preorderTraversal(tree->lt);
    preorderTraversal(tree->rt);
  }
}

void inorderTraversal(ND* tree) {
  if (tree != NULL) {
    inorderTraversal(tree->lt);
    printf("%d ", tree->data);
    inorderTraversal(tree->rt);
  }
}

void postorderTraversal(ND* tree) {
  if (tree != NULL) {
    postorderTraversal(tree->lt);
    postorderTraversal(tree->rt);
    printf("%d ", tree->data);
  }
}