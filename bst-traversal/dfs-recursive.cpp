// DFS recursive
#include "def.h"

// pre order recursive
void preorder(TNode root) {
    if (root == NULL) {
        return;
    }

    printf("%d\t", root->data);
    preorder(root->left);
    preorder(root->right);
}

// in order recursive
void inorder(TNode root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    printf("%d\t", root->data);
    inorder(root->right);
}

// post order recursive
void postorder(TNode root) {
    if (root == NULL) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    printf("%d\t", root->data);
}