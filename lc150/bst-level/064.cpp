// 199. 二叉树的右视图
#include "../def.h"

// DFS + 层高 + 右子树
// 结点 和 深度 存储两个队列/栈


// BFS + 队列
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        // BFS 最后一个元素
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();
            for (int i=0; i<sz; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }

                if (i == sz-1) {
                    res.push_back(node->val);
                }
            }
        }
        return res;
    }
};