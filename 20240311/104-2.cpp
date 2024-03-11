#include "tree.h"

int maxDepth(TreeNode* root) {
  int level = 0;

  if (root == nullptr) return level;

  queue<TreeNode*> que;
  que.push(root);
  while (!que.empty()) {
    int n = que.size();
    while (n--) {
      TreeNode* t = que.front();
      que.pop();
      if (t->left != nullptr) que.push(t->left);
      if (t->right != nullptr) que.push(t->right);
    }
    level++;
  }
  return level;
}
