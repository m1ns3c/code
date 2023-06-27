#include <stdio.h>
#include <stdlib.h>

#define C_RED 1
#define C_BLACK 0

struct node {
  int d;
  int c;  // 1-red, 0-black
  struct node * p;
  struct node * l;
  struct node * r;
};

struct node *root = NULL;

static int
height(struct node *node) {
  if (node == NULL) {
    return 0;
  }

  int lh = height(node->l);
  int rh = height(node->r);
  if (lh > rh) {
    return lh + 1;
  }

  return rh + 1;
}

static void
printGivenLevel (struct node *node, int level) {
  if (node == NULL) {
    printf("[*] ");
    return;
  }

  if (level == 1) {
    printf("%d_%d ", node->d, node->c);
  } else if (level > 1) {
    printGivenLevel(node->l, level-1);
    printGivenLevel(node->r, level-1);
  }
}

void levelprint(struct node *root) {
  int h = height(root);
  int i;

  for (i=1; i<=h; i++) {
    printf("[%d] ", i);

    printGivenLevel(root, i);

    printf("\n");
  }
}

void right_rotate(struct node* temp)
{
    struct node* left = temp->l;
    temp->l = left->r;
    if (temp->l)
        temp->l->p = temp;
    left->p = temp->p;
    if (!temp->p)
        root = left;
    else if (temp == temp->p->l)
        temp->p->l = left;
    else
        temp->p->r = left;
    left->r = temp;
    temp->p = left;
}

void left_rotate(struct node* temp)
{
    struct node* right = temp->r;
    temp->r = right->l;
    if (temp->r)
        temp->r->p = temp;
    right->p = temp->p;
    if (!temp->p)
        root = right;
    else if (temp == temp->p->l)
        temp->p->l = right;
    else
        temp->p->r = right;
    right->l = temp;
    temp->p = right;
}

struct node*
bst(struct node *trav, struct node *temp) {
  // empty tree
  if (trav == NULL)
    return temp;

  if (temp->d < trav->d) {
    // left child
    trav->l = bst(trav->l, temp);
    trav->l->p = trav;
  } else if (temp->d > trav->d) {
    // right child
    trav->r = bst(trav->r, temp);
    trav->r->p = trav;
  }

  return trav;
}

void inorder(struct node* trav)
{
  if (trav == NULL)
      return;
  inorder(trav->l);
  printf("%d ", trav->d);
  inorder(trav->r);
}

void
fixup(struct node *root, struct node *x) {
  struct node *p = NULL, *u = NULL, *g = NULL;

  // ? x->c != C_BLACK  ->  x->c == C_RED
  while (x != root && x->c != C_BLACK && x->p->c == C_RED) {
    p = x->p;
    g = x->p->p;

    // Case A
    // p is left of g
    if (p == g->l) {
      u = g->r;

      // Case 1
      // recoloring
      if (u != NULL && u->c == C_RED) {
        p->c = u->c = C_BLACK;
        g->c = C_RED;
        x = g;
      } else {
        // L

        // Case 2
        // rotate
        // LR
        if (x == p->r) {
          left_rotate(p);
          x = p;
          p = x->p;
        }

        // Case 3
        // LL
        right_rotate(g);
        int t = p->c;
        p->c = g->c;
        g->c = t;

        x = p;
      }
    } else {
      // Case B
      // p is right of g
      u = g->l;

      // Case 1
      if (u != NULL && u->c == C_RED) {
        p->c = u->c = C_BLACK;
        g->c = C_RED;
        x = g;
      } else {
        // R

        // Case 2
        // rotate
        // RL
        if (x == p->l) {
          right_rotate(p);
          x = p;
          p = x->p;
        }

        // Case 3
        // RR
        left_rotate(g);
        int t = p->c;
        p->c = g->c;
        g->c = t;

        x = p;
      }
    }
  }
}

int main() {
  int n = 17;
  int a[17] = {5,11,10,14,26,24,27,35,37,41,39,47,63,57,75,84,96};

  for (int i=0; i<n; i++) {
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    temp->p = temp->l = temp->r = NULL;
    temp->d = a[i];
    temp->c = C_RED;

    root = bst(root, temp);
    fixup(root, temp);
    root->c = 0;
  }

  inorder(root);

  levelprint(root);

  return 0;
}
