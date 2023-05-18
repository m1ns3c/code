/**
 * quick sort
 */
#include "sort.h"

/*
// wrong
void _quick_sort(elemType arr[], int l, int r) {
  if (l >= r) return;

  int pivot = l;

  for (int i=l+1; i<=r; i++) {
    if (arr[i] <= arr[pivot]) {
      swap(&arr[i], &arr[pivot]);
      pivot = i;
    }
  }

  print_arr(arr, 5);

  _quick_sort(arr, l, pivot-1);
  _quick_sort(arr, pivot+1, r);
}
*/

void _quick_sort(elemType arr[], int l, int r) {
  if (l >= r) return;

  int i=l, j=r, pivot=arr[l];
  while (i<j) {
    while (i<j && arr[j] >= pivot) {
      j--;
    }

    if (i<j) {
      arr[i] = arr[j];
      i++;
    }

    while (i<j && arr[i] < pivot) {
      i++;
    }

    if (i<j) {
      arr[j] = arr[i];
      j--;
    }
  }

  arr[i] = pivot;

  _quick_sort(arr, l, i-1);
  _quick_sort(arr, i+1, r);
}

void quick_sort(elemType arr[], int n) {
  _quick_sort(arr, 0, n-1);
}

//void (*sort_ptr)(elemType[], int) = &quick_sort;
