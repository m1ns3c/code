#include "tree.h"

bool Solution::isSymmetric(TreeNode* root) {
  if (root == nullptr || (root->left == nullptr && root->right == nullptr)) return true;

  queue<TreeNode*> que;
  que.push(root->left);
  que.push(root->right);

  while (!que.empty()) {
    TreeNode* l = que.front();
    que.pop();
    TreeNode* r = que.front();
    que.pop();

    if (l == nullptr && r == nullptr) {
      continue;
    }

    if (l == nullptr || r == nullptr) {
      return false;
    }

    if (l->val != r->val) {
      return false;
    }

    que.push(l->left);
    que.push(r->right);

    que.push(l->right);
    que.push(r->left);
  }

  return true;
}
