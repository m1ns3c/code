#include "tree.h"

vector<vector<int>> Solution::levelOrder(TreeNode* root) {
  vector<vector<int>> res;

  if (root == nullptr) return res;

  queue<TreeNode*> que;
  que.push(root);

  while (!que.empty()) {
    int n = que.size();
    vector<int> vec;

    while (n--) {
      TreeNode* t = que.front();
      que.pop();
      vec.push_back(t->val);
      if (t->left != nullptr) que.push(t->left);
      if (t->right != nullptr) que.push(t->right);
    }
    res.push_back(vec);
  }
  return res;
}
