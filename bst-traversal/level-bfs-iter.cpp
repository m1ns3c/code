#include "def.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;

        if (root == nullptr) {
            return res;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();
            vector<int> v;

            for (int i=0; i<sz; i++) {
                TreeNode* n = q.front();
                q.pop();
                v.push_back(n->val);
                if (n->left != nullptr) {
                    q.push(n->left);
                }
                if (n->right != nullptr) {
                    q.push(n->right);
                }
            }
            res.push_back(v);
        }
        return res;
    }
};