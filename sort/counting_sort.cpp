/**
 * counting sort
 */
#include "sort.h"
#include <iostream>
#include <vector>

using namespace std;

void counting_sort(elemType arr[], int n) {
  int i, j = 0, d, min = arr[0], max = arr[0];
  for (i=1; i<n; i++) {
    if (arr[i] < min) {
      min = arr[i];
    }

    if (arr[i] > max) {
      max = arr[i];
    }
  }

  d = max - min + 1;

  // printf("calc:%d=%d-%d\n", d, max, min);

  vector<int> temp(d, 0);

  for (i=0; i<n; i++) {
    temp[arr[i] - min]++;
  }

  for (i=0; i<temp.size(); i++) {
    // printf("step:%d [%d]:(%d)\n", i, min + i, temp[i]);

    while(temp[i]--) {
      arr[j++] = min + i;
    }
  }
}

void (*sort_ptr)(elemType[], int) = &counting_sort;
