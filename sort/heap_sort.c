/**
 * heap sort
 */
#include "sort.h"

void _heapify(elemType arr[], int n, int x) {
  int largest = x;
  int l_child = 2 * x + 1;
  int r_child = 2 * x + 2;

  if (l_child < n && arr[largest] < arr[l_child]) {
    largest = l_child;
  }

  if (r_child < n && arr[largest] < arr[r_child]) {
    largest = r_child;
  }

  if (largest != x) {
    swap(&arr[largest], &arr[x]);
    _heapify(arr, n, largest);
  }
}

void heap_sort(elemType arr[], int n) {
  // as complete binary tree
  int i;
  for (i= n / 2 - 1; i>=0; i--) {
    _heapify(arr, n, i);
  }

  for (int i=n-1; i>=0; i--) {
    swap(&arr[0], &arr[i]);
    _heapify(arr, i, 0);
  }
}

void (*sort_ptr)(elemType[], int) = &heap_sort;
