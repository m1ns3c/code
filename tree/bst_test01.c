#include <stdio.h>
#include "bst.h"

int
main() {
  BSTNode *root = NULL;
  root = insert(root, 50);
  insert(root, 30);
  insert(root, 20);
  insert(root, 40);
  insert(root, 70);
  insert(root, 60);
  insert(root, 80);

  inorder_print(root);

  printf("\n");

  level_print(root);

  return 0;
}
