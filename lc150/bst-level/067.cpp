// 103. 二叉树的锯齿形层序遍历
#include "../def.h"

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) {
            return res;
        }

        queue<TreeNode*> q;
        q.push(root);
        bool reverse = false;
        while (!q.empty()) {
            int sz = q.size();
            vector<int> tv(sz);
            for (int i=0; i<sz; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (reverse) {
                    tv[sz-1-i] = node->val;
                } else {
                    tv[i] = node->val;
                }

                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            
            res.push_back(tv);
            reverse = !reverse;
        }

        return res;
    }
};