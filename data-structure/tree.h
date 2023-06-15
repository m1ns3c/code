#ifndef TREE_H_
#define TREE_H_

#define MaxSize 200

// parent
typedef struct Pnode {
  DataType data;
  int parent;
}PNode;

typedef struct {
  PNode node[MaxSize];
  int num;
}PTree;


// child
typedef struct CNode {
  int child;
  struct CNode *next;
}ChildNode;

typedef struct {
  DataType data;
  ChildNode *firstchild;
}DataNode;

typedef struct {
  DataNode node[MaxSize];
  int num;
  int root;
}CTree;

// child sibling
typedef struct CSNode {
  DataType data;
  struct CSNode *firstchild;
  struct CSNode *nextsibling;
} CSNode, *CSTree;

// thread binary tree
typedef enum {LINK, THREAD} PointerTag;
typedef struct Node {
  DataType data;
  struct Node *lchild;
  struct Node *rchild;
  PointerTag ltag;
  PointerTag rtag;
}*BiThrTree,BiThrNode;

#endif // TREE_H_
