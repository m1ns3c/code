#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

typedef struct Node {
  DataType data;
  struct Node *next;
} ListNode, *LinkList;

void CreateCircularList(LinkList *L) {
  ListNode *node = (ListNode *) malloc(sizeof(ListNode));
  if (node == NULL) {
  }
  node->next = node;
  *L = node;
}

int Insert(LinkList L, int i, DataType e) {
  ListNode *p = L->next, *head = L;

  while (--i) {
    if (p == head) {
      return 0;
    }
    p = p->next;
  }

  ListNode *node = (ListNode *) malloc(sizeof(ListNode));
  if (node == NULL) {
    return -1;
  }

  node->data = e;
  node->next = p->next;
  p->next = node;
}

void Print(LinkList L) {
  ListNode *p = L->next, *head = L;
  printf("print: ");
  while (p != head) {
    printf("%d\t", p->data);
    p = p->next;
  }
  printf("\n");
}

void Init() {}

int main() {
  int i;
  LinkList H, HA, HB;

  CreateCircularList(&H);

  DataType a[] = {23, -87, 66, 98, -1, 90, -70, 20, 129};
  for (i=0;i<sizeof(a)/sizeof(a[0]);i++) {
    Insert(H, i+1, a[i]);
  }
  Print(H);


  return 0;
}
