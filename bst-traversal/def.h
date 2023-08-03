#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <deque>
#include <stack>

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