#include "linklist.h"

#include <stdio.h> // printf
#include <stdlib.h> // malloc

void InitList(LinkList *head) {
  ListNode *node = (ListNode *) malloc(sizeof(ListNode));
  node->next = NULL;
  *head = node;
}

int ListEmpty(LinkList head) {
  if (head->next == NULL) {
    return 1;
  }
  return 0;
}

ListNode *Get(LinkList head, int i) {
  ListNode *node = head;
  int p = i;

  if (ListEmpty(head) || i < 0) {
    return NULL;
  }

  while (p--) {
    node = node->next;
    if (node == NULL) {
      return NULL;
    }
  }
  return node;
}

ListNode *LocateElem(LinkList head, DataType e) {
  ListNode *node = head->next;
  while (node) {
    if (node->data == e) {
      return node;
    }
    node = node->next;
  }

  return NULL;
}

int LocatePos(LinkList head, DataType e) {
  ListNode *node = head->next;
  int i = 1;

  if (ListEmpty(head)) {
    return 0;
  }

  while (node) {
    if (node->data == e) {
      return i;
    }
    node = node->next;
    i++;
  }

  return 0;
}

int InsertList(LinkList head, int i, DataType e) {
  ListNode *node = head, *prev;
  int p = i;
  if (i < 1) {
    return 0;
  }

  while (p-- && node) {
    prev = node;
    node = node->next;
  }
  if (p > 0) {
    return 0;
  }

  ListNode *n = (ListNode *)malloc(sizeof(ListNode));
  n->data = e;
  n->next = prev->next;
  prev->next = n;
  return 1;
}

int DeleteList(LinkList head, int i, DataType *e) {
  ListNode *node = head, *prev;
  int p = i;
  while (p-- && node) {
    prev = node;
    node = node->next;
  }
  if (p > 0) {
    return 0;
  }

  *e = node->data;
  prev->next = node->next;
  free(node);
  return 1;
}

int ListLength(LinkList head) {
  ListNode *node = head;
  int i = 0;
  while (node) {
    node = node->next;
    i++;
  }
  return i;
}

void DestroyList(LinkList head) {
  ListNode *node = head, *t;
  while (node) {
    t = node;
    node = node->next;
    free(t);
  }
}

void PrintList(LinkList head) {
  ListNode *node = head->next;
  printf("Print: ");
  while (node) {
    printf("%d\t", node->data);
    node = node->next;
  }
  printf("\n");
}
