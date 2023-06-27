#ifndef BST_H_
#define BST_H_

typedef struct Node {
  int key;
  struct Node *left;
  struct Node *right;
}BSTNode;

typedef struct HNode {
  int key;
  struct HNode *left;
  struct HNode *right;
  int height;
}AVLNode;

typedef struct RBNode {
  int key;
  int color;
  struct RBNode *left;
  struct RBNode *right;
  struct RBNode *parent;
} RBTNode;

// BST
extern BSTNode *bst_insert(BSTNode *, int);
extern BSTNode *bst_delete(BSTNode *, int);
extern void inorder_print(BSTNode *);
extern void level_print(BSTNode *);

// AVL
extern AVLNode *avl_insert(AVLNode *, int);
extern void avl_level_print(AVLNode *);

// R-B T
extern RBTNode *rbt_insert(RBTNode *, int);
extern void rbt_level_print(RBTNode *);

extern int max(int a, int b);

#endif // BST_H_
