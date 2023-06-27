#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int
max(int a, int b) {
  return (a > b) ? a : b;
}

static int
height(AVLNode *node) {
  if (node == NULL) {
    return 0;
  }

  return node->height;
}

AVLNode *
left_rotate(AVLNode *node) {
  AVLNode *root = node->right;
  node->right = root->left;
  root->left = node;

  node->height = max(height(node->left), height(node->right)) + 1;
  root->height = max(height(root->left), height(root->right)) + 1;

  return root;
}

AVLNode *
right_rotate(AVLNode *node) {
  AVLNode *root = node->left;
  node->left = root->right;
  root->right = node;

  node->height = max(height(node->left), height(node->right)) + 1;
  root->height = max(height(root->left), height(root->right)) + 1;

  return root;
}

static int
get_balance(AVLNode *node) {
  if (node == NULL) {
    return 0;
  }

  return height(node->left) - height(node->right);
}

AVLNode *
avl_insert(AVLNode *node, int key) {
  if (node == NULL) {
    AVLNode *n = (AVLNode *) malloc(sizeof(AVLNode));
    n->key = key;
    n->left = n->right = NULL;
    n->height = 1;

    return n;
  }

  if (key < node->key) {
    node->left = avl_insert(node->left, key);
  } else if (key > node->key) {
    node->right = avl_insert(node->right, key);
  } else {
    return node;
  }

  node->height = max(height(node->left), height(node->right)) + 1;

  int balance = get_balance(node);
  if (balance > 1 && key < node->left->key) {
    // LL
    return right_rotate(node);
  }

  if (balance < -1 && key > node->right->key) {
    // RR
    return left_rotate(node);
  }

  if (balance > 1 && key > node->left->key) {
    // LR
    node->left = left_rotate(node->left);
    return right_rotate(node);
  }
  if (balance < -1 && key < node->right->key) {
    // RL
    node->right = right_rotate(node->right);
    return left_rotate(node);
  }

  return node;
}

static void
printGivenLevel (AVLNode *node, int level) {
  if (node == NULL) {
    printf("empty");
    return;
  }

  if (level == 1) {
    printf("%d ", node->key);
  } else if (level > 1) {
    printGivenLevel(node->left, level-1);
    printGivenLevel(node->right, level-1);
  }
}

void avl_level_print(AVLNode *root) {
  int h = height(root);
  int i;

  for (i=1; i<=h; i++) {
    printf("[%d]", i);

    printGivenLevel(root, i);

    printf("\n");
  }
}
