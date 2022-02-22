/* Data Structures Using C, 2nd, Reema Thareja
Chapter 11. Multi-way Search Trees
11.1 Introduction
11.2 B tree
  11.2.1 Searching for an element in a B tree
  11.2.2 Inserting a new element in a B tree
  11.2.3 Deleting an element from a B tree
  11.2.4 Applications of B trees
11.3 B* trees
  11.3.1 Inserting a new element in a B+ tree
  11.3.2 Deleting an element from a B+ tree
11.4 2-3 Tree
  11.4.1 Searching for an element in a 2-3 Tree
  11.4.2 Inserting a New element in a 2-3 Tree
  11.4.3 Deleting an element from a 2-3 Tree
*/

/*
* 2-3 tree
  - height balanced tree, not a binary tree

* Properties of 2-3 tree
  In a 2-3 tree, each interior node has either two or three children.
  - Nodes with two children are called 2-nodes. 
    The 2-nodes have one data value and two children
  - Nodes with three children are called 3-nodes. 
    The 3-nodes have two data values and three children 
    (left child, middle child, and a right child)

  https://www.cs.csustan.edu/~john/Classes/Previous_Semesters/CS3100_DataStructures/2005_04_Fall/Notes/Trees/2_3_Tree.html
  - Each node has one or two keys
  - All leaves are at the same level (balanced)
  - Each internal node has 1 key and 2 children or 2 keys and 3 children.
  - A binary search tree containing N nodes has O(log(N)) height on average 
    but the height can be Θ(N).
  - A 2-3 tree with N nodes always has height O(log(N))
  - Specifically, in a 2-3 tree with N nodes and height h, h <= ceiling(log2(N+1)) and N >= 2h-1.
  - 2-3 trees therefore have worst case search, insertion, and deletion performance of O(logN).

  http://pages.cs.wisc.edu/~vernon/cs367/notes/10.23TREE.html

* Searching 
  The search for a data value x starts at the root. 
  If k1 and k2 are the two values stored in the root node, then

  - if x < k1, move to the left child.
  - if x >= k1 and the node has only two children, move to the right child.
  - if x >= k1 and the node has three children, 
    then move to the middle child if x < k2 else to the right child if x >= k2.

  At the end of the process, 
  the node with data value x is reached if and only if x is at this leaf.

* Inserting a new element in a 2-3 Tree

                           [*54*]
                   /                    \
             [*36*]                   [*72*90*]
            /      \                 /    |    \
    [*18*27*]  [*45*]            [*63*] [*81*] [*99*]

                           [*54*]
                   /                    \
             [*36*]                   [*72*90*]
            /      \                 /    |    \
    [*18*27*] [*(39)*45*]         [*63*] [*81*] [*99*]   // insert 39

                           [*54*]
                   /                    \
             [*36*]                   [*72*90*]
            /      \                 /    |    \
    [*18*27*] [*(37)*39*45*]     [*63*] [*81*] [*99*]   

                           [*54*]
                   /                    \
             [*36*39*]                [*72*90*]
            /    |    \              /    |    \
    [*18*27*] [*37*] [*45*]     [*63*] [*81*] [*99*]   

                           [*54*]
                   /                    \
             [*36*39*]                [*72*90*]
            /    |    \              /    |    \
    [*18*27*] [*37*] [*(42)*45*] [*63*] [*81*] [*99*]   

                           [*54*]
                   /                    \
             [*36*39*]                   [*72*90*]
            /    |    \                 /    |    \
    [*18*27*] [*37*] [*42*45*(47)*] [*63*] [*81*] [*99*]      

                           [*54*]
                   /                    \
             [*36*39*(45)*]              [*72*90*]
            /    |    \    \            /    |    \
    [*18*27*] [*37*] [*42*] [*47*] [*63*] [*81*] [*99*]     

                           [*(39)*54*]
                   /           |          \
             [*36*]         [*45*]        [*72*90*]
            /      \       /      \      /    |    \
    [*18*27*]   [*37*] [*42*] [*47*] [*63*] [*81*] [*99*]     

* Deleting an element from a 2-3 Tree

                       [*54*]
                   /            \
             [*36*]           [*69*90*]
            /      \         /    |    \
    [*18*27*]  [*45*]  [*63*] [*72*81*] [*99*] 

                       [*54*]
                   /             \
             [*36*]            [*(72)*90*]
            /      \          /    |    \
    [*18*27*]  [*45*]   [*63*]   [*81*] [*99*]   // 69 deleted

                      [*54*]
                   /         \
             [*36*]           [*(81)*90*]
            /      \          /    |    \
    [*18*27*]  [*45*]   [*63*]     X     [*99*]   

                       [*54*]
                   /             \
             [*36*]              [*90*]
            /      \           /        \
    [*18*27*]  [*45*]   [*63*81*]       [*99*] 

                       [*54*]
                   /             \
             [*36*]              [*90*]
            /      \           /        \
    [*18*27*]  [*45*]   [*63*81*]       X   // 99 deleted

                       [*54*]
                   /           \
             [*36*]            [*(81)*]
            /      \         /        \
    [*18*27*]  [*45*]   [*63*]       [*(90)*]

                       [*54*]
                   /           \
             [*36*]            [*(90)*]
            /      \         /        \
    [*18*27*]  [*45*]   [*63*]        X  // 81 deleted

                    [*54*]
                   /      \
             [*36*]        X
            /      \       |
    [*18*27*]  [*45*]  [*63*90*]        

              [*36*54*]
             /    |    \
    [*18*27*]  [*45*]   [*63*90*]     
*/

// https://github.com/rafallis/2-3-tree-in-C

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STACK_SIZE 1000

/**
 * 2-3 tree (THree) have two types of pointer nodes.
 * Those who pointes to leaf and those who points to other nodes.
 *
 * @node points to a 2-3 tree node.
 * @data item value of a node.
 */
struct _THtree_node;
typedef struct _THtree_link
{
  struct _THtree_node *node; // internal node
  // int data;
} THtree_link;

/**
 * @key1 points to items with the smallest key in the middle-child.
 * @key2 points to items with the smallest key in the right-child (NULL if not
 * exists).
 * @left, @middle, @right stores the 3 possible paths of itens.
 * @link_kink defines if node is leaf or internal.
 */
typedef struct _THtree_node
{
  int key1, key2;
  THtree_link *left, *middle, *right;
  enum
  {
    LEAF,
    INTERNAL
  } link_kind;
} THtree_node;

/**
 * @n number of data items stored.
 * @root points to the root node.
 * @stack stack of items in the tree.
 */
typedef struct _THtree
{
  int n;
  THtree_node *root;
  THtree_node **stack;
} THtree;

/**
 * Allocates instances of 2-3 tree and returns a poninter to it
 */
THtree *THtree_alloc();

/**
 * Frees space used by the 2-3 tree.
 */
void THtree_free(THtree *tree);

/**
 * Inserts an item to 2-3 tree.
 * If the item already is in the tree, the function returns
 * the pointer to the existent item.
 */
void *THtree_insert(THtree *tree, int item);
void *THtree_find(THtree *tree, int key_item);
void *THtree_find_min(THtree *tree);
void *THtree_delete(THtree *tree, int key_item);
void *THtree_delete_min(THtree *tree);

int main(int argc, char **argv)
{
  printf("hellow\n");
  // alloc_test();

  return 0;
}

/********** THtree_alloc **********/
THtree *THtree_alloc()
{
  THtree *tree;
  THtree_node *root;

  tree = malloc(sizeof(THtree));
  tree->n = 0;
  root = tree->root = malloc(sizeof(THtree_node));
  tree->stack = malloc(STACK_SIZE * sizeof(THtree_node *));
  root->key1 = r->key2 = 0;
  root->link_kind = LEAF;
  root->left->node = root->middle->node = root->right->node = NULL;

  return t;
}

/********** THtree_free **********/
void THtree_free(THtree *tree)
{
  int tos;
  THtree_node *p, *stack;

  stack = malloc(2 * STACK_SIZE * sizeof(THtree_node *));
  stack[0] = tree->root;
  tos = 1;

  while (tos)
  {
    p = stack[--tos];
    if (p->link_kind == INTERNAL)
    {
      stack[tos++] = p->left.node;
      stack[tos++] = p->middle.node;
      if (p->right.node)
        stack[tos++] = p->right.node;
    }
    x free(p);
  }

  free(stack);

  free(tree->stack);
  free(tree);
}

/********** THtree_insert **********/
void *THtree_insert(THtree *tree, int item)
{
  THtree_node *temp = NULL;
  THtree_node *temp2 = NULL;

  if (tree->n == 0)
  {
    tree->root->key1 = item;
    tree->root->n++;
  }
  else
  {
    // only root node with one key
    if (tree->n == 1)
    {
      if (item > tree->root->key1)
      {
        tree->root->key2 = tree->root->key1;
        tree->root->key1 = item;
      }
      else
      {
        tree->root->key2 = item;
      }
    }

    // only root node with two keys
    else if (tree->n == 2)
    {
      temp = malloc(sizeof(*THtree_node));
      temp->key1 = temp->key2 = 0;
      temp->left = temp->middle = temp->right = NULL;
      temp->link_kind = LEAF;

      temp2 = malloc(sizeof(*THtree_node));
      temp2->key1 = temp2->key2 = 0;
      temp2->left = temp2->middle = temp2->right = NULL;
      temp->link_kind = LEAF;

      if (item < tree->root->key1)
      {
        temp->key1 = item;
        temp2->key1 = tree->root->key2;
        tree->root->key2 = 0;
      }
      else if (item < tree->root->key2)
      {
        temp->key1 = tree->root->key1;
        temp2->key1 = tree->root->key2;
        tree->root->key1 = item;
        tree->root->key2 = 0;
      }
      else
      {
        temp->key1 = tree->root->key1;
        temp2->key1 = item;
        tree->root->key1 = tree->root->key2;
        tree->root->key2 = 0;
      }
      tree->root->left = temp;
      tree->root->right = temp2;
    }

    // tree has more than 2 keys
    else
    {
      if (item < tree->root->key1)
      {
      }
      else if item < tree->root->key2)
        {
        }
      else
      {
      }
    }

    tree->n++;
  }
}

/********** THtree_find **********/
void *THtree_find(THtree *tree, int key_item) {}

/********** THtree_find_min **********/
void *THtree_find_min(THtree *tree) { return t->min_item; }