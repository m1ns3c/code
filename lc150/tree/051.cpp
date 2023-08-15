// 100. 相同的树
#include "../def.h"

// 先序(后序)和中序 数组相等
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void pre(TreeNode* root, vector<int>& res) {
        if (root == nullptr) {
            return;
        }

        res.push_back(root->val);
        pre(root->left, res);
        pre(root->right, res);
    }
    void in(TreeNode* root, vector<int>& res) {
        if (root == nullptr) {
            return;
        }

        pre(root->left, res);
        res.push_back(root->val);
        pre(root->right, res);
    }
    void post(TreeNode* root, vector<int>& res) {
        if (root == nullptr) {
            return;
        }

        pre(root->left, res);
        pre(root->right, res);
        res.push_back(root->val);
    }

    bool cmp(vector<int>& a, vector<int>& b) {
        if (a.size() != b.size()) {
            return false;
        }

        for(int i=0; i<a.size(); i++) {
            if (a[i] != b[i]) {
                return false;
            }
        }

        return true;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> pr;
        vector<int> qr;

        pre(p, pr);
        pre(q, qr);
        if (!cmp(pr, qr)) {
            return false;
        }

        in(p, pr);
        in(q, qr);
        if (!cmp(pr, qr)) {
            return false;
        }

        return true;
    }
};

// 递归
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p != nullptr && q != nullptr) {
            if (p->val != q->val) {
                return false;
            }

            if (!isSameTree(p->left, q->left)) {
                return false;
            }
            if (!isSameTree(p->right, q->right)) {
                return false;
            }

            return true;
        }

        return p == nullptr && q == nullptr;
    }
};