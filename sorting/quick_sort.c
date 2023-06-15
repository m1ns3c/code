void _quick_sort(int A[], int left, int right) {
  if (left >= right) {
    return;
  }

  int pivot = A[left], t;
  int low=left, high=right;

  while (low < high) {
    while (low < high && A[high] >= pivot) {
      high--;
    }

    if (low < high) {
      A[low] = A[high];
    }

    while (low < high && A[low] <= pivot) {
      low++;
    }

    if (low < high) {
      A[high] = A[low];
    }
  }
  A[low] = pivot;

  _quick_sort(A, left, low-1);
  _quick_sort(A, low+1, right);
}

void Quick_Sort(int A[], int n) {
  _quick_sort(A, 0, n-1);
}
