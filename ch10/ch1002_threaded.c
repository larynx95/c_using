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
*/

/*
Programming Example
2. Write a program to implement simple right in-threaded binary trees.
   (one-way, right-threaded binary tree)
*/

/*
* Threaded binary tree
  - The NULL entries can be replaced to store a pointer
    to the in-order predecessor or the in-order successor of the node.
    These special pointers are called 'threads'
    and binary trees containing threads are called threaded trees
  - One-way threaded tree (successor)
    - Left-threaded binary tree
    - Right-threaded binary tree (predecessor & successor)
  - Two-way threaded tree (double-threaded tree)

* Representation (one-way, right-threaded binary tree)
  1. Linked representation of a binary tree

                     [L 1 R]            X is Null pointer
                    /       \
             [L 2 R]         [L 3 R]
            /       \       /       \
        [X 4 X]  [X 5 X] [X 6 X]  [X 7 X]

  2. Linked representation of a one-way threaded binary tree
    - extra pointer pointing to in-order successor

                     [L 1 R]            X is Null pointer
                    / ↑     \
             [L 2 R]  |      [L 3 R]
            / ↗    \ |     / ↗     \
        [X 4 R]  [X 5 R] [X 6 R]  [X 7 X]

  3. Linked representation of a two-way threaded binary tree
    - extra pointer pointing to in-order predecessor (Lt)
    - extra pointer pointing to in-order successor (Rt)

                     [L 1 R]            X is Null pointer
                    / ↑  ↑  \
             [L 2 R]  |  |   [L 3 R]
            / ↗ ↖ \ |   | / ↗  ↖ \
        [X 4 R]  [L 5 R] [L 6 R]  [L 7 X]

* Traversal of threaded tree
  - algorithm
  Step 1: Check if the current node has a left child that has not been visited.
          If a left child exists that has not been visited, go to Step 2,
          else go to Step 3.
  Step 2: Add the left child in the list of visited nodes.
          Make it as the current node and then go to Step 6.
  Step 3: If the current node has a right child, go to Step 4 else go to Step 5.
  Step 4: Make that right child as current node and go to Step 6.
  Step 5: Print the node and if there is a threaded node
          make it the current node.
  Step 6: If all the nodes have visited then END else go to Step 1.

  - example
                    1
                  /↗ \
                 2     3
                /↗   /↗
               4     5

  1) at     : Node 1
     state  : Node 1 has Lt child 2, and not visited
     then   : add 2, and current -> 2
  2) at     : Node 2
     state  : Node 2 has Lt child 4, and not visited
     then   : add 4, and current -> 4
  3) at     : Node 4
     state  : Node 4 has neither Lt nor Rt child
     then   : Print 4, and current -> threaded link 2
  4) at     : Node 2
     state  : Node 2 already visited
     then   : Print 2, and current -> threaded link 1
  5) at     : Node 1
     state  : Lt child already visited, Rt child 3 is not visited
     then   : Print 1, add 3 and current -> 3
  6) at     : Node 3
     state  : Node 3 has Rt child 5, and not visited
     then   : add 5, and current -> 5
  7) at     : Node 5
     state  : Node 5 has neither Lt nor Rt child
     then   : Print 5, current -> threaded link 3
  8) at     : Node 3
     state  : Node 3 has Lt child, but already visited
     then   : Print 3
  9) at     : Node 3
     state  : There are no nodes left
     then   : End. The sequence of nodes printed is 4 2 1 5 3.

* Advantages of threaded binary tree over regular binary tree?
  - It enables linear traversal of elements in the tree.
  - Linear traversal eliminates the use of stacks
    which in turn consume a lot of memory space and computer time.
  - It enables to find the parent of a given element
    without explicit use of parent pointers.
  - Since nodes contain pointers to in-order predecessor and successor,
    the threaded tree enables forward and backward traversal of the nodes
    as given by in-order fashion.

TODO: Implement other threaded trees (Linked representation)
      Implement other threaded trees (Array representation)
*/

#include <stdio.h>
#include <stdlib.h>

struct tree {
  int val;
  struct tree *right;  // right subtree
  struct tree *left;   // left subtree
  int hasSuccessor;    // 0: no successor, 1: has successor
};

struct tree *root = NULL;  // declare root and initialize it with NULL pointer

/* function prototypes */
struct tree *insert_node(struct tree *root, struct tree *ptr, struct tree *rt);
struct tree *create_threaded_tree();
void inorder(struct tree *root);

/* main function */
void main() {
  // struct tree *root=NULL;
  system("clear");
  create_threaded_tree();
  printf("The in-order traversal of the tree can be given as: ");
  inorder(root);
}

/*
* Showing each step (adding 4->2->5->1)
  val new-node   insert_node
  ----------------------------------------------------------------------
  4   [X 4-0 X]  IN(X, [4], X)                           [X 4-0 X]

  2   [X 2-0 X]  IN([4], [2], X)                         [L 4-0 X]
                [4]->Lt = IN(X, [2], [4])               / ↗
                                                  [X 2-1 R]

  5   [X 5-0 X]  IN([4], [5], X)                         [L 4-0 R]
                [4]->Rt = IN(X, [5], X)                 / ↗    \
                                                  [X 2-1 R]  [X 5-1 X]

  1   [X 1-0 X]  IN([4], [1], X)                         [L 4-0 R]
                ->IN([2], [1], [4])                     / ↗    \
                ->IN(X, [1], [2])                 [L 2-1 R]   [X 5-1 X]
                                                  / ↗
                                            [X 1-1 R]
*/

struct tree *create_threaded_tree() {
  struct tree *new;
  int num;
  printf("Enter the elements, press -1 to terminate ");
  scanf("%d", &num);
  while (num != -1) {
    new = (struct tree *)malloc(sizeof(struct tree));
    new->val = num;
    new->left = new->right = NULL;
    new->hasSuccessor = 0;
    root = insert_node(root, new, NULL);
    printf("Enter the next element ");
    fflush(stdin);
    scanf("%d", &num);
  }
  return root;
}

struct tree *insert_node(struct tree *root, struct tree *new, struct tree *rt) {
  /* if tree is empty */
  if (root == NULL) {
    root = new;
    if (rt != NULL) {
      root->right = rt;
      root->hasSuccessor = 1;
    }
  }
  /* add to the Lt. subtree */
  else if (new->val < root->val)
    root->left = insert_node(root->left, new, root);
  /* add to the Rt. subtree */
  else if (root->hasSuccessor == 1) {
    root->right = insert_node(NULL, new, rt);
    root->hasSuccessor = 0;
  } else
    root->right = insert_node(root->right, new, rt);
  return root;
}

/*
* Algorithm
  - Declare two pointers. (*ptr, *prev)
  - Move pointer to the left-most node (for in-order traversal).
    `ptr` points to the `left` pointer of the left-most node. (NULL)
    `prev` points to the left-most node.

* Showing each step

              [L 4-0 R]
              / ↗    \
      [L 2-1 R]  [X 5-1 X]
      / ↗
  [X 1-1 R]

  1) first do-while loop
    i. result of the first inner-while loop (to the left-most node)
      prev --> [1]
      ptr --> NULL

    ii. prev != NULL
      print 1
      ptr --> [2]

    iii. result of the second inner-while loop
      a. prev --> [1] && prev->thread == 1
        print 2
        prev --> [2]
        ptr --> [4]
      b. prev --> [2] && prev->thread == 1
        print 4
        prev --> [4]
        ptr --> [5]
      c. prev --> [4] && prev->thread == 0
        exit the second while loop and if-statement
  2) second do-while loop
    i. first inner-while loop
      prev --> [5]
      ptr --> NULL
    ii. prev != NULL
      print 5
      ptr --> NULL (right-most node)
      pass the second while loop
      exit do-while loop
*/

void inorder(struct tree *root) {
  struct tree *ptr = root, *prev;
  do {
    while (ptr != NULL) {
      prev = ptr;
      ptr = ptr->left;
    }
    if (prev != NULL) {
      printf(" %d", prev->val);
      ptr = prev->right;
      while (prev != NULL && prev->hasSuccessor) {
        printf(" %d", ptr->val);
        prev = ptr;
        ptr = ptr->right;
      }
    }
  } while (ptr != NULL);
}