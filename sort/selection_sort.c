#include "../learning/algo/sort.h"

void selection_sort_v1(elemType arr[], int n)
{
  int min = 0;
  for(int i=0;i<n;i++) {
    for (int j=i+1; j<n; j++) {
      if (arr[j] < arr[min]) {
        min = j;
      }
    }
    if (min != i) {
      swap(&arr[min], &arr[i]);
    }
    min = i+1;
  }
}

void selection_sort_v2(elemType arr[], int n) {
  int min;
  for (int i = 0; i < n - 1; i++) {
    min = i;

    for (int j=i; j<n; j++) {
      if (arr[j] < arr[min]) {
        min = j;
      }
    }

    if (i != min) {
      swap(&arr[min], &arr[i]);
    }
  }
}

void selection_sort(elemType arr[], int n) {
  int min, max, left = 0, right = n - 1;

  while (left < right) {
    min = left;
    max = right;
    for (int j=left; j<=right; j++) {
      if (arr[j] < arr[min]) {
        min = j;
      }

      if (arr[j] > arr[max]) {
        max = j;
      }
    }

    if (min != left) {
      swap(&arr[min], &arr[left]);
      if (max == left) {
        max = min;
      }
    }

    if (max != right) {
      swap(&arr[max], &arr[right]);
    }

    print_arr(arr, n);

    left++;
    right--;
  }
}

void (*sort_algo_ptr)(elemType[], int) = &selection_sort;
