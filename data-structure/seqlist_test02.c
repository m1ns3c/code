#include <stdio.h>

#define MaxLen 100
typedef int seqlist[MaxLen];

int input(seqlist A) {
  return 0;
}

void main() {
  int a[] = {1,2,3,4,5};
  int len = sizeof(a)/sizeof(a[0]);
  int mid = len / 2;
  int odd = 0;
  if (len % 2 != 0) {
    odd = 1;
  }

  for (int i=0; i<mid; i++) {
    int t = a[i];
    a[i] = a[i+mid+odd];
    a[i+mid+odd] = t;
  }

  for (int i=0;i<len;i++) {
    printf("%d\t", a[i]);
  }
}
