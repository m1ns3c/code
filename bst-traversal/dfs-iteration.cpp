// DFS iteration
#include "def.h"

// pre order iteration
void preorder_iter(TNode root) {
    stack<TNode> s;

    while (root != NULL || !s.empty()) {
        while (root != NULL) {
            printf("%d\t", root->data);
            s.push(root);
            root = root->left;
        }
        if (!s.empty()) {
            root = s.top();
            s.pop();
            root = root->right;
        }
    }
}

// in order iteration
void inorder_iter(TNode root) {
    stack<TNode> s;
    while (root != NULL || !s.empty()) {
        while (root != NULL) {
            s.push(root);
            root = root->left;
        }
        if (!s.empty()) {
            root = s.top();
            s.pop();
            printf("%d\t", root->data);
            root = root->right;
        }
    }
}

// post order iteration
// 1. single stack
void postorder_iter_ss(TNode root) {
    if (root == NULL) {
        return;
    }

    vector<int> v;
    stack<TNode> s;
    s.push(root);
    while (!s.empty()) {
        TNode n = s.top();
        s.pop();
        v.push_back(n->data);
        if (n->left != NULL) {
            s.push(n->left);
        }
        if (n->right != NULL) {
            s.push(n->right);
        }
    }

    reverse(v.begin(), v.end());

    vector<int>::iterator it;
    for (it=v.begin(); it!=v.end(); it++) {
        printf("%d\t", *it);
    }
}

// 2. single stack + sentinel
void postorder_iter_sss(TNode root) {
    if (root == NULL) {
        return;
    }
    vector<int> v;

    stack<TNode> s;
    TNode pre = NULL;

    while (root != NULL || !s.empty()) {
        while (root != NULL) {
            s.push(root);
            root = root->left;
        }

        root = s.top();
        if (root->right == NULL || root->right == pre) {
            s.pop();
            v.push_back(root->data);
            pre = root;
            root = NULL;
        } else {
            root = root->right;
        }
    }

    vector<int>::iterator it;
    for (it=v.begin(); it!=v.end(); it++) {
        printf("%d\t", *it);
    }
}

// 3. double stack
// 打印：左-右-中，出栈：左-右-中，入栈：中-右-左
void postorder_iter_ds(TNode root) {
    if (root == NULL) {
        return;
    }

    stack<TNode> s;
    stack<TNode> s2;
    while (root != NULL || !s.empty()) {
        if (root != NULL) {
            s.push(root);
            s2.push(root);
            root = root->right;
        } else {
            root = s.top();
            s.pop();
            root = root->left;
        }
    }

    while (!s2.empty()) {
        printf("%d\t", s2.top()->data);
        s2.pop();
    }
}