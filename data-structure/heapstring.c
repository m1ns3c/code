#include "heapstring.h"
#include <stdlib.h>

void InitString(HeapString *S) {
  S->str = '\0';
  S->length = 0;
}

void StrAssign(HeapString *S, char cstr[]) {
  int i, len;
  if (S->str) {
    free(S->str);
  }

  for (i=0; cstr[i] != '\0'; i++) {
    len = i;
  }

  if (!i) {
    S->str = '\0';
    S->length = 0;
  } else {
    S->str = (char *)malloc(len * sizeof(char));
    if (!S->str) {
      exit(-1);
    }


    for (i=0; i<len; i++) {
      S->str[i] = cstr[i];
    }

    S->length = len;
  }
}

void StrCopy(HeapString *T, HeapString S) {
  int i;
  T->str = (char *)malloc(S.length*sizeof(char));
  if (!T->str) {
    exit(-1);
  }

  for (i=0; i<S.length; i++) {
    T->str[i] = S.str[i];
  }
  T->length = S.length;
}

int StrInsert(HeapString *S, int pos, HeapString T) {
  int i;
  S->str = (char *)realloc(S->str, (S->length + T.length) * sizeof(char));
  if (!S->str) {
    exit(-1);
  }

  for (i = S->length-1; i>=pos-1; i--) {
    S->str[i+T.length] = S->str[i];
  }

  for (i=0; i<T.length; i++) {
    S->str[pos+i-1] = T.str[i];
  }
  S->length = S->length + T.length;

  return 1;
}

int StrDelete(HeapString *S, int pos, int len) {
  int i;
  char *p;

  p = (char *) malloc(S->length - len);
  if (!p) {
    exit(-1);
  }

  for (i=0; i<pos-1; i++) {
    p[i] = S->str[i];
  }

  for (i=pos-1; i<S->length - len; i++) {
    p[i] = S->str[i+len];
  }
  S->length = S->length - len;
  free(S->str);
  S->str = p;
  return 1;
}

int StrConcat(HeapString *T, HeapString S) {
  int i;
  T->str = (char *)realloc(T->str, (T->length + S.length) * sizeof(char));
  if (!T->str) {
    exit(-1);
  }

  for (i=T->length;i<T->length+S.length; i++) {
    T->str[i] = S.str[i-T->length];
  }
  T->length = T->length + S.length;

  return 1;
}

void StrDestroy(HeapString *S) {
  if (S->str) {
    free(S->str);
  }
  S->str = '\0';
  S->length = 0;
}
