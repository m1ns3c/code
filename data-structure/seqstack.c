#include "seqstack.h"

void InitStack(SeqStack *S) {
  S->top = 0;
}

int StackEmpty(SeqStack S) {
  return S.top == 0;
}

int GetTop(SeqStack S, DataType *e) {
  if (S.top <= 0) {
    return 0;
  }

  *e = S.stack[S.top-1];
  return 1;
}

int PushStack(SeqStack *S, DataType e) {
  if (S->top >= StackSize) {
    return 0;
  }

  S->stack[S->top++] = e;
  return 1;
}

int PopStack(SeqStack *S, DataType *e) {
  if (S->top <= 0) {
    return 0;
  }

  S->top--;
  *e = S->stack[S->top];
  return 1;
}

int StackLength(SeqStack S) {
  return S.top;
}

void ClearStack(SeqStack *S) {
  S->top = 0;
}
