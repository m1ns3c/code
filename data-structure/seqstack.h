#ifndef SEQSTACK_H_
#define SEQSTACK_H_

#define StackSize 100
typedef struct {
  DataType stack[StackSize];
  int top;
}SeqStack;

void InitStack(SeqStack *S);
int StackEmpty(SeqStack S);
int GetTop(SeqStack S, DataType *e);
int PushStack(SeqStack *S, DataType e);
int PopStack(SeqStack *S, *e);
int StackLength(SeqStack S);
void ClearStack(SeqStack *S);

#endif // SEQSTACK_H_
