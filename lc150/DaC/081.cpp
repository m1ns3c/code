// 108. 将有序数组转换为二叉搜索树
#include "../def.h"

// 要对已排序 递增 非递减 有敏感度

class Solution {
public:
    TreeNode* genTree(vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        int mid = left + (right - left) / 2;

        TreeNode* node = new TreeNode(nums[mid]);
        node->left = genTree(nums, left, mid-1);
        node->right = genTree(nums, mid+1, right);

        return node;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // 中序构造
        int n = nums.size();
        return genTree(nums, 0, n-1);
    }
};