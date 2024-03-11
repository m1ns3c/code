#include "tree.h"

// 递归 左右子树+1
// 非递归
int maxDepth(TreeNode* root) {
  if (root == nullptr) return 0;
  return max(maxDepth(root->left)+1, maxDepth(root->right)+1);
}
