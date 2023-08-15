// 105. 从前序与中序遍历序列构造二叉树
#include "../def.h"

// 中序做哈希，分割左|右子树长度及位置信息

class Solution {
public:
    unordered_map<int, int> mp;
    vector<int> pre;

    TreeNode* makeNode(int ps, int pe, int is, int ie) {
        if (ps > pe || is > ie) {
            return nullptr;
        }

        int val = pre[ps];
        int index = mp[val];

        TreeNode* node = new TreeNode(val);

        node->left = makeNode(ps+1, ps + (index - is), is, index-1);
        node->right = makeNode(ps + (index - is) + 1, pe, index+1, ie);

        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i=0; i<inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        pre = preorder;

        return makeNode(0, preorder.size()-1, 0, inorder.size()-1);
    }
};