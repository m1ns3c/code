/**
 * shell sort
 */
#include "sort.h"

/*
// wrong
void shell_sort(elemType arr[], int n) {
  int gap = n / 3 + 1; // (n / 2);
  int i, j;

  while (gap > 0) {
    for (i=0; i<gap; i++) {
      for (j=gap+i; j<n; j+=gap) {
        if (arr[j-gap] > arr[j]) {
          swap(&arr[j-gap], &arr[j]);
        }
      }
    }
    gap--;
  }
}
*/

void shell_sort(elemType arr[], int n) {
  int gap = n, i;
  while (gap > 1) {
    gap = gap / 3 + 1;
    for (i = gap; i< n; i++) {
      int temp = arr[i];
      int j;
      for (j = i; j>=gap && arr[j-gap]>temp; j-=gap) {
        arr[j] = arr[j-gap];
      }
      arr[j] = temp;
    }
  }
}

void (*sort_ptr)(elemType[], int) = &shell_sort;
