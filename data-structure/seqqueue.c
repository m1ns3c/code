#include "seqqueue.h"

void InitQueue(SeqQueue *Q) {
  Q->front = Q->rear = 0;
}

int QueueEmpty(SeqQueue Q) {
  return Q.front == Q.rear;
}

int EnQueue(SeqQueue *Q, DataType e) {
  if (Q->front == (Q->rear+1) % QueueSize) {
    return 0;
  }

  Q->queue[Q->rear] = e;
  Q->rear = (Q->rear+1) % QueueSize;
  return 1;
}

int DeQueue(SeqQueue *Q, DataType *e) {
  if (QueueEmpty(Q)) {
    return 0;
  }

  *e = Q->queue[Q->front];

  Q->front = (Q->front+1) % QueueSize;
  return 1;
}

int GetHead(SeqQueue Q, DataType *e) {
  if (QueueEmpty(Q)) {
    return 0;
  }

  *e = Q.queue[Q.front];
  return 1;
}

void ClearQueue(SeqQueue *Q) {
  Q->front = Q->rear = 0;
}
