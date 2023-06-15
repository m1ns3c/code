#include "linkbitree.h"

void PreOrderTraverse(BiTree T) {
  if (T) {
    printf("%2c", T->data);
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
  }
}

void InOrderTraverse(BiTree T) {
  if (T) {
    InOrderTraverse(T->lchild);
    printf("%2c", T->data);
    InOrderTraverse(T->rchild);
  }
}

void PostOrderTraverse(BiTree T) {
  if (T) {
    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    printf("%2c", T->data);
  }
}

void InOrder(BiTree T) {
  BiTree stack[MaxSize];
  int top;
  BitNode *p;

  top = 0;
  p = T;

  while (p != NULL || top > 0) {
    while (p != NULL) {
      stack[top++] = p;
      p = p->lchild;
    }
    if (top>0) {
      p = stack[--top];
      printf("%2c", p->data);
      p = p->rchild;
    }
  }
}

void PostOrder(BiTree T) {
  BiTree stack[MaxSize];
  int top;
  BitNode *p, *q;
  top = 0;
  p=T, q=NULL;
  while (p != NULL || top > 0) {
    while (p!=NULL) {
      stack[top++] = p;
      p = p->lchild;
    }
    if (top > 0) {
      p = stack[top -1];
      if (p->rchild == NULL || p->rchild == q) {
        printf("%2c", p->data);
        q = p;
        p = NULL;
        top--;
      } else {
        p = p->rchild;
      }
    }
  }
}


void LevelPrint(BiTree T) {
  BiTree queue[MaxSize];
  BitNode *p;
  int front, rear;
  front = rear = -1;
  rear++;
  queue[rear] = T;

  while (front != rear) {
    front = (front + 1) % MaxSize;
    p = queue[front];
    printf("%2c", p->data);

    if (p->lchild != NULL) {
      rear = (rear + 1) % MaxSize;
      queue[rear] = p->lchild;
    }

    if (p->rchild != NULL) {
      rear = (rear + 1) % MaxSize;
      queue[rear] = p->rchild;
    }
  }
}

int LeafNum(BiTree T) {
  if (!T) {
    return 0;
  } else {
    if (!T->lchild && !T->rchild) {
      return 1;
    } else {
      return LeafNum(T->lchild) + LeafNum(T->rchild);
    }
  }
}

int NotLeafNum(BiTree T) {
  if (!T) {
    return 0;
  } else {
    if (!T->lchild && !T->rchild) {
      return 0;
    } else {
      return NotLeafNum(T->lchild) + NotLeafNum(T->rchild);
    }
  }
}
