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
*/

/*
Programming Example
1. Write a program to create a binary search tree and perform all the operations
discussed in the preceding sections.

# Creating a binary seearch tree: 45,39,56,12,34,78,32, ...
  45    45        45         45         45          45
 /     / \       / \        / \        / \         / \
39*  39  56*   39  56     39  56     39  56      39  56
              /          /          /     \     /     \
            12*        12         12      78* 12      78
                        \          \          \
                        34*        34         34
                                              /
                                            32*
# Characteristics of binary trees
- all elems of left subtree are smaller than parent
- all elems of right subtree are greater than parent

# Tree traversal
         1
      /    \
     2      3
    / \    / \
   4   5  6   7
  (a) Inorder (Left -> Root -> Right) : 4 2 5 1 6 3 7
  (b) Preorder (Root -> Left -> Right) : 1 2 4 5 3 6 7
  (c) Postorder (Left -> Right -> Root) : 4 5 2 6 7 3 1
  (d) Level-order (breadth-first traversal algorithm) : 1 2 3 4 5 6 7

# Delete node
          45
         / \
       39  56
           / \
         54  78
          \
          55
  a. no child: deleting 78
  b. one child: deleting 54
  c. two children: deleting 56

*/

#include <stdio.h>
#include <stdlib.h>

/**********************************************************
 * node
 **********************************************************/

struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node *tree;

/**********************************************************
 * prototypes
 **********************************************************/

void create_tree(struct node *);
struct node *insertElement(struct node *, int);
struct node *insertElement2(struct node *, int);
void preorderTraversal(struct node *);
void inorderTraversal(struct node *);
void postorderTraversal(struct node *);

struct node *findSmallestElement(struct node *);
struct node *findLargestElement(struct node *);
struct node *deleteElement(struct node *, int);
struct node *deleteElement2(struct node *, int);
struct node *mirrorImage(struct node *);

int totalNodes(struct node *);
int totalExternalNodes(struct node *);
int totalInternalNodes(struct node *);
int Height(struct node *);
struct node *deleteTree(struct node *);

/**********************************************************
 * main function
 **********************************************************/

int main() {
  int option, val;
  struct node *ptr;
  create_tree(tree);
  system("clear");

  do {
    printf("******MAIN MENU******* \n");
    /* Inserting */
    printf("1. Insert Element\n");
    /* Traversal */
    printf("2. Preorder Traversal (Root->Lt->Rt)\n");
    printf("3. Inorder Traversal (Lt->Root->Rt)\n");
    printf("4. Postorder Traversal (Lt->Rt->Root)\n");
    /* smallest, largest */
    printf("5. Find the smallest element\n");
    printf("6. Find the largest element\n");
    /* deleting a element */
    printf("7. Delete an element\n");
    /* counting */
    printf("8. Count the total number of nodes\n");
    printf("9. Count the total number of external nodes\n");
    printf("10. Count the total number of internal nodes\n");
    printf("11. Determine the height of the tree\n");
    printf("12. Find the mirror image of the tree\n");
    /* deleting whole tree */
    printf("13. Delete the tree\n");
    printf("14. Exit\n");

    printf("Enter your option: ");
    scanf("%d", &option);

    switch (option) {
      case 1:
        printf("Enter the value of the new node: ");
        scanf("%d", &val);
        tree = insertElement(tree, val);
        break;
      case 2:
        printf("The elements of the tree are:");
        preorderTraversal(tree);
        printf("\n");
        break;
      case 3:
        printf("The elements of the tree are:");
        inorderTraversal(tree);
        printf("\n");
        break;
      case 4:
        printf("The elements of the tree are:");
        postorderTraversal(tree);
        printf("\n");
        break;
      case 5:
        ptr = findSmallestElement(tree);
        printf("Smallest element is :%d\n", ptr->data);
        break;
      case 6:
        ptr = findLargestElement(tree);
        printf("Largest element is: %d\n", ptr->data);
        break;
      case 7:
        printf("Enter the element to be deleted: ");
        scanf("%d", &val);
        tree = deleteElement2(tree, val);
        break;
      case 8:
        printf("Total no. of nodes = %d\n", totalNodes(tree));
        break;
      case 9:
        printf("Total no. of external nodes = %d\n", totalExternalNodes(tree));
        break;
      case 10:
        printf("Total no. of internal nodes = %d\n", totalInternalNodes(tree));
        break;
      case 11:
        printf("The height of the tree = %d\n", Height(tree));
        break;
      case 12:
        tree = mirrorImage(tree);
        break;
      case 13:
        tree = deleteTree(tree);
        break;
    }
  } while (option != 14);

  return 0;
}

/**********************************************************
 * create_tree:
 * - initialize tree with NULL
 **********************************************************/

void create_tree(struct node *tree) { tree = NULL; }

/**********************************************************
 * insertElement:
 **********************************************************/

struct node *insertElement(struct node *tree, int val) {
  // two pointers are required
  struct node *new, *cur, *parent;

  // create a new node
  new = (struct node *)malloc(sizeof(struct node));
  new->data = val;
  new->left = NULL;
  new->right = NULL;

  // if tree is NULL
  if (tree == NULL) {
    tree = new;
    tree->left = NULL;
    tree->right = NULL;
  }
  // if tree is not NULL
  else {
    // tree traversal to find the parent node
    parent = NULL;
    cur = tree;
    while (cur != NULL) {
      parent = cur;
      if (val < cur->data)
        cur = cur->left;
      else
        cur = cur->right;
    }
    if (val < parent->data)
      // if val is smaller than parent data
      parent->left = new;
    else
      // if val is larget than parent data *
      parent->right = new;
  }

  return tree;
}

/**********************************************************
 * insertElement2:
 * - TODO: Why is this incorrect?
 **********************************************************/

struct node *insertElement2(struct node *tree, int val) {
  struct node *ptr, *moving;
  ptr = (struct node *)malloc(sizeof(struct node));
  ptr->data = val;
  ptr->left = NULL;
  ptr->right = NULL;

  // if tree is NULL
  if (tree == NULL) {
    tree = ptr;
    tree->left = NULL;
    tree->right = NULL;
  }
  // if tree is not NULL
  else {
    moving = tree;
    while (moving != NULL) {
      if (val < moving->data)
        moving = moving->left;
      else
        moving = moving->right;
    }
    moving = ptr;
  }
  return tree;
}

/**********************************************************
 * preorderTraversal: Root -> Lt -> Rt
 **********************************************************/

void preorderTraversal(struct node *tree) {
  if (tree != NULL) {
    printf("%d ", tree->data);  // anything, any job
    preorderTraversal(tree->left);
    preorderTraversal(tree->right);
  }
}

/**********************************************************
 * inorderTraversal: Lt -> Root -> Rt
 **********************************************************/

void inorderTraversal(struct node *tree) {
  if (tree != NULL) {
    inorderTraversal(tree->left);
    printf("%d ", tree->data);
    inorderTraversal(tree->right);
  }
}

/**********************************************************
 * postorderTraversal: Lt -> Rt -> Root
 **********************************************************/

void postorderTraversal(struct node *tree) {
  if (tree != NULL) {
    postorderTraversal(tree->left);
    postorderTraversal(tree->right);
    printf("%d ", tree->data);
  }
}

/**********************************************************
 * findSmallestElement:
 **********************************************************/

struct node *findSmallestElement(struct node *tree) {
  /* if tree is empty or no elem in left
     all values of elems in the left half of a tree
     is smaller than the value of parent node
  */
  if ((tree == NULL) || (tree->left == NULL)) return tree;
  /* recursively find base condition */
  else
    return findSmallestElement(tree->left);
}

/**********************************************************
 * findLargestElement:
 **********************************************************/

struct node *findLargestElement(struct node *tree) {
  if ((tree == NULL) || (tree->right == NULL))
    return tree;
  else
    return findLargestElement(tree->right);
}

/**********************************************************
 * deleteElement:
 * TODO: This is not working, code in this book is not correct!!
 * https://www.geeksforgeeks.org/binary-search-tree-set-2-delete/
  ex) delete 78           delete 54
    45       45           45       45        45
   / \      / \          / \      / \       / \
 39  56   39  56       39  56   39  56     39  56
    / \      / \          / \      / \        / \
  54  78   54  (-)      54  78   (-) 78     55  78
   \        \            \        \
   55       55           55       55

  ex) delete 56
    45       45        45       45
   / \      / \       / \      / \
 39  56   39  (-)   39  55*  39  55
    / \      / \       / \      / \
  54  78   54  78    54  78   54  78
   \   \    \   \     \   \        \
   55  80   55* 80   (-)  80       80
 **********************************************************/

struct node *deleteElement(struct node *root, int val) {
  struct node *cur, *parent, *suc, *psuc, *ptr;

  // if tree is empty
  if (root->left == NULL) {
    printf("The root is empty \n");
    return (root);
  }

  // traverse tree to find val
  parent = root;
  cur = root->left;
  while (cur != NULL && val != cur->data) {
    parent = cur;
    cur = (val < cur->data) ? cur->left : cur->right;
  }

  // if val does not exist
  if (cur == NULL) {
    printf("The value to be deleted is not present in the root\n");
    return root;
  }

  //
  if (cur->left == NULL)
    ptr = cur->right;
  else if (cur->right == NULL)
    ptr = cur->left;
  else {
    // Find the in-order successor and its parent
    psuc = cur;
    cur = cur->left;
    while (suc->left != NULL) {
      psuc = suc;
      suc = suc->left;
    }
    if (cur == psuc) {
      // Situation 1
      suc->left = cur->right;
    } else {
      // Situation 2
      suc->left = cur->left;
      psuc->left = suc->right;
      suc->right = cur->right;
    }
    ptr = suc;
  }

  // Attach ptr to the parent node
  if (parent->left == cur)
    parent->left = ptr;
  else
    parent->right = ptr;
  free(cur);

  return root;
}

/**********************************************************
 * deleteElement2:
 * TODO: Review this code again.
 * https://www.geeksforgeeks.org/binary-search-tree-set-2-delete/
 **********************************************************/

struct node *deleteElement2(struct node *root, int val) {
  /* I. base case: empty tree */
  if (root == NULL) return root;

  /* II-1. if val < root->data */
  if (val < root->data) root->left = deleteElement2(root->left, val);

  /* II-2. if val > root->data */
  else if (val > root->data)
    root->right = deleteElement2(root->right, val);

  /* II-3. if val == root->data, and, right or left is null */
  else {
    /* (1) node with only one child or no child */
    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    }
    /* (2) node with only one child or no child */
    else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    }
    /* (3) neither left nor right are NULL */
    struct node *temp = findSmallestElement(root->right);
    root->data = temp->data;

    /* (4) free the node which is moved to the root */
    root->right = deleteElement2(root->right, temp->data);
  }

  return root;
}

/**********************************************************
 * totalNodes:
 **********************************************************/

int totalNodes(struct node *tree) {
  if (tree == NULL)
    return 0;
  else
    return (totalNodes(tree->left) + totalNodes(tree->right) + 1);
}

/**********************************************************
 * totalExternalNodes:
 * - node with both left and right are null
 **********************************************************/

int totalExternalNodes(struct node *tree) {
  /* I-1. base case: empty tree, no root */
  if (tree == NULL) return 0;
  /* I-2. base case: only one node, root */
  else if ((tree->left == NULL) && (tree->right == NULL))
    return 1;
  /* II. recursive case: */
  else
    return (totalExternalNodes(tree->left) + totalExternalNodes(tree->right));
}

/**********************************************************
 * totalInternalNodes:
 * - any node with child node
 **********************************************************/

int totalInternalNodes(struct node *tree) {
  if ((tree == NULL) || ((tree->left == NULL) && (tree->right == NULL)))
    return 0;
  else
    return (totalInternalNodes(tree->left) + totalInternalNodes(tree->right) +
            1);
}

/**********************************************************
 * Height:
 **********************************************************/

int Height(struct node *tree) {
  int leftheight, rightheight;
  /* if empty tree, height is 0 */
  if (tree == NULL) return 0;
  /* if not empty, */
  else {
    leftheight = Height(tree->left);
    rightheight = Height(tree->right);
    if (leftheight > rightheight)
      return (leftheight + 1);
    else
      return (rightheight + 1);
  }
}

/**********************************************************
 * mirrorImage:
 * - swapping
 **********************************************************/

struct node *mirrorImage(struct node *tree) {
  struct node *ptr;
  if (tree != NULL) {
    /* recursively mirroring both Lt and Rt */
    mirrorImage(tree->left);
    mirrorImage(tree->right);

    /* swapping */
    ptr = tree->left;
    ptr->left = ptr->right;
    tree->right = ptr;
  }
  return tree;
}

/**********************************************************
 * deleteTree:
 * - TODO: review this kind of recursion later again.
 **********************************************************/

struct node *deleteTree(struct node *tree) {
  if (tree != NULL) {
    deleteTree(tree->left);
    deleteTree(tree->right);
    free(tree);
  }
}