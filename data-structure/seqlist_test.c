#include "seqlist.h"

void swap(DataType *a, DataType *b);
void SepList(SeqList *L);

int main() {
  SeqList L;
  DataType l[] = {-12, 3, -6, -10, 20, -7, 9, -20};

  InitList(&L);

  for (int i=0; i<sizeof(l)/sizeof(l[0]);i++) {
    InsertList(&L, i+1, l[i]);
  }

  PrintList(L);

  SepList(&L);

  PrintList(L);

  return 0;
}

void swap(DataType *a, DataType *b) {
  DataType temp = *a;
  *a = *b;
  *b = temp;
}

void SepList(SeqList *L) {
  int left=0, right=L->length - 1;
  while (left < right) {
    while (left < L->length) {
      if (L->list[left] > 0) {
        break;
      }
      left++;
    }

    while (right > left) {
      if (L->list[right] < 0) {
        break;
      }
      right--;
    }

    swap(&L->list[left], &L->list[right]);
  }
}
