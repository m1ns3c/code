// 117. 填充每个节点的下一个右侧节点指针 II
#include "../def.h"

// 使用队列进行层序遍历

// 常量空间，使用层高进行打印
// 递归控制层高

// 增加空 头结点 引入下一层
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) {
            return root;
        }

        Node* cur = root;
        while (cur != NULL) {
            Node* dummy = new Node(0);
            Node* pre = dummy;

            while (cur != NULL) {
                if (cur->left != NULL) {
                    pre->next = cur->left;
                    pre = pre->next;
                }
                if (cur->right != NULL) {
                    pre->next = cur->right;
                    pre = pre->next;
                }
                cur = cur->next;
            }

            cur = dummy->next;
        }
        return root;
    }
};