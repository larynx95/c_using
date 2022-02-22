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

https://www.geeksforgeeks.org/splay-tree-set-1-insert/
https://www.geeksforgeeks.org/splay-tree-set-2-insert-delete/
https://www.geeksforgeeks.org/splay-tree-set-3-delete/
*/

// The code is adopted from http://goo.gl/SDH9hH
#include <stdio.h>
#include <stdlib.h>

// An AVL tree node
struct node {
  int key;
  struct node *left, *right;
};

/* Helper function that allocates a new node with the given key and
        NULL left and right pointers. */
struct node *newNode(int key) {
  struct node *node = (struct node *)malloc(sizeof(struct node));
  node->key = key;
  node->left = node->right = NULL;
  return (node);
}

// A utility function to right rotate subtree rooted with y
// See the diagram given above.
struct node *rightRotate(struct node *x) {
  struct node *y = x->left;
  x->left = y->right;
  y->right = x;
  return y;
}

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
struct node *leftRotate(struct node *x) {
  struct node *y = x->right;
  x->right = y->left;
  y->left = x;
  return y;
}

// This function brings the key at root if key is present in tree.
// If key is not present, then it brings the last accessed item at
// root. This function modifies the tree and returns the new root
struct node *splay(struct node *root, int key) {
  // Base cases: root is NULL or key is present at root
  if (root == NULL || root->key == key) return root;

  // Key lies in left subtree
  if (root->key > key) {
    // Key is not in tree, we are done
    if (root->left == NULL) return root;

    // Zig-Zig (Left Left)
    if (root->left->key > key) {
      // First recursively bring the key as root of left-left
      root->left->left = splay(root->left->left, key);

      // Do first rotation for root, second rotation is done after else
      root = rightRotate(root);
    } else if (root->left->key < key)  // Zig-Zag (Left Right)
    {
      // First recursively bring the key as root of left-right
      root->left->right = splay(root->left->right, key);

      // Do first rotation for root->left
      if (root->left->right != NULL) root->left = leftRotate(root->left);
    }

    // Do second rotation for root
    return (root->left == NULL) ? root : rightRotate(root);
  } else  // Key lies in right subtree
  {
    // Key is not in tree, we are done
    if (root->right == NULL) return root;

    // Zag-Zig (Right Left)
    if (root->right->key > key) {
      // Bring the key as root of right-left
      root->right->left = splay(root->right->left, key);

      // Do first rotation for root->right
      if (root->right->left != NULL) root->right = rightRotate(root->right);
    } else if (root->right->key < key)  // Zag-Zag (Right Right)
    {
      // Bring the key as root of right-right and do first rotation
      root->right->right = splay(root->right->right, key);
      root = leftRotate(root);
    }

    // Do second rotation for root
    return (root->right == NULL) ? root : leftRotate(root);
  }
}

// The search function for Splay tree. Note that this function
// returns the new root of Splay Tree. If key is present in tree
// then, it is moved to root.
struct node *search(struct node *root, int key) {
  return splay(root, key);
}

// Function to insert a new key k in splay tree with given root
struct node *insert(struct node *root, int k) {
  // Simple Case: If tree is empty
  if (root == NULL) return newNode(k);

  // Bring the closest leaf node to root
  root = splay(root, k);

  // If key is already present, then return
  if (root->key == k) return root;

  // Otherwise allocate memory for new node
  struct node *newnode = newNode(k);

  // If root's key is greater, make root as right child
  // of newnode and copy the left child of root to newnode
  if (root->key > k) {
    newnode->right = root;
    newnode->left = root->left;
    root->left = NULL;
  }

  // If root's key is smaller, make root as left child
  // of newnode and copy the right child of root to newnode
  else {
    newnode->left = root;
    newnode->right = root->right;
    root->right = NULL;
  }

  return newnode;  // newnode becomes new root
}

// The delete function for Splay tree. Note that this function
// returns the new root of Splay Tree after removing the key
struct node *delete_key(struct node *root, int key) {
  struct node *temp;
  if (!root) return NULL;

  // Splay the given key
  root = splay(root, key);

  // If key is not present, then
  // return root
  if (key != root->key) return root;

  // If key is present
  // If left child of root does not exist
  // make root->right as root
  if (!root->left) {
    temp = root;
    root = root->right;
  }

  // Else if left child exits
  else {
    temp = root;

    /*Note: Since key == root->key,
    so after Splay(key, root->lchild),
    the tree we get will have no right child tree
    and maximum node in left subtree will get splayed*/
    // New root
    root = splay(root->left, key);

    // Make right child of previous root  as
    // new root's right child
    root->right = temp->right;
  }

  // free the previous root node, that is,
  // the node containing the key
  free(temp);

  // return root of the new Splay Tree
  return root;
}

// A utility function to print preorder traversal of the tree.
// The function also prints height of every node
void preOrder(struct node *root) {
  if (root != NULL) {
    printf("%d ", root->key);
    preOrder(root->left);
    preOrder(root->right);
  }
}

/* Driver program to test above function*/
int main() {
  struct node *root = newNode(100);
  root->left = newNode(50);
  root->right = newNode(200);
  root->left->left = newNode(40);
  root->left->left->left = newNode(30);
  root->left->left->left->left = newNode(20);

  root = search(root, 20);
  printf("Preorder traversal of the modified Splay tree is \n");
  preOrder(root);
  return 0;
}
