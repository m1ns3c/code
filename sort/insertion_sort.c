/**
 * insertion sort
 */
#include "sort.h"

void insertion_sort(elemType arr[], int n) {
  for (int i=1; i<n; i++) {
    int temp = arr[i];
    int j = i-1;
    for (; j>=0; j--) {
     if (arr[j] > temp) {
       arr[j+1] = arr[j];
     } else {
       break;
     }
    }
    arr[j+1] = temp;
  }
}

void (*sort_ptr)(elemType[], int) = &insertion_sort;
