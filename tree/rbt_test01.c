#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int
main() {
  RBTNode *root = NULL;
  root = rbt_insert(root, 9);
  root = rbt_insert(root, 5);
  root = rbt_insert(root, 10);
  root = rbt_insert(root, 0);
  root = rbt_insert(root, 6);
  root = rbt_insert(root, 11);
  root = rbt_insert(root, -1);
  root = rbt_insert(root, 1);
  root = rbt_insert(root, 2);

  rbt_level_print(root);

  return 0;
}
