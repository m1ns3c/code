#include <stdio.h>
#include <stdlib.h>

#include "linklist.h"

void PickLastKNode(LinkList A, int k, DataType *e) {
  ListNode *p = A->next, *pp = A->next;
  while (p) {
    p = p->next;
    if (k-- <= 0) {
      pp = pp->next;
    }
  }
  *e = pp->data;
}

int main() {
  int i;
  LinkList A;

  DataType a[] = {8,10,15,21,67,91};

  InitList(&A);

  for (i=0;i<sizeof(a)/sizeof(a[0]);i++) {
    InsertList(A, i+1, a[i]);
  }

  PrintList(A);

  DataType e;
  int k = 3;
  PickLastKNode(A, k, &e);
  printf("[%d]=%d\n", k, e);

  return 0;
}
