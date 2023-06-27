#include <stdio.h>
#include "bst.h"

int
main() {
  BSTNode *root = NULL;
  root = insert(root, 50);
  root = insert(root, 30);
  root = insert(root, 20);
  root = insert(root, 40);
  root = insert(root, 70);
  root = insert(root, 60);

  inorder_print(root);

  root = delete(root, 50);

  inorder_print(root);

  return 0;
}
