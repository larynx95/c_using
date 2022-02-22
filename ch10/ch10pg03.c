/* Data Structures Using C, 2nd, Reema Thareja
Chapter 10. Efficient Binary Trees

Programming Exercises
3. Write a program to draw a binary tree data structure.

# References
- Print Binary Tree in 2-Dimensions
  https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
- https://pastebin.com/d3AtFKAK

# My plans
1) displaying edges: '/', '\'
- each num has two-digit spaces: " 5", "20"
- the number of spaces before the first num in each line
2) not displaying edges, only numbers
3) top to bottom, left to right (rotated)
4) using temporary data structures: --> array or something --> print

*/

// Program to print binary tree in 2D
#include <malloc.h>
#include <stdio.h>
#define COUNT 10

// A binary tree node
struct Node {
  int data;
  struct Node *left, *right;
};

struct Node* newNode(int data);
void print2DUtil(struct Node* root, int space);
void print2D(struct Node* root);

// Driver program to test above functions
int main() {
  struct Node* root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);

  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(6);
  root->right->right = newNode(7);

  root->left->left->left = newNode(8);
  root->left->left->right = newNode(9);
  root->left->right->left = newNode(10);
  root->left->right->right = newNode(11);
  root->right->left->left = newNode(12);
  root->right->left->right = newNode(13);
  root->right->right->left = newNode(14);
  root->right->right->right = newNode(15);

  print2D(root);

  return 0;
}

// Helper function to allocates a new node
struct Node* newNode(int data) {
  struct Node* node = malloc(sizeof(struct Node));
  node->data = data;
  node->left = node->right = NULL;
  return node;
}

// Function to print binary tree in 2D
// It does reverse inorder traversal
void print2DUtil(struct Node* root, int space) {
  // Base case
  if (root == NULL) return;

  // Increase distance between levels
  space += COUNT;

  // Process right child first
  print2DUtil(root->right, space);

  // Print current node after space
  // count
  printf("\n");
  for (int i = COUNT; i < space; i++) printf(" ");
  printf("%d\n", root->data);

  // Process left child
  print2DUtil(root->left, space);
}

// Wrapper over print2DUtil()
void print2D(struct Node* root) {
  // Pass initial space count as 0
  print2DUtil(root, 0);
}