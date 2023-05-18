/**
 * counting sort
 */
#include "sort.h"
#include <stdlib.h> // calloc

void counting_sort(elemType arr[], int n) {
  int i, j = 0, d, min = arr[0], max = arr[0];
  for (i=1; i<n; i++) {
    if (arr[i] < min) {
      min = arr[i];
    } else if (arr[i] > max) {
      max = arr[i];
    }
  }

  d = max - min + 1;

  // printf("calc:%d=%d-%d\n", d, max, min);

  int *temp = (int *)calloc(d, sizeof(int));

  for (i=0; i<n; i++) {
    temp[arr[i] - min]++;
  }

  for (i=0; i<d; i++) {
    // printf("step:%d [%d]:(%d)\n", i, min + i, temp[i]);

    while(temp[i]--) {
      arr[j++] = min + i;
    }
  }

  free(temp);
}

void (*sort_ptr)(elemType[], int) = &counting_sort;
