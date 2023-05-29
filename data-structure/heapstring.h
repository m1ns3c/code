#ifndef HEAPSTRING_H_
#define HEAPSTRING_H_

typedef struct {
  char *str;
  int length;
} HeapString;

void InitString(HeapString *S);
void StrAssign(HeapString *S, char cstr[]);
void StrCopy(HeapString *T, HeapString S);
int StrInsert(HeapString *S, int pos, HeapString T);
int StrDelete(HeapString *S, int pos, int len);
int StrConcat(HeapString *T, HeapString S);
void StrDestroy(HeapString *S);

#endif // HEAPSTRING_H_
