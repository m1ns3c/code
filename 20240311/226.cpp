#include "tree.h"

TreeNode* Solution::invertTree(TreeNode* root) {
  if (root == nullptr) return root;

  queue<TreeNode*> que;
  que.push(root);

  while (!que.empty()) {
    int n = que.size();
    while (n--) {
      TreeNode* t = que.front();
      que.pop();

      if (t->left != nullptr) que.push(t->left);
      if (t->right != nullptr) que.push(t->right);

      TreeNode* temp = t->left;
      t->left = t->right;
      t->right = temp;
    }
  }
  return root;
}
