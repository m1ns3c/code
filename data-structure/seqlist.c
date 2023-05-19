#include "seqlist.h"
#include <stdio.h>

void PrintList(SeqList L) {
  printf("List: ");
  for (int i=0;i<L.length;i++) {
    printf("%4d\t", L.list[i]);
  }
  printf("\n");
}

void InitList(SeqList *L) {
  L->length = 0;
}

int ListEmpty(SeqList L) {
  return L.length == 0;
}

int GetElem(SeqList L, int i, DataType *e) {
  if (i < 1 || i > L.length) {
    return -1;
  }

  *e = L.list[i-1];

  return 1;
}

int LocateElem(SeqList L, DataType e) {
  for (int i=0; i<L.length; i++) {
    if (L.list[i] == e) {
      return i+1;
    }
  }

  return 0;
}

int InsertList(SeqList *L, int i, DataType e) {
  if (i < 1 || i > L->length+1) {
    printf("invalid i\n");
    return -1;
  } else if (L->length >= ListSize) {
    printf("list full\n");
    return 0;
  }

  for (int j=L->length; j>=i; j--) {
    L->list[j] = L->list[j-1];
  }

  L->list[i-1] = e;
  L->length++;

  return 1;
}

int DeleteList(SeqList *L, int i, DataType *e) {
  if (L->length <=0) {
    printf("empty list\n");
    return 0;
  } else if (i<1 || i>L->length) {
    printf("invalid i\n");
    return -1;
  }

  *e = L->list[i-1];

  for (int j=i; j<=L->length-1; j++) {
    L->list[j-1] = L->list[j];
  }
  L->length--;
  return 1;
}

int ListLength(SeqList L) {
  return L.length;
}

void ClearList(SeqList *L) {
  L->length = 0;
}
