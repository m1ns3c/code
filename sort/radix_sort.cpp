/**
 * radix sort
 */
#include "sort.h"
#include <vector>

using namespace std;

void radix_sort(elemType arr[], int n) {
  int i, max = arr[0], count = 0;
  for (i=1; i<n; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }

  printf("max:%d\n", max);

  while (max>0) {
    max = max / 10;
    count++;
  }

  printf("count:%d\n", count);

  vector<vector<int> > buckets(10);

  for (int m=0; m<count; m++) {
    for (i=0; i<n; i++) {
      int k = arr[i];
      if (m) {
        k /= (m * 10);
      }
      k %= 10;

      buckets[k].push_back(arr[i]);
    }

    int n = 0;
    for (i=0; i<10; i++) {
      for (int j=0; j<buckets[i].size(); j++) {
        arr[n++] = buckets[i][j];
      }
      buckets[i].clear();
    }
  }
}

void (*sort_ptr)(elemType[], int) = &radix_sort;
