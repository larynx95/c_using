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
Code Dope
https://www.codesdope.com/course/data-structures-splay-trees/#:~:text=Deletion%20in%20a%20Splay%20Tree,splay%20it%20to%20the%20root.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *left;
  struct node *right;
  struct node *parent;
} node;

typedef struct splay_tree {
  struct node *root;
} splay_tree;

node *new_node(int data) {
  node *n = malloc(sizeof(node));
  n->data = data;
  n->parent = NULL;
  n->right = NULL;
  n->left = NULL;

  return n;
}

splay_tree *new_splay_tree() {
  splay_tree *t = malloc(sizeof(splay_tree));
  t->root = NULL;

  return t;
}

node *maximum(splay_tree *t, node *x) {
  while (x->right != NULL) x = x->right;
  return x;
}

void left_rotate(splay_tree *t, node *x) {
  node *y = x->right;
  x->right = y->left;
  if (y->left != NULL) {
    y->left->parent = x;
  }
  y->parent = x->parent;
  if (x->parent == NULL) {  // x is root
    t->root = y;
  } else if (x == x->parent->left) {  // x is left child
    x->parent->left = y;
  } else {  // x is right child
    x->parent->right = y;
  }
  y->left = x;
  x->parent = y;
}

void right_rotate(splay_tree *t, node *x) {
  node *y = x->left;
  x->left = y->right;
  if (y->right != NULL) {
    y->right->parent = x;
  }
  y->parent = x->parent;
  if (x->parent == NULL) {  // x is root
    t->root = y;
  } else if (x == x->parent->right) {  // x is left child
    x->parent->right = y;
  } else {  // x is right child
    x->parent->left = y;
  }
  y->right = x;
  x->parent = y;
}

void splay(splay_tree *t, node *n) {
  while (n->parent != NULL) {    // node is not root
    if (n->parent == t->root) {  // node is child of root, one rotation
      if (n == n->parent->left) {
        right_rotate(t, n->parent);
      } else {
        left_rotate(t, n->parent);
      }
    } else {
      node *p = n->parent;
      node *g = p->parent;  // grandparent

      if (n->parent->left == n &&
          p->parent->left == p) {  // both are left children
        right_rotate(t, g);
        right_rotate(t, p);
      } else if (n->parent->right == n &&
                 p->parent->right == p) {  // both are right children
        left_rotate(t, g);
        left_rotate(t, p);
      } else if (n->parent->right == n && p->parent->left == p) {
        left_rotate(t, p);
        right_rotate(t, g);
      } else if (n->parent->left == n && p->parent->right == p) {
        right_rotate(t, p);
        left_rotate(t, g);
      }
    }
  }
}

void insert(splay_tree *t, node *n) {
  node *y = NULL;
  node *temp = t->root;
  while (temp != NULL) {
    y = temp;
    if (n->data < temp->data)
      temp = temp->left;
    else
      temp = temp->right;
  }
  n->parent = y;

  if (y == NULL)  // newly added node is root
    t->root = n;
  else if (n->data < y->data)
    y->left = n;
  else
    y->right = n;

  splay(t, n);
}

node *search(splay_tree *t, node *n, int x) {
  if (x == n->data) {
    splay(t, n);
    return n;
  } else if (x < n->data)
    return search(t, n->left, x);
  else if (x > n->data)
    return search(t, n->right, x);
  else
    return NULL;
}

void delete (splay_tree *t, node *n) {
  splay(t, n);

  splay_tree *left_subtree = new_splay_tree();
  left_subtree->root = t->root->left;
  if (left_subtree->root != NULL) left_subtree->root->parent = NULL;

  splay_tree *right_subtree = new_splay_tree();
  right_subtree->root = t->root->right;
  if (right_subtree->root != NULL) right_subtree->root->parent = NULL;

  free(n);

  if (left_subtree->root != NULL) {
    node *m = maximum(left_subtree, left_subtree->root);
    splay(left_subtree, m);
    left_subtree->root->right = right_subtree->root;
    t->root = left_subtree->root;
  } else {
    t->root = right_subtree->root;
  }
}

void inorder(splay_tree *t, node *n) {
  if (n != NULL) {
    inorder(t, n->left);
    printf("%d\n", n->data);
    inorder(t, n->right);
  }
}

int main() {
  splay_tree *t = new_splay_tree();

  node *a, *b, *c, *d, *e, *f, *g, *h, *i, *j, *k, *l, *m;
  a = new_node(10);
  b = new_node(20);
  c = new_node(30);
  d = new_node(100);
  e = new_node(90);
  f = new_node(40);
  g = new_node(50);
  h = new_node(60);
  i = new_node(70);
  j = new_node(80);
  k = new_node(150);
  l = new_node(110);
  m = new_node(120);

  insert(t, a);
  insert(t, b);
  insert(t, c);
  insert(t, d);
  insert(t, e);
  insert(t, f);
  insert(t, g);
  insert(t, h);
  insert(t, i);
  insert(t, j);
  insert(t, k);
  insert(t, l);
  insert(t, m);

  delete (t, a);
  delete (t, m);

  inorder(t, t->root);

  return 0;
}