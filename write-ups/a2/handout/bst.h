#ifndef _BST_H_
#define _BST_H_

typedef struct TreeNode
{
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
} TreeNode;

// Returns:
//
// - 1 if the element was added
// - 0 if we ran out of memory
// - -1 if the element was already in the tree, in which case
//   nothing is malloc'ed and the element is not re-added.
//   (The element already being in the tree implies the
//   comparator returned 0 for some element.)
int insert(TreeNode *root, int val);

int lookup(TreeNode *root, int val);

#endif // _BST_H_
