/**
 * bubble sort
 */
#include "sort.h"

void bubble_sort(elemType arr[], int n) {
  int i, j;

  for (i=0; i<n; i++) {
    for (j=1; j<n-i; j++) {
      if (arr[j] < arr[j-1]) {
        swap(&arr[j], &arr[j-1]);
      }
    }
  }
}

void (*sort_ptr)(elemType[], int) = &bubble_sort;
