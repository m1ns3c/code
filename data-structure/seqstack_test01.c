#include "seqstack.h"
#include <stdio.h>

int main() {
  SeqStack S;
  int i;
  DataType a[] = {'A', 'B', 'C', 'D', 'E', 'F'};

  InitStack(&S);

  for (i=0; i<sizeof(a)/sizeof(a[0]);i++) {
    PushStack(&S, a[i]);
  }

  DataType e;
  PopStack(&S, &e);
  printf("%c\n", e);

  PopStack(&S, &e);
  printf("%c\n", e);

  e = 'G';
  PushStack(&S, e);
  e = 'H';
  PushStack(&S, e);

  printf("Print: ");
  while (PopStack(&S, &e)) {
    printf("%c\t", e);
  }
  printf("\n");

  return 0;
}
