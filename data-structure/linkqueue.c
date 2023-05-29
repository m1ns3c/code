#include "linkqueue.h"
#include <stdlib.h>

void InitQueue(LinkQueue *Q) {
  LQNode *node = (LQNode *) malloc(sizeof(LQNode));
  if (node == NULL) {

  }
  Q->front = Q->rear = node;
}

int QueueEmpty(LinkQueue Q) {
  return Q.front == Q.rear;
}

int EnQueue(LinkQueue *Q, DataType e) {
  LQNode *node = (LQNode *) malloc(sizeof(LQNode));
  node->next = NULL;
  node->data = e;

  Q->rear->next = node;
  Q->rear = node;
}

int DeQueue(LinkQueue *Q, DataType *e) {
  if (QueueEmpty(Q)) {
    return 0;
  }

  QueuePtr p = Q->front->next;
  *e = p->data;
  Q->front->next = p->next;
  free(p);
  return 1;
}

int GetHead(LinkQueue Q, DataType *e) {
  if (QueueEmpty(Q)) {
    return 0;
  }

  *e = Q.front->next->data;
  return 1;
}

void ClearQueue(LinkQueue *Q) {
  while (Q->front != Q->rear) {
    QueuePtr p = Q->front->next;
    Q->front = p->next;
    free(p);
  }
  Q->front = Q->rear = Q;
}
