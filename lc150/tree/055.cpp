// 106. 从中序与后序遍历序列构造二叉树
#include "../def.h"

class Solution {
public:
    unordered_map<int, int> mp;
    vector<int> po;

    TreeNode* build(int is, int ie, int ps, int pe) {
        if (is > ie || ps > pe) {
            return nullptr;
        }

        int rootVal = po[pe];
        int rootIndex = mp[rootVal];

        TreeNode* root = new TreeNode(rootVal);
        root->left = build(is, rootIndex-1, ps, ps + (rootIndex - is) - 1);
        root->right = build(rootIndex+1, ie, ps + (rootIndex - is), pe - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i=0; i<inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        po = postorder;

        return build(0, inorder.size()-1, 0, postorder.size()-1);
    }
};