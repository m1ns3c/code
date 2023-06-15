#include <stdio.h>

void createIndex(int index[], int isize, int A[], int asize) {
  int i, j;
  for (i=0,j=0; i<asize; i+=8, j++) {
    index[j] = A[i];
  }
  index[j] = A[asize - 1];
}

int indexSeqSearch(int val, int index[], int isize, int A[], int asize) {
  int i=0, j=0, pos = 0;
  int high = 0, low = 0;
  if (val > index[isize - 1] || val < index[0]) {
    return -1;
  }
  while (i < isize) {
    if (val == index[i])  {
      pos = 8 * i;
      return pos;
    }
    if (val < index[i]) {
      low = 8 * (i - 1);
      high = 8 * i;
      break;
    } else {
      low = 8 * i;
      high = 8 * (i + 1);
    }
    i++;
  }
  printf("\n low = %d, high = %d\n", low, high);
  while (low < high) {
    if (val == A[low]) {
      return low;
    } else {
      low++;
    }
  }
  return -1;
}
