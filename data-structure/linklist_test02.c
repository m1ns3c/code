#include <stdio.h>
#include <stdlib.h>

#include "linklist.h"

void MergeList(LinkList A, LinkList B, LinkList *C) {
  ListNode *p1, *p2, *temp;
  DataType e;

  p1 = A->next;
  p2 = B->next;
  while (1) {
    if (p1 == NULL) {
      p1 = p2;
      break;
    } else if (p2 == NULL) {
      break;
    }

    if (p1->data == e) {
      temp = p1;
      p1 = p1->next;
      free(temp);
      continue;
    }

    if (p2->data == e) {
      temp = p2;
      p2 = p2->next;
      free(temp);
      continue;
    }

    if (p1->data > p2->data) {
      temp = p2;
      p2 = p2->next;
    } else if (p1->data < p2->data) {
      temp = p1;
      p1 = p1->next;
    } else {
      temp = p1;
      p1 = p1->next;
      free(temp);

      temp = p2;
      p2 = p2->next;
    }

    if (*C != NULL) {
      temp->next = (*C);
    } else {
      temp->next = NULL;
    }

    *C = temp;
    e = temp->data;
  }

  while (p1) {
    if (p1->data == e) {
      temp = p1;
      p1 = p1->next;
      free(temp);
      continue;
    }

    if (*C != NULL) {
      p1->next = (*C);
    } else {
      p1->next = NULL;
    }
    *C = p1;
    e = p1->data;
  }
}

int main() {
  int i;
  LinkList A, B, C;

  DataType a[] = {8,10,15,21,67,91};
  DataType b[] = {5,9,10,13,21,78,91};

  InitList(&A);
  InitList(&B);

  for (i=0;i<sizeof(a)/sizeof(a[0]);i++) {
    InsertList(A, i+1, a[i]);
  }

  for (i=0;i<sizeof(b)/sizeof(b[0]);i++) {
    InsertList(B, i+1, b[i]);
  }

  PrintList(A);
  PrintList(B);

  MergeList(A, B, &C);

  PrintList(C);
  return 0;
}
