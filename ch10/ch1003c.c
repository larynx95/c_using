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
https://www.zentut.com/c-tutorial/c-avl-tree/
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node* left;
  struct node* right;
  int height;
} node;

void dispose(node* t);
node* find(int e, node* t);
node* find_min(node* t);
node* find_max(node* t);
node* insert(int data, node* t);
node* delete (int data, node* t);
void display_avl(node* t);
int get(node* n);

int main() {
  node *t, *p;
  int i;
  int j = 0;
  const int max = 10;

  printf("--- C AVL Tree Demo  ---\n");

  t = NULL;

  printf("Insert: ");
  for (i = 0; i < max; i++, j = (j + 7) % max) {
    t = insert(j, t);
    printf("%d ", j);
  }
  printf(" into the tree\n\n");

  display_avl(t);

  dispose(t);

  return 0;
}

/*
    remove all nodes of an AVL tree
*/
void dispose(node* t) {
  if (t != NULL) {
    dispose(t->left);
    dispose(t->right);
    free(t);
  }
}

/*
    find a specific node's key in the tree
*/
node* find(int e, node* t) {
  if (t == NULL) return NULL;
  if (e < t->data)
    return find(e, t->left);
  else if (e > t->data)
    return find(e, t->right);
  else
    return t;
}

/*
    find minimum node's key
*/
node* find_min(node* t) {
  if (t == NULL)
    return NULL;
  else if (t->left == NULL)
    return t;
  else
    return find_min(t->left);
}

/*
    find maximum node's key
*/
node* find_max(node* t) {
  if (t != NULL)
    while (t->right != NULL) t = t->right;

  return t;
}

/*
    get the height of a node
*/
static int height(node* n) {
  if (n == NULL)
    return -1;
  else
    return n->height;
}

/*
    get maximum value of two integers
*/
static int max(int l, int r) { return l > r ? l : r; }

/*
    perform a rotation between a k2 node and its left child

    note: call single_rotate_with_left only if k2 node has a left child
*/

static node* single_rotate_with_left(node* k2) {
  node* k1 = NULL;

  k1 = k2->left;
  k2->left = k1->right;
  k1->right = k2;

  k2->height = max(height(k2->left), height(k2->right)) + 1;
  k1->height = max(height(k1->left), k2->height) + 1;
  return k1; /* new root */
}

/*
    perform a rotation between a node (k1) and its right child

    note: call single_rotate_with_right only if
    the k1 node has a right child
*/

static node* single_rotate_with_right(node* k1) {
  node* k2;

  k2 = k1->right;
  k1->right = k2->left;
  k2->left = k1;

  k1->height = max(height(k1->left), height(k1->right)) + 1;
  k2->height = max(height(k2->right), k1->height) + 1;

  return k2; /* New root */
}

/*

    perform the left-right double rotation,

    note: call double_rotate_with_left only if k3 node has
    a left child and k3's left child has a right child
*/

static node* double_rotate_with_left(node* k3) {
  /* Rotate between k1 and k2 */
  k3->left = single_rotate_with_right(k3->left);

  /* Rotate between K3 and k2 */
  return single_rotate_with_left(k3);
}

/*
    perform the right-left double rotation

   notes: call double_rotate_with_right only if k1 has a
   right child and k1's right child has a left child
*/

static node* double_rotate_with_right(node* k1) {
  /* rotate between K3 and k2 */
  k1->right = single_rotate_with_left(k1->right);

  /* rotate between k1 and k2 */
  return single_rotate_with_right(k1);
}

/*
    insert a new node into the tree
*/
node* insert(int e, node* t) {
  if (t == NULL) {
    /* Create and return a one-node tree */
    t = (node*)malloc(sizeof(node));
    if (t == NULL) {
      fprintf(stderr, "Out of memory!!! (insert)\n");
      exit(1);
    } else {
      t->data = e;
      t->height = 0;
      t->left = t->right = NULL;
    }
  } else if (e < t->data) {
    t->left = insert(e, t->left);
    if (height(t->left) - height(t->right) == 2)
      if (e < t->left->data)
        t = single_rotate_with_left(t);
      else
        t = double_rotate_with_left(t);
  } else if (e > t->data) {
    t->right = insert(e, t->right);
    if (height(t->right) - height(t->left) == 2)
      if (e > t->right->data)
        t = single_rotate_with_right(t);
      else
        t = double_rotate_with_right(t);
  }
  /* Else X is in the tree already; we'll do nothing */

  t->height = max(height(t->left), height(t->right)) + 1;
  return t;
}

/*
    remove a node in the tree
*/
node* delete (int e, node* t) {
  printf("Sorry; Delete is unimplemented; %d remains\n", e);
  return t;
}

/*
    data data of a node
*/
int get(node* n) { return n->data; }

/*
    Recursively display AVL tree or subtree
*/
void display_avl(node* t) {
  if (t == NULL) return;
  printf("%d", t->data);

  if (t->left != NULL) printf("(L:%d)", t->left->data);
  if (t->right != NULL) printf("(R:%d)", t->right->data);
  printf("\n");

  display_avl(t->left);
  display_avl(t->right);
}