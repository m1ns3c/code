#include "seqstring.h"

void StrAssign(SeqString *S, char cstr[]) {
  int i;
  for(i=0; cstr[i] != '\0'; i++) {
    S->str[i] = cstr[i];
  }
  S->length = i;
}

int StrEmpty(SeqString S) {
  return S.length == 0;
}

int StrLength(SeqString S) {
  return S.length;
}

void StrCopy(SeqString *T, SeqString S) {
  int i;
  for (i=0; i<S.length; i++) {
    T->str[i] = S.str[i];
  }

  T->length = S.length;
}

int StrCompare(SeqString S, SeqString T) {
  int i;
  if (S.length != T.length) {
    return S.length > T.length ? 1 : -1;
  }

  for (i=0; i<S.length; i++) {
    if (S.str[i] > T.str[i]) {
      return 1;
    } else if (S.str[i] < T.str[i]) {
      return -1;
    }
  }

  return 0;
}

int StrInsert(SeqString *S, int pos, SeqString T) {
  int i;
  for (i=S->length-1; i>=pos ;i--) {
    S->str[i+T.length] = S->str[i];
  }

  for (i=0; i<T.length; i++) {
    S->str[pos+i] = T.str[i];
  }

  return 1;
}

int StrDelete(SeqString *S, int pos, int len) {
  int i, offset = pos + len;
  for (i=S->length - offset; i>=0; i++) {
    S->str[pos+i] = S->str[offset+i];
  }
  S->length -= len;
  return 1;
}

int StrConcat(SeqString *T, SeqString S) {
  int i;
  for (i=0; i<S.length; i++) {
    T->str[T->length+i] = S.str[i];
  }

  T->length += S.length;
  return 1;
}

void StrClear(SeqString *S) {
  S->length = 0;
}
