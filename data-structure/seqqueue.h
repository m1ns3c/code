#ifndef SEQQUEUE_H_
#define SEQQUEUE_H_

typedef int DataType;

#define QueueSize 60
typedef struct Squeue {
  DataType queue[QueueSize];
  int front;
  int rear;
}SeqQueue;

void InitQueue(SeqQueue *Q);
int QueueEmpty(SeqQueue Q);
int EnQueue(SeqQueue *Q, DataType e);
int DeQueue(SeqQueue *Q, DataType *e);
int GetHead(SeqQueue *Q, DataType *e);
void ClearQueue(SeqQueue *Q);

#endif // SEQQUEUE_H_
