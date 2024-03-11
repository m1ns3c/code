#ifndef TREE_H_
#define TREE_H_

#include <iostream>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(): val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x): val(x),  left(nullptr), right(nullptr) {}
};

class Solution {
public:
  // 144 前序
  vector<int> preorder(TreeNode* root);
  // 94 中序
  vector<int> inorder(TreeNode* root);
  // 145 后序
  vector<int> postorder(TreeNode* root);
};

#endif // TREE_H_
