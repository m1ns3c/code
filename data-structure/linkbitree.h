#ifndef LINKBITREE_H_
#define LINKBITREE_H_

typedef struct Node {
  DataType data;
  struct Node *lchild;
  struct Node *rchild;
}BitNode, *BiTree;

void InitBitTree(BiTree *T);
void DestroyBitTree(BiTree *T);
void CreateBitTree(BiTree *T);
int InsertChild(BiTree p, int LR, BiTree c);
DataType LeftChild(BiTree T, DataType e);
DataType RightChild(BiTree T, DataType e);
BiTree Point(BiTree T, DataType e);
int DeleteChild(BiTree p, int LR);

#endif // LINKBITREE_H_
