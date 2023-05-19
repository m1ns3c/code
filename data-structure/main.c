#include "seqlist.h"

int main() {
  SeqList L;

  InitList(&L);

  printf("ListEmpty:%d\n", ListEmpty(L));

  DataType e = 12;
  printf("InsertList:%d\n", InsertList(&L, 1, e));

  printf("ListEmpty:%d\n", ListEmpty(L));
  printf("ListLength:%d\n", ListLength(L));

  DataType ret;
  GetElem(L, 0, &ret);

  printf("DeleteList:%d\n", DeleteList(&L, 1, &ret));

  printf("ListEmpty:%d\n", ListEmpty(L));
  printf("ListLength:%d\n", ListLength(L));

  return 0;
}
