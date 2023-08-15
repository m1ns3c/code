// 114. 二叉树展开为链表
#include "../def.h"

// 右子树 深度递归 下降到 左子树的右子树叶子节点
// 左子树 转换为 右子树
// 递归右子树

class Solution {
public:
    void flatten(TreeNode* root) {
        // 先序遍历
        // 左子树不为空时
        // 右子树下降，称为左子树的子节点
        TreeNode* p = root;
        while (p != nullptr) {
            if (p->left != nullptr) {
                if (p->right != nullptr) {
                    TreeNode* cur = p->left;
                    TreeNode* prev;
                    while (cur != nullptr) {
                        prev = cur;
                        cur = cur->right;
                    }
                    prev->right = p->right;
                }
                p->right = p->left;
                p->left = nullptr;
            }
            p = p->right;
        }
    }
};