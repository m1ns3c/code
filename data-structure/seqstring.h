#define MaxLen 80

typedef struct {
  char str[MaxLen];
  int length;
}SeqString;

void StrAssign(SeqString *S, char cstr[]);
int StrEmpty(SeqString S);
int StrLength(SeqString S);
void StrCopy(SeqString *T, SeqString S);
int StrCompare(SeqString S, SeqString T);
int StrInsert(SeqString *S, int pos, SeqString T);
int StrDelete(SeqString *S, int pos, int len);
int StrConcat(SeqString *T, SeqString S);
void StrClear(SeqString *S);
