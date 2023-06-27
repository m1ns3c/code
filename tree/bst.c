#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

#include <queue>

using namespace std;

BSTNode *
bst_delete(BSTNode *root, int key) {
  if (root == NULL) {
    return root;
  }

  if (root->key > key) {
    root->left = bst_delete(root->left, key);
    return root;
  } else if (root->key < key) {
    root->right = bst_delete(root->right, key);
    return root;
  }

  // root is the node to be deleted

  // if one of the children is empty
  if (root->left == NULL) {
    BSTNode *temp = root->right;
    free(root);
    return temp;
  } else if (root->right == NULL) {
    BSTNode *temp = root->left;
    free(root);
    return temp;
  } else {
    // both exist
    BSTNode *p = root;
    BSTNode *succ = root->right;
    while (succ->left != NULL) {
      p = succ;
      succ = succ->left;
    }

    // delete successor
    if (p != root) {
      p->left = succ->right;
    } else {
      p->right = succ->right;
    }

    root->key = succ->key;

    free(succ);
    return root;
  }
}

BSTNode *
bst_insert(BSTNode *root, int key) {
  if (root == NULL) {
    BSTNode *node = (BSTNode *) malloc(sizeof(BSTNode));
    node->key = key;
    node->left = node->right = NULL;

    if (node == NULL) {
      exit(-1);
    }

    return node;
  }

  if (key > root->key) {
    root->right = bst_insert(root->right, key);
  } else if (key < root->key) {
    root->left = bst_insert(root->left, key);
  }

  return root;
}

void
inorder_print(BSTNode *root) {
  if (root == NULL) {
    return;
  }

  printf("[%d]\n", root->key);
  inorder_print(root->left);
  inorder_print(root->right);
}

static int
height(BSTNode *node) {
  if (node == NULL) {
    return 0;
  }

  int lh = height(node->left);
  int rh = height(node->right);
  if (lh > rh) {
    return lh + 1;
  }

  return rh + 1;
}

static void
printGivenLevel (BSTNode *node, int level) {
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

void level_print(BSTNode *root) {
  int h = height(root);
  int i;

  for (i=1; i<=h; i++) {
    printf("[%d]", i);

    printGivenLevel(root, i);

    printf("\n");
  }
}
