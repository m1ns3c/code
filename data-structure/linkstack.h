#ifndef LINKSTACK_H_
#define LINKSTACK_H_

typedef int DataType;

typedef struct Node {
  DataType data;
  struct Node *next;
}LStackNode, *LinkStack;

void InitStack(LinkStack *S);
int EmptyStack(LinkStack S);
int PushStack(LinkStack *S, DataType e);
int PopStack(LinkStack *S, DataType *e);
int GetTop(LinkStack S, DataType *e);
int StackLength(LinkStack S);
void DestroyStack(LinkStack S);
void PrintStack(LinkStack S);

#endif // LINKSTACK_H_
