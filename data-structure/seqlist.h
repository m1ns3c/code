#ifndef SEQLIST_H_
#define SEQLIST_H_

#include <stdio.h>

#define ListSize 100
typedef int DataType;

typedef struct {
  DataType list[ListSize];
  int length;
}SeqList;

void PrintList(SeqList L);

void InitList(SeqList *L);
int ListEmpty(SeqList L);
int GetElem(SeqList L, int i, DataType *e);
int LocateElem(SeqList L, DataType e);
int InsertList(SeqList *L, int i, DataType e);
int DeleteList(SeqList *L, int i, DataType *e);
int ListLength(SeqList L);
void ClearList(SeqList *L);

#endif // SEQLIST_H_
