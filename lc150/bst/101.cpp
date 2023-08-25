// 230. 二叉搜索树中第K小的元素
#include "../def.h"

// DFS - 递归
class Solution {
public:
    int minK;
    void dfs(TreeNode* root, int& k) {
        if (root == nullptr || k <= 0) {
            return;
        }

        dfs(root->left, k);
        if (--k == 0) {
            minK = root->val;
            return;
        }
        dfs(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        // 中序遍历 升序
        // 第 k 个位置
        dfs(root, k);

        return minK;
    }
};

// DFS - 栈
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        st.push(root);

        while (root != nullptr || !st.empty()) {
            while (root != nullptr) {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            --k;
            if (k == 0) {
                break;
            }
            root = root->right;
        }

        return root->val;
    }
};

// 频繁查找，记录节点子树节点数
