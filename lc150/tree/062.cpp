// 222. 完全二叉树的节点个数
#include "../def.h"

// 位运算 + 二分查找

class Solution {
public:
    int h = 0;
    void height(TreeNode* root) {
        TreeNode* node = root;
        while (node->left != nullptr) {
            h++;
            node = node->left;
        }
    }

    bool exists(TreeNode* root, int pos) {
        int bits = 1 << (h - 1);
        TreeNode* node = root;
        while (node != nullptr && bits > 0) {
            if (pos & bits) {
                node = node->right;
            } else {
                node = node->left;
            }
            bits >>= 1;
        }
        return node != nullptr;
    }

    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        height(root);
        int low = 1 << h, high = (1 << (h + 1)) - 1;
        while (low < high) {
            int mid = (high - low + 1) / 2 + low;
            if (exists(root, mid)) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};