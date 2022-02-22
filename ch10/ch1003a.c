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
GeeksforGeeks
https://www.geeksforgeeks.org/avl-tree-set-1-insertion/
https://www.programiz.com/dsa/avl-tree
*/

// C program to insert a node in AVL tree
#include <stdio.h>
#include <stdlib.h>

// An AVL tree node
struct Node {
  int key;
  struct Node *left;
  struct Node *right;
  int height;
};

int height(struct Node *N);
int getmax(int a, int b);
struct Node *newNode(int key);
struct Node *rightRotate(struct Node *y);
struct Node *leftRotate(struct Node *x);
int getBalance(struct Node *N);
struct Node *insert(struct Node *node, int key);
void preOrder(struct Node *root);

/* Driver program to test above function*/
int main() {
  struct Node *root = NULL;

  /* Constructing tree given in the above figure */
  root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 30);
  root = insert(root, 40);
  root = insert(root, 50);
  root = insert(root, 25);

  /* The constructed AVL Tree would be
                   30
                  / \
                 20 40
                / \	 \
               10 25 50
  */

  printf(
      "Preorder traversal of the constructed AVL"
      " tree is \n");
  preOrder(root);

  return 0;
}

int height(struct Node *N) {
  if (N == NULL) return 0;
  return N->height;
}

int getmax(int a, int b) { return (a > b) ? a : b; }

/* Helper function that allocates a new node with the given key and
        NULL left and right pointers. */
struct Node *newNode(int key) {
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;  // new node is initially added at leaf
  return (node);
}

// A utility function to right rotate subtree rooted with y
// See the diagram given above.
struct Node *rightRotate(struct Node *y) {
  struct Node *x = y->left;
  struct Node *T2 = x->right;

  // Perform rotation
  x->right = y;
  y->left = T2;

  // Update heights
  y->height = getmax(height(y->left), height(y->right)) + 1;
  x->height = getmax(height(x->left), height(x->right)) + 1;

  // Return new root
  return x;
}

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
struct Node *leftRotate(struct Node *x) {
  struct Node *y = x->right;
  struct Node *T2 = y->left;

  // Perform rotation
  y->left = x;
  x->right = T2;

  // Update heights
  x->height = getmax(height(x->left), height(x->right)) + 1;
  y->height = getmax(height(y->left), height(y->right)) + 1;

  // Return new root
  return y;
}

// Get Balance factor of node N
int getBalance(struct Node *N) {
  if (N == NULL) return 0;
  return height(N->left) - height(N->right);
}

// Recursive function to insert a key in the subtree rooted
// with node and returns the new root of the subtree.
struct Node *insert(struct Node *node, int key) {
  /* 1. Perform the normal BST insertion */
  if (node == NULL) return (newNode(key));

  if (key < node->key)
    node->left = insert(node->left, key);
  else if (key > node->key)
    node->right = insert(node->right, key);
  else  // Equal keys are not allowed in BST
    return node;

  /* 2. Update height of this ancestor node */
  node->height = 1 + getmax(height(node->left), height(node->right));

  /* 3. Get the balance factor of this ancestor
          node to check whether this node became
          unbalanced */
  int balance = getBalance(node);

  // If this node becomes unbalanced, then
  // there are 4 cases

  // Left Left Case
  if (balance > 1 && key < node->left->key) return rightRotate(node);

  // Right Right Case
  if (balance < -1 && key > node->right->key) return leftRotate(node);

  // Left Right Case
  if (balance > 1 && key > node->left->key) {
    node->left = leftRotate(node->left);
    return rightRotate(node);
  }

  // Right Left Case
  if (balance < -1 && key < node->right->key) {
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }

  /* return the (unchanged) node pointer */
  return node;
}

// A utility function to print preorder traversal
// of the tree.
// The function also prints height of every node
void preOrder(struct Node *root) {
  if (root != NULL) {
    printf("%d ", root->key);
    preOrder(root->left);
    preOrder(root->right);
  }
}
