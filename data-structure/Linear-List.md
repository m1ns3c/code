# Linear List

## Sequential Mapping

```c
#define ListSize 200

typedef struct
{
    DataType list[ListSize];
    int length;
}SeqList;
```

```c
SeqList L;
```

```c
SeqList *L;
```

## Link List

```c
typedef struct Node
{
    DataType data;
    struct Node *next;
}ListNode, *LinkList;
```

```c
ListNode L;
```

```c
ListNode *L;
```



