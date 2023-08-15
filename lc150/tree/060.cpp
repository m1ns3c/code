// 124. 二叉树中的最大路径和
#include "../def.h"

class Solution {
public:
    int maxSum;

    int maxPath(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int leftMax = max(maxPath(root->left), 0);
        int rightMax = max(maxPath(root->right), 0);

        int pricePath = root->val + leftMax + rightMax;

        maxSum = max(maxSum, pricePath);

        return root->val + max(leftMax, rightMax);
    }

    int maxPathSum(TreeNode* root) {
        maxSum = root->val;
        maxPath(root);
        return maxSum;
    }
};