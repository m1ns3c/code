#include "tree.h"

int main(int argc, char *argv[]) {
  auto s = new Solution();

  TreeNode* root = new TreeNode(100);
  root->left = new TreeNode(50);
  root->left->left = new TreeNode(20);
  root->right = new TreeNode(120);
  root->right->right = new TreeNode(140);

  auto result = s->inorder(root);

  for (auto i: result) {
    cout << i << " ";
  }

  return 0;
}
