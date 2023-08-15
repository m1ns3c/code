// 112. 路径总和
#include "../def.h"

// key：保存路径和，而不是一个变量 sum 记录全局
// 保证路径不丢失，方便回退

// DFS BFS 回溯 栈

// 错误
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return false;
        }

        stack<TreeNode*> st;
        st.push(root);

        int sum = 0;
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();

            sum += node->val;
            
            if (node->left != nullptr) {
                st.push(node->left);
            }

            if (node->right != nullptr) {
                st.push(node->right);
            }

            if (node->left == nullptr && node->right == nullptr) {
                if (sum == targetSum) {
                    return true;
                } else {
                    sum -= node->val;
                }
            }
        }

        return false;
    }
};

// 递归 DFS
class Solution {
public:
    bool dfs(TreeNode* root, int targetSum, int sum) {
        if (root == nullptr) {
            return false;
        }

        sum += root->val;
        if (root->left == nullptr && root->right == nullptr && targetSum == sum) {
            return true;
        }

        return dfs(root->left, targetSum, sum) || dfs(root->right, targetSum, sum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        // DFS
        if (root == nullptr) {
            return false;
        }

        return dfs(root, targetSum, 0);
    }
};

// BFS 二元组（结点,路径和）
