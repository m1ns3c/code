#include "linklist.h"
#include <stdio.h>

int main() {
  LinkList head;

  InitList(&head);

  DataType e = 101;
  InsertList(head, 1, e);
  e = 102;
  InsertList(head, 2, e);

  e = 105;
  InsertList(head, 1, e);

  PrintList(head);

  DeleteList(head, 1, &e);
  printf("e: %d\n", e);

  PrintList(head);

  return 0;
}
