#include "linkstack.h"
#include <stdlib.h>

void InitStack(LinkStack *S) {
  LStackNode *node = (LStackNode *) malloc(sizeof(LStackNode));
  if (node == NULL) {

  }

  node->next = NULL;
  *S = node;
}

int EmptyStack(LinkStack S) {
  return S->next == NULL;
}

int PushStack(LinkStack *S, DataType e) {
  LStackNode *node = (LStackNode *) malloc(sizeof(LStackNode));
  if (node == NULL) {

  }

  node->data = e;
  node->next = S->next;
  S->next = node;
  return 1;
}

int PopStack(LinkStack *S, DataType *e) {
  LStackNode *node = S->next;
  if (node == NULL) {
    return 0;
  }

  *e = node->data;
  S->next = node->next;
  free(node);
  return 1;
}

int GetTop(LinkStack S, DataType *e) {
  LStackNode *node = S->next;
  if (node == NULL) {
    return 0;
  }

  *e = node->data;
  return 1;
}

int StackLength(LinkStack S) {
  LStackNode *node = S->next;
  int i = 0;
  while (node) {
    node = node->next;
    i++;
  }

  return i;
}

void DestroyStack(LinkStack *S) {
  LStackNode *node = S, *p;
  while (node) {
    p = node;
    node = node->next;
    free(p);
  }
}
