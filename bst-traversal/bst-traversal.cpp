// binary search tree traversal

/**
 * 一.递归
 * 1.前序遍历
 * 2.中序遍历
 * 3.后续遍历
 * 
 * 二.迭代
 * 1.前序遍历
 * 2.中序遍历
 * 3.后序遍历
 * 
 * 三.Morris 遍历
 * 1.前序遍历
 * 2.中序遍历
 * 3.后序遍历
 * 
 * 四.层次遍历
 * 递归（深度优先遍历DFS）
 * 迭代（广度优先遍历BFS）
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

typedef struct node {
    struct node *left;
    struct node *right;
    int data;
}*TNode;

TNode new_node(int data) {
    TNode node = (TNode) malloc(sizeof(struct node));
    node->left = node->right = NULL;
    node->data = data;
    return node;
}

TNode init(int data) {
    return new_node(data);
}

TNode insert(TNode root, int data) {
    if (root == NULL) {
        return init(data);
    }

    TNode t = root, p;
    while (t != NULL) {
        p = t;
        if (t->data < data) {
            t = t->right;
        } else {
            t = t->left;
        }
    }

    TNode n = new_node(data);
    if (p->data < data) {
        p->right = n;
    } else {
        p->left = n;
    }

    return root;
}

// DFS

// 1. Recursive 递归

// 1.1 dfs pre order recursive
void preorder(TNode root) {
    if (root == NULL) {
        return;
    }

    printf("%d\t", root->data);
    preorder(root->left);
    preorder(root->right);
}

// 1.2 dfs in order recursive
void inorder(TNode root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    printf("%d\t", root->data);
    inorder(root->right);
}

// 1.3 dfs post order recursive
void postorder(TNode root) {
    if (root == NULL) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    printf("%d\t", root->data);
}

// 2. Iterate 迭代

// 2.1 pre order iteration
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

// 2.2 in order iteration
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

// 2.3 post order iteration
void postorder_iter(TNode root) {
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


// 3. Morris

// 4. BFS

// bfs
void bfs(TNode root) {
    if (root == NULL) {
        return;
    }

    queue<TNode> q;
    q.push(root);
    while (!q.empty()) {
        TNode t = q.front();
        q.pop();
        if (t == NULL) {
            printf("*\t");
            continue;
        }
        printf("%d\t", t->data);
        q.push(t->left);
        q.push(t->right);
    }
}

// bfs with level
void bfs_level(TNode root) {
    if (root == NULL) {
        return;
    }

    queue<TNode> q;
    q.push(root);
    while (!q.empty()) {
        int s = q.size();
        for (int i=0; i<s; i++) {
            TNode t = q.front();
            q.pop();
            if (t == NULL) {
                printf("*\t");
                continue;
            }
            printf("%d\t", t->data);
            q.push(t->left);
            q.push(t->right);
        }
        printf("\n");
    }
}

int main() {
    TNode root;

    root = init(5);
    root = insert(root, 10);
    root = insert(root, 6);
	root = insert(root, 3);
	root = insert(root, 4);

    preorder(root);
    printf("\n");

    inorder(root);
    printf("\n");

    postorder(root);
    printf("\n");

    bfs(root);
    printf("\n");

    preorder_iter(root);
    printf("\n");

    inorder_iter(root);
    printf("\n");

    postorder_iter(root);
    printf("\n");

    postorder_iter_ss(root);
    printf("\n");

    postorder_iter_sss(root);
    printf("\n");

    return 0;
}