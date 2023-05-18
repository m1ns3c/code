/**
 * bucket sort
 */
#include "sort.h"
#include <stdlib.h> // calloc

void _bucket_sort(elemType arr[], int n, int num) {
  int i, space, min = arr[0], max = arr[0], k=0;
  // set bucket
  int **buckets = (int **)calloc(num, sizeof(int*));
  int *buckets_count = (int *)calloc(num, sizeof(int));

  // get min max
  for (i=1; i<n;i++) {
    if (arr[i] < min) {
      min = arr[i];
    } else if (arr[i] > max) {
      max = arr[i];
    }
  }

  // set bucket space
  space = (max - min) / num + 1;
  for (i=0; i<num; i++) {
    buckets[i] = (int *)calloc(space, sizeof(int));
  }

  // fill bucket
  for (i=0; i<n;i++) {
    int index = (arr[i] - min) / space;
    buckets[index][buckets_count[index]++] = arr[i];
  }

  // sort bucket[i]
  for (i=0;i<num;i++) {
    // print_arr(buckets[i], buckets_count[i]);
    quick_sort(buckets[i], buckets_count[i]);
    // print_arr(buckets[i], buckets_count[i]);

    // reset arr result
    for (int j=0; j<buckets_count[i]; j++) {
      arr[k++] = buckets[i][j];
    }

    free(buckets[i]);
  }

  free(buckets);
  free(buckets_count);
}

void bucket_sort(elemType arr[], int n) {
  int num = 3;
  _bucket_sort(arr, n, num);
}

void (*sort_ptr)(elemType[], int) = &bucket_sort;
