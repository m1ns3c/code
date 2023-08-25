// 98. 验证二叉搜索树
#include "../def.h"

// 前序遍历
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        // 中序遍历
        stack<TreeNode*> st;

        TreeNode* pre = nullptr;
        while (root != nullptr || !st.empty()) {
            while (root != nullptr) {
                st.push(root);
                root = root->left;
            }

            root = st.top();
            st.pop();

            if (pre == nullptr) {
                pre = root;
            } else {
                if (pre->val >= root->val) {
                    return false;
                }
                pre = root;
            }

            root = root->right;
        }

        return true;
    }
};