/**********************************************************
  btree.c - A binary tree implementation
  https://stuff.mit.edu/afs/sipb/user/gamadrid/nscript/btree.c

  Public functions
  ----------------

  BTREE btree_Create(size_t size, int (*cmp)(const void *, const void *))

  Create a btree which holds elements of size <size>.  The (non-strict)
  ordering or the elements is determined by the function <cmp>.  <cmp> should
  be a function which takes a two pointers to elements and returns a value
  less than, equal to, or greater than zero if the first value is less than,
  equal to, or greater than the second, respectively.


  int btree_Search(BTREE tree, void *key, void *ret)

  Search the <tree> for an element "equal" to <key> and return it in the space
  pointed to by <ret>.  If <ret> is NULL, then don't bother returning any
  values.  This routine returns a zero value on success and a non-zero value
  if it fails to find the <key> value.


  int btree_Minimum(BTREE tree, void *ret)
  int btree_Maximum(BTREE tree, void *ret)

  Return the minimum/maximum value in <tree> in the space pointed to by <ret>.
  If <ret> is NULL, then don't bother returning any values.  This routine
  returns a zero value on success and a non-zero value if it fails, (i.e., the
  tree is empty).

  int btree_Empty(BTREE tree)

  Returns a non-zero value if the <tree> is empty, and a zero value if it
  contains elements.


  int btree_Successor(BTREE tree, void *key, void *ret)
  int btree_Predecessor(BTREE tree, void *key, void *ret)

  Returns the value immediately after/before <key> in the <tree>.  The value
  is returned in the space pointed to by <ret>.  If <ret> is NULL, then don't
  bother to return anything.  This routine returns a zero value on success and
  a non-zero value if it fails.


  int btree_Insert(BTREE tree, void *elem)

  Insert <elem> into the <tree>.  Returns zero on success and non-zero if it
  fails.


  int btree_Delete(BTREE tree, void *elem)

  Remove <elem> from the <tree>.  Returns zero on success and non-zero if it
  fails, i.e., <elem> is not in the <tree> to begin with.


  void btree_Destroy(BTREE tree)

  Close <tree> and free all of the memory that it used.

***********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ---------- Private macros ---------- */
#define root(t) (t->root)
#define node_size(t) (t->node_size)
#define elem_size(t) (t->elem_size)

#define parent(n) (n->parent)
#define left(n) (n->left)
#define right(n) (n->right)

#define data(t, n) (((char *)n) + node_size(t))
#define data_copy(t, d, s) memcpy(d, s, elem_size(t))
#define data_compare(t, f, s) ((t)->cmp)(f, s)

/* ---------- Private data type declarations ---------- */
struct _btree_struct
{
  struct node *root;
  size_t node_size; /* Size of the node is unknown, e.g., R-B trees. */
  size_t elem_size;
  int (*cmp)(const void *, const void *);
};

typedef struct node
{
  struct node *parent;
  struct node *left;
  struct node *right;
} * btnode;

/* ---------- Incomplete data types ---------- */
typedef struct _btree_struct *BTREE;

/* ---------- Private function declarations ---------- */
static btnode node_Minimum(btnode);
static btnode node_Maximum(btnode);
static btnode node_Search(BTREE, btnode, void *);
static void node_Close(btnode);
static btnode node_Successor(btnode);
static btnode node_Make(BTREE tree, void *data);
static void btree_reallyPrint(BTREE, btnode, FILE *, unsigned int);

/* ---------- Public function declarations ---------- */
extern BTREE btree_Create(size_t size, int (*cmp)(const void *, const void *));
extern int btree_Search(BTREE tree, void *key, void *ret);
extern int btree_Minimum(BTREE tree, void *ret);
extern int btree_Maximum(BTREE tree, void *ret);
extern int btree_Empty(BTREE tree);
extern int btree_Successor(BTREE tree, void *key, void *ret);
extern int btree_Predecessor(BTREE tree, void *key, void *ret);
extern int btree_Insert(BTREE tree, void *data);
extern int btree_Delete(BTREE tree, void *data);
extern void btree_Destroy(BTREE);
extern void btree_print(BTREE, void *); /* Do NOT use. */

/* ---------------------------------------------------------------------- */
BTREE btree_Create(size_t size, int (*cmp)(const void *, const void *))
{
  BTREE ret;

  ret = malloc(sizeof(struct _btree_struct));
  if (ret)
  {
    ret->root = NULL;
    ret->node_size = sizeof(struct node);
    ret->elem_size = size;
    ret->cmp = cmp;
  }
  return ret;
}

/* ---------------------------------------------------------------------- */
int btree_Search(BTREE tree, void *key, void *ret)
{
  btnode node;

  node = root(tree);

  node = node_Search(tree, node, key);

  if (node)
  {
    if (ret)
      data_copy(tree, ret, data(tree, node));
    return 0;
  }
  else
  {
    return 1;
  }
}

/* ---------------------------------------------------------------------- */
static btnode node_Search(BTREE tree, btnode node, void *key)
{
  int result;

  if (node)
  {
    while (node && (result = data_compare(tree, data(tree, node), key)))
    {
      if (result > 0)
      {
        node = left(node);
      }
      else
      {
        node = right(node);
      }
    }
  }
  return node;
}

/* ---------------------------------------------------------------------- */
int btree_Minimum(BTREE tree, void *ret)
{
  btnode node;

  node = node_Minimum(root(tree));
  if (node)
  {
    data_copy(tree, ret, data(tree, node));
    return 0;
  }
  return 1;
}

/* ---------------------------------------------------------------------- */
static btnode node_Minimum(btnode node)
{
  if (node)
  {
    while (left(node))
    {
      node = left(node);
    }
  }
  return node;
}

/* ---------------------------------------------------------------------- */
int btree_Maximum(BTREE tree, void *ret)
{
  btnode node;

  node = node_Maximum(root(tree));
  if (node)
  {
    data_copy(tree, ret, data(tree, node));
    return 0;
  }
  return 1;
}

/* ---------------------------------------------------------------------- */
static btnode node_Maximum(btnode node)
{
  if (node)
  {
    while (right(node))
    {
      node = right(node);
    }
  }
  return node;
}

/* ---------------------------------------------------------------------- */
int btree_Empty(BTREE tree) { return root(tree) ? 0 : 1; }

/* ---------------------------------------------------------------------- */
int btree_Successor(BTREE tree, void *key, void *ret)
{
  btnode node;

  if (!root(tree))
    return 1;

  node = node_Search(tree, root(tree), key);

  if (!node)
    return 1;

  node = node_Successor(node);

  if (node)
  {
    data_copy(tree, ret, data(tree, node));
    return 0;
  }
  return 1;
}

/* ---------------------------------------------------------------------- */
static btnode node_Successor(btnode node)
{
  btnode node2;

  if (right(node))
  {
    node = node_Minimum(right(node));
  }
  else
  {
    node2 = parent(node);
    while (node2 && node == right(node2))
    {
      node = node2;
      node2 = parent(node);
    }
    node = node2;
  }
  return node;
}

/* ---------------------------------------------------------------------- */
int btree_Predecessor(BTREE tree, void *key, void *ret)
{
  btnode node, node2;

  if (!root(tree))
    return 1;

  node = node_Search(tree, root(tree), key);

  if (!node)
    return 1;

  if (left(node))
  {
    node = node_Maximum(left(node));
  }
  else
  {
    node2 = parent(node);
    while (node2 && node == left(node2))
    {
      node = node2;
      node2 = parent(node);
    }
    node = node2;
  }

  if (node)
  {
    data_copy(tree, ret, data(tree, node));
    return 0;
  }
  return 1;
}

/* ---------------------------------------------------------------------- */
int btree_Insert(BTREE tree, void *data)
{
  btnode parent, node, newnode;

  newnode = node_Make(tree, data);
  if (!newnode)
  {
    return 1;
  }

  parent = NULL;
  node = root(tree);

  while (node)
  {
    parent = node;
    if (data_compare(tree, data, data(tree, node)) < 0)
    {
      node = left(node);
    }
    else
    {
      node = right(node);
    }
  }

  parent(newnode) = parent;

  if (!parent)
  {
    root(tree) = newnode;
  }
  else
  {
    if (data_compare(tree, data, data(tree, parent)) < 0)
    {
      left(parent) = newnode;
    }
    else
    {
      right(parent) = newnode;
    }
  }
  return 0;
}

/* ---------------------------------------------------------------------- */
int btree_Delete(BTREE tree, void *data)
{
  btnode node;
  btnode remove;
  btnode other;

  if (!root(tree))
    return 1;

  node = node_Search(tree, root(tree), data);

  if (!node)
    return 1;

  if (!left(node) || !right(node))
  {
    remove = node;
  }
  else
  {
    remove = node_Successor(node);
  }

  if (left(remove))
  {
    other = left(remove);
  }
  else
  {
    other = right(remove);
  }

  if (other)
  {
    parent(other) = parent(remove);
  }

  if (!parent(remove))
  {
    root(tree) = other;
  }
  else
  {
    if (remove == left(parent(remove)))
    {
      left(parent(remove)) = other;
    }
    else
    {
      right(parent(remove)) = other;
    }
  }

  if (node != remove)
  {
    data_copy(tree, data(tree, node), data(tree, remove));
  }
  free(node);
  return 0;
}

/* ---------------------------------------------------------------------- */
void btree_Destroy(BTREE tree)
{
  if (root(tree))
  {
    node_Close(root(tree));
  }
  free(tree);
}

/* ---------------------------------------------------------------------- */
static void node_Close(btnode node)
{
  if (left(node))
  {
    node_Close(left(node));
  }
  if (right(node))
  {
    node_Close(right(node));
  }
  free(node);
}

/* ---------------------------------------------------------------------- */
static btnode node_Make(BTREE tree, void *data)
{
  btnode ret;

  ret = malloc(node_size(tree) + elem_size(tree));

  if (ret)
  {
    data_copy(tree, data(tree, ret), data);
    parent(ret) = left(ret) = right(ret) = NULL;
  }
  return ret;
}

/* ------------------------------------------------------------------------ */
/*
  Note that this routine assumes that the data elements are char *'s
 */
void btree_print(BTREE tree, void *where)
{
  btree_reallyPrint(tree, root(tree), (FILE *)where, 2);
}

/* ------------------------------------------------------------------------ */
void btree_reallyPrint(BTREE tree, btnode node, FILE *where,
                       unsigned int spaces)
{
  fprintf(where, "%*s%s\n", spaces, " ",
          (node ? *(char **)data(tree, node) : "NULL"));
  if (node)
  {
    btree_reallyPrint(tree, left(node), where, spaces + 4);
    btree_reallyPrint(tree, right(node), where, spaces + 4);
  }
}
