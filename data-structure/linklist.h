#ifndef LINKLIST_H_
#define LINKLIST_H_

typedef int DataType;

typedef struct Node
{
  DataType data;
  struct Node *next;
}ListNode, *LinkList;

void InitList(LinkList *head);
int ListEmpty(LinkList head);
ListNode *Get(LinkList head, int i);
ListNode *LocateElem(LinkList head, DataType e);
int LocatePos(LinkList head, DataType e);
int InsertList(LinkList head, int i, DataType e);
int DeleteList(LinkList head, int i, DataType *e);
int ListLength(LinkList head);
void DestroyList(LinkList head);
void PrintList(LinkList head);

#endif // LINKLIST_H_
