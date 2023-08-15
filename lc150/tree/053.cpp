// 101. 对称二叉树
#include "../def.h"

// DFS 递归
class Solution {
public:
    bool isSame(TreeNode* l, TreeNode* r) {
        if (l == nullptr) {
            if (r != nullptr) {
                 return false;
             } else {
                 return true;
             }
        } else {
             if (r == nullptr) {
                 return false;
             } else {
                if (l->val != r->val) {
                    return false;
                }
             }
        }

        if (!isSame(l->left, r->right)) {
            return false;
        }
        if (!isSame(l->right, r->left)) {
            return false;
        }

        return true;
    }

    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        return isSame(root->left, root->right);
    }
};

// BFS 队列
class Solution {
public:
    bool check(TreeNode* u, TreeNode* v) {
        queue<TreeNode*> q;
        q.push(u);
        q.push(v);

        while (!q.empty()) {
            u = q.front(); q.pop();
            v = q.front(); q.pop();
            if (!u && !v) continue;

            if ((!u || !v) || (u->val != v->val)) {
                return false;
            }

            q.push(u->left);
            q.push(v->right);

            q.push(u->right);
            q.push(v->left);
        }
        return true;
    }

    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }
};