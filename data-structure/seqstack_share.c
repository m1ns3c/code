#define StackSize 100

typedef struct {
  DataType stack[StackSize];
  int top[2];
}SSeqStack;

void InitStack(SSeqStack *S) {
  S->top[0] = 0;
  S->top[1] = StackSize - 1;
}

int PushStack(SSeqStack *S, DataType e, int flag) {
  if (S->top[0] == S->top[1]-1) {
    return 0;
  }



}

int PopStack(SSeqStack *S, DataType *e) {

}
