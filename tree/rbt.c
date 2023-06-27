#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

#define COLOR_RED 1
#define COLOR_BLACK 2

static RBTNode *
new_node(int key) {
  RBTNode *node = (RBTNode *) malloc(sizeof(RBTNode));
  if (node == NULL) {
    exit(-1);
  }

  node->key = key;
  node->color = COLOR_BLACK;
  node->left = node->right = node->parent = NULL;

  return node;
}

static void
left_rotate(RBTNode *node) {
  RBTNode *right = node->right;
  node->right = right->left;
  if (node->right != NULL) {
    node->right->parent = node;
  }
  right->parent = node->parent;
  if (node->parent == NULL) {

  } else if (node == node->parent->left) {
    // left
    node->parent->left = right;
  } else {
    // right
    node->parent->right = right;
  }
  right->left = node;
  node->parent = right;
}

static void
right_rotate(RBTNode *node) {
  RBTNode *left = node->left;
  node->left = left->right;
  if (node->left != NULL) {
    node->left->parent = node;
  }
  left->parent = node->parent;
  if (node->parent == NULL) {

  } else if (node == node->parent->left) {
    // left
    node->parent->left = left;
  } else {
    // right
    node->parent->right = left;
  }
  left->right = node;
  node->parent = left;
}

RBTNode *
rbt_insert(RBTNode *root, int key) {
  if (root == NULL) {
    return new_node(key);
  }

  RBTNode *x, *p, *u, *g;
  if (key > root->key) {
    x = rbt_insert(root->right, key);
    x->parent = root;
    x->color = COLOR_RED;
    root->right = x;
  } else if (key < root->key) {
    x = rbt_insert(root->left, key);
    x->parent = root;
    x->color = COLOR_RED;
    root->left = x;
  }

  while (x->parent != NULL && x->parent->color != COLOR_BLACK) {
    g = x->parent->parent;
    u = g->right;
    if (u->color == COLOR_RED) {
      x->parent->color = u->color = COLOR_BLACK;
      g->color = COLOR_RED;

      x = g;
    } else if (u->color == COLOR_BLACK) {
      // rotate
      // 
      if (p == g->left && x == x->parent->left) {
        // LL
        right_rotate(x->parent);
      } else if (p == g->left && x == p->right) {
        // LR
        left_rotate(x->right);
        right_rotate(x);
      } else if (p == g->right && x == p->right) {
        // RR
        left_rotate(p);
      } else if (p == g->right && x == p->left) {
        // RL
        right_rotate(x->left);
        left_rotate(x);
      }
    }
  }

  return root;
}

static int
height(RBTNode *node) {
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
printGivenLevel (RBTNode *node, int level) {
  if (node == NULL) {
    printf("* ");
    return;
  }

  if (level == 1) {
    printf("%d_%d ", node->key, node->color);
  } else if (level > 1) {
    printGivenLevel(node->left, level-1);
    printGivenLevel(node->right, level-1);
  }
}

void
rbt_level_print(RBTNode *root) {
  int h = height(root);
  int i;

  for (i=1; i<=h; i++) {
    printf("[%d]", i);

    printGivenLevel(root, i);

    printf("\n");
  }
}
