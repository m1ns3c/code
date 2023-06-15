#include <stdio.h>
#include <stdlib.h>

#define DataType int

typedef struct Node {
  DataType data;
  struct Node *left;
  struct Node *right;
}BTNode, *BTree;

void invert_btree(BTree root) {
  if (root == NULL) {
    return;
  }

  BTree temp = root->left;
  root->left = root->right;
  root->right = temp;

  invert_btree(root->left);
  invert_btree(root->right);
}

void insert(BTree *root, DataType e) {
  BTNode *node = (BTNode *)malloc(sizeof(BTNode));
  node->data = e;
  node->left = node->right = NULL;

  if (*root == NULL) {
    *root = node;
    return;
  }

  BTNode *p, *t = *root;
  while (t != NULL) {
    p = t;
    if (t->data < e) {
      t = t->right;
    } else {
      t = t->left;
    }
  }

  if (p->data < e) {
    p->right = node;
  } else {
    p->left = node;
  }
}

void preorder(BTree root) {
  if (root == NULL) {
    return;
  }

  printf("%d\n", root->data);
  preorder(root->left);
  preorder(root->right);
}

void inorder(BTree root) {
  if (root == NULL) {
    return;
  }

  inorder(root->left);
  printf("%d\n", root->data);
  inorder(root->right);
}

void postorder(BTree root) {
  if (root == NULL) {
    return;
  }

  postorder(root->left);
  postorder(root->right);
  printf("%d\n", root->data);
}

void initTree(BTree *T) {
  T = NULL;
}

int main() {
  BTree root;


  DataType elems[] = {109,20,36,42,12,27,206,202};

  for (int i=0; i<8; i++) {
    insert(&root, elems[i]);
  }

  invert_btree(root);

  printf("pre-order:\n");
  preorder(root);
  printf("in-order:\n");
  inorder(root);
  printf("post-order:\n");
  postorder(root);

  return 0;
}
