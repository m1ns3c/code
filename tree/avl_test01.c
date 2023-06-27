#include <stdio.h>
#include "bst.h"

int
main() {
  AVLNode *root = NULL;
  root = avl_insert(root, 10);
  root = avl_insert(root, 20);
  root = avl_insert(root, 30);
  root = avl_insert(root, 40);
  root = avl_insert(root, 50);
  root = avl_insert(root, 25);

  avl_level_print(root);

  return 0;
}
