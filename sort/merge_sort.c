/**
 * merge sort
 */
#include "sort.h"

void _merge_arr(elemType a[], int l, int m, int r, elemType *temp) {
  int i=l, j=m+1, k=0;

  while (i<=m && j <= r) {
    if (a[i] < a[j]) {
      temp[k++] = a[i++];
    } else {
      temp[k++] = a[j++];
    }
  }

  while (i <= m) {
    temp[k++] = a[i++];
  }

  while (j <= r) {
    temp[k++] = a[j++];
  }

  for (i=0;i<k;i++) {
    a[l+i] = temp[i];
  }
}

void _merge_sort(elemType arr[], int l, int r, elemType *temp) {
  if (l >= r) return;

  int mid = l + (r - l) / 2;

  _merge_sort(arr, l, mid, temp);
  _merge_sort(arr, mid+1, r, temp);

  _merge_arr(arr, l, mid, r, temp);
}

void merge_sort(elemType arr[], int n) {
  elemType temp[n];

  _merge_sort(arr, 0, n-1, temp);
}

void (*sort_ptr)(elemType[], int) = &merge_sort;
