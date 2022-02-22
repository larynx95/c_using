/* Data Structures Using C, 2nd, Reema Thareja
Chapter 11. Multi-way Search Trees
11.1 Introduction
*/

/*
# M-way search tree
- The structure of an M-way search tree node
  p0 k0 p1 k1 p2 k2 ... p(n-1) k(n-1) p(n)
- k0 ~ k(n) are sorted: k(n-1) < k(n)

# example
                   [(0) 18 (1) 45 (2)]
  [* 9 (0) 11 *]     [* 27 (1) 36 *]     [* 54 (2) 63 (3)]
                     [* 29 (1) 30 *]     [* 72 (3) 81 *]


# references
  http://faculty.cs.niu.edu/~freedman/340/340notes/340multi.htm
  https://www.geeksforgeeks.org/m-way-search-trees-set-1-searching/
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct node {
  int count;
  int value[MAX + 1];
  struct node* child[MAX + 1];
};

struct node* search(int val, struct node* root, int* pos);
int searchnode(int val, struct node* n, int* pos);

int main() {
  //
  return 0;
}

// Searches value in the node
struct node* search(int val, struct node* root, int* pos) {
  // if root is Null then return
  if (root == NULL)
    return NULL;
  else {
    // if node is found
    if (searchnode(val, root, pos)) return root;

    // if not then search in child nodes
    else
      return search(val, root->child[*pos], pos);
  }
}

// Searches the node
int searchnode(int val, struct node* n, int* pos) {
  // if val is less than node->value[1]
  if (val < n->value[1]) {
    *pos = 0;
    return 0;
  }

  // if the val is greater
  else {
    *pos = n->count;

    // check in the child array
    // for correct position
    while ((val < n->value[*pos]) && *pos > 1) (*pos)--;
    if (val == n->value[*pos])
      return 1;
    else
      return 0;
  }
}