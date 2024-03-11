// 530. 二叉搜索树的最小绝对差
#include "../def.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minDiff = INT_MAX;
    void dfs(TreeNode* root, int& pre) {
        if (root == nullptr) {
            return;
        }

        dfs(root->left, pre);
        if (pre == -1) {
            pre = root->val;
        } else {
            minDiff = min(minDiff, root->val - pre);
            pre = root->val;
        }
        dfs(root->right, pre);
    }

    int getMinimumDifference(TreeNode* root) {
        int pre = -1;
        dfs(root, pre);
        return minDiff;
    }
};