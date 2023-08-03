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
    vector<vector<int>> res;

    void dfs(TreeNode* root, int depth) {
        if (root == nullptr) {
            return;
        }
        depth++;

        if (res.size() < depth) {
            vector<int> tv;
            res.push_back(tv);
        }

        res[depth - 1].push_back(root->val);
        dfs(root->left, depth);
        dfs(root->right, depth);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        dfs(root, 0);

        return res;
    }
};