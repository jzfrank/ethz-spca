#include <stdio.h>  // for NULL
#include <stdlib.h> // malloc free
#include <assert.h> // assert
#include "bst.h"

int insert(TreeNode *root, int val)
{
  if (root == NULL)
  {
    TreeNode *new_node = (TreeNode *)malloc(sizeof(TreeNode));
    if (new_node == NULL)
    {
      return 0;
    }
    new_node->val = val;
    root = new_node;
    return 1;
  }

  if (root->val > val)
  {
    insert(root->left, val);
  }
  else if (root->val < val)
  {
    insert(root->right, val);
  }
  else
  {
    return -1; // already present
  }
}

int lookup(TreeNode *root, int val);
