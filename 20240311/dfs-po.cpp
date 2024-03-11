#include "g.h"

class Solution {
public:
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> st;

    if (!root) return result;

    st.push(root);

    while (!st.empty()) {
      TreeNode*& node = st.top();
      st.pop();
      result.push_back(node->val);

      if (node->right) st.push(node->right);
      if (node->left) st.push(node->left);
    }

    return result;
  }
};

int main() {
  auto s = new Solution();

  TreeNode* root = new TreeNode(100);
  root->left = new TreeNode(50);
  root->left->left = new TreeNode(20);
  root->right = new TreeNode(80);
  root->right->right = new TreeNode(40);

  auto result = s->preorderTraversal(root);

  for (auto i: result) {
    cout << i << " ";
  }
}
