#include "tree.h"

// dfs 非递归 中序
vector<int> Solution::inorder(TreeNode* root) {
  vector<int> result;
  stack<TreeNode*> st;

  if (!root) return result;

  TreeNode* cur = root;

  while (cur != nullptr || !st.empty()) {
    while (cur != nullptr) {
      st.push(cur);
      cur = cur->left;
    }

    cur = st.top();
    st.pop();

    result.push_back(cur->val);

    cur = cur->right;
  }

  return result;
}

/** 递归
vector<int> res;

void dfs(TreeNode* node, ) {
  if (node == nullptr) return;

  dfs(node->left);
  res.push_back(node->val);
  dfs(node->right);
}

vector<int> Solution::dfsInorder(TreeNode* root) {
  vector<int> res;

  dfs(root);

  return res;
}
*/
