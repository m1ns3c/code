#ifndef LINKQUEUE_H_
#define LINKQUEUE_H_

typedef int DataType;

typedef struct QNode {
  DataType data;
  struct QNode *next;
} LQNode, *QueuePtr;

typedef struct {
  QueuePtr front;
  QueuePtr rear;
}LinkQueue;

void InitQueue(LinkQueue *Q);
int QueueEmpty(LinkQueue Q);
int EnQueue(LinkQueue *Q, DataType e);
int DeQueue(LinkQueue *Q, DataType *e);
int GetHead(LinkQueue Q, DataType *e);
void ClearQueue(LinkQueue *Q);

#endif // LINKQUEUE_H_
