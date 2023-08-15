// 226. 翻转二叉树
#include "../def.h"

// 递归 DFS
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root != nullptr) {
            TreeNode* t = root->left;
            root->left = invertTree(root->right);
            root->right = invertTree(t);
        }

        return root;
    }
};

// BFS
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return root;
        }

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            TreeNode* t = node->left;
            node->left = node->right;
            node->right = t;

            if (node->left != nullptr) {
                q.push(node->left);
            }
            if (node->right != nullptr) {
                q.push(node->right);
            }
        }
        
        return root;
    }
};