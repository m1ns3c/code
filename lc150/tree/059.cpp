// 129. 求根节点到叶节点数字之和
#include "../def.h"

// 记录路径

// DFS 栈
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        stack<pair<TreeNode*, int>> st;
        st.push({root, 0});

        int sum = 0;
        while (!st.empty()) {
            TreeNode* node = st.top().first;
            int path = st.top().second * 10 + node->val;
            st.pop();

            if (node->left != nullptr) {
                st.push({node->left, path});
            }
            if (node->right != nullptr) {
                st.push({node->right, path});
            }
            if (node->left == nullptr && node->right == nullptr) {
                sum += path;
            }
        }
        return sum;
    }
};

// BFS 双队列
