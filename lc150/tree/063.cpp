// 236. 二叉树的最近公共祖先
#include "../def.h"

// DFS 递归 条件分析
// 共同祖先 / q为祖先|p为祖先
// - 左孩子 true 且 右孩子 true （左右各找到一个）
// - 或
// - 当前元素 =p 或 =q
//   - 且
//   - 左孩子 true 且 右孩子 true （左或右找到一个）
class Solution {
public:
    TreeNode* ans;
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) {
            return false;
        }
        bool lson = dfs(root->left, p, q);
        bool rson = dfs(root->right, p, q);

        if ((lson && rson) || (root->val == p->val || root->val == q->val) && (lson || rson)) {
            ans = root;
        }

        return lson || rson || (root->val == p->val || root->val == q->val);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // p 是 q 祖先
        // q 是 p 祖先
        // p q 向上回溯祖先
        dfs(root, p, q);
        return ans;
    }
};

// 路径跟踪，哈希记录每个节点的父路径
// 路径跟踪，路径跟随节点
class Solution {
public:
    int found = 0;

    bool dfs(TreeNode* s, TreeNode* t) {
        if (s == NULL) {
            return false;
        }
        if (s->val == t->val) {
            return true;
        }
        return dfs(s->left, t) || dfs(s->right, t);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // p 是 q 祖先
        // q 是 p 祖先
        // p q 向上回溯祖先
        if (dfs(p, q)) {
            return p;
        } else if (dfs(q, p)) {
            return q;
        }

        // 递归 root
        // 记录路径 - 对比路径
        vector<TreeNode*> pv;
        vector<TreeNode*> qv;

        stack<pair<TreeNode*, vector<TreeNode*>>> st;
        st.push({root, {}});
        while (!st.empty()) {
            TreeNode* node = st.top().first;
            vector<TreeNode*> v = st.top().second;
            st.pop();

            if (node->val == p->val) {
                pv = v;
            } else if (node->val == q->val) {
                qv = v;
            }

            if (!pv.empty() && !qv.empty()) {
                break;
            }

            v.push_back(node);

            if (node->left != NULL) {
                st.push({node->left, v});
            }
            if (node->right != NULL) {
                st.push({node->right, v});
            }
        }

        int i = 1;
        for(; i< min(pv.size(), qv.size()); i++) {
            if (pv[i]->val != qv[i]->val) {
                break;
            }
        }

        return pv[i-1];
    }
};
