#ifndef LINKLIST_H_
#define LINKLIST_H_

typedef int DataType;

typedef struct Node
{
  DataType data;
  struct Node *next;
}ListNode, *LinkList;

#endif // LINKLIST_H_
